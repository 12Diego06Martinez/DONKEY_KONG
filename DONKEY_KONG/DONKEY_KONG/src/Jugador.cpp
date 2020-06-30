#define _CRT_SECURE_NO_WARNINGS

#include "Jugador.h"
#include <string>
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
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/mario_pie_dcha.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1);		glVertex2d(-1, 0);
	glTexCoord2d(1, 1);		glVertex2d(1, 0);
	glTexCoord2d(1, 0);		glVertex2d(1, 1);
	glTexCoord2d(0, 0);		glVertex2d(-1, 1);
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

bool Jugador::sobrePlataforma(Plataforma plataforma) {
	//Detecta si el jugador está sobre una plataforma
	//+0.00000006
	if (posicion.y <= plataforma.getPos().y) {
		posicion.y = plataforma.getPos().y;
		isOnPlatform = true;
	}
		
	else
		isOnPlatform = false;

	return isOnPlatform;
}

bool Jugador::detectaEscalera(Escalera escalera) {
	float distancia = escalera.calculaDistancia(escalera.getPos(), posicion);
	if (distancia > 1.999 && distancia < 2.004) {
		isInLadder = true;
	}
	else
		isInLadder = false;

	return isInLadder;
}

//bool Jugador::detectaEscaleraAbajo(Escalera escalera) {
//	//Detecta cuando el jugador está en línea con la escalera para subir
//	float distancia = escalera.calculaDistancia(escalera.getPos(), posicion);
//	if (distancia > 1.849 && distancia < 1.852) {
//		isUnderLadder = true;
//	}
//	else
//		isUnderLadder = false;
//	
//	return isUnderLadder;
//}
//
//bool Jugador::detectaEscaleraArriba(Escalera escalera) {
//	//Detecta cuando el jugador está en línea con la escalera para bajar
//	float distancia = escalera.calculaDistancia(escalera.getPos(), posicion);
//	if (distancia > 2.149 && distancia < 2.152) {
//		isAboveLadder = true;
//	}
//	else
//		isAboveLadder = false;
//
//	return isAboveLadder;
//}

void Jugador::limiteEscalera(Escalera escalera) {

	float y_max = escalera.getLimite2().y;
	float y_min = escalera.getLimite1().y;

	if (posicion.y > y_max && isAligned == true) {
		isUpStairs = true;
		setPos(posicion.x, y_max);
	}
		
	else if (posicion.y < y_min && isAligned == true) {
		isDownStairs = true;
		setPos(posicion.x, y_min);
	}
		
	else {
		isUpStairs = false;
		isDownStairs = false;
	}
}