#include "Elemento.h"

/////////////////////////////////////CONSTRUCTOR////////////////////////
Elemento::~Elemento() {

}

///////////////////////////////////METODOS/////////////////////////////
void Elemento::setHarmful(bool harm) {
	Harmful = harm;
}

void Elemento::setPos(float px, float py) {
	posicion.x = px;
	posicion.y = py;
}

void Elemento::setColor(unsigned char r, unsigned char g, unsigned char b) {
	rojo = r;
	verde = g;
	azul = b;
}