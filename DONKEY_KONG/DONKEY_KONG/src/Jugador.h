#pragma once
#include "Vector2D.h"
#include "Plataforma.h"
#include "Escalera.h"

class Jugador
{
private:
	char* path;
	bool isOnLadder;
	bool isOnPlatform;
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
public:
	Jugador();
	virtual ~Jugador();
	void Dibuja();
	void setPos(float px, float py);
	void setVel(float vx, float vy);
	void Desplaza(float t);
	void Salto(float t, float angulo);
	void setReposo();
	void Interaccion(Plataforma& plataforma);
	bool Interaccion(Escalera& escalera);
	bool LimitePlataforma(Plataforma& plataforma);
};
