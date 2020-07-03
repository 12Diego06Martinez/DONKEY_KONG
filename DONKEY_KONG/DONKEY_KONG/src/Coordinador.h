#pragma once
#include "Mundo.h"

class Coordinador
{
private:
	Mundo miMundo;
	enum Pantallas{MENU, INSTRUCCIONES, JUEGO, GAMEOVER, PAUSA, GANA};
	Pantallas estado;
public:
	Coordinador();
	virtual ~Coordinador();
	void Dibuja();
	void Mueve();
	void Tecla(unsigned char key);
	void TeclaEspecial(unsigned char key);
};

