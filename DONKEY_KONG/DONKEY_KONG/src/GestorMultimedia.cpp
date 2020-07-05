#include "GestorMultimedia.h"
#include "ETSIDI.h"

using namespace ETSIDI;

//////////////////////////////////////METODOS//////////////////////////////
void GestorMultimedia::imprimeMenu() {
	gluLookAt(0, 7.5, 30,
		0.0, 7.5, 0.0,
		0.0, 1.0, 0.0);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Menu.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1);		glVertex3f(-16, 0, -0.1);
	glTexCoord2d(1, 1);		glVertex3f(16, 0, -0.1);
	glTexCoord2d(1, 0);		glVertex3f(16, 16, -0.1);
	glTexCoord2d(0, 0);		glVertex3f(-16, 16, -0.1);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
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
	glTexCoord2d(0, 1);		glVertex3f(-16, 0, -0.1);
	glTexCoord2d(1, 1);		glVertex3f(16, 0, -0.1);
	glTexCoord2d(1, 0);		glVertex3f(16, 16, -0.1);
	glTexCoord2d(0, 0);		glVertex3f(-16, 16, -0.1);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}

void GestorMultimedia::imprimeGameOver() {
	gluLookAt(0, 7.5, 30,
		0.0, 7.5, 0.0,
		0.0, 1.0, 0.0);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/GameOver.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1);		glVertex3f(-16, 0, -0.1);
	glTexCoord2d(1, 1);		glVertex3f(16, 0, -0.1);
	glTexCoord2d(1, 0);		glVertex3f(16, 16, -0.1);
	glTexCoord2d(0, 0);		glVertex3f(-16, 16, -0.1);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}

void GestorMultimedia::imprimePausa() {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Pause.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1);		glVertex3f(-16, 0, 0.1);
	glTexCoord2d(1, 1);		glVertex3f(16, 0, 0.1);
	glTexCoord2d(1, 0);		glVertex3f(16, 16, 0.1);
	glTexCoord2d(0, 0);		glVertex3f(-16, 16, 0.1);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}

void GestorMultimedia::imprimeVictoria() {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Victoria.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1);		glVertex3f(-16, 0, 0.1);
	glTexCoord2d(1, 1);		glVertex3f(16, 0, 0.1);
	glTexCoord2d(1, 0);		glVertex3f(16, 16, 0.1);
	glTexCoord2d(0, 0);		glVertex3f(-16, 16, 0.1);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}

void GestorMultimedia::playLose() {
	play("sonidos/pierde.wav");
}

void GestorMultimedia::playSalto() {
	play("sonidos/salto.wav");
}

void GestorMultimedia::playSube() {
	play("sonidos/subir.wav");
}

void GestorMultimedia::playBaja() {
	play("sonidos/bajar.wav");
}

void GestorMultimedia::playMenu() {
	playMusica("sonidos/MainMenu.mp3", true);
}

void GestorMultimedia::stopMenu() {
	stopMusica();
}