#pragma once
#include "Vector2D.h"

class Plataforma
{
private:
	float alto;
	float largo;
	Vector2D posicion;
public:
	Plataforma();
	virtual ~Plataforma();
	void Dibuja();
	void setPos(float, float);
	void setSize(float, float);
};

