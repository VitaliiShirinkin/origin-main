// 6_2_template_class.cpp : Использование шаблона для формирования массивов и вывода их элементов.

#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <time.h>
#include <Windows.h>

template <class type> //объявление шаблона с аргументом type
class array
{
    type* contens;//указатель на динамический массив типа type
    int size;     //размер массива
public:
        array(int number)
    {
        contens = new type[size = number];
    }
    ~array() { delete[] contens; }

    type & operator[] (int x)    //переопределие операции []
    {
        if((x<0) || (x>=size))
        {
            cerr << "Ошибочный индекс"; x = 0;
            return contens x;
        }
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int i;
    srand((unsigned)time(NULL));
    array<int>int_a(5);//массив элементов целого типа
    array<char> char_a(5);//массив элементов типа char

    for (i = 0; i < 5; i++)//определение компонент массивов
    {
        int_a[i] = rand() / 1000 + 10; char_a[i] = 'A' + i;
    }
    puts("Компоненты массивов");
    for ( i = 0; i < 5; i++)
    {
        std::cout << "  " << int_a[i] << " " << char_a[i] << '\n';
    }
}
