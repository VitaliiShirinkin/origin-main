// NaiveHashFunctionForAstring.cpp : Реализация функции, которая рассчитывает хэш для строки с помощью наивного алгоритма.
// Функция должна принимать на вход строку, а возвращать хэш этой функции — целое число.
//Наивный алгоритм вычисления хэша строки заключается в сложении кодов всех символов строки

#include <iostream>
#include <Windows.h>

int simple_string_hash(std::string s)
{
	int hash(0);
	int lenght = s.length();//длина слова(шаблона)

	for (size_t i = 0; i < lenght; i++)
	{
		hash += s[i];//значения символов по таблице ascii записываются в хеш и суммируются
	}

	return hash;
}

int main(int argc, char** argv)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::string input = " ";

	do
	{
		std::cout << "Введите строку: ";
		std::cin >> input;
		std::cout << "Наивный хэш строки " << input << "= " << simple_string_hash(input) << '\n';


	} while (input != "exit");

	return 0;
}


