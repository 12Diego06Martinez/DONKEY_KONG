#define  _CRT_SECURE_NO_WARNINGS	

#include "Enemigo.h"

using namespace ETSIDI;

////////////////////////////////////CONSTRUCTOR///////////////////////////
Enemigo::Enemigo(float px, float py, float w, float h) {
	posicion.x = px;
	posicion.y = py;
	limite1.x = px - ancho / 2;
	limite1.y = py - alto / 2;
	limite2.x = px + ancho / 2;
	limite2.y = py + alto / 2;
}

Enemigo::~Enemigo() {

}

//////////////////////////////////////METODOS/////////////////////////////
void Enemigo::Dibuja() {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("enemy_dcha.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1);		glVertex3f(limite1.x, limite1.y, 0.1);
	glTexCoord2d(1, 1);		glVertex3f(limite2.x, limite1.y, 0.1);
	glTexCoord2d(1, 0);		glVertex3f(limite2.x, limite2.y, 0.1);
	glTexCoord2d(0, 0);		glVertex3f(limite1.x, limite2.y, 0.1);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}

void Enemigo::Mueve(float t) {
	//No va a caer ni nada->MRU
	posicion = posicion + velocidad * t;
}

int Enemigo::generaAleatorio() {
	int num=lanzaDado(1.0, 6.0);
	if (num <= 3)
		setVel(5.0f, 0.0f);
	else
		setVel(-5.0f, 0.0f);
}

void Enemigo::setPos(float px, float py) {
	posicion.x = px;
	posicion.y = py;
}

void Enemigo::setVel(float vx, float vy) {
	velocidad.x = vx;
	velocidad.y = vy;
}