
#include "rectangle.h"
#include "Exception.h"
#include <iostream>

	rectangle::rectangle(double a, double b) : Quadrangle(a, b, a, b, 90, 90, 90, 90)
	{
		Quadrangle::name = "�������������";

		if ((a != c || b != d) && (A != 90 || B != 90 || C != 90 || D != 90))
		{
			throw Exception("������� a,c � b,d ������ ���� ������� �����, ��� ���� ������ ���� ����� 90");
		};

		//if (a != c || b != d)
		//{
		//	throw Exception("������� a,c � b,d ������ ���� ������� �����");
		//}

		//if (A != 90 || B != 90 || C != 90 || D != 90)
		//{
		//	throw Exception("��� ���� ������ ���� ����� 90");
	/*	}*/
	}