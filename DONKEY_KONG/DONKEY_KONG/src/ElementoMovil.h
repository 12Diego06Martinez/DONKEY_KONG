#pragma once

#include <ETSIDI.h>

class ElementoMovil
{
protected:
	const char* path;
	float ancho;
	float alto;
	ETSIDI::Vector2D posicion;
	ETSIDI::Vector2D velocidad;
	ETSIDI::Vector2D limite1;
	ETSIDI::Vector2D limite2;
public:
	ElementoMovil() {}
	ElementoMovil(float px, float py, const char* p);
	virtual ~ElementoMovil();
	void Dibuja();
	virtual void Mueve(float t) = 0;
	//Setters
	void setPos(float px, float py);
	void setVel(float vx, float vy);
	void setPath(const char* p);
	//Getters
	ETSIDI::Vector2D getPos() { return posicion; }
	ETSIDI::Vector2D getVel() { return velocidad; }
};

