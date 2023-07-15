#include "Append_to_dynamic_array.h"
#include <iostream>

int* append_to_dynamic_array(int* arr, int& logical_size, int& actual_size, int& new_element)
{
	if (actual_size == logical_size)//���� ���������� ������ ������� ����� ��� ������������ �������
	{
		actual_size *= 2;//������������� � ��� ����
		logical_size += 1;//������������� �� �������

		int* temp_arr = new int[actual_size]();//�������� ����� ������ �������� � 2 ���� ������

		int last_element = 1;
		//� ���� ��������������� �������� �� ������� ������� 
		for (size_t i = 0; i < logical_size; i++)
		{
			if (last_element < logical_size)
			{
				temp_arr[i] = arr[i];
					last_element++;
			}
			else
			{
				temp_arr[i] = new_element;//������ � ����� ��������� � �����.
			}

		}

		delete[] arr;//������ ������ ������������. 
		return temp_arr;//����� ��������� ������ �������� ��� � ����� ��������
	}
	else//���� ���������� ������ ������� ������ ������������
	{
		logical_size += 1;//������������ ��� ���������� ������ �� 1.
		arr [logical_size - 1] = new_element;//� ���������� ����� ������� � ����� ������ �������
		return arr;
	}
}
