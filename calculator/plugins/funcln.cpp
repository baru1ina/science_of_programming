#include "funcln.h"

extern "C" {
	__declspec(dllexport) double unaryf(double x) {
		if (x > 0) return log(x);
		throw std::string{ "wrong sublog expression!" };
	}
	__declspec(dllexport) std::string getName() { return std::string{ "ln" }; }
	__declspec(dllexport) int getPrecedence() { return 4; }
}