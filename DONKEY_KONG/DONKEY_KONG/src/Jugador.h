#pragma once
#include "ElementoMovil.h"


class Jugador:public ElementoMovil
{
private:
	bool isOnPlatform;
	bool saltoAllowed;
	bool isGoingUp;
	bool isGoingDown;
	bool isFalling;
	ETSIDI::Vector2D aceleracion;
	friend class Interaccion;
public:
	Jugador();
	virtual ~Jugador();
	virtual void Mueve(float t);
	//Setters
	void setAcel(float ax, float ay);
	void setSalto(bool salto) { saltoAllowed = salto; }
	void setUp(bool up) { isGoingUp = up; }
	void setDown(bool down) { isGoingDown = down; }
	void setFalling(bool falling) { isFalling = falling; }
	void setPlatform(bool platform) { isOnPlatform = platform; }
	//Getters
	ETSIDI::Vector2D getAcel() { return aceleracion; }
	bool getSalto() { return saltoAllowed; }
	bool getUp() { return isGoingUp; }
	bool getDown() { return isGoingDown; }
	bool getFalling() { return isFalling; }
};
