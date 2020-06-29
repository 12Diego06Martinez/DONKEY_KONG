#define _CRT_SECURE_NO_WARNINGS

#include "Plataforma.h"
#include <string>

using namespace ETSIDI;

/////////////////////////////////////CONSTRUCTOR//////////////////////////
Plataforma::Plataforma(bool harm, const char* p) {
	path = new char[strlen(p) + 1];
	strcpy(path, p);

	harmful = harm;
}

Plataforma::~Plataforma() {

}

///////////////////////////////////METODOS////////////////////////////////
void Plataforma::Dibuja() {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture(path).id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1);		glVertex3f(limite1.x, limite1.y, 0);
	glTexCoord2d(1, 1);		glVertex3f(limite2.x, limite1.y, 0);
	glTexCoord2d(1, 0);		glVertex3f(limite2.x, limite2.y, 0);
	glTexCoord2d(0, 0);		glVertex3f(limite1.x, limite2.y, 0);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}

void Plataforma::setLimites(float x1, float y1, float x2, float y2) {
	limite1.x = x1;
	limite1.y = y1;
	limite2.x = x2;
	limite2.y = y2;
}

void Plataforma::Inicializa(float px, float py, float ancho, float alto, const char* p) {
	posicion.x = px;
	posicion.y = py;
	limite1.x = px - ancho / 2;
	limite1.y = py - alto / 2;
	limite2.x = px + ancho / 2;
	limite2.y = py + alto / 2;
	path = new char[strlen(p) + 1];
	strcpy(path, p);
}

void Plataforma::setPos(float px, float py) {
	posicion.x = px;
	posicion.y = py;
}

void Plataforma::setPath(const char* p) {
	strcpy(path, p);
}

void Plataforma::setHarmful(bool harm) {
	harmful = harm;
}

float Plataforma::calculaDistancia(Vector2D vector1, Vector2D vector2) {
	float distancia;
	distancia = sqrt(pow(vector2.x - vector1.x, 2.0) + pow(vector2.y - vector1.y, 2.0));
	
	return distancia;
}