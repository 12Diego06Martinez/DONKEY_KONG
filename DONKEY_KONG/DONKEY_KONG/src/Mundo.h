#pragma once
#include "Jugador.h"
#include "Plataforma.h"
#include "Escalera.h"
#include "ListaPlataformas.h"
#include "ListaEscaleras.h"

class Mundo
{
private:
	float x_ojo;
	float y_ojo;
	float z_ojo;
	Jugador player;
	ListaPlataformas plataformasLargas;
	ListaPlataformas plataformasCortas;
	ListaEscaleras escaleras;
public:
	Mundo() {}
	virtual ~Mundo();
	void Inicializa();
	void Dibuja();
	void Mueve();
	void TeclaEspecial(unsigned char key);
};