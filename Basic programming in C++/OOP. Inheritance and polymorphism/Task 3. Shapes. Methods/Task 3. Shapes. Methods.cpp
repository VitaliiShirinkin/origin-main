// Task 3. Shapes. Methods.cpp

#include <iostream>
#include <string>
#include <Windows.h>

class Figure
{
protected:
	std::string name = "Фигура";//Имя фигуры
	bool check = false;//Правильность фигуры
	int sumS = 0;//Кол-во сторон фигуры

	virtual bool Check() //метод проверки фигуры.Кол-во сторон == 0 
	{
		if (sumS == 0) { return true; }
		else { return false; }
	};

public://Геттеры 
	std::string get_name() { return name; }

	virtual void printf() //Метод печати и проверка правильности фигуры
	{
		std::cout << std::endl;
		std::cout << name << ":" << std::endl;
		if (Check()) { std::cout << "Правильная" << std::endl; }
		else { std::cout << "Неправильная" << std::endl; }

		std::cout << "Количество сторон: " << sumS << std::endl;
	}
};


class Triangle : public Figure
{
protected:
	double a = 0, b = 0, c = 0;//Длины сторон
	double A = 0, B = 0, C = 0;//Углы фигур
	bool Check() override //переопределение метода проверки на сумму углов треуг == 180
	{
		if ((A + B + C) == 180) { return true; }
		else { return false; }
	};
public://Конструктор
	Triangle(double a, double b, double c, double A, double B, double C):a(a), b(b), c(c), A(A), B(B), C(C)
	{
		name = "Треугольник";
		sumS = 3; check = Check();
	}
	double get_a() { return a; }
	double get_b() { return b; }
	double get_c() { return c; }

	double get_A() { return A; }
	double get_B() { return B; }
	double get_C() { return C; }

	void printf() override //Переопределение метода печати с вызовом базового метода печати
	{
	    Figure::printf();

		std::cout << "Стороны: " << "a=" << get_a() << ", b=" << get_b() << ", c=" << get_c() << std::endl;
		std::cout << "Углы: " << "A=" << get_A() << ", B=" << get_B() << ", C=" << get_C() << std::endl;
	}
};

class rightTriangle : public Triangle//прямоугольный треугольник
{
protected:
	bool Check() override
	{
		if (Triangle::Check() && (C == 90)) { return true; }
		else { return false; }
	};
public:
	rightTriangle(double a, double b, double c, double A, double B, double C) : Triangle(a, b, c, A, B, C)
	{ Triangle::name = "Прямоугольный треугольник"; }
};

class isosTriangle : public Triangle//равнобедренный треугольник
{
protected:
	bool Check() override
	{
		if (Triangle::Check() && (a==c && A==C)) { return true; }
		else { return false; }
	};
public:
	isosTriangle(double a, double b, double c, double A, double B, double C) : Triangle(a, b, c, A, B, C)
	{ Triangle::name = "Равнобедренный треугольник"; }
};

class equilTriangle : public Triangle//равносторонний треугольник
{
private:
	bool CheckEquilTriangle()
	{
		if (a == b && b == c && (A == 60) && B == 60 && C == 60) { return true; }
		else { return false; }
	};
public:
	equilTriangle(double a, double b, double c, double A, double B, double C) : Triangle(a, b, c, A, B, C)
	{
		Triangle::name = "Равносторонний треугольник";
	}
protected:
	bool Check() override
	{
		if (Triangle::Check() && (CheckEquilTriangle())) { return true; }
		else { return false; }
	};
};

class Quadrangle : public Figure//Четырехугольник
{
protected:
	double a = 0, b = 0, c = 0, d = 0;//Длины сторон
	double A = 0, B = 0, C = 0, D = 0;//Углы фигур

