#pragma once
#include "Elemento.h"

class ElementoEstatico:public Elemento
{
public:
	ElementoEstatico(bool harmful, std::string path) :Elemento(harmful, path) { ; }
	virtual ~ElementoEstatico();
	virtual void Dibuja();
};

