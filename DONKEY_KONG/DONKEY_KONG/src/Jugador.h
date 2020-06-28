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
	///////////////////
	bool isAligned;
	bool isDownStairs;
	bool isUpStairs;
	bool ableToUp;
	bool ableToDown;
	//////////////////
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
	void setSalto(bool salto);
	void Desplaza(float t);
	void Salto();
	void setReposo();
	void limitePared(Pared pared);
	ETSIDI::Vector2D getPos() { return posicion; }
	ETSIDI::Vector2D getVel() { return velocidad; }
	ETSIDI::Vector2D getAcel() { return aceleracion; }
	bool getSalto() { return saltoAllowed; }
	//////////////////////////////////////////////
	bool sobrePlataforma(Plataforma& plataforma);
	////////////////////////////////////////////
	bool detectaEscalera(Escalera& escalera);
	void limiteEscalera(Escalera& escalera);
	///////////////////////////////////////////
	
};
