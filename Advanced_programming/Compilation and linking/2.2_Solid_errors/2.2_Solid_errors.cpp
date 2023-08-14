// 2.2_Solid_errors.cpp : Задача 2*. Сплошные ошибки
//

﻿//Cинтаксические ошибки:
/*
#include <iostream>

int main()
{
	for (int i = 0; i < 10, ++i)								i<10;	вместо ; поставлена ,
	{
		if (i % 2) std::cout << i								i;		нет ;
		if (i >= 5) std::cout << i " больше 5" << std::endl;	i << "	нет <<
}																}		нет закрывающей фигурной скобки
*/

// Семантические ошибки:
/*
#include <iostream>

int main()
{
	for (int i = 0; i < 10; +i)									++i		неправильная запись префиксного инкремента
	{
		if (i % 2) std::cout << i << std::endl;
		if (i >= 5) std::cout << i << " больше 5" << std::endl;	больше 5	больше или равно
	}

}
*/

// Ошибка линковки:
/*
test.h
int f(int n);


test.cpp

#include <iostream>
#include "test.h"

int f(bool n)														int f(int n)	объявленная фунция в заголовочном файле имеет другой тип параметров
{}

int Main()															int main()		строго написание main() маленькими строчными буквами
{
	for (int i = 0; i < 10; ++i)
	{
		if (i % 2) std::cout << i << std::endl;
		if (i >= 5) std::cout << i << " больше 5" << std::endl;
		int m = f(i);
	}
	return 0;
};
*/