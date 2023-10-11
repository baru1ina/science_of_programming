#pragma once 
#include <iostream>
#include <map>
#include <functional>
#include <iostream>
#include <stack>
#include <cctype>
#include <algorithm>
#include <string>
#include <cmath>
#include <sstream>
#include <vector>
#include <Windows.h>
#include <filesystem>

typedef double(*unaryf) (double);
typedef double(*binaryf) (double, double);

class loader {
private:
	std::filesystem::path path = "plugins";
	std::vector<HINSTANCE> libraries;

public:
	loader() = default;
	~loader() {
		for (const auto& lib : libraries)
			FreeLibrary(lib);
		libraries.clear();
	}

	loader(loader const&) = default;
	loader(loader&&) = default;
	loader& operator=(loader const&) = default;
	loader& operator=(loader&&) = default;

	void loadDll(std::map<std::string, int>& funcPrecedence,
		std::map<std::string, unaryf>& functionsU,
		std::map<std::string, binaryf>& functionsB);
};
