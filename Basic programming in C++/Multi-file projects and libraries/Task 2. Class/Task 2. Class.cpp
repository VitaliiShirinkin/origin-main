// Task 2. Class.cpp

#include <iostream>
#include <Windows.h>
#include <cstring>
#include "Counter.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string v;
    int initial_init_value = 0;
    bool check_true_initial_init_value = false;

    //Цикл проверки и задания начального значения счётчика
    do
    {
        std::cout << std::endl << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
        std::cin >> v;
        std::cout << std::endl;

        if (v == "да" || v == "Да")
        {
            std::cout << "Введите начальное значение счётчика: ";
            std::cin >> initial_init_value;
            check_true_initial_init_value = true;
        }
        else if (v == "нет" || v == "Нет")
        {
            check_true_initial_init_value = true;
        }
        else
        {
            std::cout << "Вы ввели неверную команду.";
        }
    } while (!check_true_initial_init_value);

    Counter Counter(initial_init_value);

    std::cout << std::endl;

    std::string command;
    bool check = false;

    //Цикл работы счётчика
    do
    {
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> command;

        if (command == "x")
        {
            std::cout << "Пока.";
            check = true;
        }
        else if (command == "+")
        {
            Counter.plus_one();
        }
        else if (command == "-")
        {
            Counter.minus_one();
        }
        else if (command == "=")
        {
            std::cout << "Значение счетчика: " << Counter.getCounter() << "." << std::endl;
        }
        else
        {
            std::cout << "Вы ввели неверную команду." << std::endl;
        }
    } while (!check);
    return 0;
}
