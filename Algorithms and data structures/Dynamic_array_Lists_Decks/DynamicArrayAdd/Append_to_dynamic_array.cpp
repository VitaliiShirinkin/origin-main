#include "Append_to_dynamic_array.h"
#include <iostream>

int* append_to_dynamic_array(int* arr, int& logical_size, int& actual_size, int& new_element)
{
	if (actual_size == logical_size)//Если логический размер массива равен его фактическому размеру
	{
		actual_size *= 2;//увеличивается в два раза
		logical_size += 1;//увеличивается на единицу

		int* temp_arr = new int[actual_size]();//создаётся новый массив размером в 2 раза больше

		int last_element = 1;
		//В него перекладываются элементы из старого массива 
		for (size_t i = 0; i < logical_size; i++)
		{
			if (last_element < logical_size)
			{
				temp_arr[i] = arr[i];
					last_element++;
			}
			else
			{
				temp_arr[i] = new_element;//вместе с новым элементом в конце.
			}

		}

		delete[] arr;//старый массив уничтожается. 
		return temp_arr;//Далее программа должна работать уже с новым массивом
	}
	else//если логический размер массива меньше фактического
	{
		logical_size += 1;//увеличиваете его логический размер на 1.
		arr [logical_size - 1] = new_element;//и добавляете новый элемент в запас вашего массива
		return arr;
	}
}
