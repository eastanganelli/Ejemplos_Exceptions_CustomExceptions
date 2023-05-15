#pragma once
#define u_int unsigned int

#include "customEx.h"

class cochera {
	static u_int contador;
	const u_int ID;
	bool occupy; // auto_* miAuto_;
public:
	cochera();
	cochera(bool o_);
	~cochera();

	u_int get_ID();
	bool estaOcupado();
	void cambiarEstado();
	bool operator==(const cochera& c_);
};