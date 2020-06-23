#pragma once
#define MAX_NUM 20

#include "ElementoEstatico.h"

class ListaEstaticos
{
	private:
		ElementoEstatico* lista[MAX_NUM];
		int num;
	public:
		ListaEstaticos();
		virtual ~ListaEstaticos();
		void Dibuja();
		bool Agregar(ElementoEstatico* elemento);
		void destruirContenido();
		void Eliminar(int index);
		void Eliminar(ElementoEstatico* elemento);
		int getNum() { return num; }
		ElementoEstatico* operator [](int pos);
};

