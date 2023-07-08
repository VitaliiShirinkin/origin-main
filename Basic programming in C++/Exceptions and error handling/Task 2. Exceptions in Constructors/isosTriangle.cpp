//#include "Figure.h"
//#include "Triangle.h"
#include "isosTriangle.h"
#include <iostream>
#include "Exception.h"


	isosTriangle::isosTriangle(double a, double b, double A, double B) : Triangle(a, b, a, A, B, A)
	{

		Triangle::name = "Равнобедренный треугольник";

		if (a != c && A != C)
		{
			throw Exception("Стороны a и c не равны и Углы A и C не равны");
		}

		//if (a != c)
		//{
		//	throw Exception("Стороны a и c не равны");
		//}

		//if (A != C)
		//{
		//	throw Exception("Углы A и C не равны");
		//}
	}