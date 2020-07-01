#pragma once
#define MAX_NUM 20

#include "Moneda.h"
#include "Jugador.h"

class ListaMonedas {
private:
	Moneda* lista[MAX_NUM];
	int num;
public:
	ListaMonedas();
	virtual ~ListaMonedas();
	bool Agregar(Moneda* moneda);
	void Dibuja();
	void Destruir();
	void Delete(int index); //elimina esfera en la posicion indicada
	void Delete(Moneda* moneda); //elimina la esfera apuntada por el puntero
	int getNum() { return num; }
	Moneda* operator [](int pos);
	///////////////////////////////////////////
	Moneda* cogeMonedas(Jugador& jugador);
};
