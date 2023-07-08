#include "math_func.h"
#include <cmath>

double summ(double x, double y) {
	return x + y;
}

double subtr(double x, double y) {
	return x - y;
}

double mult(double x, double y) {
	return x * y;
}

double div(double x, double y) {
	return x / y;
}

double exp(double x, double y) {
	return std::pow(x, y);
}
