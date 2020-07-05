#pragma once
#define MAX_NUM 20

#include "Vidas.h"



class ListaVidas {
private:
	Vidas* lista[MAX_NUM];
	int num;
public:
	ListaVidas();
	virtual ~ListaVidas();
	bool Agregar(Vidas* vida);
	void Dibuja();
	void Mueve(float t);
	void setVel();
	void Destruir();
	void Delete(int index); //elimina esfera en la posicion indicada
	void Delete(Vidas* vida); //elimina la esfera apuntada por el puntero
	int getNum() { return num; }
	Vidas* operator [](int pos);

};
