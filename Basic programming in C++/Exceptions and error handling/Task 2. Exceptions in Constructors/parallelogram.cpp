
#include "parallelogram.h"
#include "Exception.h"
#include <iostream>

	parallelogram::parallelogram(double a, double b, double A, double B) : Quadrangle(a, b, a, b, A, B, A, B)
	{
		Quadrangle::name = "Параллелограмм";

		if ((a != c || b != d)
			&& (A != A || B != D))
		{
			throw Exception("Все стороны должны быть равны, Все углы должны быть равны 90");
		}

		//if (a != c || b != d)
		//{
		//	throw Exception("Стороны a,c и b,d должны быть попарно равны");
		//}

		//if (A != C || B != D)
		//{
		//	throw Exception("Углы A,C и B,D должны быть попарно равны");
		//}
	}