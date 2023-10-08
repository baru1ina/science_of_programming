#include <cmath>

extern "C" __declspec(dllexport)
double mySin(double x) {
	return sin(x);
}