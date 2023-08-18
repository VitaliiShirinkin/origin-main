// 3.1_Smart_array.cpp : программа по теме "Жизненный цикл объекта. RAII"
//

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
	smart_array(const smart_array&) = delete;
	smart_array& operator = (const smart_array&) = delete;
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
	
};



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);
		std::cout << arr.get_element(1) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
	return 0;
}

