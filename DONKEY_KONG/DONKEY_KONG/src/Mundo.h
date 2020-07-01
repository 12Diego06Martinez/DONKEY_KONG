#pragma once
#include "Jugador.h"
#include "Pared.h"
#include "ListaPlataformas.h"
#include "ListaEscaleras.h"
#include "ListaMonedas.h"

class Mundo
{
private:
	float x_ojo;
	float y_ojo;
	float z_ojo;
	Pared suelo;
	Pared hueco1;
	Pared hueco2;
	Jugador player;
	ListaPlataformas plataformas;
	ListaEscaleras escaleras;
	ListaMonedas monedas;
public:
	Mundo() {}
	virtual ~Mundo();
	void Inicializa();
	void Dibuja();
	void Mueve();
	void TeclaEspecial(unsigned char key);
	void Tecla(unsigned char key);
};