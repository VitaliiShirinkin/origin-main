// Код C++ для печати обхода BFS из заданной исходной вершины 

#include <vector>
#include <list>
#include <iostream>
#include <Windows.h>
using namespace std;

// Этот класс представляет ориентированный граф, используя 
// представление списка смежности
class Graph {

	// Количество вершин 
	int V;

	// Указатель на массив, содержащий списки смежности 
	vector<list<int> > adj;

public:
	// Constructor
	Graph(int V);

	// Функция добавления ребра к графу 
	void addEdge(int v, int w);

	// Выводит обход BFS из заданного источника s 
	void BFS(int s);
};

Graph::Graph(int V)
{
	this->V = V;
	adj.resize(V);
}

void Graph::addEdge(int v, int w)
{
	// Добавим w в список v. 
	adj[v].push_back(w);
}

void Graph::BFS(int s)
{
	// Отметим все вершины, как не посещенные 
	vector<bool> visited;
	visited.resize(V, false);

	// Создим очередь для BFS 
	list<int> queue;

	// Пометим текущий узел как посещенный и поставим его в очередь 
	visited[s] = true;
	queue.push_back(s);

	while (!queue.empty()) {

		// Удалим вершину из очереди и распечатаем ее 
		s = queue.front();
		cout << s << " ";
		queue.pop_front();

		/*Получим все соседние вершины, удаленной из очереди, вершины s.
			Если соседний узел не был посещен,
			то отметьм его посещенным и поставим в очередь*/
		for (auto adjacent : adj[s]) {
			if (!visited[adjacent]) {
				visited[adjacent] = true;
				queue.push_back(adjacent);
			}
		}
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// Создим график, указанный на приведенной выше диаграмме.
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);



	cout << "Ниже приведен первый обход в ширину "
		<< "(начиная с вершины 2) \n";
	g.BFS(2);

	return 0;
}
