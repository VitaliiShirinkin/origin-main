//файл Greeter.cpp

#include "Greeter.h"
#include <iostream>

namespace Greeting {

	void Greeter::setName(std::string name) {

		name_ = name;
	}
	std::string Greeter::getName() {

		return name_;
	}

	void Greeter::Greet(std::string name) {


		setName(name);
		std::cout << "Здравствуйте, " << getName() << "!\n";

	}
}