#include "plato.h"

unsigned int plato::cantidadPlatos = 0;

plato::plato() {
	this->nombre = "Platito";
	this->precio = 0.00f;
	this->gluten_free = this->kosher = this->dulce = false;
}

plato::plato(std::string nombre, float precio, bool dulce, bool kosher, bool gluten_free) {
	this->nombre = nombre;
	this->precio = precio;
	this->gluten_free = gluten_free;
	this->kosher = kosher;
	this->dulce = dulce;
	
	plato::cantidadPlatos++;
}

plato::~plato() {
	plato::cantidadPlatos--;
}

std::string plato::to_string() {
	std::stringstream ss;
	ss << this->nombre   << " $" << this->precio			   << std::endl
	   << "Gluten Free: " << (this->gluten_free ? "Si" : "No") << std::endl
	   << "Dulce: "       << (this->dulce ? "Si"  : "No")      << std::endl
	   << "Kosher: "      << (this->kosher ? "Si" : "No")      << std::endl;
	return ss.str();
}

unsigned int plato::get_cantPlatos() {
	return plato::cantidadPlatos;
}

std::ostream& operator<<(std::ostream& out, const plato& data) {
	out << data.nombre << " $" << data.precio					   << std::endl
		<< "Gluten Free: "     << (data.gluten_free ? "Si" : "No") << std::endl
		<< "Dulce: "           << (data.dulce ? "Si" : "No")       << std::endl
		<< "Kosher: "          << (data.kosher ? "Si" : "No")      << std::endl;
	return out;
}
