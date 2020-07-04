#include "GestorMultimedia.h"
#include "ETSIDI.h"

using namespace ETSIDI;

//////////////////////////////////////METODOS//////////////////////////////
void GestorMultimedia::imprimeMenu() {
	gluLookAt(0, 7.5, 30,
		0.0, 7.5, 0.0,
		0.0, 1.0, 0.0);

	setTextColor(1, 1, 0);
	setFont("fuentes/ARCADE_I.TTF", 25);
	printxy("BIENVENIDO", -5, 10);
	printxy("DONKEY KONG COVID", -8.8, 8.5);
	printxy("LA DESESCALADA", -7, 6.5);
	setFont("fuentes/ARCADE_I.TTF", 10);
	printxy("Pulse -C- para jugar", -4, 5);
	printxy("Pulse -H- para ayuda", -4, 4.75);
}

void GestorMultimedia::imprimeInstrucciones() {
	gluLookAt(0, 7.5, 30,
		0.0, 7.5, 0.0,
		0.0, 1.0, 0.0);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Instrucciones.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1);		glVertex3f(-14, 0, -0.1);
	glTexCoord2d(1, 1);		glVertex3f(14, 0, -0.1);
	glTexCoord2d(1, 0);		glVertex3f(14, 15, -0.1);
	glTexCoord2d(0, 0);		glVertex3f(-14, 15, -0.1);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}

void GestorMultimedia::imprimeGameOver() {
	gluLookAt(0, 7.5, 30,
		0.0, 7.5, 0.0,
		0.0, 1.0, 0.0);
	setTextColor(1, 1, 0);
	setFont("fuentes/invaders.ttf", 20);
	printxy("f", 0, 10);
	setFont("fuentes/ARCADE_I.TTF", 25);
	printxy("LOSER", -2, 9);
	printxy("TRY AGAIN", -3, 8);
	setFont("fuentes/ARCADE_I.TTF", 10);
	printxy("Pulse -C- para reintentarlo", -7, 7);
	printxy("Pulse -M- para volver al menu", -6.5, 6);
}

void GestorMultimedia::imprimePausa() {
	setTextColor(1, 1, 0);
	setFont("fuentes/ARCADE_I.TTF", 22);
	printxy("PAUSE", -2.5, 9);
	setFont("fuentes/ARCADE_I.TTF", 10);
	printxy("Pulse -P- para reaunudar la partida", -7, 8);
	printxy("Pulse -M- para volver al menu", -6.5, 7);
}