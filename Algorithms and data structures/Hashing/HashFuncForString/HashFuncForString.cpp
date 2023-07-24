// HashFuncForString.cpp : Настоящая хэш-функция для строки
//

#include <iostream>
#include <Windows.h>
#include <cmath>

int real_string_hash(std::string s, int p, int n)
{
	uint64_t hash(0);
	int lenght = s.length();//длина слова(шаблона)

	for (size_t i = 0; i < lenght; i++)
	{
		hash += pow(p, i) * s[i];//код каждого символа строки умножается на p в степени индекса этого символа, полученные числа складываются
	}

	return (hash % n);//В конце берётся остаток от деления получившейся суммы на число n — это и будет хэш.
}

int main(int argc, char** argv)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	int p = 0;
	int n = 0;
	std::string input = " ";

	std::cout << "Введите p: ";
	std::cin >> p;
	std::cout << "Введите n: ";
	std::cin >> n;

	do
	{
		std::cout << "Введите строку: ";
		std::cin >> input;
		std::cout << "Хэш строки " << input << "= " << real_string_hash(input, p, n) << '\n';


	} while (input != "exit");

	return 0;
}


