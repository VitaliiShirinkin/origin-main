// Task 2. Shapes. Sides and corners.cpp

#include <iostream>
#include <string>
#include <Windows.h>

class Figure
{
protected:
	std::string name;//Имя фигуры

public:
	std::string get_name() { return name; }
	virtual void metod() {
		std::cout << name;
	}
};

class Triangle : public Figure
{
protected:
	double a = 0, b = 0, c = 0;//Длины сторон
	double A = 0, B = 0, C = 0;//Углы фигур

public:
	Triangle(double a, double b, double c, double A, double B, double C) :a(a), b(b), c(c), A(A), B(B), C(C)
	{
		name = "Треугольник";
	}
	double get_a() { return a; }
	double get_b() { return b; }
	double get_c() { return c; }

	double get_A() { return A; }
	double get_B() { return B; }
	double get_C() { return C; }

	void metod() override {
		std::cout << name << ":" << std::endl;
		std::cout << "Стороны: ";
		std::cout << "a=" << get_a() << ", b=" << get_b() << ", c=" << get_c() << std::endl;
		std::cout << "Углы: ";
		std::cout << "A=" << get_A() << ", B=" << get_B() << ", C=" << get_C() << std::endl;
		std::cout << std::endl;
	}
};

class rightTriangle : public Triangle//прямоугольный треугольник
{
public:
	rightTriangle(double a, double b, double c, double A, double B) : Triangle(a, b, c, A, B, 90)
	{
		Triangle::name = "Прямоугольный треугольник";
	}

};

class isosTriangle : public Triangle//равнобедренный треугольник
{
public:
	isosTriangle(double a, double b, double A, double B) : Triangle(a, b, a, A, B, A)
	{
		Triangle::name = "Равнобедренный треугольник";
	}
};

class equilTriangle : public Triangle//равносторонний треугольник
{
public:
	equilTriangle(double a) : Triangle(a, a, a, 60, 60, 60)
	{
		Triangle::name = "Равносторонний треугольник";
	}
};

class Quadrangle : public Figure//Четырехугольник
{
protected:
	double a = 0, b = 0, c = 0, d = 0;//Длины сторон
	double A = 0, B = 0, C = 0, D = 0;//Углы фигур

public:
	Quadrangle(double a, double b, double c, double d, double A, double B, double C, double D) : a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D)
	{
		name = "Четырехугольник";
	}
	double get_a() { return a; }
	double get_b() { return b; }
	double get_c() { return c; }
	double get_d() { return d; }

	double get_A() { return A; }
	double get_B() { return B; }
	double get_C() { return C; }
	double get_D() { return D; }
	void metod() override {
		std::cout << name << ":" << std::endl;
		std::cout << "Стороны: ";
		std::cout << "a=" << get_a() << ", b=" << get_b() << ", c=" << get_c() << ", d=" << get_d() << std::endl;
		std::cout << "Углы: ";
		std::cout << "A=" << get_A() << ", B=" << get_B() << ", C=" << get_C() << ", D=" << get_D() << std::endl;
		std::cout << std::endl;
	}
};

class rectangle : public Quadrangle//прямоугольник
{
public:
	rectangle(double a, double b) : Quadrangle(a, b, a, b, 90, 90, 90, 90)
	{
		Quadrangle::name = "Прямоугольник";
	}
};

class square : public Quadrangle//квадрат
{
public:
	square(double a) : Quadrangle(a, a, a, a, 90, 90, 90, 90)
	{
		Quadrangle::name = "Квадрат";
	}
};

class parallelogram : public Quadrangle//Параллелограмм
{
public:
	parallelogram(double a, double b, double A, double B) : Quadrangle(a, b, a, b, A, B, A, B)
	{
		Quadrangle::name = "Параллелограмм";
	}
};

class rhomb : public Quadrangle//Ромб
{
public:
	rhomb(double a, double A, double B) : Quadrangle(a, a, a, a, A, B, A, B)
	{
		Quadrangle::name = "Ромб";
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Triangle triangle(10, 20, 30, 50, 60, 70);
	Figure* f_triangle = &triangle;
	f_triangle->metod();

	rightTriangle r_triangle(10, 20, 30, 50, 60);
	Figure* f_r_triangle = &r_triangle;
	f_r_triangle->metod();

	isosTriangle i_triangle(10, 20, 50, 60);
	Figure* f_i_triangle = &i_triangle;
	f_i_triangle->metod();

	equilTriangle e_triangle(30);
	Figure* f_e_triangle = &e_triangle;
	f_e_triangle->metod();

	Quadrangle quadrangle(10, 20, 30, 40, 50, 60, 70, 80);
	Figure* f_quadrangle = &quadrangle;
	f_quadrangle->metod();

	rectangle rectangle(10, 20);
	Figure* f_rectangle = &rectangle;
	f_rectangle->metod();

	square square(20);
	Figure* f_square = &square;
	f_square->metod();

	parallelogram parallelogram(20, 30, 30, 40);
	Figure* f_parallelogram = &parallelogram;
	f_parallelogram->metod();

	rhomb rhomb(30, 30, 40);
	Figure* f_rhomb = &rhomb;
	f_rhomb->metod();
}