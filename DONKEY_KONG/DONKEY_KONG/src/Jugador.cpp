#include "Jugador.h"
#include "Paths.h"
#include "ETSIDI.h"
#include "glut.h"

//////////////////////////////////////CONSTRUCTOR////////////////////////
Jugador::Jugador() {
	isOnLadder = false;
}

Jugador::~Jugador() {

}
//////////////////////////////////////METODOS///////////////////////////
void Jugador::Dibuja() {

	glEnable(GL_TEXTURE_2D);
	glTranslatef(posicion.x, posicion.y, 0);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/mario_transparent.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1);		glVertex2d(-0.5, 0);
	glTexCoord2d(1, 1);		glVertex2d(0.5, 0);
	glTexCoord2d(1, 0);		glVertex2d(0.5, 1);
	glTexCoord2d(0, 0);		glVertex2d(-0.5, 1);
	glEnd();
	glTranslatef(-posicion.x, -posicion.y, 0);
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

void Jugador::Interaccion(Plataforma& plataforma) {
	float x_max = plataforma.getPos().x + plataforma.getSize().x;
	float x_min = plataforma.getPos().x - plataforma.getSize().x;
	float y_max = plataforma.getPos().y + plataforma.getSize().y;
	//float y_min = plataforma.getPos().y - plataforma.getAlto();

	if (posicion.x > x_max && posicion.y < y_max)
		posicion.x = x_max;
	if (posicion.x < x_min && posicion.y < y_max)
		posicion.x = x_min;
}

bool Jugador::Interaccion(Escalera& escalera) {
	float x_max = escalera.getPos().x + escalera.getSize().x;
	float x_min = escalera.getPos().x - escalera.getSize().x;
	float y_max = escalera.getPos().y + escalera.getSize().y + 0.3;
	float y_min = escalera.getPos().y - escalera.getSize().y;
	
	if (posicion.x > x_min && posicion.x < x_max)
		isOnLadder = true;
	if (posicion.y >= y_min && posicion.y < y_max)
		isOnLadder = true;
	else
		isOnLadder = false;

	return isOnLadder;
}