#include "Vacuna.h"

Vacuna::Vacuna():ElementoFijo() {
	posicion.x = 0;
	posicion.y = 10.5;
	/*ancho = alto = 1.0f;*/
	path = "imagenes/vacuna.png";
	limite1.x = -0.5;
	limite1.y = 10.0;
	limite2.x = 0.5;
	limite2.y = 11;
}