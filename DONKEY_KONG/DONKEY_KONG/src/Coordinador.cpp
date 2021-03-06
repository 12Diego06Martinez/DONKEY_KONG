#include "Coordinador.h"
#include "InteraccionListas.h"
#include "ETSIDI.h"

using namespace ETSIDI;
//////////////////////////////////////CONSTRUCTOR////////////////////////////////
Coordinador::Coordinador() {
	estado = MENU;
	multi.playMenu();
}

Coordinador::~Coordinador() {

}

//////////////////////////////////////METODOS///////////////////////////////////
void Coordinador::Dibuja() {
	if (estado == MENU) {
		multi.imprimeMenu();
		miMundo.recargaNivel();
	}
	else if (estado == INSTRUCCIONES) {
		multi.imprimeInstrucciones();
	}
	else if (estado == JUEGO) {
		miMundo.dibujaNivel();
		multi.playNivel();
	}
	else if (estado == GAMEOVER) {
		multi.imprimeGameOver();
		miMundo.recargaNivel();
	}
	else if (estado == PAUSA) {
		multi.playNivel();
		miMundo.dibujaNivel();
		multi.imprimePausa();
	}
	else if (estado == FIN) {
		multi.imprimeVictoria();
	}
}

void Coordinador::Mueve() {
	if (estado == JUEGO) {
		miMundo.mueveNivel();
		
		if (miMundo.getVidas() == 0) {
			estado = GAMEOVER;
		}
			
		if (miMundo.getValidacion()) {
			if (miMundo.getNivel() <= 2) {
				miMundo.subeNivel();
				miMundo.recargaNivel();
				miMundo.cargaNivel();
				multi.playPasaNivel();
				estado = JUEGO;
			}
				
			if (miMundo.getNivel() > 2) {
				estado = FIN;
			}
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
			multi.playNivel();
			estado = JUEGO;
		}
		if (key == 'H' || key == 'h') {
			estado = MENU;
		}
	}
	else if (estado == JUEGO) {
		multi.playNivel();
		miMundo.teclasNivel(key);
		if (key == 'P' || key == 'p') {
			estado = PAUSA;
		}
	}
	else if (estado == GAMEOVER) {
		if (key == 'C' || key == 'c') {
			miMundo.cargaNivel();
			//multi.playNivel();
			estado = JUEGO;
		}
		else if (key == 'S' || key == 's') {
			exit(0);
		}
		else if (key == 'M' || key == 'm') {
			multi.playMenu();
			estado = MENU;
		}
	}
	else if (estado == PAUSA) {
		if (key == 'P' || key == 'p') {
			//multi.playNivel();
			estado = JUEGO;
		}
		else if (key == 'M' || key == 'm') {
			multi.playMenu();
			estado = MENU;
		}
	}
	else if (estado == FIN) {
		if (key == 'M' || key == 'm') {
			//miMundo.recargaNivel();
			multi.playMenu();
			estado = MENU;
		}
		else if (key == 'S' || key == 's') {
			exit(0);
		}
	}
}

