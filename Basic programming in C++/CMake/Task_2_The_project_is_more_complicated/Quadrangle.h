#pragma once
#include "Figure.h"

class Quadrangle : public Figure//Четырехугольник
{
protected:
	double a = 0, b = 0, c = 0, d = 0;//Длины сторон
	double A = 0, B = 0, C = 0, D = 0;//Углы фигур

public:
	Quadrangle(double a, double b, double c, double d, double A, double B, double C, double D);
	double get_a();
	double get_b();
	double get_c();
	double get_d();

	double get_A();
	double get_B();
	double get_C();
	double get_D();
	void metod() override;
};