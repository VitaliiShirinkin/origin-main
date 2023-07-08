#pragma once
#include <string>

class Figure {
protected:
	std::string name;

public:
	std::string get_name();
	virtual void metod();
};

