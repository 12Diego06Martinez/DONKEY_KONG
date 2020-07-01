#pragma once
#define MAX_NUM 20

#include "Escalera.h"
#include "Jugador.h"

class ListaEscaleras {
private:
	Escalera* lista[MAX_NUM];
	int num;
public:
	ListaEscaleras();
	virtual ~ListaEscaleras();
	bool Agregar(Escalera* escalera);
	void Dibuja();
	void Destruir();
	void Delete(int index); //elimina esfera en la posicion indicada
	void Delete(Escalera* escalera); //elimina la esfera apuntada por el puntero
	int getNum() { return num; }
	Escalera* operator [](int pos);
	/////////////////////////////////////////////////////////
	Escalera* detectaEscalerasSubir(Jugador& jugador);
	Escalera* detectaEscalerasBajar(Jugador& jugador);
	Escalera* jugadorArriba(Jugador& jugador);
	Escalera* jugadorAbajo(Jugador& jugador);
};