#define _CRT_SECURE_NO_WARNINGS

#include "ElementoMovil.h"
#include <string>

////////////////////////////////////////CONSTRUCTOR/////////////////////////////
ElementoMovil::ElementoMovil(float px, float py, const char* p) {
	posicion.x = px;
	posicion.y = py;

	path = p;
}

ElementoMovil::~ElementoMovil() {

}

////////////////////////////////////////METODOS////////////////////////////////
void ElementoMovil::Dibuja() {
	glEnable(GL_TEXTURE_2D);
	glTranslatef(posicion.x, posicion.y, 0);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture(path).id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1);		glVertex3f(-ancho, 0, 0);
	glTexCoord2d(1, 1);		glVertex3f(ancho, 0, 0);
	glTexCoord2d(1, 0);		glVertex3f(ancho, alto, 0);
	glTexCoord2d(0, 0);		glVertex3f(-ancho, alto, 0);
	glEnd();
	glTranslatef(-posicion.x, -posicion.y, 0);
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}

void ElementoMovil::setPos(float px, float py) {
	posicion.x = px;
	posicion.y = py;
}

void ElementoMovil::setVel(float vx, float vy) {
	velocidad.x = vx;
	velocidad.y = vy;
}

void ElementoMovil::setPath(const char* p) {
	//strcpy(path, p);
	path = p;
}
