#pragma once

class Counter
{
public:
	Counter(int initial_init_value);
	int getCounter();
	int plus_one();
	int minus_one();

private:
	int internal_val = 0;
};
