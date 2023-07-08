#include "Counter.h"
//#include "Task 2. Class.cpp"

Counter::Counter(int initial_init_value) { internal_val = initial_init_value; }

int Counter::getCounter() { return internal_val; }

int Counter::plus_one(){ return ++internal_val; }

int Counter::minus_one(){ return --internal_val; }

