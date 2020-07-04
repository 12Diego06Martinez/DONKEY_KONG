#include "Coordinador.h"
#include "InteraccionListas.h"
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
		multi.imprimeMenu();
	}
	else if (estado == INSTRUCCIONES) {
		multi.imprimeInstrucciones();
	}
	else if (estado == JUEGO) {
		miMundo.Inicializa();
		miMundo.Dibuja();
	}
	else if (estado == GAMEOVER) {
		gluLookAt(0, 7.5, 30,
			0.0, 7.5, 0.0,
			0.0, 1.0, 0.0);
		setTextColor(1, 1, 0);
		setFont("fuentes/invaders.ttf", 40);
		printxy("f", 0, 0);
		setFont("fuentes/ARCADE_I.TTF", 25);
		printxy("LOSER", -5, 9);
		printxy("TRY AGAIN", -8.75, 8);
		miMundo.~Mundo();
	}
	//else if (estado == PAUSA) {
	//	//miMundo.Dibuja();
	//	setTextColor(1, 0, 0);
	//	setFont("fuentes/ARCADE_I.TTF", 18);
	//	printxy("PAUSE", -2, 8);
	//}
	//else if (estado == GANA) {
	//	miMundo.Dibuja();
	//	setTextColor(1, 0, 0);
	//	setFont("fuentes/ARCADE_I.TTF", 18);
	//	printxy("ENHORABUENA", -5, 9);
	//	printxy("Has completado la desescalada", -2, 8);
	//}
}

void Coordinador::Mueve() {
	if (estado == JUEGO) {
		miMundo.Mueve();
		
		if (miMundo.getVidas() == 0)
			estado = GAMEOVER;
		else if (miMundo.getValidacion())
			estado = GANA;
	}
}

void Coordinador::TeclaEspecial(unsigned char key) {
	if (estado == JUEGO) {
		miMundo.TeclaEspecial(key);
	}
}

void Coordinador::Tecla(unsigned char key) {
	if (estado == MENU) {
		if (key == 'H' || key == 'h') {
			estado = INSTRUCCIONES;
		}
		else if (key == 'C' || key == 'c') {
			
			estado = JUEGO;
		}
	}

	else if (estado == INSTRUCCIONES) {
		if (key == 'C' || key == 'c') {
			//miMundo.Inicializa();
			estado = JUEGO;
		}
		if (key == 'H' || key == 'h') {
			estado = MENU;
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
			//miMundo.Inicializa();
			estado = JUEGO;
		}
		else if (key == 'S' || key == 's') {
			exit(0);
		}
		else if (key == 'M' || key == 'm') {
			estado = MENU;
		}
	}
	else if (estado == PAUSA) {
		if (key == 'P' || key == 'p') {
			estado = JUEGO;
		}
		else if (key == 'M' || key == 'm') {
			estado = MENU;
		}
	}
	else if (estado == GANA) {
		if (key == 'C' || key == 'c') {
			estado = JUEGO;
		}
		else if (key == 'M' || key == 'm') {
			estado = MENU;
		}
		else if (key == 'S' || key == 's') {
			exit(0);
		}
	}
}

