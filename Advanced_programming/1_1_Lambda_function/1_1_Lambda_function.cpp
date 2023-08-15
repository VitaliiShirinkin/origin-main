// 1_1_Lambda_function.cpp : программа, которая все нечётные элементы массива (std::vector) умножает на 3 с помощью лямбда-функции. 
//Циклы использовать не нужно.
    //for_each Применяет заданный объект функции к каждому элементу
    //в прямом порядке в пределах диапазона и возвращает объект функции.

#include <iostream>
#include <Windows.h>
#include <vector>
#include <algorithm>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::vector<int> ivect {4, 7, 9, 14, 12, 2, 21, 14};


    std::cout << "Входные данные: ";
    std::for_each
    (ivect.begin(), ivect.end(), [](const int& n) {std::cout << '\t' << n;});
    std::cout << std::endl;


    std::cout << "Выходные данные: ";
    auto itertns = ivect.begin();

    std::for_each(ivect.begin(), ivect.end(), [&itertns](const int& n) {if(1 == n %2) {*itertns = n * 3;} ++itertns;});
    std::for_each(ivect.begin(), ivect.end(), [](const int& n) {std::cout << '\t' << n;});

    return 0;
}


