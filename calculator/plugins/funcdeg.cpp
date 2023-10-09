#include "funcdeg.h"

extern "C" {
	__declspec(dllexport) double binaryf(double x, double y) {
		return pow(x, y);
	}
	__declspec(dllexport) std::string getName() { return std::string{ "^" }; }
	__declspec(dllexport) int getPrecedence() { return 3; }
}