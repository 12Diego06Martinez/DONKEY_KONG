#pragma once
#include <ETSIDI.h>
#include "Globales.h"

class Enemigo {
private:
	enemigo_t estado;
	const char* path;
	float ancho;
	float alto;
	ETSIDI::Vector2D posicion;
	ETSIDI::Vector2D velocidad;
	ETSIDI::Vector2D limite1;
	ETSIDI::Vector2D limite2;
public:
	Enemigo(){}
	Enemigo(float px, float py, float ancho, float alto);
	virtual ~Enemigo();
	void Dibuja();
	void Mueve(float t);
	int generaAleatorio();
	//Setters
	void setPos(float px, float py);
	void setVel(float vx, float vy);
	//Getters
	ETSIDI::Vector2D getPos() { return posicion; }
	ETSIDI::Vector2D getVel() { return velocidad; }
	ETSIDI::Vector2D getLimite1() { return limite1; }
	ETSIDI::Vector2D getLimite2() { return limite2; }
	ETSIDI::Vector2D getSize() { return limite2-limite1; }
};
