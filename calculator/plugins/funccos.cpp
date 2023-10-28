#include "funccos.h"

extern "C" {
	__declspec(dllexport) double unaryf(double x) {
	return cos(x);
	}
	__declspec(dllexport) std::string getName() { return std::string{ "cos" }; }
	__declspec(dllexport) int getPrecedence() { return 4; }
}