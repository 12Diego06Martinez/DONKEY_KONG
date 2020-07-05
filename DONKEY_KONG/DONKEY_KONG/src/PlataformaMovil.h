#pragma once
#include "Plataforma.h"

class PlataformaMovil:public Plataforma
{
private:
	ETSIDI::Vector2D velocidad;
public:
	PlataformaMovil(float px, float py, float ancho, float alto, const char* path) :Plataforma(px, py, ancho, alto, path) {}
	void Mueve(float t);
	void setVel(float vx, float vy);
};

