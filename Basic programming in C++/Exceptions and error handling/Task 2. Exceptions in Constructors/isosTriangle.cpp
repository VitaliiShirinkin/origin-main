//#include "Figure.h"
//#include "Triangle.h"
#include "isosTriangle.h"
#include <iostream>
#include "Exception.h"


	isosTriangle::isosTriangle(double a, double b, double A, double B) : Triangle(a, b, a, A, B, A)
	{

		Triangle::name = "�������������� �����������";

		if (a != c && A != C)
		{
			throw Exception("������� a � c �� ����� � ���� A � C �� �����");
		}

		//if (a != c)
		//{
		//	throw Exception("������� a � c �� �����");
		//}

		//if (A != C)
		//{
		//	throw Exception("���� A � C �� �����");
		//}
	}