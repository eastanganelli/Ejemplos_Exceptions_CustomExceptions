#include "cochera.h"

cochera::cochera() : ID(cochera::contador) {
	this->occupy = false;
	cochera::contador++;
}

cochera::cochera(bool o_) : ID(cochera::contador) {
	this->occupy = o_;
	cochera::contador++;
}

cochera::~cochera() {
	cochera::contador--;
}

u_int cochera::get_ID() {
	return this->ID;
}

bool cochera::estaOcupado() {
	return this->occupy;
}

void cochera::cambiarEstado() {
	this->occupy = !(this->occupy);
}

bool cochera::operator==(const cochera& c_) {
	return ( (this->ID == c_.ID) );
}
