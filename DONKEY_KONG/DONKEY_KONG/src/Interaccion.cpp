#include "Interaccion.h"

///////////////////////////////CONSTRUCTOR////////////////////////////////
Interaccion::Interaccion() {

}

Interaccion::~Interaccion(){

}

///////////////////////////////METODOS////////////////////////////////////
void Interaccion::Rebote(Jugador& j, Plataforma p) {
	float x_max = p.limite2.x;
	float x_min = p.limite1.x;

	if (j.posicion.x > x_max)
		j.posicion.x = x_max;

	if (j.posicion.x < x_min)
		j.posicion.x = x_min;
}