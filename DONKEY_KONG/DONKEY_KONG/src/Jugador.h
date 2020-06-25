#pragma once
#include "Vector2D.h"
#include "Plataforma.h"
#include "Escalera.h"

class Jugador
{
private:
	char* path;
	bool isOnLadder;
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
public:
	Jugador();
	virtual ~Jugador();
	void Dibuja();
	void setPos(float px, float py);
	void setVel(float vx, float vy);
	void Mueve(float t);
	void Interaccion(Plataforma& plataforma);
	bool Interaccion(Escalera& escalera);
};
