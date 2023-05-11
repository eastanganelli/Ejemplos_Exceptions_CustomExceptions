#pragma once
#include <string>
#include <exception>
using namespace std;


class DIV_ZERO : public exception {
	const char* what() const throw();
};

