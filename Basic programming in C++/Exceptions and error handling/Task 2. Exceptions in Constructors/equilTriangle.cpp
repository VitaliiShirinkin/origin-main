//#include "Figure.h"
//#include "Triangle.h"
#include "equilTriangle.h"
#include "Exception.h"
#include <iostream>

	equilTriangle::equilTriangle(double a) : Triangle(a, a, a, 60, 60, 60)
	{

		Triangle::name = "–авносторонний треугольник";

		if ((a != b && b != c) && (A != B && B != C))
		{
			throw Exception("¬се стороны должны быть равны, все углы должны быть равны 60");
		}

		//if (a != b && b != c)
		//{
		//	throw Exception("¬се стороны должны быть равны");
		//}

		//if (A != B && B != C)
		//{
		//	throw Exception("все углы должны быть равны 60");
		//}
	}