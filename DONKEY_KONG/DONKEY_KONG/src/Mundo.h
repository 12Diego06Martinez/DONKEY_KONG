#pragma once
#include "Jugador.h"
#include "Plataforma.h"
#include "Escalera.h"
#include "ListaEstaticos.h"

class Mundo
{
private:
	float x_ojo;
	float y_ojo;
	float z_ojo;
	Jugador player;
	ListaEstaticos plataformas;
	//ListaEstaticos escaleras;
public:
	Mundo() {}
	virtual ~Mundo();
	void Inicializa();
	void Dibuja();
	void Mueve();
	void TeclaEspecial(unsigned char key);
};