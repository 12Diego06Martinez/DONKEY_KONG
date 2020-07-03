#include "Enemigo.h"


////////////////////////////////////CONSTRUCTOR///////////////////////////
Enemigo::Enemigo(float px, float py, const char* p):ElementoMovil(px, py, p){
	alto = ancho = 0.35f;
	generaAleatorio();
}

Enemigo::~Enemigo() {

}

//////////////////////////////////////METODOS/////////////////////////////
void Enemigo::Mueve(float t) {
	//No va a caer ni nada->MRU
	posicion = posicion + velocidad * t;
}

void Enemigo::generaAleatorio() {
	bool num=ETSIDI::lanzaMoneda();
	if (num == true)
		setVel(6.5f, 0.0f);
	else
		setVel(-6.5f, 0.0f);
}