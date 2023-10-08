#include <cmath>

extern "C" __declspec(dllexport)
double myPow(double x, double y) {
	return pow(x, y);
}