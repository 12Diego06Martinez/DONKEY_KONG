#pragma once

#define MAX_NUM 20

#include "Enemigo.h"
#include "Jugador.h"
#include "ListaPlataformas.h"

class ListaEnemigos 
{
private:
	Enemigo* lista[MAX_NUM];
	int num;
public:
	ListaEnemigos();
	virtual ~ListaEnemigos();
	bool Agregar(Enemigo* enemigo);
	void Dibuja();
	void Mueve(float t);
	void Destruir();
	void Delete(int index); //elimina esfera en la posicion indicada
	void Delete(Enemigo* enemigo); //elimina la esfera apuntada por el puntero
	int getNum() { return num; }
	Enemigo* operator [](int pos);
};
