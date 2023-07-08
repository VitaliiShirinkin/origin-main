//#include "Figure.h"
//#include "Quadrangle.h"
//#include "rectangle.h"
//#include "square.h"
#include "parallelogram.h"
#include <iostream>

	parallelogram::parallelogram(double a, double b, double A, double B) : Quadrangle(a, b, a, b, A, B, A, B)
	{
		Quadrangle::name = "ֿאנאככוכמדנאלל";
	}