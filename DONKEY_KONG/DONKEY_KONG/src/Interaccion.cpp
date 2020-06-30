#include "Interaccion.h"

/////////////////////////////////////CONSTRUCTOR////////////////////////////
Interaccion::Interaccion() {

}

Interaccion::~Interaccion() {

}

/////////////////////////////////////METODOS////////////////////////////////
void Interaccion::reboteExterior(Jugador& jugador, Pared pared) {
	
	if (jugador.posicion.x > pared.limite2.x) {
		jugador.posicion.x = pared.limite2.x;
	}
	if (jugador.posicion.x < pared.limite1.x) {
		jugador.posicion.x = pared.limite1.x;
	}
}

bool Interaccion::sobrePlataforma(Jugador& jugador, Plataforma plataforma) {

	if (jugador.posicion.y <= plataforma.posicion.y && jugador.posicion.y > plataforma.limite1.y) {
		jugador.setPos(jugador.posicion.x, plataforma.posicion.y);
		return true;
	}
	
	else
		return false;
}

bool Interaccion::detectaEscalera(Jugador& jugador, Escalera escalera) {
	float distancia = escalera.calculaDistancia(escalera.posicion, jugador.posicion);
	if (distancia > 1.999 && distancia < 2.004)
		return true;
	else
		return false;
}

bool Interaccion::arribaEscalera(Jugador& jugador, Escalera escalera){
	if (jugador.posicion.y >= escalera.limite2.y && jugador.isAligned == true) {
		jugador.setPos(jugador.posicion.x, escalera.limite2.y);
		return true;
	}
	else
		return false;
}

//bool Interaccion::comprobarAltura(Jugador& jugador, Plataforma plataforma) {
//
//	if (jugador.posicion.y > plataforma.limite1.y)
//		return true;
//	else
//		return false;
//}