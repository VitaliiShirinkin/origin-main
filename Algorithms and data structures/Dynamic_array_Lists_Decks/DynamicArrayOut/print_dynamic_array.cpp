#include "print_dynamic_array.h"
#include <iostream>

void print_dynamic_array(int* arr, int& logical_size, int& actual_size)
{
	std::cout << "Динамический массив : ";

	for (size_t i = 0; i < logical_size; i++)
	{
		std::cout << arr[i] << " ";
	}
	for (size_t i = logical_size; i < actual_size; i++)
	{
		std::cout << "_ ";
	}

}