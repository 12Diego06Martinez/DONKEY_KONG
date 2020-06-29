#define _CRT_SECURE_NO_WARNINGS

#include "Escalera.h"
#include <cmath>
#include <string>

using namespace ETSIDI;

////////////////////////////////CONSTRUCTOR////////////////////////////////
Escalera::Escalera(bool harm, const char* p) {
	path = new char[strlen(p) + 1];
	strcpy(path, p);

	harmful = harm;
}

Escalera::~Escalera() {

}

/////////////////////////////////METODOS///////////////////////////////////
void Escalera::Dibuja() {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Diego/escalera_transparente.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1);		glVertex3f(limite1.x, limite1.y, 0);
	glTexCoord2d(1, 1);		glVertex3f(limite2.x, limite1.y, 0);
	glTexCoord2d(1, 0);		glVertex3f(limite2.x, limite2.y, 0);
	glTexCoord2d(0, 0);		glVertex3f(limite1.x, limite2.y, 0);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}

void Escalera::setLimites(float x1, float y1, float x2, float y2) {
	limite1.x = x1;
	limite1.y = y1;
	limite2.x = x2;
	limite2.y = y2;
}

void Escalera::Inicializa(float px, float py, float ancho, float alto) {
	posicion.x = px;
	posicion.y = py;
	limite1.x = px - ancho / 2;
	limite1.y = py - alto / 2;
	limite2.x = px + ancho / 2;
	limite2.y = py + alto / 2;
}

void Escalera::setPos(float px, float py) {
	posicion.x = px;
	posicion.y = py;
}

void Escalera::setPath(const char* p) {
	strcpy(path, p);
}

void Escalera::setHarmful(bool harm) {
	harmful = harm;
}

float Escalera::calculaDistancia(Vector2D vector1, Vector2D vector2) {
	//Para controlar la posicion del jugador respecto a la escalera lo hacemos
	//tomando como referencia la base de la escalera.
	//Creamos una variable auxiliar que tiene esta medida en cuenta
	float distancia;
	distancia = sqrt(pow(vector2.x - vector1.x, 2.0) + pow(vector2.y - vector1.y, 2.0));
	
	return distancia;
}