#pragma once
#include "ElementoEstatico.h"

class Plataforma:public ElementoEstatico
{
public:
	Plataforma(bool harmful, std::string path):ElementoEstatico(harmful, path){}
	Plataforma(bool harmful) :ElementoEstatico(harmful){}
	virtual ~Plataforma();
};

