// 5_1_Template.cpp : Шаблоны функций, классов, специализация

#include <iostream>
#include <windows.h>
#include "Table.h"


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int row_ = 6;
    int cols_ = 10;
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



