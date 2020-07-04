#pragma once

#include "ListaEnemigos.h"
#include "ListaMonedas.h"
#include "ListaEscaleras.h"
#include "ListaPlataformas.h"


class InteraccionListas 
{
public:
	static Plataforma* sobrePlataforma(Jugador& jugador, ListaPlataformas plataformas);
	static Escalera* detectaEscalerasSubir(Jugador& jugador, ListaEscaleras escaleras);
	static Escalera* detectaEscalerasBajar(Jugador& jugador, ListaEscaleras escaleras);
	static Escalera* jugadorArriba(Jugador& jugador, ListaEscaleras escaleras);
	static Escalera* jugadorAbajo(Jugador& jugador, ListaEscaleras escaleras);
	static Moneda* cogeMonedas(Jugador& jugador, ListaMonedas monedas);
	static Enemigo* colisionJugador(Jugador& jugador, ListaEnemigos& enemigos);
	static void colisionEnemigos(ListaEnemigos& enemigos);
	static void rebotePlataformas(ListaPlataformas& plataformas, ListaEnemigos& enemigos);
	static void persiguenJugador(Jugador& jugador, ListaEnemigos& enemigos);
};
