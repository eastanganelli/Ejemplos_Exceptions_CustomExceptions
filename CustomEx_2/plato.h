#pragma once
#include <string>
#include <sstream>
#include <iostream>

class plato {
	static unsigned int cantidadPlatos;
	float precio;
	bool dulce, kosher, gluten_free;
	std::string nombre;
public:
	plato();
	plato(std::string nombre, float precio, bool dulce, bool kosher, bool gluten_free);
	~plato();
	
	std::string to_string();
	friend std::ostream& operator<<(std::ostream& out, const plato& data);
	
	std::string get_nombre() {
		return this->nombre;
	}

	static unsigned int get_cantPlatos();
};