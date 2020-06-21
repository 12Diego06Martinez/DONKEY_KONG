#pragma once
#include <string>
#include "Vector2D.h"

class Elemento
{
protected:
	bool Harmful;
	float alto;
	float largo;
	std::string Path;
	Vector2D posicion;
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
public:
	Elemento(bool harmful):Harmful(harmful) {}
	Elemento(bool harmful, std::string path): Harmful(harmful), Path(path){}
	virtual ~Elemento();
	virtual void Dibuja() = 0;
	void setColor(unsigned char r, unsigned char g, unsigned char b);
	void setHarmful(bool harm);
	void setPos(float px, float py);
	void setSize(float width, float height);
	bool isHarmful() { return Harmful; }
	Vector2D getCentro();
	Vector2D getPos() { return posicion; }
};