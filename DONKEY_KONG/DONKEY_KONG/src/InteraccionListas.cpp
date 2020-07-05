#include "InteraccionListas.h"
#include "Interaccion.h"

Plataforma* InteraccionListas::sobrePlataforma(Jugador& jugador, ListaPlataformas plataformas) {

	for (int i = 0; i < plataformas.getNum(); i++) {
		if (Interaccion::sobrePlataforma(jugador, *plataformas[i]))
			return plataformas[i];
	}
	return 0;
}

Escalera* InteraccionListas::detectaEscalerasSubir(Jugador& jugador, ListaEscaleras escaleras) {

	for (int i = 0; i < escaleras.getNum(); i++) {
		if (Interaccion::detectaEscaleraSubir(jugador, *escaleras[i]))
			return escaleras[i];
	}
	return 0;
}

Escalera* InteraccionListas::detectaEscalerasBajar(Jugador& jugador, ListaEscaleras escaleras) {

	for (int i = 0; i < escaleras.getNum(); i++) {
		if (Interaccion::detectaEscaleraBajar(jugador, *escaleras[i]))
			return escaleras[i];
	}
	return 0;
}


Escalera* InteraccionListas::jugadorArriba(Jugador& jugador, ListaEscaleras escaleras) {

	for (int i = 0; i < escaleras.getNum(); i++) {
		if (Interaccion::arribaEscalera(jugador, *escaleras[i]))
			return escaleras[i];
	}
	return 0;
}

Escalera* InteraccionListas::jugadorAbajo(Jugador& jugador, ListaEscaleras escaleras) {

	for (int i = 0; i < escaleras.getNum(); i++) {
		if (Interaccion::abajoEscalera(jugador, *escaleras[i]))
			return escaleras[i];
	}
	return 0;
}

Moneda* InteraccionListas::cogeMonedas(Jugador& jugador, ListaMonedas monedas) {
	for (int i = 0; i < monedas.getNum(); i++) {
		if (Interaccion::colisionMoneda(jugador, *monedas[i])) {
			ETSIDI::play("sonidos/coin.wav");
			return monedas[i];
		}
			
	}
	return 0;
}

Enemigo* InteraccionListas::colisionJugador(Jugador& jugador, ListaEnemigos& enemigos) {
	for (int i = 0; i < enemigos.getNum(); i++) {
		if (Interaccion::colisionEnemigo(jugador, *enemigos[i])) {
			return enemigos[i];
		}
	}
	return 0;
}

void InteraccionListas::colisionEnemigos(ListaEnemigos& enemigos) {
	for (int i = 0; i < enemigos.getNum(); i++) {
		for (int j = 0; j < enemigos.getNum(); j++) {
			Interaccion::colisionEnemigos(*enemigos[i], *enemigos[j]);
		}
	}
}

void InteraccionListas::rebotePlataformas(ListaPlataformas& plataformas, ListaEnemigos& enemigos) {
	for (int i = 0; i < plataformas.getNum(); i++) {
		for (int j = 0; j < enemigos.getNum(); j++) {
			Interaccion::reboteEnemigos(*enemigos[j], *plataformas[i]);
		}
	}
}

Plataforma* InteraccionListas::caidaVacio(Jugador& jugador, ListaPlataformas plataformas) {
	for (int i = 0; i < plataformas.getNum(); i++) {
		if (Interaccion::caidaVacio(jugador, *plataformas[i]))
			return plataformas[i];
	}
	return 0;
}

/////////////////////////////
void InteraccionListas::persiguenJugador(Jugador& jugador, ListaEnemigos& enemigos) {
	for (int i = 0; i < enemigos.getNum(); i++) {
		Interaccion::persigueJugador(jugador, *enemigos[i]);
	}
}
