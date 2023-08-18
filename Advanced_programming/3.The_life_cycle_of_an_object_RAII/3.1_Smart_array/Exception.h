#pragma once

#include <iostream>

class ArrException : std::domain_error{

public:
	ArrException (const std::string& message);

};
