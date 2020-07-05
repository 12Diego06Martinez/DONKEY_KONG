#pragma once
#define MAX_NUM 20

#include "Plataforma.h"
#include "PlataformaMovil.h"
#include "PlataformaEvanescente.h"

class ListaPlataformas 
{
private:
	Plataforma* lista[MAX_NUM];
	//PlataformaMovil* movil[MAX_NUM];
	int num;
public:
	ListaPlataformas();
	virtual ~ListaPlataformas();
	bool Agregar(Plataforma* plataforma);
	void Dibuja();
	void Destruir();
	void Delete(int index); //elimina esfera en la posicion indicada
	void Delete(Plataforma* plataforma); //elimina la esfera apuntada por el puntero
	int getNum() { return num; }
	Plataforma* operator [](int pos);
};