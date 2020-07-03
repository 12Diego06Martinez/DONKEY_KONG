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
	int monedas_recogidas = 0;
	int vidas = 3;
	bool pasar_nivel;
	bool fin_juego;
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

	int getVidas() { return vidas; }
	int getMonedas() { return monedas_recogidas; }
};