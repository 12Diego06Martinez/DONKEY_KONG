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
		if (Interaccion::colisionMoneda(jugador, *monedas[i]))
			return monedas[i];
	}
	return 0;
}

void InteraccionListas::colisionJugador(Jugador& jugador, ListaEnemigos& enemigos) {
	for (int i = 0; i < enemigos.getNum(); i++) {
		if (Interaccion::colisionEnemigo(jugador, *enemigos[i])) {
			ETSIDI::play("sonidos/jump.wav");
			jugador.setVidas(jugador.getVidas()-1);
			if (jugador.getVidas() == 0) {
				ETSIDI::setTextColor(1, 0, 0);
				ETSIDI::setFont("fuentes/my game.ttf", 16);
				ETSIDI::printxy("GAMEOVER: Has perdido", 0, 5);
			}
		}
	}
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

void InteraccionListas::persiguenJugador(Jugador& jugador, ListaEnemigos& enemigos) {
	for (int i = 0; i < enemigos.getNum(); i++) {
		Interaccion::persigueJugador(jugador, *enemigos[i]);
	}
}
