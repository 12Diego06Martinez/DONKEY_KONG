#pragma once

#include "Jugador.h"
#include "Plataforma.h"
#include "Pared.h"
#include "Escalera.h"
#include "Moneda.h"
#include "Enemigo.h"

class Interaccion{
public:
	Interaccion();
	virtual ~Interaccion();
	static void reboteExterior(Jugador& jugador, Pared pared);
	static bool sobrePlataforma(Jugador& jugador, Plataforma plataforma);
	static bool arribaEscalera(Jugador& jugador, Escalera escalera);
	static bool abajoEscalera(Jugador& jugador, Escalera escalera);
	static bool detectaEscaleraSubir(Jugador& jugador, Escalera escalera);
	static bool detectaEscaleraBajar(Jugador& jugador, Escalera escalera);
	static bool caidaHueco(Jugador& jugador, Pared pared);
	static bool colisionMoneda(Jugador& jugador, Moneda moneda);
	static bool colisionEnemigo(Jugador& jugador, Enemigo& enemigo);
	//static bool comprobarAltura(Jugador& jugador, Plataforma plataforma);
};
