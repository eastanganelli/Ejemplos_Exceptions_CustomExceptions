#include "alumno.h"

using namespace std;

u_int alumno::cant_alumnos = 0;

int main() {
	alumno* miAlumno = nullptr;
	
	try {
		miAlumno = alumno::crearAlumno("", "perez", "7584930", "29/12/1992", "ing");
	}
	catch (EMPTY_STR<string>) {
		cerr << "ERROR";
	}

	delete miAlumno;
	return 0;
}