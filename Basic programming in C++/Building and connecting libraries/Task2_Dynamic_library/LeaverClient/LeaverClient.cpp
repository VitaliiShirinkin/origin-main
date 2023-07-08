// LeaverClient.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <iostream>
#include <Windows.h>
#include "Task2_Dynamic_library/Leaver.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Farewell::Leaver lv;
    std::string name;
    std::cout << "Введите имя: "; std::cin >> name;
    lv.leave(name);

    return 0;
}