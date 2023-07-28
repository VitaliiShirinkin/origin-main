// Dfs.cpp : Обход графа в глубину
//

#include <iostream>
#include <Windows.h>
#include <fstream>

int** vertex_array(int N)//для хранения матрицы смежности, N= количество вершин
{
    int** array = new int* [N];
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
    std::cout << "Матрица смежности: "<< '\n';
    for (size_t i = 0; i < N; i++)//номер строки
    {
        for (size_t j = 0; j < N; j++)//номер элемента в строке
        std::cout << array[i][j] << " ";
        std::cout << '\n';
    }

}

void dfs(int** graph, bool*visited_verteces, int connection_between_vertices, int vertex_start)
{
    std::cout << vertex_start + 1<< " ";
    visited_verteces[vertex_start] = true;
    for (size_t i = 0; i < connection_between_vertices; i++)
    {
        if((graph[vertex_start][i] != 0) and (!visited_verteces[i]))//пока есть соседи у вершин или вершины не пройдены
            dfs(graph, visited_verteces, connection_between_vertices, i);//бежим по вершинам рекурсивно
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int connection_between_vertices;
    std::ifstream fin("input.txt");

    if (fin.is_open())
    {
        fin >> connection_between_vertices;

        int** graph = vertex_array(connection_between_vertices);
        bool* visited_verteces = new bool[connection_between_vertices];

        while (!fin.eof())
        {
            for (size_t i = 0; i < connection_between_vertices; i++)
            {
                for (size_t j = 0; j < connection_between_vertices; j++)
                {
                    fin >> graph[i][j];
                }
            }

        }
        print_ajecency_matrix(graph, connection_between_vertices);
        for (size_t i = 0; i < connection_between_vertices; i++)
        {
            visited_verteces[i] = false;
        }

        std::cout << '\n' << "Порядок обхода вершин: ";

        dfs(graph, visited_verteces, connection_between_vertices, 0);


        fin.close();
        delete[]visited_verteces;
        deleting_vertex_array(graph, connection_between_vertices);

    }
    else
    {
        std::cout << "Файл не открывается!" << '\n';
    }
    
    return 0;
}
