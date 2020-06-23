#pragma once
#include "ElementoEstatico.h"

class Escalera:public ElementoEstatico
{
public:
	Escalera(bool harmful, std::string path) :ElementoEstatico(harmful, path) {}
	Escalera(bool harmful) :ElementoEstatico(harmful) {}
	Escalera(float width, float height, float px, float py, bool harmful) :ElementoEstatico(width, height, px, py, harmful) {}
	virtual ~Escalera();
};

