//#include "Figure.h"
//#include "Triangle.h"
#include "isosTriangle.h"
#include <iostream>


	isosTriangle::isosTriangle(double a, double b, double A, double B) : Triangle(a, b, a, A, B, A)
	{
		Triangle::name = "Равнобедренный треугольник";
	}