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
	bool isOnTop;
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
	void limitePlataforma(Plataforma& plataforma);
	bool limiteEscalera(Escalera& escalera);
	bool detectaEscalera(Escalera& escalera);
	bool sobrePlataforma(Plataforma& plataforma);

};
