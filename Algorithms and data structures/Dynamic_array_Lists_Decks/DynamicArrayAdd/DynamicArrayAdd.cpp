// DynamicArrayAdd.cpp : Добавление в изменяемый динамический массив

#include <iostream>
#include <Windows.h>
#include "Append_to_dynamic_array.h"
#include "print_dynamic_array.h"


int main(int argc, char** argv)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int actual_size = 0;//фактический размер
    int logical_size = 0;//логический размер

    do
    {
        std::cout << "Введите фактичеcкий размер массива: ";
        std::cin >> actual_size; /*std::cout << '\n';*/

        std::cout << "Введите логический размер массива: ";
        std::cin >> logical_size; std::cout << '\n';

        if (logical_size > actual_size)
        {
            std::cout << "Логический размер массива не может превышать его фактический размер!\n";
            std::cout << '\n';
        }

    } while (logical_size > actual_size);

    int* arr = new int[actual_size]();
    for (size_t i = 0; i < logical_size; i++)
    {
        std::cout << "Введите arr[" << i << "]: ";
        std::cin >> arr[i]; /*std::cout << '\n';*/
    }
    std::cout << '\n';
    std::cout << "Динамический массив : ";
    print_dynamic_array(arr, logical_size, actual_size);
    std::cout << '\n';

    int new_element(0);

    while (true)
    {
        std::cout << "\nВведите элемент для добавления: ";
        std::cin >> new_element;

        if (new_element != 0)
        {
            arr = append_to_dynamic_array(arr, logical_size, actual_size, new_element);
            std::cout << "Динамический массив:";
            print_dynamic_array(arr, logical_size, actual_size);
            std::cout << '\n';
        }
        else break;
    }
    std::cout << "\nСпасибо!Ваш массив: ";
    print_dynamic_array(arr, logical_size, actual_size);
    std::cout << '\n';

    return 0;
}


