
#include "rhomb.h"
#include "Exception.h"
#include <iostream>

	rhomb::rhomb(double a, double A, double B) : Quadrangle(a, a, a, a, A, B, A, B)
	{
		Quadrangle::name = "����";

		if ((a != b || b != c || c != d)
			&& (A != C || B != D))
		{
			throw Exception("��� ������� ������ ���� �����, ���� A,C � B,D ������ ���� ������� �����");
		}

		//if (a != b || b != c || c != d)
		//{
		//	throw Exception("��� ������� ������ ���� �����");
		//}

		//if (A != C || B != D)
		//{
		//	throw Exception("���� A,C � B,D ������ ���� ������� �����");
		//}
	}