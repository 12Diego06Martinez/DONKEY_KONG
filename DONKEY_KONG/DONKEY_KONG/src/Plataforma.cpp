#include "Plataforma.h"
#include "glut.h"

/////////////////////////////////////////CONSTRUCTOR////////////////////////
Plataforma::Plataforma() {

}

Plataforma::~Plataforma() {

}

////////////////////////////////////////METODOS////////////////////////////
void Plataforma::Dibuja() {
	glDisable(GL_LIGHTING);
	glColor3ub(0, 255, 255);
	glBegin(GL_POLYGON);
	glVertex2d(posicion.x + largo / 2, posicion.y + alto / 2);
	glVertex2d(posicion.x - largo / 2, posicion.y + alto / 2);
	glVertex2d(posicion.x - largo / 2, posicion.y - alto / 2);
	glVertex2d(posicion.x + largo / 2, posicion.y - alto / 2);
	glEnd();
	glEnable(GL_LIGHTING);
}

void Plataforma::setPos(float px, float py) {
	posicion.x = px;
	posicion.y = py;
}

void Plataforma::setSize(float w, float h) {
	largo = w;
	alto = h;
}