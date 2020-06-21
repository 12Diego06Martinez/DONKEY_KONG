#pragma once
#include "ElementoEstatico.h"

class Escalera:public ElementoEstatico
{
public:
	Escalera(bool harmful, std::string path) :ElementoEstatico(harmful, path) {}
	Escalera(bool harmful) :ElementoEstatico(harmful) {}
	virtual ~Escalera();
};

