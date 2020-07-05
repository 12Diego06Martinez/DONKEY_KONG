#include "Coordinador.h"
#include "InteraccionListas.h"
#include "ETSIDI.h"

using namespace ETSIDI;
//////////////////////////////////////CONSTRUCTOR////////////////////////////////
Coordinador::Coordinador() {
	estado = MENU;
	miMundo.recargaNivel();
}

Coordinador::~Coordinador() {

}

//////////////////////////////////////METODOS///////////////////////////////////
void Coordinador::Dibuja() {
	if (estado == MENU) {
		multi.imprimeMenu();
		//multi.playMenu();
	}
	else if (estado == INSTRUCCIONES) {
		multi.imprimeInstrucciones();
	}
	else if (estado == JUEGO) {
		//multi.stopMenu();
		miMundo.dibujaNivel();
	}
	else if (estado == GAMEOVER) {
		//multi.stopMenu();
		multi.imprimeGameOver();
		miMundo.recargaNivel();
	}
	else if (estado == PAUSA) {
		//multi.stopMenu();
		miMundo.dibujaNivel();
		multi.imprimePausa();
	}
	else if (estado == GANA) {
		//multi.stopMenu();
		miMundo.dibujaNivel();
		setTextColor(1, 0, 0);
		setFont("fuentes/ARCADE_I.TTF", 18);
		printxy("ENHORABUENA", -5, 9);
		printxy("Has completado la desescalada", -2, 8);
	}
}

void Coordinador::Mueve() {
	if (estado == JUEGO) {
		miMundo.mueveNivel();
		
		if (miMundo.getVidas() == 0)
			estado = GAMEOVER;
		else if (miMundo.getValidacion()) {
			miMundo.subeNivel();
			if (miMundo.getNivel() <= 3) {
				miMundo.recargaNivel();
				miMundo.cargaNivel();
				estado = GANA;
			}
				
			if (miMundo.getNivel() > 3)
				estado = FIN;
		}	
	}
}

void Coordinador::TeclaEspecial(unsigned char key) {
	if (estado == JUEGO) {
		miMundo.flechasNivel(key);
	}
}

void Coordinador::Tecla(unsigned char key) {
	if (estado == MENU) {
		if (key == 'H' || key == 'h') {
			estado = INSTRUCCIONES;
		}
		else if (key == 'C' || key == 'c') {
			miMundo.cargaNivel();
			estado = JUEGO;
		}
		else if (key == 'S' || key == 's') {
			exit(0);
		}
	}

	else if (estado == INSTRUCCIONES) {
		if (key == 'C' || key == 'c') {
			miMundo.cargaNivel();
			estado = JUEGO;
		}
		if (key == 'H' || key == 'h') {
			estado = MENU;
		}
	}
	else if (estado == JUEGO) {
		miMundo.teclasNivel(key);
		if (key == 'P' || key == 'p') {
			estado = PAUSA;
		}
	}
	else if (estado == GAMEOVER) {
		if (key == 'C' || key == 'c') {
			miMundo.cargaNivel();
			estado = JUEGO;
		}
		else if (key == 'S' || key == 's') {
			exit(0);
		}
		else if (key == 'M' || key == 'm') {
			estado = MENU;
			miMundo.recargaNivel();
		}
	}
	else if (estado == PAUSA) {
		if (key == 'P' || key == 'p') {
			estado = JUEGO;
		}
		else if (key == 'M' || key == 'm') {
			estado = MENU;
			miMundo.recargaNivel();
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

