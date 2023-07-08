#include "Triangle.h"
//#include "Figure.h"
#include <iostream>
#include "Exception.h"

Triangle::Triangle(double a, double b, double c, double A, double B, double C) :a(a), b(b), c(c), A(A), B(B), C(C)
{
	name = "Треугольник";

}

double Triangle::get_a() { return a; }
double Triangle::get_b() { return b; }
double Triangle::get_c() { return c; }

double Triangle::get_A() { return A; }
double Triangle::get_B() { return B; }
double Triangle::get_C() { return C; }

void Triangle::metod() {
	std::cout << std::endl;
	std::cout << name << ":" << std::endl;
	std::cout << "Стороны: ";
	std::cout << "a=" << get_a() << ", b=" << get_b() << ", c=" << get_c() << std::endl;
	std::cout << "Углы: ";
	std::cout << "A=" << get_A() << ", B=" << get_B() << ", C=" << get_C() << std::endl;

	if ((A + B + C) != 180)
	{
		throw Exception("Сумма углов не равна 180");
	}
}
