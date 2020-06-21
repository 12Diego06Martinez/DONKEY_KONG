#include "ElementoEstatico.h"
#include "glut.h"

//////////////////////////////////////CONSTRUCTOR/////////////////////////
ElementoEstatico::~ElementoEstatico() {

}

/////////////////////////////////////METODOS//////////////////////////////
void ElementoEstatico::Dibuja() {
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