
#include "parallelogram.h"
#include "Exception.h"
#include <iostream>

	parallelogram::parallelogram(double a, double b, double A, double B) : Quadrangle(a, b, a, b, A, B, A, B)
	{
		Quadrangle::name = "��������������";

		if ((a != c || b != d)
			&& (A != A || B != D))
		{
			throw Exception("��� ������� ������ ���� �����, ��� ���� ������ ���� ����� 90");
		}

		//if (a != c || b != d)
		//{
		//	throw Exception("������� a,c � b,d ������ ���� ������� �����");
		//}

		//if (A != C || B != D)
		//{
		//	throw Exception("���� A,C � B,D ������ ���� ������� �����");
		//}
	}