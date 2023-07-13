// 2.2Accelerating_Fibonacci.cpp : 
//Программа применения динамического программирования к рекурсии.

//Сложность алгоритма по скорости О(n). Сложность по памяти О(n).


#include <iostream>
#include <Windows.h>


int fibo (int n){
const int MAXN = 1000;
  static int c [MAXN];//создаём ст. массив и инициализирующий его нулями
  if (n == 0) return 0;
  if (n == 1) return 1;
  if (c[n]>0) return c[n];//завершаем бесконечный цикл рекурсии
  return c[n] = fibo (n-1) + fibo(n-2);
}

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

  for(int n=0; n <= 15; n++){
  std::cout << n << '\t'<< fibo(n)<<"\n";
  }
  return 0;
}
