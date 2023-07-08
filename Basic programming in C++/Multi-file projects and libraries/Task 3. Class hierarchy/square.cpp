//#include "Figure.h"
//#include "Quadrangle.h"
//#include "rectangle.h"
#include "square.h"
#include <iostream>

	square::square(double a) : Quadrangle(a, a, a, a, 90, 90, 90, 90)
	{
		Quadrangle::name = " вадрат";
	}