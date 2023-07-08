#include "rightTriangle.h"
//#include "Figure.h"
//#include "Triangle.h"
#include <iostream>

	rightTriangle::rightTriangle(double a, double b, double c, double A, double B) : Triangle(a, b, c, A, B, 90)
	{
	Triangle::name = "Прямоугольный треугольник";
	}
