//#include "Figure.h"
#include "Quadrangle.h"
#include <iostream>

	Quadrangle::Quadrangle(double a, double b, double c, double d, double A, double B, double C, double D)
		: a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D)
	{
		name = "Четырехугольник";
	}
	double Quadrangle::get_a() { return a; }
	double Quadrangle::get_b() { return b; }
	double Quadrangle::get_c() { return c; }
	double Quadrangle::get_d() { return d; }

	double Quadrangle::get_A() { return A; }
	double Quadrangle::get_B() { return B; }
	double Quadrangle::get_C() { return C; }
	double Quadrangle::get_D() { return D; }
	void Quadrangle::metod() {
		std::cout << name << ":" << std::endl;
		std::cout << "Стороны: ";
		std::cout << "a=" << get_a() << ", b=" << get_b() << ", c=" << get_c() << ", d=" << get_d() << std::endl;
		std::cout << "Углы: ";
		std::cout << "A=" << get_A() << ", B=" << get_B() << ", C=" << get_C() << ", D=" << get_D() << std::endl;
		std::cout << std::endl;
	}