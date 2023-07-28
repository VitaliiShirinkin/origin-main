// Dfs.cpp : Обход графа в глубину
//

#include <iostream>
#include <Windows.h>
#include <fstream>

int** vertex_array(int N)//для хранения матрицы смежности, N= количество индексов
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

//void print_ajecency_matrix(int** array, int N)//распечатка массива матрицы смежности
//{
//    std::cout << "Матрица смежности: " << '\n';
//    for (size_t i = 0; i < N; i++)//номер строки
//    {
//        for (size_t j = 0; j < N; j++)//номер элемента в строке
//            std::cout << array[i][j] << " ";
//        std::cout << '\n';
//    }
//
//}

void bfs(int** graph, bool* visited_verteces, int V, int vertex_start)
{
    int* queue = new int[V]();//очередь посещения соседних вершин для выбранной, V - количество вершин
    int count = 0;
    int head = 0;
    queue[count++] = vertex_start;
    visited_verteces[vertex_start] = true;

    while (head < count)
    {
        vertex_start = queue[head++];
        std::cout << vertex_start + 1 << " ";

        for (size_t i = 0; i < V; i++)
        
            if (graph[vertex_start][i] and !visited_verteces[i])//пока есть соседи у вершин или вершины не пройдены
            {
                queue[count++] = i;
                visited_verteces[i] = true;
            }
    }
    delete[] queue;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int V; //- количество вершин
    int vertex_start; //- стартовая вершина

    std::ifstream fin("input.txt");

    if (fin.is_open())
    {
        fin >> V;

        int** graph = vertex_array(V);
        bool* visited_verteces = new bool[V];

        while (true)
        {
            std::cout << "В графе " << V << " вершин. Введите номер стартовой вершины: ";
            std::cin >> vertex_start;
            if ((vertex_start <= 0) or (vertex_start > V))
            {
                std::cout << "Вершины с таким номером в графе нет." << '\n';
                continue;
            }
            else break;

        }

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
        //print_ajecency_matrix(graph, V);
        for (size_t i = 0; i < V; i++)
        {
            visited_verteces[i] = false;
        }

        std::cout << '\n' << "Порядок обхода вершин: " << '\n';

        bfs(graph, visited_verteces, V, vertex_start - 1);


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
