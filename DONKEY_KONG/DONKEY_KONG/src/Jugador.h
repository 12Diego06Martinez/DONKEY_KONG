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
	bool isAligned;
	bool isAboveLadder;
	bool isUnderLadder;
	bool isDownStairs;
	bool isUpStairs;
	bool isInLadder;
	ETSIDI::Vector2D posicion;
	ETSIDI::Vector2D velocidad;
	ETSIDI::Vector2D aceleracion;
	friend class Interaccion;
public:
	Jugador();
	virtual ~Jugador();
	void Dibuja();
	void Mueve(float t);
	void setPath(const char* p);
	void setPos(float px, float py);
	void setVel(float vx, float vy);
	void setAcel(float ax, float ay);
	void setSalto(bool salto) { saltoAllowed = salto; }
	void setUpStairs(bool up) { isUpStairs = up; }
	void setAligned(bool aligned) { isAligned = aligned; }
	void setReposo();
	void limiteEscalera(Escalera escalera);
	ETSIDI::Vector2D getPos() { return posicion; }
	ETSIDI::Vector2D getVel() { return velocidad; }
	ETSIDI::Vector2D getAcel() { return aceleracion; }
	bool getSalto() { return saltoAllowed; }
	bool getAligned() { return isAligned; }
	bool getDownStairs() { return isDownStairs; }
	bool getUpStairs() { return isUpStairs; }
};
