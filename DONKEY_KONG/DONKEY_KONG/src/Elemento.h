#pragma once
#include "Vector2D.h"

class Elemento
{
protected:
	char *path;
	bool Harmful;
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
public:
	Elemento(bool harmful, const char* p);
	virtual ~Elemento();
	virtual void Dibuja()=0;
	void setColor(unsigned char r, unsigned char g, unsigned char b);
	void setHarmful(bool harm);
	bool isHarmful() { return Harmful; }
};