#include "rightTriangle.h"
#include "Exception.h"
#include <iostream>

	rightTriangle::rightTriangle(double a, double b, double c, double A, double B) : Triangle(a, b, c, A, B, 90)
	{
	
	Triangle::name = "Прямоугольный треугольник";

	if (C != 90)
	{
		throw Exception("Угол C не равен 90");
	}
	}
