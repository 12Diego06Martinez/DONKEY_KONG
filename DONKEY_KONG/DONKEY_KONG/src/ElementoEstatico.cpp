#include "ElementoEstatico.h"
#include "ETSIDI.h"
#include "glut.h"

//////////////////////////////////////CONSTRUCTOR/////////////////////////
ElementoEstatico::~ElementoEstatico() {

}

/////////////////////////////////////METODOS//////////////////////////////
void ElementoEstatico::Dibuja() {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture(path).id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1);		glVertex2d(limite1.x, limite1.y);
	glTexCoord2d(1, 1);		glVertex2d(limite2.x, limite1.y);
	glTexCoord2d(1, 0);		glVertex2d(limite2.x, limite2.y);
	glTexCoord2d(0, 0);		glVertex2d(limite1.x, limite2.y);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}

void ElementoEstatico::setLimites(float x1, float y1, float x2, float y2) {
	limite1.x = x1;
	limite1.y = y1;
	limite2.x = x2;
	limite2.y = y2;
}
