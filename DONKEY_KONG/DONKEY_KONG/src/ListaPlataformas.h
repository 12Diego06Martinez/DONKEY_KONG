#pragma once
#define MAX_NUM 20

#include "Plataforma.h"

class ListaPlataformas
{
private:
	Plataforma* lista[MAX_NUM];
	int num;
public:
	ListaPlataformas();
	virtual ~ListaPlataformas();
	void Dibuja();
	bool Agregar(Plataforma* plataforma);
	void destruirContenido();
	void Eliminar(int index);
	void Eliminar(Plataforma* plataforma);
	int getNum() { return num; }
	Plataforma* operator [](int pos);
};

