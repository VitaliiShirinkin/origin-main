
#include "square.h"
#include "Exception.h"
#include <iostream>

	square::square(double a) : Quadrangle(a, a, a, a, 90, 90, 90, 90)
	{
		Quadrangle::name = "�������";

		if ((a != b || b != c || c != d)
			&& (A != 90 || B != 90 || C != 90 || D != 90))
		{
			throw Exception("��� ������� ������ ���� �����, ��� ���� ������ ���� ����� 90");
		}

		//if (a != b || b != C || c != d)
		//{
		//	throw Exception("��� ������� ������ ���� �����");
		//}

		//if (A != 90 || B != 90 || C != 90 || D != 90)
		//{
		//	throw Exception("��� ���� ������ ���� ����� 90");
		//}
	}