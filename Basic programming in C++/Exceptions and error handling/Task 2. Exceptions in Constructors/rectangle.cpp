
#include "rectangle.h"
#include "Exception.h"
#include <iostream>

	rectangle::rectangle(double a, double b) : Quadrangle(a, b, a, b, 90, 90, 90, 90)
	{
		Quadrangle::name = "Прямоугольник";

		if ((a != c || b != d) && (A != 90 || B != 90 || C != 90 || D != 90))
		{
			throw Exception("Стороны a,c и b,d должны быть попарно равны, Все углы должны быть равны 90");
		};

		//if (a != c || b != d)
		//{
		//	throw Exception("Стороны a,c и b,d должны быть попарно равны");
		//}

		//if (A != 90 || B != 90 || C != 90 || D != 90)
		//{
		//	throw Exception("Все углы должны быть равны 90");
	/*	}*/
	}