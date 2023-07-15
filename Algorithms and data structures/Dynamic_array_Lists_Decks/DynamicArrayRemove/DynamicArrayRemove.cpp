// DynamicArrayRemove.cpp : Удаление первого элемента из изменяемого динамического массива
//

#include <iostream>
#include <Windows.h>
#include "remove_dynamic_array_head.h"
#include "print_dynamic_array.h"


int main(int argc, char** argv)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int actual_size (0);//фактический размер
    int logical_size (0);//логический размер

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

    std::string answer;

    while (true)
    {
        std::cout << "\nУдалить первый элемент? ";
        std::cin >> answer;
        if (logical_size == 0) {
            std::cout << "Невозможно удалить первый элемент, так как массив пустой.До свидания!" << std::endl;
            return 0;
        }

        if (answer == "да")
        {
            arr = remove_dynamic_array_head(arr, logical_size, actual_size);
            std::cout << "Динамический массив:";
            print_dynamic_array(arr, logical_size, actual_size);
            std::cout << '\n';
        }
        else if (answer == "нет")
        {
            std::cout << "\nСпасибо!Ваш динамический массив: ";
            print_dynamic_array(arr, logical_size, actual_size);
            break;
        }
        else {
            std::cout << "Не верный ответ! Выберите да/нет." << std::endl;
            continue;
        }
    }

    delete[] arr;
    arr = nullptr;
    return 0;
}
