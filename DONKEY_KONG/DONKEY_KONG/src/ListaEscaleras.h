#pragma once
#define MAX_NUM 20
#include "Escalera.h"

class ListaEscaleras
{
private:
	Escalera* lista[MAX_NUM];
	int num;
public:
	ListaEscaleras();
	virtual ~ListaEscaleras();
	void Dibuja();
	bool Agregar(Escalera* escalera);
	void destruirContenido();
	void Eliminar(int index);
	void Eliminar(Escalera* Escaleras);
	int getNum() { return num; }
	Escalera* operator [](int pos);
};

