// HashTable.cpp: Алгоритм создания хеш-таблицы на C ++

// Ниже приведена пошаговая процедура, которой следует следовать для реализации хэш-таблицы на C ++ с использованием хэш-функции:

/*Инициализация размера таблицы некоторым целочисленным значением.
Создание структуры хэш - таблицы hashTableEntry для объявления пар ключ и значение.
Создание конструктора hashMapTable.
Создание хэш - функцию() и нахождение хэш - значение, которое будет индексом для хранения фактических данных в хэш - таблице, используя формулу :
hash_value = hashFunction(key);
index = hash_value % (table_size)
Соответствующие функции, такие как Insert(), SearchKey() и Remove(), 
используются для вставки элемента по ключу, поиска элемента по ключу
и удаления элемента по ключу соответственно.
Деструктор вызывается для уничтожения всех объектов hashMapTable.*/

#include <iostream>
#include <list>

using namespace std;

class HashMapTable
{
	
	int table_size;// размер хеш-таблицы
	list<int>* table;// Указатель на массив, содержащий ключи

public:
	
	HashMapTable(int key);// создание конструктора вышеуказанного класса, содержащего все методы
	
	int hashFunction(int key)// хэш-функция для вычисления индекса с использованием table_size и ключа
	{
		return (key % table_size);
	}
	
	void insertElement(int key);// вставка ключа в хеш-таблицу
	
	void deleteElement(int key);// удаление ключа в хеш-таблице
	
	void displayHashTable();// отображение полной хеш-таблицы
};

HashMapTable::HashMapTable(int ts)//создание хеш-таблицы с заданным размером таблицы
{
	this->table_size = ts;
	table = new list<int>[table_size];
}

void HashMapTable::insertElement(int key)// вставляем функцию для ввода ключей в хеш-таблицу
{
	int index = hashFunction(key);
	table[index].push_back(key);
}

void HashMapTable::deleteElement(int key)// функция удаления для удаления элемента из хеш-таблицы
{
	int index = hashFunction(key);

	// находим ключ по вычисляемому индексу
	list <int> ::iterator i;

	for (i = table[index].begin(); i != table[index].end(); i++)
	{
		if (*i == key)
			break;
	}
	// удаление ключа из хеш-таблицы, если он найден
	if (i != table[index].end())
		table[index].erase(i);
}
// функция отображения для демонстрации всей хеш-таблицы
void HashMapTable::displayHashTable()
{
	for (int i = 0; i < table_size; i++)
	{
		cout << i;
		// обход по последнему/текущему индексу
		for (auto j : table[i])
			cout << " ==> " << j;
		cout << endl;
	}
}

int main()
{
	
	int arr[] = { 20, 34, 56, 54, 76, 87, 0, 236, 556, 1, 25, 456, 55 };// массив всех ключей для вставки в хеш-таблицу]
	int n = sizeof(arr) / sizeof(arr[0]);
	
	HashMapTable ht(13);// table_size хэш-таблицы как 13

	for (int i = 0; i < n; i++)
		ht.insertElement(arr[i]);
	
	ht.deleteElement(34);// удаление элемента 34 из хеш-таблицы

	ht.displayHashTable();// вывод окончательных данных хеш-таблицы
	return 0;
}