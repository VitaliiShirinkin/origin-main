//#include "Figure.h"
//#include "Triangle.h"
#include "equilTriangle.h"
#include "Exception.h"
#include <iostream>

	equilTriangle::equilTriangle(double a) : Triangle(a, a, a, 60, 60, 60)
	{

		Triangle::name = "�������������� �����������";

		if ((a != b && b != c) && (A != B && B != C))
		{
			throw Exception("��� ������� ������ ���� �����, ��� ���� ������ ���� ����� 60");
		}

		//if (a != b && b != c)
		//{
		//	throw Exception("��� ������� ������ ���� �����");
		//}

		//if (A != B && B != C)
		//{
		//	throw Exception("��� ���� ������ ���� ����� 60");
		//}
	}