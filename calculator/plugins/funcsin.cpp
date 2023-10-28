#include "funcsin.h"


extern "C" {
	__declspec(dllexport) double unaryf(double x) {
		return sin(x);
	}
	__declspec(dllexport) std::string getName() { return std::string{ "sin" }; }
	__declspec(dllexport) int getPrecedence() { return 4; }
}