//Leaver.h

#pragma once
#include <iostream>

#ifdef TASK2DYNAMICLIBRARY_EXPORTS
#define TASK2DYNAMICLIBRARY_API __declspec(dllexport)
#else
#define TASK2DYNAMICLIBRARY_API __declspec(dllimport)
#endif // !TASK2DYNAMICLIBRARY_EXPORTS


namespace Farewell {

	class Leaver {

	protected:
		std::string name_;
	public:
		TASK2DYNAMICLIBRARY_API void setName(std::string name);
		TASK2DYNAMICLIBRARY_API std::string getName();
		TASK2DYNAMICLIBRARY_API void leave(std::string name);
	};
}


