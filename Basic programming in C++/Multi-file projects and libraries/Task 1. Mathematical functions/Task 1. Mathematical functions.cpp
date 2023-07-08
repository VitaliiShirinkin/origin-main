// Task 1. Mathematical functions.cpp

#include <iostream>
#include "math_func.h"
#include <Windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    double x; double y;
    int num; std::string name_oper;
    bool check = false;

    std::cout << "Введите первое число: "; std::cin >> x;
    std::cout << std::endl;
    std::cout << "Введите второе число: "; std::cin >> y;
    std::cout << std::endl;

    do
    {
        std::cout << "Выберите операцию (1 - сложение, 2 - вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень):";
        std::cin >> num; std::cout << std::endl;
        if (num == 4 && y == 0) {
            std::cout << "Делить на 0 нельзя!" << std::endl;
        }
        else if  (num <= 5 && num >= 1) {
            check = true;
        }
        else
        {
            std::cout << "Повторите ввод." << std::endl;
        }
        
    } while (!check);
    switch (num)
    {
           case(1): {name_oper = "плюс";
               break; }
           case(2): {name_oper = "минус";
               break; }
           case(3): {name_oper = "умножить";
               break; }
           case(4): {name_oper = "разделить";
               break; }
           case(5): {name_oper = "в степени";
               break; }
    }

    std::cout << x << " " << name_oper << " " << y << " = ";
    if (num==1){ std::cout << summ(x, y); }
    else if (num == 2) { std::cout << subtr(x, y); }
    else if (num == 3) { std::cout << mult(x, y); }
    else if (num == 4) { std::cout << div(x, y); }
    else { std::cout << exp(x, y); }
}

