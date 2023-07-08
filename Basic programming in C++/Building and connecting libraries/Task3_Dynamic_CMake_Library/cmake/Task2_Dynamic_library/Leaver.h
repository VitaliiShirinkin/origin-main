//Leaver.h

#pragma once
#include <iostream>

//#ifdef TASK2DYNAMICLIBRARY_EXPORTS
//#define TASK2DYNAMICLIBRARY_API __declspec(dllexport)
//#else
//#define TASK2DYNAMICLIBRARY_API __declspec(dllimport)
//#endif // !TASK2DYNAMICLIBRARY_EXPORTS


namespace Farewell {

	class Leaver {

	protected:
		std::string name_;
	public:
		 void setName(std::string name);
		 std::string getName();
		 void leave(std::string name);
	};
}


