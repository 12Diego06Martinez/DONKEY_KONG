#define _CRT_SECURE_NO_WARNINGS

#include "Escalera.h"
#include "ETSIDI.h"
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