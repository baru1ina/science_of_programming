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
	std::string path = "./plugins/";
	std::vector<HINSTANCE> libraries;

public:
	loader() = default;

	~loader() {
		for (const auto& lib : libraries) FreeLibrary(lib);
		libraries.clear();
	}

	void loadDll(std::map<std::string, int>& funcPrecedence,
		std::map<std::string, unaryf>& functionsU,
		std::map<std::string, binaryf>& functionsB);
};
