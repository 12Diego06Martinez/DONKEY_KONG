#define _CRT_SECURE_NO_WARNINGS

#include "Elemento.h"
#include <string>

/////////////////////////////////////CONSTRUCTOR////////////////////////
Elemento::Elemento(bool harmful, const char* p) {
	path = new char[strlen(p) + 1];
	strcpy(path, p);

	Harmful = harmful;
}

Elemento::~Elemento() {

}

///////////////////////////////////METODOS/////////////////////////////
void Elemento::setColor(unsigned char r, unsigned char g, unsigned char b) {
	rojo = r;
	verde = g;
	azul = b;
}

void Elemento::setHarmful(bool harm) {
	Harmful = harm;
}