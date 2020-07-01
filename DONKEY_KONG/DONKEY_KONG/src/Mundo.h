#pragma once
#include "Jugador.h"
#include "Pared.h"
#include "ListaPlataformas.h"
#include "ListaEscaleras.h"

class Mundo
{
private:
	float x_ojo;
	float y_ojo;
	float z_ojo;
	Pared suelo;
	Jugador player;
	ListaPlataformas plataformas;
	ListaEscaleras escaleras;
public:
	Mundo() {}
	virtual ~Mundo();
	void Inicializa();
	void Dibuja();
	void Mueve();
	void TeclaEspecial(unsigned char key);
	void Tecla(unsigned char key);
};