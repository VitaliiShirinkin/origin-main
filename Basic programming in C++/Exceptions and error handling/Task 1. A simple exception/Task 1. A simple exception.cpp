// Task 1. A simple exception.cpp
#include <iostream>
#include <Windows.h>


class bad_length : public std::exception
{
public:
	const char* what() const override { return "Вы ввели слово запретной длины! До свидания"; }
};
int function(std::string str, int forbidden_length) { 

	if (str.length() == forbidden_length) throw bad_length();
	return static_cast<int>(str.length());
}

int main(int argc, char** argv)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int forbidden_length = 0; 
	std::string str;
	int length = 0;

	std::cout << "Введите запретную длину: ";
	std::cin >> forbidden_length;

	try {
		do
		{
			std::cout << "Введите слово: ";
			std::cin >> str;
			length = function(str, forbidden_length);
			std::cout << "Длина слова " << str << " равна " << static_cast<int>(str.length()) << std::endl;

		} while (forbidden_length != length);
	}
	catch (const bad_length& ex) { std::cout << ex.what() << std::endl; }
	catch (...) { std::cout << "Неизвестная ошибка" << std::endl; }
}