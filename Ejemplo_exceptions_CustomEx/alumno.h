#pragma once
#include <iostream>
#include <string>
#include <sstream>

#include "customEx.h"

#define u_int unsigned int

class alumno {
	static u_int cant_alumnos;
	const std::string nombre, apellido, dni, legajo, f_nac;
public:
	alumno(std::string nombre, std::string apellido, std::string dni, std::string f_nac, std::string codefacultad);
	~alumno();

	std::string to_string();
	friend std::ofstream& operator<<(std::ofstream& out, const alumno& data);

	static alumno* crearAlumno(std::string nombre, std::string apellido, std::string dni, std::string f_nac, std::string codefacultad);
};