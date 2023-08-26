// 6_1.cpp : Использование шаблонов функций при создании шаблонов классов

#include <iostream>
#include <locale.h>
#include <conio.h>
#include <string.h>
#include <Windows.h>

template <class T> T maxx (T x, T y)
{
    return (x > y) ? x : y;
}

char* maxx(char* x, char* y)//функция для строк
{
    return strcmp(x, y) > 0 ? x : y;
}

int main()
{
    setlocale(0, "rassian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int a = 1, b = 2;
    char c = 'a', d = 'm';
    float e = 123.12, f = 452.15;
    char str1[] = "Виктор"; char str2[] = "Виталий";

    //вызов функции для объектов различного типа
    std::cout << "integer maxx = " << maxx(a, b) << '\n';
    std::cout << "character maxx = " << maxx(c, d) << '\n';
    std::cout << "float maxx = " << maxx(e, f) << '\n';
    std::cout << "string maxx = " << maxx(str1, str2) << '\n';
}
