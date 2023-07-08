// Task 3. Class hierarchy.cpp

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