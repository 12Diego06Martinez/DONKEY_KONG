#pragma once
#include "ETSIDI.h"
#include "Plataforma.h"
#include "Escalera.h"

class Jugador
{
private:
	char* path;
	bool isOnLadder;
	bool isOnPlatform;
	ETSIDI::Vector2D posicion;
	ETSIDI::Vector2D velocidad;
	ETSIDI::Vector2D aceleracion;
public:
	Jugador();
	virtual ~Jugador();
	void Dibuja();
	void setPos(float px, float py);
	void setVel(float vx, float vy);
	void setAcel(float ax, float ay);
	void Desplaza(float t);
	void Salto(float t);
	void setReposo();
	ETSIDI::Vector2D getPos() { return posicion; }
	ETSIDI::Vector2D getVel() { return velocidad; }
	ETSIDI::Vector2D getAcel() { return aceleracion; }
	void Interaccion(Plataforma& plataforma);
	bool Interaccion(Escalera& escalera);
	bool LimitePlataforma(Plataforma& plataforma);
};
