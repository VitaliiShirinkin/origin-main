// Task 2. Exceptions in Constructors.cpp

#include <iostream>
#include <string>
#include "Figure.h"
#include "Triangle.h"
#include "rightTriangle.h"
#include "isosTriangle.h"
#include "equilTriangle.h"
#include "Quadrangle.h"
#include "rectangle.h"
#include "square.h"
#include "rhomb.h"
#include "parallelogram.h"
#include <Windows.h>
#include "Exception.h"


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	try
	{
		Triangle triangle(10, 20, 30, 50, 60, 70);
		Figure* f_triangle = &triangle;
		f_triangle->metod();
		std::cout << "создан" << std::endl;
	}
	catch (const std::exception& Tr)
	{
		std::cerr << "Треугольник не был создан. " << std::endl << "Причина: ";
		std::cerr << Tr.what() << std::endl;
	}

	try
	{
		rightTriangle r_triangle(10, 20, 30, 30, 60);
		Figure* f_r_triangle = &r_triangle;
		f_r_triangle->metod();
		std::cout << "создан." << std::endl;
	}
	catch (const std::exception& rT)
	{
		std::cerr << "Прямоугольный треугольник не был создан. " << std::endl << "Причина: ";
		std::cerr << rT.what() << std::endl;
	}

	try
	{
		isosTriangle i_triangle(10, 20, 50, 60);
		Figure* f_i_triangle = &i_triangle;
		f_i_triangle->metod();
		std::cout << "создан." << std::endl;
	}
	catch (const std::exception& iT)
	{
		std::cerr << "Равнобедренный треугольник не был создан. " << std::endl << "Причина: ";
		std::cerr << iT.what() << std::endl;
	}

	try
	{
		equilTriangle e_triangle(30);
		Figure* f_e_triangle = &e_triangle;
		f_e_triangle->metod();
		std::cout << "создан." << std::endl;
	}
	catch (const std::exception& eT)
	{
		std::cerr << "Равносторонний треугольник не был создан. " << std::endl << "Причина: ";
		std::cerr << eT.what() << std::endl;
	}

	try
	{
		Quadrangle quadrangle(10, 20, 30, 40, 50, 60, 70, 80);
		Figure* f_quadrangle = &quadrangle;
		f_quadrangle->metod();
		std::cout << "создан." << std::endl;
	}
	catch (const std::exception& Q)
	{
		std::cerr << "Четырехугольник не был создан. " << std::endl << "Причина: ";
		std::cerr << Q.what() << std::endl;
	}

	try
	{
		rectangle rectangle(10, 20);
		Figure* f_rectangle = &rectangle;
		f_rectangle->metod();
		std::cout << "создан." << std::endl;
	}
	catch (const std::exception& Rect)
	{
		std::cerr << "Прямоугольник не был создан. " << std::endl << "Причина: ";
		std::cerr << Rect.what() << std::endl;
	}

	try
	{
		square square(20);
		Figure* f_square = &square;
		f_square->metod();
		std::cout << "создан." << std::endl;
	}
	catch (const std::exception& Sq)
	{
		std::cerr << "Квадрат не был создан. " << std::endl << "Причина: ";
		std::cerr << Sq.what() << std::endl;
	}

	try
	{
		parallelogram parallelogram(20, 30, 30, 40);
		Figure* f_parallelogram = &parallelogram;
		f_parallelogram->metod();
		std::cout << "создан." << std::endl;
	}
	catch (const std::exception& Par)
	{
		std::cerr << "Параллелограмм не был создан. " << std::endl << "Причина: ";
		std::cerr << Par.what() << std::endl;
	}

	try
	{
		rhomb rhomb(30, 30, 40);
		Figure* f_rhomb = &rhomb;
		f_rhomb->metod();
		std::cout << "создан." << std::endl;
	}
	catch (const std::exception& Rh)
	{
		std::cerr << "Ромб не был создан. " << std::endl << "Причина: ";
		std::cerr << Rh.what() << std::endl;
	}
}