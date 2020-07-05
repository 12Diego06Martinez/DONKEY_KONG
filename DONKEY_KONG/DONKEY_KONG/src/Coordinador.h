#pragma once
#include "GestorNiveles.h"
#include "GestorMultimedia.h"

class Coordinador
{
private:
	enum Pantallas{MENU, INSTRUCCIONES, JUEGO, GAMEOVER, PAUSA, NEXT, FIN};
	Pantallas estado;
	GestorNiveles miMundo;
	GestorMultimedia multi;
public:
	Coordinador();
	virtual ~Coordinador();
	void Dibuja();
	void Mueve();
	void Tecla(unsigned char key);
	void TeclaEspecial(unsigned char key);
};

