#pragma once
#include "Mundo.h"
#include "GestorMultimedia.h"

class Coordinador
{
private:
	Mundo miMundo;
	enum Pantallas{MENU, INSTRUCCIONES, JUEGO, GAMEOVER, PAUSA, GANA, FIN};
	Pantallas estado;
	bool pasar_nivel;
	int monedas_recogidas;
	GestorMultimedia multi;
public:
	Coordinador();
	virtual ~Coordinador();
	void Dibuja();
	void Mueve();
	void Tecla(unsigned char key);
	void TeclaEspecial(unsigned char key);
};

