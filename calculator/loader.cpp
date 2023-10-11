#include "loader.h"

void loader::loadDll(std::map<std::string, int>& funcPrecedence,
	std::map<std::string, unaryf>& functionsU,
	std::map<std::string, binaryf>& functionsB)
{
	std::vector<std::filesystem::path> files ;
	for (const auto& entry : std::filesystem::directory_iterator(this->path))
		if (entry.path().extension() == ".dll")
			files.push_back(entry.path().c_str());

	const wchar_t* widecFileName;
	HINSTANCE load;
	for (const auto& example : files) {
		widecFileName = example.c_str();
		load = LoadLibraryW(widecFileName);
		if (load) {
			this->libraries.push_back(load);
			std::function<std::string(void)> name = (std::string(*) (void)) GetProcAddress(load, "getName");
			std::function<int(void)> precedence = (int(*) (void)) GetProcAddress(load, "getPrecedence");

			funcPrecedence.insert(std::make_pair(name(), precedence()));

			unaryf funcU = nullptr;
			binaryf funcB = nullptr;
			funcU = (unaryf)GetProcAddress(load, "unaryf");
			if (funcU != nullptr) functionsU.insert(std::make_pair(name(), funcU));
			else {
				funcB = (binaryf)GetProcAddress(load, "binaryf");
				if (funcB != nullptr) functionsB.insert(std::make_pair(name(), funcB));
				else throw std::string{ "func not found!" };
			}
		}
		else std::cerr << "file opening failure: " << example << " not found!" << std::endl;
	}
}