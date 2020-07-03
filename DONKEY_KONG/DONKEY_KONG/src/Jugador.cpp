#include "Jugador.h"

using namespace ETSIDI;

//////////////////////////////////////CONSTRUCTOR////////////////////////
Jugador::Jugador():ElementoMovil() {
	posicion.x = -8.0f;
	posicion.y = -1.85f;
	alto = ancho = 1.0f;
	path = "imagenes/mario_pie_dcha.png";
}

Jugador::~Jugador() {

}
//////////////////////////////////////METODOS///////////////////////////
void Jugador::Mueve(float t) {
	//Movimiento rectilineo unirformemente acelerado
	posicion = posicion + velocidad *t + aceleracion * (0.5 * t * t);
	velocidad = velocidad + aceleracion * t;
}

void Jugador::setAcel(float ax, float ay) {
	aceleracion.x = ax;
	aceleracion.y = ay;
}
