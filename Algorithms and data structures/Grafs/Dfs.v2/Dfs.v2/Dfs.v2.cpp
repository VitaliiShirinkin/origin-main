// Dfs.v2.cpp : Проход графа в глубину на основе класса Graph
//

#include <iostream>
#include <fstream>
#include <Windows.h>

class Graph
{
private:
	int verteсes;
	int** adjacency_matrix;
	bool* used;

private:
	void matrix_filling(std::ifstream& in, int** adjacency_matrix)//заполнение матрицы смежности из файла In

	{
		while (!in.eof())
		{
			for (int i = 0; i < verteсes; i++)
			{
				for (int j = 0; j < verteсes; j++)
				{
					int value;
					in >> value;
					adjacency_matrix[i][j] = value;//и запись этих данных в массив
				}
			}
			in.close();//закрытие файла
		}
	}

public:
	Graph()
	{
		std::ifstream in("in.txt");
		in >> verteсes;

		used = new bool[verteсes]();//массив для пройденных вершин

		adjacency_matrix = new int* [verteсes];//для матрицы смежности
		for (int i = 0; i < verteсes; i++)
		{
			adjacency_matrix[i] = new int[verteсes];
		}

		matrix_filling(in, adjacency_matrix);

		
	}
	//Освобождение занятой памяти
	template <typename T>
	void deleter(T array) {
		delete[] array;
		array = nullptr;
	}

	~Graph() {
		for (int i = 0; i < verteсes; ++i) {
			delete[] adjacency_matrix[i];
		}

		deleter(adjacency_matrix);
		deleter(used);
	}

	void Print()//вывод данных из массива матрицы смежности в консоль
	{
		std::cout << "Матрица смежности: " << '\n' << '\n';

		for (int i = 0; i < verteсes; i++)
		{
			for (int j = 0; j < verteсes; j++)
			
				std::cout << adjacency_matrix[i][j] << " ";
				std::cout << '\n';
			
		}
		std::cout << '\n';
	}

	void dfs(int vertex)//обход графа в глубину
	{
		used[vertex] = true;
		std::cout << vertex + 1 << " ";
		for (int i = vertex; i < verteсes; i++)
		{
			for (int j = 0; j < verteсes; j++)
			{
				if (adjacency_matrix[i][j] == 1)
				{
					if (!used[j])
					{
						dfs(j);
					}
				}
			}
		}
	}


};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::ifstream fin("in.txt");

	if (!fin.is_open()) {
		std::cout << "Файл in поврежден!" << std::endl;
		return 1;
	}

	int verteсes;
	Graph* graph = new Graph();
	graph->Print();

	std::cout << "Порядок обхода вершин: ";
	graph->dfs(3);
	std::cout << '\n';
	delete graph;
}