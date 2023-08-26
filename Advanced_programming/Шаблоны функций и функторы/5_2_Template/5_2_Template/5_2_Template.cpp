// 5_2_Template.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <iostream>
#include <windows.h>
#include "Table.h"


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int row = 6;
    int cols = 10;
    auto table = Table<int>(row, cols);

    std::cout << "Table_size = " << table.get_size();
    std::cout << std::endl;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < cols; j++) {
            table[i][j] = (i + 1) * (j + 1);
            std::cout << table[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}