#pragma once
#include "Jugador.h"
#include "Pared.h"
#include "ListaPlataformas.h"
#include "ListaEscaleras.h"
#include "ListaMonedas.h"
#include "ListaEnemigos.h"
#include "GestorMultimedia.h"

class GestorNiveles
{
private:
	Pared suelo;
	Pared hueco1;
	Pared hueco2;
	Jugador player;
	ListaPlataformas plataformas;
	ListaEscaleras escaleras;
	ListaMonedas monedas;
	ListaEnemigos enemigos;
	GestorMultimedia dj;
	float x_ojo;
	float y_ojo;
	float z_ojo;
	int nivel;
	int vidas;
	int monedas_recogidas;
	bool pasar_nivel;
public:
	virtual ~GestorNiveles();
	void cargaNivel();
	void dibujaNivel();
	void mueveNivel();
	void teclasNivel(unsigned char key);
	void flechasNivel(unsigned char key);
	void recargaNivel();
	//Setters
	void subeNivel() { nivel++; }
	//Getters
	int getVidas() { return vidas; }
	int getNivel() { return nivel; }
	bool getValidacion() { return pasar_nivel; }
};

