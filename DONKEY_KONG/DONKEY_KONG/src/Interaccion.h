#pragma once

#include "Jugador.h"
#include "Plataforma.h"
#include "Pared.h"
#include "Escalera.h"

class Interaccion{
public:
	Interaccion();
	virtual ~Interaccion();
	static void reboteExterior(Jugador& jugador, Pared pared);
};
