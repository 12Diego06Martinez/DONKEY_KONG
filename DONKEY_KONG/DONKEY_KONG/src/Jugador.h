#pragma once
#include "ETSIDI.h"
#include "Plataforma.h"
#include "Escalera.h"
#include "Pared.h"

class Jugador
{
private:
	char* path;
	bool isOnPlatform;
	bool saltoAllowed;
	bool isGoingUp;
	bool isGoingDown;
	ETSIDI::Vector2D posicion;
	ETSIDI::Vector2D velocidad;
	ETSIDI::Vector2D aceleracion;
	friend class Interaccion;
public:
	Jugador();
	virtual ~Jugador();
	void Dibuja();
	void Mueve(float t);
	//Setters
	void setPath(const char* p);
	void setPos(float px, float py);
	void setVel(float vx, float vy);
	void setAcel(float ax, float ay);
	void setSalto(bool salto) { saltoAllowed = salto; }
	void setUp(bool up) { isGoingUp = up; }
	void setDown(bool down) { isGoingDown = down; }
	void setReposo();
	//Getters
	ETSIDI::Vector2D getPos() { return posicion; }
	ETSIDI::Vector2D getVel() { return velocidad; }
	ETSIDI::Vector2D getAcel() { return aceleracion; }
	bool getSalto() { return saltoAllowed; }
	//bool getAligned() { return isAligned; }
	//bool getDownStairs() { return isDownStairs; }
	//bool getUpStairs() { return isUpStairs; }
};
