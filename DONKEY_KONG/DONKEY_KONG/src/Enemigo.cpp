#define  _CRT_SECURE_NO_WARNINGS	

#include "Enemigo.h"

using namespace ETSIDI;

////////////////////////////////////CONSTRUCTOR///////////////////////////
Enemigo::Enemigo(float px, float py) {
	alto = ancho = 0.5f;
	velocidad.x = 8.0f;
	posicion.x = px;
	posicion.y = py;
}

Enemigo::~Enemigo() {

}

//////////////////////////////////////METODOS/////////////////////////////
void Enemigo::Dibuja() {
	glEnable(GL_TEXTURE_2D);
	glTranslatef(posicion.x, posicion.y, 0);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/enemy_dcha.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1);		glVertex3f(-0.35, 0, 0);
	glTexCoord2d(1, 1);		glVertex3f(0.35, 0, 0);
	glTexCoord2d(1, 0);		glVertex3f(0.35, 0.35, 0);
	glTexCoord2d(0, 0);		glVertex3f(-0.35, 0.35, 0);
	glEnd();
	glTranslatef(-posicion.x, -posicion.y, 0);
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}

void Enemigo::Mueve(float t) {
	//No va a caer ni nada->MRU
	posicion = posicion + velocidad * t;
}

void Enemigo::generaAleatorio() {
	int num=lanzaDado(200.0);
	if (num <25)
		setVel(8.0f, 0.0f);
	else
		setVel(-8.0f, 0.0f);
}

void Enemigo::setPos(float px, float py) {
	posicion.x = px;
	posicion.y = py;
}

void Enemigo::setVel(float vx, float vy) {
	velocidad.x = vx;
	velocidad.y = vy;
}