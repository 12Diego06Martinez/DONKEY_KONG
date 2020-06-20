#pragma once
#include "Vector2D.h"	
#include <string>

class Jugador
{
private:
	std::string path;
	float x;
	float y;
	float largo;
	float alto;
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
public:
	Jugador();
	virtual ~Jugador();
	void setPos(float px, float py);
	void setVel(float vx, float vy);
	void setSize(float w, float h);
	void setCentro(float cx, float cy);
	void Mueve(float t);
	void Dibuja();
	void cargaTextura();
};