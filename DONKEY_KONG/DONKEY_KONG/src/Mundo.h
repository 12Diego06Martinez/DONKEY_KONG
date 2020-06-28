#pragma once
#include "Jugador.h"
#include "Plataforma.h"
#include "Pared.h"
#include "Escalera.h"

class Mundo
{
private:
	float x_ojo;
	float y_ojo;
	float z_ojo;
	Pared suelo;
	Jugador player;
	//ListaEstaticos plataformas;
	Plataforma plataforma1;
	Plataforma plataforma2;
	Plataforma plataforma3;
	Plataforma plataforma4;
	Plataforma plataforma5;
	Plataforma plataforma6;
	Plataforma plataforma7;
	Escalera escalera1;
	Escalera escalera2;
	Escalera escalera3;
	Escalera escalera4;
	Escalera escalera5;
	Escalera escalera6;
public:
	Mundo() {}
	virtual ~Mundo();
	void Inicializa();
	void Dibuja();
	void Mueve();
	void TeclaEspecial(unsigned char key);
	void Tecla(unsigned char key);
};