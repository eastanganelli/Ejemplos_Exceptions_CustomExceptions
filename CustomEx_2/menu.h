#pragma once
#include <list>
#include <string>
#include <iterator>
#include "plato.h"

class menu : public std::list<plato> {
public:
	plato* operator[](std::string PlatoInteres);
};