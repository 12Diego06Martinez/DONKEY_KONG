#pragma once
#include "ETSIDI.h"

class Pared
{
private:
	ETSIDI::Vector2D limite1;
	ETSIDI::Vector2D limite2;
	friend class Interaccion;
public:
	Pared();
	virtual ~Pared();
	void Dibuja();
	//Setters
	void setLimites(float x1, float y1, float x2, float y2);
	//Getters
	ETSIDI::Vector2D getLimite1() { return limite1; }
	ETSIDI::Vector2D getLimite2() { return limite2; }
};

