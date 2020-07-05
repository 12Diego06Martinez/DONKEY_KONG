#include "PlataformaMovil.h"

////////////////////////////////////////METODOS////////////////////////////////
void PlataformaMovil::Mueve(float t) {
	//Caerán con un MRU
	posicion = posicion + velocidad * t;
}

void PlataformaMovil::setVel(float vx, float vy) {
	velocidad.x = 5.0f;
	velocidad.y = 0.0;
}
