#include "PlataformaMovil.h"

////////////////////////////////////////METODOS////////////////////////////////
void PlataformaMovil::Mueve(float t) {
	//Caer�n con un MRU
	posicion = posicion + velocidad * t;
}
