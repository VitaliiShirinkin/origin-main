// Task 1. Shapes. Number of sides.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.//

#include <iostream>
#include <string>

class Figure
{
protected:
	std::string name;
	int sides_count = 0;

public:
	Figure() :Figure(0, "Фигура") {};
	Figure(int sides_count, std::string name)
	{
		this->name = name;
		this->sides_count = sides_count;
	}
	int get_sides_count() const {return sides_count;}
	std::string get_name() const { return name; }
};

class Triangle : public Figure
{
public:
	Triangle() :Figure(3, "Треугольник") {};

};

class Quadrangle : public Figure
{
public:
	Quadrangle() :Figure(4, "Четырехугольник") {};

};

void printf(Figure& f) {
	std::cout << f.get_name() << ": " << f.get_sides_count() << std::endl;
}


int main()
{
    system("chcp 1251 > nul");

    std::cout << "Количество сторон: \n";

	Figure Figure1;
	printf(Figure1);

	Triangle Triangle1;
	printf(Triangle1);

	Quadrangle Quadrangle1;
	printf(Quadrangle1);
}

