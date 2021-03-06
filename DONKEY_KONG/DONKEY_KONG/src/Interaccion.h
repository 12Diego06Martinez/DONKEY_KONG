#pragma once

#include "Jugador.h"
#include "Plataforma.h"
#include "PlataformaMovil.h"
#include "Pared.h"
#include "Escalera.h"
#include "Moneda.h"
#include "Enemigo.h"
#include "Vacuna.h"

class Interaccion
{
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
	static void colisionEnemigos(Enemigo& enemigo1, Enemigo& enemigo2);
	static void reboteEnemigos(Enemigo& enemigo, Plataforma plataforma);
	static bool caidaVacio(Jugador& jugador, Plataforma plataforma);
	static bool detectaEvanescente(Jugador& jugador, Plataforma plataforma);
	static bool cogeVacuna(Jugador& jugador, Vacuna vacuna);
	static bool detectaCaja(Jugador& jugador, Plataforma plataforma);
	////////////////////////////////////////////
	static void persigueJugador(Jugador& jugador, Enemigo& enemigo);
};
