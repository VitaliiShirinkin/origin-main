// Finding_сonnectivity_сomponents.cpp : Поиск компонентов связности


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

bool dfs(int** graph, int* cids, int V, int vertex_start, int cid)//V-количество вершин
{
    cids[vertex_start] = cid;

    for (size_t i = 0; i < V; i++)
    {
        if ((graph[vertex_start][i] != 0))// пока есть соседи у вершин или вершины не пройдены
        {
            if (cids[i] == 0)
            {
                (dfs(graph, cids, V, i, cid));//бежим по вершинам рекурсивно
            }
        }

    }
    return false;
}

void Finding_сonnectivity_сomponents(int** graph, int* cids, int V, int vertex_start)
{
    int cid = 0;

    for (vertex_start = 0; vertex_start <= V; vertex_start++)
    {
        if (cids[vertex_start] == 0)
        {
            cid += 1;
            dfs(graph, cids, V, vertex_start, cid);
        }
        std::cout << vertex_start << " - " << cid << '\n';
    }
    std::cout << "Количество компонентов связности в графе: " << cid << '\n';
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int V, cid;
    std::ifstream fin("input2.txt");

    if (fin.is_open())
    {
        fin >> V;

        int** graph = vertex_array(V);
        bool* visited_verteces = new bool[V]();
        int* cids = new int[V]();

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
        Finding_сonnectivity_сomponents(graph, cids, V, 0);

        fin.close();
        delete[]cids;
        delete[]visited_verteces;
        deleting_vertex_array(graph, V);

    }
    else
    {
        std::cout << "Файл не открывается!" << '\n';
    }

    return 0;
}
