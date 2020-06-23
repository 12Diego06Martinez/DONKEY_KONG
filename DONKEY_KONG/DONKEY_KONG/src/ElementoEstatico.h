#pragma once
#include "Elemento.h"

class ElementoEstatico:public Elemento
{
public:
	ElementoEstatico(bool harmful, std::string path) :Elemento(harmful, path) {}
	ElementoEstatico(bool harmful) :Elemento(harmful) {}
	ElementoEstatico(float width, float height, float px, float py, bool harmful):Elemento(width,height, px, py, harmful){}
	virtual ~ElementoEstatico();
	virtual void Dibuja();
};

