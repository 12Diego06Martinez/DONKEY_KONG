#include "Pared.h"

using namespace ETSIDI;

////////////////////////////////////CONSTRUCTOR//////////////////////
Pared::Pared() {
	limite1.x = limite1.y = limite2.x = limite2.y = 0;
}

Pared::~Pared() {

}
////////////////////////////////////METODOS//////////////////////////
void Pared::Dibuja() {
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex3f(limite1.x, limite1.y, 0);
	glVertex3f(limite2.x, limite1.y, 0);
	glVertex3f(limite2.x, limite2.y, 0);
	glVertex3f(limite1.x, limite2.y, 0);
	glEnd();
	glEnable(GL_LIGHTING);
}

void Pared::setLimites(float x1, float y1, float x2, float y2) {
	limite1.x = x1;
	limite1.y = y1;
	limite2.x = x2;
	limite2.y = y2;
}
