#include "Jugador.h"
#include "glut.h"

using namespace ETSIDI;

//////////////////////////////////////CONSTRUCTOR////////////////////////
Jugador::Jugador() {

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
	//Movimiento rectilineo unirforme
	posicion = posicion + velocidad *t + aceleracion * (0.5 * t * t);
	velocidad = velocidad + aceleracion * t;
}

void Jugador::Salto() {
		setVel(velocidad.x, 5.0f);
		while (posicion.y > 1.0f) {
			setVel(velocidad.x, -5.0f);
		}
		if (posicion.y == -1.85f)
			setVel(velocidad.x, 0);
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

void Jugador::setSalto(bool salto) {
	saltoAllowed = salto;
}

void Jugador::setUpStairs(bool up) {
	isUpStairs = up;
}

void Jugador::setAligned(bool aligned) {
	isAligned = aligned;
}

void Jugador::setReposo() {
	setVel(0.0f, 0.0f);
}

void Jugador::limitePared(Pared pared){
	if (posicion.x > pared.getLimite2().x)
		posicion.x = pared.getLimite2().x;
	if (posicion.x < pared.getLimite1().x)
		posicion.x = pared.getLimite1().x;
}

bool Jugador::sobrePlataforma(Plataforma plataforma) {
	//Detecta si el jugador está sobre una plataforma
	if (posicion.y <= plataforma.getLimite2().y) {
		posicion.y = plataforma.getLimite2().y;
		isOnPlatform = true;
	}
		
	else
		isOnPlatform = false;

	return isOnPlatform;
}

bool Jugador::detectaEscalera(Escalera escalera) {
	//Detecta cuando el jugador está en línea con la escalera
	float distancia = escalera.calculaDistancia(escalera.getPos(), posicion);
	if (distancia > 1.849 && distancia < 1.855) {
		isDownStairs = true;
	}
	else
		isDownStairs = false;
	
	return isDownStairs;
}

bool Jugador::arribaEscalera(Escalera escalera) {

	float y_max = escalera.getLimite2().y;

	if (posicion.y > y_max && isAligned==true)
		isUpStairs = true;
	else
		isUpStairs = false;

	return isUpStairs;
}

