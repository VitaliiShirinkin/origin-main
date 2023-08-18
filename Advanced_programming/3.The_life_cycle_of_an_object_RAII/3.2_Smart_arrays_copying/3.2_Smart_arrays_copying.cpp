// 3.2_Smart_arrays_copying.cpp : программа по теме "Жизненный цикл объекта. RAII"
//Задача 2. Копирование умных массивов

#include <iostream>
#include "Exception.h"
#include <string>
#include <Windows.h>

class smart_array
{
	int* A;
	int size;
	int i = 0;

public:

	smart_array (int size_)
	{
		size = size_;
		A = new int [size] {};
	}


	~smart_array()
	{
		delete[]A;
	};

	void add_element(int num)
	{
		if (i < size)
		{
			A[i] = num;
			i++;
		}
		else
		{
			throw ArrException("Добавление элемента невозможно: превышен размер массива \n");
		}
	};
		int get_element(int n)
		{
			if ((n>=0) and (n<size))
			{
				return A[n];
			}
			else
			{
				throw ArrException("Отсутствует элемент" + std::to_string(n));
			}
		}
		smart_array& operator=(const smart_array& right)
		{
			if (this!= &right)
			{
				delete[] A;
				size = right.size;
				i = right.i;
				A = new int [size] {};
				for (size_t j = 0; j < size; j++)
				{
					A[j] = right.A[j];
				}
			}
			return *this;
		
		}
		smart_array(const smart_array& right)
		{
			size = right.size;
			i = right.i;
			A = new int [size] {};
			for (size_t j = 0; j < size; j++)
			{
				A[j] = right.A[j];
			}
		}
	
};



int main()
{
	setlocale(LC_ALL, "Russian");
	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(1);
		arr.add_element(5);
		arr.add_element(1);
		arr.add_element(1);
		smart_array new_array(3);
		new_array.add_element(10);
		new_array.add_element(20);
		new_array.add_element(30);

		arr = new_array;
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	return 0;
}

