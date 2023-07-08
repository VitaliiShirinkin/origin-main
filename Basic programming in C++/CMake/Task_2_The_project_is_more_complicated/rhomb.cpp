//#include "Figure.h"
//#include "Quadrangle.h"
//#include "rectangle.h"
//#include "square.h"
//#include "parallelogram.h"
#include "rhomb.h"
#include <iostream>

	rhomb::rhomb(double a, double A, double B) : Quadrangle(a, a, a, a, A, B, A, B)
	{
		Quadrangle::name = "Ромб";
	}