// GreeterClient.cpp

#include <iostream>
#include "Greeter.h"
#include <Windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Greeting::Greeter grt;
    std::string name;

    std::cout << "Введите имя: ";
    std::cin >> name;
    grt.Greet(name);

    return 0;
}

