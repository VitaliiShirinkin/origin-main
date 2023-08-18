// 3_1_Operations_on_corners.cpp : Задача 3*. Операции над углами
//

#include <iostream>
#include <vector>
#include <Windows.h>
#include <algorithm>
#include <functional>
#include <iomanip>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    constexpr auto PI = 3.1415926;
     
    std::vector<int>angles = { 30, 60, 90 };
    std::cout << std::fixed << std::setprecision(7);

    std::cout << "[Входные данные]: " << '\n';
    for (const auto& angle : angles)
    {
        std::cout << angle << " * " << PI << " / 180, ";
    }
    std::cout << "\b//Перевод из градусов в радианы" << '\n';

    std::vector<std::function<void(int)>>functions;

    auto func_cos = [](int angle)
    {
        std::cout << "cos: " << std::cos(angle * PI /180) << " ";
    };
    auto func_sin = [](int angle)
    {
        std::cout << "sin: " << std::sin(angle * PI / 180) << " ";
    };

    functions.push_back(func_cos);
    functions.push_back(func_sin);

    std::cout << "[Выходные данные]: "<< '\n';

    std::cout << std::defaultfloat;

    for (const auto& angle : angles) {
        std::cout << angle * PI/180 << ": ";
        for (const auto& function : functions)
            function(angle);
        std::cout << std::endl;
    }

    return 0;
}
