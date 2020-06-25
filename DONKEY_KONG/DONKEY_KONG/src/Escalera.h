#pragma once
#include "Vector2D.h"

class Escalera
{
private:
	char* path;
	bool harmful;
	Vector2D size;
	Vector2D posicion;
public:
	Escalera(){}
	Escalera(bool harm, const char* p);
	virtual ~Escalera();
	void Dibuja();
	void setPos(float px, float py);
	void setSize(float largo, float alto);
	void setPath(const char* p);
	void setHarmful(bool harm);
	bool isHarmful() { return harmful; }
	Vector2D getPos() { return posicion; }
	Vector2D getSize() { return size; }
};

