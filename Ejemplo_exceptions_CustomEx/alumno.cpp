#include "alumno.h"

alumno::alumno(std::string nombre, std::string apellido, std::string dni, std::string f_nac, std::string codefacultad) : nombre(nombre), apellido(apellido), dni(dni), legajo(codefacultad + "-" + dni), f_nac(f_nac) {
	alumno::cant_alumnos++;
}

alumno::~alumno() {
	alumno::cant_alumnos--;
}

std::string alumno::to_string() {
	std::stringstream ss;
	ss << this->nombre << " " << this->apellido << " " << this->dni << " " << this->f_nac
		<< this->legajo << std::endl;

	return ss.str();
}

alumno* alumno::crearAlumno(std::string nombre, std::string apellido, std::string dni, std::string f_nac, std::string codefacultad) {
	if(nombre == "" || apellido == "" || dni == "" || f_nac == "" || codefacultad == "")
		throw EMPTY_STR<std::string>();
	
	return new alumno(nombre, apellido, dni, f_nac, codefacultad);
}

std::ofstream& operator<<(std::ofstream& out, const alumno& data) {
	out << data;
	return out;
}