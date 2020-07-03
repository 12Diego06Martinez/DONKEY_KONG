#pragma once
#include "ElementoMovil.h"


class Enemigo:public ElementoMovil 
{
private:
	enum enemigo_t { NORMAL, VULNERABLE};
	enemigo_t estado;
	friend class Interaccion;
public:
	Enemigo(float px, float py, const char* p = "imagenes/enemy_dcha.png");
	virtual ~Enemigo();
	virtual void Mueve(float t);
	void generaAleatorio();
};
