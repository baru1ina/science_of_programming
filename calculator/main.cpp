#include "calc.h"
#include <Windows.h>

int main() {
	typedef double (*unaryf) (double);
	typedef double (*binaryf) (double, double);

	HINSTANCE load;

	load = LoadLibrary(L"./plugins/funcsin.dll");
	unaryf mySin = nullptr;
	if (load) {
		mySin = (unaryf)GetProcAddress(load, "mySin");
		std::cout << mySin(1.57) << std::endl;
		FreeLibrary(load);
	}
	else {
		FreeLibrary(load);
		std::cout << "errrrror" << std::endl;
	}

	load = LoadLibrary(L"./plugins/funccos.dll");
	unaryf myCos = nullptr;
	if (load) {
		myCos = (unaryf)GetProcAddress(load, "myCos");
		std::cout << myCos(0) << std::endl;
		FreeLibrary(load);
	}
	else {
		FreeLibrary(load);
		std::cout << "errrrror" << std::endl;
	}

	load = LoadLibrary(L"./plugins/funcdeg.dll");
	binaryf myPow = nullptr;
	if (load) {
		myPow = (binaryf)GetProcAddress(load, "myPow");
		std::cout << myPow(2, 2) << std::endl;
		FreeLibrary(load);
	}
	else {
		FreeLibrary(load);
		std::cout << "errrrror" << std::endl;
	}

	std::cout << "press Enter to escape\n" <<std::endl;
	std::cout << "operations available: +    -    *    /    ()    ^\nfunctions available: sin(x)  cos(x)  tg(x)  ln(x) \n\nput the expression to calculate:\n" << std::endl;

	std::string input;
	std::getline(std::cin, input);
	std::cout << "\n"  << std::endl;

	calc* sample = new calc();

	while (input != "") {
		try { sample->calculate(input); }
		catch (std::string error_message) { std::cout << error_message << std::endl; }

		std::string result = sample->getOutput();

		std::cout << "\nresult: " << result << std::endl;

		std::cout << "\nput the expression to calculate:\n" << std::endl;
		std::getline(std::cin, input);
	}

	delete sample;

	return 0;
}

// 52^ 4 + 1^(1/2) - sin(0)