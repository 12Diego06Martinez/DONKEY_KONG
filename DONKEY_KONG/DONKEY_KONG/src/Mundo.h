#pragma once
#include "Jugador.h"
#include "Pared.h"
#include "ListaPlataformas.h"
#include "ListaEscaleras.h"
#include "ListaMonedas.h"
#include "ListaEnemigos.h"

class Mundo
{
private:
	float x_ojo;
	float y_ojo;
	float z_ojo;
	int monedas_recogidas;
	int vidas;
	bool pasar_nivel;
	Pared suelo;
	Pared hueco1;
	Pared hueco2;
	Jugador player;
	ListaPlataformas plataformas;
	ListaEscaleras escaleras;
	ListaMonedas monedas;
	ListaEnemigos enemigos;
public:
	Mundo() {}
	virtual ~Mundo();
	void Inicializa();
	void Dibuja();
	void Mueve();
	void TeclaEspecial(unsigned char key);
	void Tecla(unsigned char key);
	//Getters
	bool getValidacion() { return pasar_nivel; }
	int getVidas() { return vidas; }
	int getMonedas() { return monedas_recogidas; }
};