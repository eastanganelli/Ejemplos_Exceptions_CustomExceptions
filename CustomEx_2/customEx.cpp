#include "customEx.h"

const char* DIV_ZERO::what() const throw() {
	return "No puedo dividir por cero 🤬.";
}
