// 1_1_Lambda_function.cpp : программа, которая все нечётные элементы массива (std::vector) умножает на 3 с помощью лямбда-функции. 
//Циклы использовать не нужно.

#include <iostream>
#include <Windows.h>
#include <vector>
#include <algorithm>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::vector<int> ivect {4, 7, 9, 14, 12};

    std::cout << "Входные данные: ";

    //for_each Применяет заданный объект функции к каждому элементу
    //в прямом порядке в пределах диапазона и возвращает объект функции.

    std::for_each
    (ivect.begin(), ivect.end(), [](const int& ivect)
        {
            std::cout << '\t' << ivect;
        }
    );
    std::cout << std::endl;

    std::cout << "Выходные данные: ";

    std::for_each
    (ivect.begin(), ivect.end(), [&ivect](const int& ivect)
        {
            if(ivect %2 !=0)
            std::cout << '\t' << ivect * 3;
            else
            std::cout << '\t' << ivect;
        }
    );

    return 0;
}


