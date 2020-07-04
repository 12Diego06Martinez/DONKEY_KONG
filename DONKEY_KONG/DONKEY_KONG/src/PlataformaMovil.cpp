#include "PlataformaMovil.h"

////////////////////////////////////////METODOS////////////////////////////////
void PlataformaMovil::Mueve(float t) {
	//Caerán con un MRU
	posicion = posicion + velocidad * t;
}
