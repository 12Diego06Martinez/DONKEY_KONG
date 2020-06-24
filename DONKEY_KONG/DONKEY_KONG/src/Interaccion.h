#pragma once
#include "Jugador.h"
#include "Plataforma.h"

class Interaccion
{
public:
	Interaccion();
	virtual ~Interaccion();
	static void Rebote(Jugador& j, Plataforma p);
};

