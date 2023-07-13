// Quick_sort.cpp : Быстрая сортировка

#include <iostream>
#include <Windows.h>

void quick_sort(int* array, int size)
{
    int i = 0;
    int j = size - 1;

    int pivot = array[size / 2];

    while (i <= j)
    {
        while (array[i] < pivot) { i++; }
        while (array[j] > pivot) { j--; }
        if (i <= j)
        {
            int tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
            i++;
            j--;
        }
    }
    if (j > 0) { quick_sort(array, j + 1); }
    if (i < size) { quick_sort(&array[i], size - i); }
}

void print_sort(int* array, int size)
{
    std::cout << "Исходный массив:";
    for (int i = 0; i < size; ++i) {
        std::cout << " " << array[i];
    }
    std::cout << '\n';

    quick_sort(array, size);

    std::cout << "Отсортированный массив:";
    for (int i = 0; i < size; ++i) {
        std::cout << " " << array[i];
    }
    std::cout << '\n' << '\n';
}
int main(int argc, char** argv)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int array1[] = { 3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };
    int array2[] = { 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74 };
    int array3[] = { 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };

    int size1 = sizeof(array1) / sizeof(array1[0]);
    print_sort(array1, size1);

    int size2 = sizeof(array2) / sizeof(array2[0]);
    print_sort(array2, size2);

    int size3 = sizeof(array3) / sizeof(array3[0]);
    print_sort(array3, size3);

    return 0;
}