	virtual bool Check() //Виртуальный метод проверки на сумму углов четырехугольника == 360
	{
		if ((A + B + C + D) == 360) { return true; }
		else { return false; }
	};
	bool CheckSides1() //Метод проверки, что стороны а,с и в,d попарно равны
	{
		if (a == c && b == d) { return true; }
		else { return false; }
	};
	bool CheckSides2() //Метод проверки, что все стороны равны
	{
		if (a == b && b == c && c == d) { return true; }
		else { return false; }
	};
	bool CheckAngles1() //Метод проверки, что все углы равны 90 гр
	{
		if (A == 90 && B == 90 && C == 90 && D == 90) { return true; }
		else { return false; }
	};
	bool CheckAngles2() //Метод проверки, что углы А,С и В,D попарно равны
	{
		if (A == C && B == D) { return true; }
		else { return false; }
	};
public:
	Quadrangle(double a, double b, double c, double d, double A, double B, double C, double D) : a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D)
	{
		name = "Четырехугольник"; sumS = 4;
	};
	double get_a() { return a; }
	double get_b() { return b; }
	double get_c() { return c; }
	double get_d() { return d; }

	double get_A() { return A; }
	double get_B() { return B; }
	double get_C() { return C; }
	double get_D() { return D; }

	void printf() override //Переопределение метода печати с вызовом базового метода печати
	{
		Figure::printf();

		std::cout << "Стороны: " << "a=" << get_a() << ", b=" << get_b() << ", c=" << get_c() << ", d=" << get_d() << std::endl;
		std::cout << "Углы: " << "A=" << get_A() << ", B=" << get_B() << ", C=" << get_C() << ", D=" << get_D() << std::endl;
	}
};

class rectangle : public Quadrangle//прямоугольник
{
protected:
	bool Check() override
	{
		if (Quadrangle::Check() && Quadrangle::CheckSides1() && Quadrangle::CheckAngles1())
		{
			return true;
		}
		else
		{
			return false;
		}
	};

public:
	rectangle(double a, double b, double c, double d, double A, double B, double C, double D) : Quadrangle(a, b, a, b, A, B, C, D)
	{
		Quadrangle::name = "Прямоугольник";
	}
};

class square : public Quadrangle//квадрат
{
protected:
	bool Check() override {
		if (Quadrangle::Check() && Quadrangle::CheckSides2() && Quadrangle::CheckAngles1()) { return true; }
		else { return false; }
	};
public:
	square(double a, double b, double c, double d, double A, double B, double C, double D) : Quadrangle(a, b, a, b, A, B, C, D)
	{
		Quadrangle::name = "Квадрат";
	}
};

class parallelogram : public Quadrangle//Параллелограмм
{
protected:
	bool Check() override {
		if (Quadrangle::Check() && Quadrangle::CheckSides1() && Quadrangle::CheckAngles2()) { return true; }
		else { return false; }
	};
public:
	parallelogram(double a, double b, double c, double d, double A, double B, double C, double D) : Quadrangle(a, b, a, b, A, B, C, D)
	{
		Quadrangle::name = "Параллелограмм";
	}
};

class rhomb : public Quadrangle//Ромб
{
protected:
	bool Check() override {
		if (Quadrangle::Check() && Quadrangle::CheckSides2() && Quadrangle::CheckAngles2()) { return true; }
		else { return false; }
	};
public:
	rhomb(double a, double b, double c, double d, double A, double B, double C, double D) : Quadrangle(a, b, a, b, A, B, C, D)
	{
		Quadrangle::name = "Ромб";
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Figure Figure1;
	Figure1.printf();

	Triangle Triangle1(10, 20, 30, 50, 60, 70);
	Figure* f1 = &Triangle1;
	f1->printf();

	rightTriangle rightTriangle1(10, 20, 30, 50, 60, 90);
	Figure* f2 = &rightTriangle1;
	f2->printf();

	rightTriangle rightTriangle2(10, 20, 30, 50, 40, 90);
	Figure* f3 = &rightTriangle2;
	f3->printf();

	isosTriangle isosTriangle1(10, 20, 10, 50, 60, 50);
	Figure* f4 = &isosTriangle1;
	f4->printf();

	isosTriangle isosTriangle2(10, 20, 10, 60, 60, 60);
	Figure* f5 = &isosTriangle2;
	f5->printf();

	equilTriangle equilTriangle1(30, 30, 30, 60, 60, 60);
	Figure* f6 = &equilTriangle1;
	f6->printf();

	Quadrangle Quadrangle1(10, 20, 30, 40, 50, 60, 70, 80);
	Figure* f7 = &Quadrangle1;
	f7->printf();

	rectangle rectangle1(10, 20, 10, 20, 90, 90, 90, 90);
	Figure* f8 = &rectangle1;
	f8->printf();

	square square1(20, 20, 20, 20, 90, 90, 90, 90);
	Figure* f9 = &square1;
	f9->printf();

	parallelogram parallelogram1(20, 30, 20, 30, 30, 40, 30, 40);
	Figure* f10 = &parallelogram1;
	f10->printf();

	rhomb rhomb1(30, 30, 30, 30, 30, 40, 30, 40);
	Figure* f11 = &rhomb1;
	f11->printf();
}