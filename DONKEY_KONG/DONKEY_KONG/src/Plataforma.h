#pragma once
#include "ElementoEstatico.h"


class Plataforma:public ElementoEstatico
{
public:
	Plataforma();
	virtual ~Plataforma();
	friend class Interaccion;
};