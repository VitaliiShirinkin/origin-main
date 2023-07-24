// PyramidOutArray.cpp : Вывод пирамиды на массиве
//

#include <iostream>
#include <Windows.h>

void print_array (int* array, int size_array)//исходный массив
{
    std::cout << "Исходный массив: ";
    for (size_t i = 0; i < size_array; i++)
    {
        std::cout << " " << array[i];
    }
	std::cout << '\n';
}

int parent_index(int* arr, int size, int i)//Вычисляем индекс родителя
{
	int value = arr[(i - 1) / 2];
	return value;
}

int pyramid_level(int* arr, int i)//уровень элемента в пирамиде
{
	return log2(i + 1);
}

void print_one_element(int* arr, int size, int i)//вывод каждого элемента пирамиды
{
	if (i % 2)//четные
	{
		std::cout << pyramid_level(arr, i) << " left(" << parent_index(arr, size, i) << ") " << arr[i] << std::endl;
	}
	else if (i == 0)//родитель(корень)
	{
		std::cout << pyramid_level(arr, i) << " root " << arr[i] << std::endl;
	}
	else//нечетные
	{
		std::cout << pyramid_level(arr, i) << " right(" << parent_index(arr, size, i) << ") " << arr[i] << std::endl;
	}
}

void print_pyramid(int* arr, int size)//Вывод пирамиды в консоль
{
	std::cout << "Пирамида:" << std::endl;

	for (int i = 0; i < size; ++i)
	{
		print_one_element(arr, size, i);
	}
}

int main(int argc, char** argv) {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int arr1[] = { 1, 3, 6, 5, 9, 8 };
    int arr2[] = { 94, 67, 18, 44, 55, 12, 6, 42 };
    int arr3[] = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int size3 = sizeof(arr3) / sizeof(arr3[0]);

    print_array(arr1, size1);
    print_pyramid(arr1, size1);

    print_array(arr2, size2);
    print_pyramid(arr2, size2);

    print_array(arr3, size3);
    print_pyramid(arr3, size3);

    return 0;
}

