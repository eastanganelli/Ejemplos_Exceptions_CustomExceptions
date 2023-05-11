#include <iostream>
#include <vector>
#include <ctime>

#include "menu.h"
#include "customEx.h"
#include "plato.h"
	
using namespace std;

float entrada_de_datos() {
	float val_1, val_2;
	std::cout << "Ingresar dos valores:" << std::endl;
	std::cin >> val_1;
	std::cin >> val_2;

	std::cout << val_1 << "/" << val_2 << std::endl;

	if (val_2 == 0)
		throw DIV_ZERO();

	return (float)(val_1 / val_2);
}

unsigned int random_generator(int min, int max) {
	return rand() % (max - min) + min;
}

menu generator_platos(unsigned int cant_platos) {
	vector<string> platos = { "Milanesa", "Fideos", "Ravioles", "Noquis", "Asado", "Pizza", "Tarta", "Ensalada", "Helado", "Panqueue", "Tiramusu" };
	menu auxdishes;

	int i = 0;
	while (i < cant_platos) {
		string platito = platos[random_generator(1, platos.size()) - 1];
		float precio = random_generator(500.00, 4000.00);
		bool k_  = bool(random_generator(0, 1)),
			 gf_ = bool(random_generator(0, 1)),
			 d_  = bool(random_generator(0, 1));
		auxdishes.push_back(plato(platito, precio, d_, k_, gf_));
		i++;
	}
	return auxdishes;
}

int main() {
	srand(time(NULL));
	/*{
		while (true) {
			try {
				std::cout << entrada_de_datos() << std::endl;
			}
			catch (std::exception& e) {
				std::cerr << e.what() << std::endl;
				return 0;
			}
		}
	}*/

	{
		menu misPlatos;
		misPlatos = generator_platos(7);

		try {
			cout << *(misPlatos["Milanesa"]) << endl;
			cout << *(misPlatos["Helado"]) << endl;
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
		
	}

	return 0;
}