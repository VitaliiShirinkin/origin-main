// Task 1. Preprocessor directives.cpp

#include <iostream>
#include <Windows.h>

#define MODE  1// Определили идентификатор MODE значением 1
#if !defined MODE
#error You need to define MODE
#endif

int add(int x, int y) {
	return x + y;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int x=0, y=0;

#if MODE == 1
	std::cout << "Работаю в боевом режиме"<< std::endl;
	std::cout << "Введите число 1: ";
	std::cin >> x; std::cout << std::endl;
	std::cout << "Введите число 2: ";
	std::cin >> y; std::cout << std::endl;
	std::cout << "Результат сложения: " << add(x, y) << std::endl;

#elif MODE == 0
	std::cout << "Работаю в режиме тренировки" << std::endl;

#else
	std::cout << "Неизвестный режим.Завершение работы";
#endif
}
