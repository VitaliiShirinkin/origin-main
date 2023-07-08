//#include "Figure.h"
//#include "Quadrangle.h"
#include "rectangle.h"
#include <iostream>

	rectangle::rectangle(double a, double b) : Quadrangle(a, b, a, b, 90, 90, 90, 90)
	{
		Quadrangle::name = "Прямоугольник";
	}