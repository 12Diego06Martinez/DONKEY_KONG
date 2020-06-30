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