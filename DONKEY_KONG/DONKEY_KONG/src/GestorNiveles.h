#pragma once
#include "Jugador.h"
#include "Pared.h"
#include "ListaPlataformas.h"
#include "ListaEscaleras.h"
#include "ListaMonedas.h"
#include "ListaEnemigos.h"
#include "GestorMultimedia.h"
#include "ListaVidas.h"
#include "Vacuna.h"

class GestorNiveles
{
private:
	Pared suelo;
	ListaVidas vidas_icono;
	Jugador player;
	ListaPlataformas plataformas;
	ListaPlataformas caja;
	ListaPlataformas moviles;
	ListaPlataformas evanescentes;
	ListaEscaleras escaleras;
	ListaMonedas monedas;
	ListaEnemigos enemigos;
	GestorMultimedia dj;
	Vacuna cura;
	float x_ojo;
	float y_ojo;
	float z_ojo;
	int nivel;
	int vidas;
	int monedas_recogidas;
	bool pasar_nivel;
public:
	GestorNiveles();
	virtual ~GestorNiveles();
	void cargaNivel();
	void dibujaNivel();
	void mueveNivel();
	void teclasNivel(unsigned char key);
	void flechasNivel(unsigned char key);
	void recargaNivel();
	//Setters
	void subeNivel() { nivel++; }
	void setNivel(int num) { nivel = num; }
	//Getters
	int getVidas() { return vidas; }
	int getNivel() { return nivel; }
	bool getValidacion() { return pasar_nivel; }
};

