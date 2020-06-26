#define _CRT_SECURE_NO_WARNINGS

#include "Escalera.h"
#include "ETSIDI.h"
#include <cmath>
#include <string>

////////////////////////////////CONSTRUCTOR////////////////////////////////
Escalera::Escalera(bool harm, const char* p) {
	path = new char[strlen(p) + 1];
	strcpy(path, p);

	harmful = harm;
}

Escalera::~Escalera() {

}

/////////////////////////////////METODOS///////////////////////////////////
void Escalera::Dibuja() {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Escalera2.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1);		glVertex2d(posicion.x - size.x, posicion.y - size.y);
	glTexCoord2d(1, 1);		glVertex2d(posicion.x + size.x, posicion.y - size.y);
	glTexCoord2d(1, 0);		glVertex2d(posicion.x + size.x, posicion.y + size.y);
	glTexCoord2d(0, 0);		glVertex2d(posicion.x - size.x, posicion.y + size.y);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}

void Escalera::setPos(float px, float py) {
	posicion.x = px;
	posicion.y = py;
}

void Escalera::setSize(float largo, float alto) {
	size.x = largo;
	size.y = alto;
}

void Escalera::setPath(const char* p) {
	strcpy(path, p);
}

void Escalera::setHarmful(bool harm) {
	harmful = harm;
}

float Escalera::calculaDistancia(Vector2D vector1, Vector2D vector2) {
	//Para controlar la posicion del jugador respecto a la escalera lo hacemos
	//tomando como referencia la base de la escalera.
	//Creamos una variable auxiliar que tiene esta medida en cuenta
	float distancia;

	distancia = sqrt(pow(vector2.x - vector1.x, 2.0) + pow(vector2.y - vector1.y, 2.0));
	return distancia;
}