#define _CRT_SECURE_NO_WARNINGS

#include "Plataforma.h"
#include "ETSIDI.h"
#include <string>

/////////////////////////////////////CONSTRUCTOR//////////////////////////
Plataforma::Plataforma(bool harm, const char* p) {
	path = new char[strlen(p) + 1];
	strcpy(path, p);

	harmful = harm;
}

Plataforma::~Plataforma() {

}

///////////////////////////////////METODOS////////////////////////////////
void Plataforma::Dibuja() {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Block.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1);		glVertex2d(posicion.x - size.x,posicion.y - size.y);
	glTexCoord2d(1, 1);		glVertex2d(posicion.x + size.x,posicion.y - size.y);
	glTexCoord2d(1, 0);		glVertex2d(posicion.x + size.x, posicion.y + size.y);
	glTexCoord2d(0, 0);		glVertex2d(posicion.x - size.x, posicion.y + size.y);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}

void Plataforma::setPos(float px, float py) {
	posicion.x = px;
	posicion.y = py;
}

void Plataforma::setSize(float largo, float alto) {
	size.x = largo;
	size.y = alto;
}

void Plataforma::setPath(const char* p) {
	strcpy(path, p);
}

void Plataforma::setHarmful(bool harm) {
	harmful = harm;
}