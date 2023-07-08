//#include "Figure.h"
//#include "Triangle.h"
#include "equilTriangle.h"
#include <iostream>

	equilTriangle::equilTriangle(double a) : Triangle(a, a, a, 60, 60, 60)
	{
		Triangle::name = "Равносторонний треугольник";
	}