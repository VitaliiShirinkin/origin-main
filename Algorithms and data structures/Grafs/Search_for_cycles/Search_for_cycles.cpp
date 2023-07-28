// Search_for_cycles.cpp : Поиск циклов

#include <iostream>
#include <Windows.h>
#include <fstream>

int** vertex_array(int N)//для хранения матрицы смежности, N= количество элементов
{
    int** array = new int* [N]();
    for (size_t i = 0; i < N; i++)
    {
        array[i] = new int[N]();
    }
    return array;
}

void deleting_vertex_array(int** array, int N)//удаляем массив матрицы смежности
{
    for (size_t i = 0; i < N; i++)
    {
        delete[] array[i];
    }
    delete[]array;
}

void print_ajecency_matrix(int** array, int N)//распечатка массива матрицы смежности
{
    std::cout << "Матрица смежности: " << '\n';
    for (size_t i = 0; i < N; i++)//номер строки
    {
        for (size_t j = 0; j < N; j++)//номер элемента в строке
            std::cout << array[i][j] << " ";
        std::cout << '\n';
    }

}

bool dfs(int** graph, bool* visited_verteces, int V, int vertex_start, int parent)//V-количество вершин
{
    visited_verteces[vertex_start] = true;

    for (size_t i = 0; i < V; i++)
    {
        if ((graph[vertex_start][i] != 0))// пока есть соседи у вершин или вершины не пройдены
        {
            if (visited_verteces[i] == 0)
            {
                if (dfs(graph, visited_verteces, V, i, vertex_start)) return true;//бежим по вершинам рекурсивно
            }
            else if (i != parent) return true;
        } 
            
    }
    return false;
}

void is_cyclyc (int** graph, bool* visited_verteces, int V, int vertex_start, int parent)
{
    if (dfs(graph, visited_verteces, V, 0, -1))
    {
        std::cout << "В графе есть цикл!" << '\n';
    }
    else
    {
        std::cout << "В графе нет циклов." << '\n';
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int V;
    std::ifstream fin("input2.txt");

    if (fin.is_open())
    {
        fin >> V;

        int** graph = vertex_array(V);
        bool* visited_verteces = new bool[V]();

        while (!fin.eof())
        {
            for (size_t i = 0; i < V; i++)
            {
                for (size_t j = 0; j < V; j++)
                {
                    fin >> graph[i][j];
                }
            }

        }
        print_ajecency_matrix(graph, V);
        std::cout << '\n';
        is_cyclyc(graph, visited_verteces, V, 0, -1);

        fin.close();
        delete[]visited_verteces;
        deleting_vertex_array(graph, V);

    }
    else
    {
        std::cout << "Файл не открывается!" << '\n';
    }

    return 0;
}
