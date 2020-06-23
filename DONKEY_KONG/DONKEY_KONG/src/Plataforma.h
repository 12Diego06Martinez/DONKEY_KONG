#pragma once
#include "ElementoEstatico.h"

class Plataforma:public ElementoEstatico
{
public:
	Plataforma(bool harmful, std::string path):ElementoEstatico(harmful, path){}
	Plataforma(bool harmful) :ElementoEstatico(harmful){}
	Plataforma(float width, float height, float px, float py, bool harmful):ElementoEstatico(width,height,px,py,harmful){}
	virtual ~Plataforma();
};

