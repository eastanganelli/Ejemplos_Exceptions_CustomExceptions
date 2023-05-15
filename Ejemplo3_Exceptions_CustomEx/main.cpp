#include <iostream>
#include <ctime>

#include "garage.h"

u_int cochera::contador = 0;

using namespace std;

bool random_bool() {
	return ( rand() % 2 == 1 );
}

unsigned int random_generator(u_int min, u_int max) {
	return ( (rand() % ( max - min )) + min);
}

int main() {
	srand(time((time_t*)NULL));

	const size_t tam = 10;

	// Genera los 10 valores del array con el constructor por defecto
	// Usaremos el métodos que cambiarEstado, para simular que algunas
	// estén ocupadas.
	garage<tam> GarageAzul;

	for (int i = 0; i < tam; i++)
		if (random_bool())
			GarageAzul[i].cambiarEstado();

	// Generó bloque de try catch
	// dónde si NO HAY cocheras disponibles
	// el catch levantará la exception personalizada
	// que se encuentra dentro del método disponibilidad() en la clase Garage.
	queue<cochera> dispo;
	try {
		dispo = GarageAzul.disponibilidad();
	
		// Imprimo la cantidad de cocheras disponibles
		// como que cocheras son en base a su ID
		cout << "Cocheras disponibles"		   << endl
			 << "Cantidad -> " << dispo.size() << endl
			 << "Cocheras:";

		while (!(dispo.empty())) {
			cochera c_ = dispo.front();
			cout << "\t" << c_.get_ID();
			dispo.pop();
		}
	}
	catch (exception& e) {
		std::cout << e.what() << endl;
	}

	// Testeo una sobrecarga del tipo ==
	// para ver si 2 objetos de cochera son la misma o no.
	// Para probarlo, un random seleccionara dos objetos
	// de forma random.
	{
		cochera cochera_1 = GarageAzul[random_generator(1, tam) - 1],
			cochera_2 = GarageAzul[random_generator(1, tam) - 1];

		cout << endl << "Cochera 1 [ID: " << cochera_1.get_ID() << "] == Cochera 2 [ID: " << cochera_2.get_ID() << "] : "
			<< ((cochera_1 == cochera_2) ? "Si" : "No") << endl;
	}

	return 0;
}