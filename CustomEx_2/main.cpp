#include <iostream>
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

int main() {
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
		misPlatos.push_back(plato("Milanesa", 2345.56, false, false, false));
		misPlatos.push_back(plato("Ravioles", 2367.34, false, true, false));
		misPlatos.push_back(plato("Helado", 1235.34, true, false, false));

		cout << *(misPlatos["Milanesa"]) << endl;
		
	}

	return 0;
}