#pragma once
#include "Elemento.h"
#include "Vector2D.h"

class ElementoEstatico:public Elemento
{
protected:
	Vector2D limite1;
	Vector2D limite2;
public:
	ElementoEstatico(bool harmful, const char* p):Elemento(harmful,p){}
	virtual ~ElementoEstatico();
	void setLimites(float x1, float y1, float x2, float y2);
	virtual void Dibuja();
};

