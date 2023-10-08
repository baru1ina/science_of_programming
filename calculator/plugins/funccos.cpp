#include <cmath>

extern "C" __declspec(dllexport)
double myCos(double x) {
	return cos(x);
}