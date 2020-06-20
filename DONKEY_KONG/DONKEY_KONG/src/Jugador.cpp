#include "Jugador.h"
#include "Paths.h"
#include "ETSIDI.h"
#include "glut.h"

//////////////////////////////////////CONSTRUCTOR////////////////////////
Jugador::Jugador() {
	largo = 1;
	alto = 2;
	
}

Jugador::~Jugador() {

}
//////////////////////////////////////METODOS///////////////////////////
void Jugador::Dibuja() {

	glDisable(GL_LIGHTING);
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3ub(255, 0, 255);
	glBegin(GL_POLYGON);
	glVertex2d(x + largo / 2, y + alto / 2);
	glVertex2d(x - largo / 2, y + alto / 2);
	glVertex2d(x - largo / 2, y - alto / 2);
	glVertex2d(x + largo / 2, y - alto / 2);
	glEnd();
	glTranslatef(-posicion.x, -posicion.y, 0);
	glEnable(GL_LIGHTING);
}

void Jugador::cargaTextura() {

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/mario_right.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1);		glVertex3f(-10, 0, -0.1);
	glTexCoord2d(1, 1);		glVertex3f(10, 0, -0.1);
	glTexCoord2d(1, 0);		glVertex3f(10, 15, -0.1);
	glTexCoord2d(0, 0);		glVertex3f(-10, 15, -0.1);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}

void Jugador::Mueve(float t) {
	//Ecuaciones del movimiento
	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;
}

void Jugador::setPos(float px, float py) {
	posicion.x = px;
	posicion.y = py;
}

void Jugador::setVel(float vx, float vy) {
	velocidad.x = vx;
	velocidad.y = vy;
}

void Jugador::setSize(float w, float h) {
	largo = w;
	alto = h;
}

void Jugador::setCentro(float cx, float cy) {
	x = cx;
	y = cy;
}