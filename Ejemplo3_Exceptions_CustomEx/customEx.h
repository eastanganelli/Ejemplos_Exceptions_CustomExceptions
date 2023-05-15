#pragma once
#include <exception>

using namespace std;

class cocheraEx : public exception {
	const char* what() const throw();
};