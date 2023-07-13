// 3.1_Merge_sorting.cpp : Сортировка слиянием
//разделение массива на подмассивы и сортировка подмассивов
//использован способ слияния уже отсортированных массивов. Декомпозицией делим массив на несколько

#include <iostream>
#include <Windows.h>

void merge_sort(int* array, int16_t array_size) {

    //Отслеживаем крайний случай и выходим из рекурсии!
    if (array_size <= 1) return; 

    //деление массива пополам с отбрасываем остатка
    int16_t middle = array_size / 2; 
    int* left = array;//левая часть массива
    int* right = array + middle;//правая часть массива, смещенная на middle

    //Адресная арифметика : указатель + число дает начало смещенному массиву
    int16_t left_size = middle;
    int16_t right_size = array_size - left_size;

    //рекурсия выполняется здесь ("разделяй и влавствуй"):
    merge_sort(left, left_size);//сортировка от начала до середины
    merge_sort(right, right_size);//сортировка с середины

    //Объединение двух уже отсортированных частей массива:
    //выделяем память, внутри которой будет слияние
    int *buffer = new int[array_size];
    int16_t left_i = 0;//левый текущий индекс
    int16_t right_i = 0;//правый текущий индекс
    int16_t buffer_i = 0;

    //пока не закончилась одна из половинок 
    while (left_i < left_size and right_i < right_size)
    {
        if (left[left_i] <= right[right_i])
        {
            // берем меньшее значение из левой части массива (для устойчивости сортировки):
            buffer[buffer_i] = left[left_i];
            left_i++; //и делаем сдвиг!
            buffer_i++;
        }
        else {
            //берем меньшее значение из правой части массива:
            buffer[buffer_i] = right[right_i];
            right_i++;
            buffer_i++;
        }
    }
    //а когда одна из половин закончилась
    while (left_i < left_size)//копирование элементов с левой ч/массива (если что-то осталось)
    {
        buffer[buffer_i] = left[left_i];
        left_i += 1;
        buffer_i += 1;
    }
    while (right_i < right_size)//копирование оставшихся элементов
    {
        buffer[buffer_i] = right[right_i];
        right_i++;
        buffer_i++;
    }
     //копируем из буфера в оригинальный массив:
    for (int16_t i = 0; i < array_size; i++)
    {
        array[i] = buffer[i];
    }

    delete[] buffer;
}

//распечатка массива
void print_array(int* array, int16_t array_size) {

    std::cout << "Исходный массив: ";
    for (size_t i = 0; i < array_size; i++)
    {
        std::cout << array[i] << ' ';
    }
    std::cout << '\n';

    merge_sort(array, array_size);

    std::cout << "Отсортированный массив: ";
    for (size_t i = 0; i < array_size; i++)
    {
        std::cout << array[i] << ' ';
    }
    std::cout << '\n';
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int array1[]{ 3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };
    int array2[]{ 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74 };
    int array3[]{ 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };

    int array_size1 = sizeof(array1) / sizeof(array1[0]);
    print_array(array1, array_size1);     std::cout << std::endl;

    int array_size2 = sizeof(array2) / sizeof(array2[0]);
    print_array(array2, array_size2);     std::cout << std::endl;

    int array_size3 = sizeof(array3) / sizeof(array3[0]);
    print_array(array3, array_size3);

    return 0;
}
