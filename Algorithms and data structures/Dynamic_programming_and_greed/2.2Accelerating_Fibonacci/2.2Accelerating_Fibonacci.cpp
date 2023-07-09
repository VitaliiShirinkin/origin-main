// 2.2Accelerating_Fibonacci.cpp : 
//Программа применения динамического программирования к рекурсии.

//Сложность алгоритма по скорости О(n). Сложность по памяти О(n).


#include <iostream>

int fibo (int n){
const int MAXN = 1000;
  static int c [MAXN];
  if (n == 0) return 0;
  if (n == 1) return 1;
  if (c[n]>0) return c[n];
  return c[n] = fibo (n-1) + fibo(n-2);
}

int main() {
  for(int n=0; n <= 15; n++){
  std::cout << n << '\t'<< fibo(n)<<"\n";
  }
  return 0;
}
