// Graphs_storage.cpp : Хранение графа в форме списка ребер (множества ребер)
//

#include <iostream>
#include <map>
#include <set>
#include <vector>

typedef int32_t vertex_t;//тип вершин
typedef std::set <vertex_t> SetOfVertex;//множество вершин

class AbstractGraf
{
public:
    int vertexes_number = 0;//кол-во вершин
    int edges_number = 0;//кол-во ребер

    virtual void input() = 0;
    virtual void print() const = 0;
};

class Graf_type1:public AbstractGraf
{
public:

        std::set<std::pair<vertex_t, vertex_t>>set_of_edges;//множество ребер

        void input()//механизм считывания для клавиатуры
        {
            std::cin >> vertexes_number;//вписываем вершины
            std::cin >> edges_number;//вписываем ребра
            set_of_edges.clear();//если граф существует, то очищаем его
            for (vertex_t i = 0; i < edges_number; i++)
            {
                vertex_t a, b;//пара вершин
                std::cin >> a >> b;
                set_of_edges.insert(std::make_pair(a, b));//ребра
            }
        }

        void print() const//вывод на экран множества
        {
            std::cout << "vertexes_number = " << vertexes_number << std::endl;
            for (auto edge: set_of_edges)//бежим по множеству ребер
            {
                std::cout << "(" << edge.first << ", " << edge.second << ") ";
            }
            std::cout << std::endl;
        }
}; 

class Graf_type2 :public AbstractGraf
{
public:

    //Матрица смежности
    std::vector<std::vector<bool>>matrix;//матрица смежности

    void input()//механизм считывания для клавиатуры
    {
        std::cin >> vertexes_number;//вписываем вершины
        //Как только получил кол-во вершин, создаю матрицу нужного размера
        matrix.resize(vertexes_number);
        for (auto &row: matrix)
        {
            row.resize(vertexes_number, false);
        }

        std::cin >> edges_number;//вписываем ребра
        for (vertex_t i = 0; i < edges_number; i++)
        {
            vertex_t a, b;//пара вершин
            std::cin >> a >> b;
            matrix[a][b] = 1;
            matrix[b][a] = 1;
        }
    }
    void print() const//вывод на экран множества
    {
        std::cout << "vertexes_number = " << vertexes_number << std::endl;


        for (vertex_t a = 0; a < vertexes_number; a++)//бежим по множеству ребер
        {
            for (vertex_t b = 0; b < vertexes_number; b++)
            {
                std::cout << matrix[a][b] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
};


int main()
{
    Graf_type1 g1;
    Graf_type2 g2;

    g1.input();
    g2.input();

    g1.print();
    g2.print();
}

