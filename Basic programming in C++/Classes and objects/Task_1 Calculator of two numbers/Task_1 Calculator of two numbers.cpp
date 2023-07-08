
#include <iostream>
#include <Windows.h>

class Calculator
{
    double num1 = 1;
    double num2 = 1;
public:
    double add() { return num1 + num2; };

    double multiply() { return num1 * num2; };

    double subtract_1_2() { return num1 - num2; };

    double subtract_2_1() { return num2 - num1; };

    double divide_1_2() { return num1 / num2; };

    double divide_2_1() { return num2 / num1; };

    bool set_num1(double num1) {
        if (num1 != 0) {
            this->num1 = num1;
            return true;
        }
        else
        {
            return false;
        }
    }
    bool set_num2(double num2) {
        if (num2 != 0) {
            this->num2 = num2;
            return true;
        }
        else
        {
            return false;
        }
    }
};

void Print_result(double result)
{
    std::cout << result << std::endl;
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << "Это твой калькулятор. В нем можно вводить любые числа, кроме 0. Дробные числа через точку." << std::endl;

    double num1=0.0, num2=0.0;

    Calculator calc;

    while (true) { std::cout << std::endl;
        do {
            std::cout << "ВВедите число 1: ";
            std::cin >> num1;
            if (!calc.set_num1(num1)) 
            {
                std::cout << "Неверный ввод, так как делить на ноль нельзя!" << std::endl;
            };
        } while (!calc.set_num1(num1));
        
        do {
            std::cout << "ВВедите число 2: ";
            std::cin >> num2;
            if (!calc.set_num2(num2)) 
            {
                std::cout << "Неверный ввод, так как делить на ноль нельзя!" << std::endl;
            };
        } while (!calc.set_num2(num2));

        std::cout << std::endl;
      
        calc.add();
        std::cout << " num1 + num2 = ";
        Print_result(calc.add());

        calc.multiply();
        std::cout << " num1 * num2 = ";
        Print_result(calc.multiply());

        calc.subtract_1_2();
        std::cout << " num1 - num2 = ";
        Print_result(calc.subtract_1_2());

        calc.subtract_2_1();
        std::cout << " num2 - num1 = ";
        Print_result(calc.subtract_2_1());

        calc.divide_1_2();
        std::cout << " num1 / num2 = ";
        Print_result(calc.divide_1_2());

        calc.divide_2_1();
        std::cout << " num2 / num1 = ";
        Print_result(calc.divide_2_1());
    }
    return 0;
}
