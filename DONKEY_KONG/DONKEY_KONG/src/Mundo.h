#pragma once
#include "Jugador.h"
#include "Plataforma.h"

class Mundo
{
private:
	float x_ojo;
	float y_ojo;
	float z_ojo;
	Jugador player;
	Plataforma plataforma1;
public:
	Mundo() { ; }
	virtual ~Mundo();
	void Inicializa();
	void Dibuja();
	void Mueve();
	void TeclaEspecial(unsigned char key);
};

