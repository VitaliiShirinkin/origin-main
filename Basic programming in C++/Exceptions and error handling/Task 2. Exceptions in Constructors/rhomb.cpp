
#include "rhomb.h"
#include "Exception.h"
#include <iostream>

	rhomb::rhomb(double a, double A, double B) : Quadrangle(a, a, a, a, A, B, A, B)
	{
		Quadrangle::name = "Ромб";

		if ((a != b || b != c || c != d)
			&& (A != C || B != D))
		{
			throw Exception("Все стороны должны быть равны, Углы A,C и B,D должны быть попарно равны");
		}

		//if (a != b || b != c || c != d)
		//{
		//	throw Exception("Все стороны должны быть равны");
		//}

		//if (A != C || B != D)
		//{
		//	throw Exception("Углы A,C и B,D должны быть попарно равны");
		//}
	}