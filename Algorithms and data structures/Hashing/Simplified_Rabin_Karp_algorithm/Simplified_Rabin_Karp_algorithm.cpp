// Simplified_Rabin_Karp_algorithm.cpp : Упрощённый алгоритм Рабина-Карпа
//Функция, которая находит в предоставленной строке заданную подстроку

#include <iostream>
#include <Windows.h>

int find_substring_light_rabin_karp(std::string source, std::string substring)//на вход строка и подстрока(искомый шаблон)
{
	int sourceSize = source.length();//вычисляется длина строки с помощью функции length() и записывается в переменную
	int substringSize = substring.length();

	for (int n = 0; n < sourceSize; n++)//поиск по строке-источнику
	{

		if (source[n] == substring[0])//ищем совпадение кода символа [0] из подстроки,  пробегая по всем символам строки-источника
		{                              //если находим, то переходим в след.цикл

			for (int k = 0; k < substringSize; k++)//поиск всей подстроки в строке с индекса найденного совпадения
			{

				if (source[n + k] != substring[k]) break;//считаем и сравниваем хеши подстроки и строки с найденного места до "конца"  

				if (k == (substringSize - 1)) return n; //возвращает индекс найденной подстроки
			}
		}
	}

	return -1;//если не найдена подстрока, то возвращает -1
}

int main(int argc, char** argv)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::string source = " ";
	std::string substring = " ";

	std::cout << "Введите строку, в которой будет осуществляться поиск: ";
	std::cin >> source;

	do {
		std::cout << "Введите строку, которую нужно найти: ";
		std::cin >> substring;

		if (find_substring_light_rabin_karp(source, substring) == -1)
		{
			std::cout << "Подстрока " << substring << " не найдена" << std::endl;
		}
		else
		{
			std::cout << "Подстрока " << substring << " найдена по индексу " << find_substring_light_rabin_karp(source, substring) << std::endl;
		}
	} while (substring != "exit");//поиск, пока пользователь не ввел слово "exit"

	return 0;
}
