#pragma once
#include <string>
#include "Vector2D.h"

class Elemento
{
protected:
	bool Harmful;
	//bool Movil;
	//bool Estatico;
	std::string Path;
	Vector2D posicion;
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
public:
	Elemento() { ; }
	Elemento(bool harmful, std::string path): Harmful(harmful), Path(path){}
	virtual ~Elemento();
	bool isHarmful() { return Harmful; }
	void setHarmful(bool harm);
	void setPos(float px, float py);
	Vector2D getPos() { return posicion; }
	virtual void Dibuja();
	void setColor(unsigned char r, unsigned char g, unsigned char b);
};

