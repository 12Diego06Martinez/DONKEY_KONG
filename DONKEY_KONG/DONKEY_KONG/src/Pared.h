#pragma once
#include "ETSIDI.h"

class Pared
{
private:
	ETSIDI::Vector2D limite1;
	ETSIDI::Vector2D limite2;
public:
	Pared();
	virtual ~Pared();
	void Dibuja();
	void setLimites(float x1, float y1, float x2, float y2);
	ETSIDI::Vector2D getLimite1() { return limite1; }
	ETSIDI::Vector2D getLimite2() { return limite2; }
};

