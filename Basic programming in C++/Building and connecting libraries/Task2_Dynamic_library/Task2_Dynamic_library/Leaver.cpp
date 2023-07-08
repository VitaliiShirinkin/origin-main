//Leaver.cpp

#include "Leaver.h"
#include <iostream>

namespace Farewell {

	void Leaver::setName(std::string name) {

		name_ = name;
	}

	std::string Leaver::getName() {

		return name_;
	}

	void Leaver::leave(std::string name) {

		setName(name);
		std::cout << "До свидания, " << getName() << "!\n";
	}
}