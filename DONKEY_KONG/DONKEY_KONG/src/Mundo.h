#pragma once
#include "Jugador.h"
#include "Plataforma.h"
#include "Escalera.h"
#include "ListaPlataformas.h"

class Mundo
{
private:
	float x_ojo;
	float y_ojo;
	float z_ojo;
	Jugador player;
	//Plataforma* plataforma2 = new Plataforma(false);
	//Plataforma* plataforma3 = new Plataforma(false);
	ListaPlataformas plataformasLargas;
	ListaPlataformas plataformasCortas;
	Escalera* escalera1 = new Escalera(false);
	Escalera* escalera2 = new Escalera(false);
	Escalera* escalera3 = new Escalera(false);

public:
	Mundo() {}
	virtual ~Mundo();
	void Inicializa();
	void Dibuja();
	void Mueve();
	void TeclaEspecial(unsigned char key);
};