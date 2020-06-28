#include "Jugador.h"
#include "glut.h"

using namespace ETSIDI;

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

void Jugador::Desplaza(float t) {
	//Movimiento a izquierda y derecha
	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;
}

void Jugador::Salto(float t) {
	
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
	//setAcel(0.0f, 0.0f);
}

void Jugador::limitePlataforma(Plataforma& plataforma) {

	if (posicion.x > plataforma.getLimite2().x)
		setVel(0.0f, 0.0f);
		//posicion.x = x_max;
	if (posicion.x < plataforma.getLimite1().x)
		setVel(0.0f, 0.0f);
		//posicion.x = x_min;
}

bool Jugador::limiteEscalera(Escalera& escalera) {

	if (posicion.y > escalera.getLimite2().y)
		isOnTop = true;

	else
		isOnTop = false;

	return isOnTop;
	//if (posicion.y > escalera.getLimite2().y) {
	//	setVel(0.0f, 0.0f);
	//	//setPos(posicion.x, escalera.getLimite2().y);
	//	//isOnLadder = false;
	//}
	
}

bool Jugador::detectaEscalera(Escalera& escalera) {
	//Detecta cuando el jugador está en línea con la escalera
	float x_max = escalera.getPos().x + escalera.getSize().x / 4;
	float x_min = escalera.getPos().x - escalera.getSize().x / 4;

	if (posicion.x > x_min && posicion.x < x_max) {
		isOnLadder = true;
	}
	else if (posicion.x<x_min || posicion.x>x_max) {
		isOnLadder = false;
	}

	return isOnLadder;
}

bool Jugador::sobrePlataforma(Plataforma& plataforma) {
	//Detecta si el jugador está sobre una plataforma
	if (posicion.y == plataforma.getLimite2().y)
		isOnPlatform = true;
	else
		isOnPlatform = false;
	
	return isOnPlatform;
}

