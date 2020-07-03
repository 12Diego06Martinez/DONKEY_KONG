#include "Coordinador.h"
#include "ETSIDI.h"

using namespace ETSIDI;
//////////////////////////////////////CONSTRUCTOR////////////////////////////////
Coordinador::Coordinador() {
	estado = MENU;
}

Coordinador::~Coordinador() {

}

//////////////////////////////////////METODOS///////////////////////////////////
void Coordinador::Dibuja() {
	if (estado == MENU) {
		gluLookAt(0, 7.5, 30,
			0.0, 7.5, 0.0,
			0.0, 1.0, 0.0);
		
		setTextColor(1, 0, 0);
		setFont("fuentes/arcade_classic.ttf", 80);
		//setJustificacion(ETSIDI::CENTRO, ETSIDI::LINEA_BASE);
		printxy("BIENVENIDO", -5, 9);
		printxy("DONKEY KONG COVID", -7,8);
		setFont("fuentes/Arcade Boxex.ttf", 30);
		printxy("Pulse -C- para continuar", -2, 7);
		
	}
	else if (estado == INSTRUCCIONES) {
		gluLookAt(0, 7.5, 30,
			0.0, 7.5, 0.0,
			0.0, 1.0, 0.0);

		setTextColor(1, 0, 0);
		setFont("fuentes/game_over.ttf", 40);
		printxy("INSTRUCCIONES", -10, 8);
	}
	else if (estado == JUEGO) {
		miMundo.Dibuja();
	}
	else if (estado == GAMEOVER) {
		gluLookAt(0, 7.5, 30,
			0.0, 7.5, 0.0,
			0.0, 1.0, 0.0);
		setTextColor(1, 0, 0);
		setFont("fuentes/invader.ttf", 20);
		printxy("f", 10, -2);
		setFont("fuentes/my game.ttf", 18);
		printxy("LOSER", -5, 6);
		printxy("TRY AGAIN", -5, 5);
	}
	else if (estado == PAUSA) {
		//miMundo.Dibuja();
		setTextColor(1, 0, 0);
		setFont("fuentes/my game.ttf", 18);
		printxy("PAUSE", -2, 8);
	}
	else if (estado == GANA) {
		miMundo.Dibuja();
		setTextColor(1, 0, 0);
		setFont("fuentes/my game.ttf", 18);
		printxy("ENHORABUENA", -5, 9);
		printxy("Has completado la desescalada", -2, 8);
	}
}

void Coordinador::Mueve() {
	if (estado == JUEGO) {
		miMundo.Mueve();
		
	}
}

void Coordinador::TeclaEspecial(unsigned char key) {
	if (estado == JUEGO) {
		miMundo.TeclaEspecial(key);
	}
}

void Coordinador::Tecla(unsigned char key) {
	if (estado == MENU) {
		if (key == 'C' || key == 'c') {
			estado = INSTRUCCIONES;
		}
	}

	else if (estado == INSTRUCCIONES) {
		if (key == 'C' || key == 'c') {
			miMundo.Inicializa();
			estado = JUEGO;
		}
	}
	else if (estado == JUEGO) {
		miMundo.Tecla(key);
		if (key == 'P' || key == 'p') {
			estado = PAUSA;
		}
	}
	else if (estado == GAMEOVER) {
		if (key == 'C' || key == 'c') {
			estado = JUEGO;
		}
		else if (key == 'S' || key == 's') {
			exit(0);
		}
	}
	else if (estado == PAUSA) {
		if (key == 'C' || key == 'c') {
			estado = JUEGO;
		}
		else if (key == 'E' || key == 'e') {
			estado = MENU;
		}
	}
	else if (estado == GANA) {
		if (key == 'C' || key == 'c') {
			estado = JUEGO;
		}
		else if (key == 'E' || key == 'e') {
			estado = MENU;
		}
		else if (key == 'S' || key == 's') {
			exit(0);
		}
	}
}

