#pragma once
#include <array>
#include <queue>

#include "cochera.h"

using namespace std;

template <size_t T>
class garage : public array<cochera, T> {
public:
	garage() {
	}
	~garage() {
	}
	queue<cochera> disponibilidad();
};

template<size_t T>
inline queue<cochera> garage<T>::disponibilidad() {
	queue<cochera> disponibles;
	
	for (int i = 0; i < this->size(); i++) {
		cochera aux = this->at(i);
		if (!(aux.estaOcupado()))
			disponibles.push(aux);
	}

	if (disponibles.empty())
		throw cocheraEx();

	return disponibles;
}
