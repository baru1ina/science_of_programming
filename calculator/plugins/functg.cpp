#include "functg.h"

extern "C"{
	__declspec(dllexport) double unaryf(double x) {
		if (sin(x) != 0) return tan(x);
		throw std::string{ "tan(x) does not exist!" };
	}
	__declspec(dllexport) std::string getName() { return std::string{ "tg" }; }
	__declspec(dllexport) int getPrecedence() { return 4; }
}