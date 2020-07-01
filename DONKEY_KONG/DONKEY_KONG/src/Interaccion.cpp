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
	float x_max = plataforma.limite2.x;
	float x_min = plataforma.limite1.x;
	float y_max = plataforma.limite2.y;
	float y_min = plataforma.limite1.y;
	if (jugador.posicion.y <= y_max && jugador.posicion.y > y_min && jugador.posicion.x >= x_min && jugador.posicion.x<=x_max) {
		jugador.setPos(jugador.posicion.x, plataforma.limite2.y);
		jugador.isOnPlatform = true;
	}
	
	else
		jugador.isOnPlatform = false;
	return jugador.isOnPlatform;
}

bool Interaccion::arribaEscalera(Jugador& jugador, Escalera escalera){
	//if (jugador.posicion.y > escalera.limite2.y && jugador.isAligned == true) {
	//	jugador.setPos(jugador.posicion.x, (escalera.limite2.y+0.15));
	//	return true;
	//}
	//else
	//	return false;
	float distancia = escalera.calculaDistancia(escalera.limite1, jugador.posicion);
	if (distancia > 4.15 && distancia < 4.16 && jugador.isGoingUp==true) {
		jugador.setPos(jugador.posicion.x, (escalera.limite2.y + 0.15));
		return true;
	}
	else
		return false;
}

bool Interaccion::abajoEscalera(Jugador& jugador, Escalera escalera) {
	float distancia = escalera.calculaDistancia(escalera.limite2, jugador.posicion);
	if (distancia > 3.84 && distancia < 3.86 && jugador.isGoingDown == true) {
		jugador.setPos(jugador.posicion.x, (escalera.limite1.y + 0.15));
		return true;
	}
	else
		return false;
}

bool Interaccion::detectaEscaleraSubir(Jugador& jugador, Escalera escalera) {
	float distancia = escalera.calculaDistancia(escalera.posicion, jugador.posicion);
	if (distancia > 1.849 && distancia < 1.852) {
		return true;
	}
	else
		return false;
}

bool Interaccion::detectaEscaleraBajar(Jugador& jugador, Escalera escalera) {
	float distancia = escalera.calculaDistancia(escalera.posicion, jugador.posicion);
	if (distancia > 2.149 && distancia < 2.152)
		return true;
	else
		return false;
}

bool Interaccion::caidaHueco(Jugador& jugador, Pared pared) {
	float x_max = pared.limite2.x;
	float x_min = pared.limite1.x;
	float y_max = pared.limite2.y;

	if (jugador.posicion.x < x_max  && jugador.posicion.x > x_min && jugador.posicion.y == y_max) 
		return true;
	else
		return false;
}