#pragma once
#include <stdexcept>

class Exception : public std::domain_error
{
public:
	using std::domain_error::domain_error;
};