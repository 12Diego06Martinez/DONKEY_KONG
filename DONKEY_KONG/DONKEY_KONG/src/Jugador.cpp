#define _CRT_SECURE_NO_WARNINGS

#include "Jugador.h"
#include <string>
#include "glut.h"

using namespace ETSIDI;

//////////////////////////////////////CONSTRUCTOR////////////////////////
Jugador::Jugador() {
	ancho = 1;
	alto = 1;
}

Jugador::~Jugador() {

}
//////////////////////////////////////METODOS///////////////////////////
void Jugador::Dibuja() {
	glEnable(GL_TEXTURE_2D);
	glTranslatef(posicion.x, posicion.y, 0);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/mario pie dcha transparente.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1);		glVertex3f(-0.5, 0, 0);
	glTexCoord2d(1, 1);		glVertex3f(0.5, 0, 0);
	glTexCoord2d(1, 0);		glVertex3f(0.5, 1, 0);
	glTexCoord2d(0, 0);		glVertex3f(-0.5, 1, 0);
	glEnd();
	glTranslatef(-posicion.x, -posicion.y, 0);
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}

void Jugador::Mueve(float t) {
	//Movimiento rectilineo unirformemente acelerado
	posicion = posicion + velocidad *t + aceleracion * (0.5 * t * t);
	velocidad = velocidad + aceleracion * t;
}

void Jugador::setPath(const char* p) {
	path = new char[strlen(p) + 1];
	strcpy(path, p);
}

void Jugador::setPos(float px, float py) {
	posicion.x = px;
	posicion.y = py;
}

void Jugador::setVel(float vx, float vy) {
	velocidad.x = vx;
	velocidad.y = vy;
}

void Jugador::setAcel(float ax, float ay) {
	aceleracion.x = ax;
	aceleracion.y = ay;
}

void Jugador::setReposo() {
	setVel(0.0f, 0.0f);
}
