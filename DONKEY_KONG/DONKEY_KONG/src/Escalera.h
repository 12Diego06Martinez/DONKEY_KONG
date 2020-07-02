#pragma once
#include <ETSIDI.h>

class Escalera
{
private:
	char* path;
	bool harmful;
	ETSIDI::Vector2D posicion;
	ETSIDI::Vector2D limite1;
	ETSIDI::Vector2D limite2;
	friend class Interaccion;
public:
	Escalera(){}
	Escalera(float px, float py, float ancho, float alto);
	virtual ~Escalera();
	void Dibuja();
	void Inicializa(float px, float py, float ancho, float alto);
	//Setters
	void setLimites(float x1, float y1, float x2, float y2);
	void setPos(float px, float py);
	void setPath(const char* p);
	void setHarmful(bool harm);
	//Getters
	bool isHarmful() { return harmful; }
	ETSIDI::Vector2D getPos() { return posicion; }
	ETSIDI::Vector2D getLimite1() { return limite1; }
	ETSIDI::Vector2D getLimite2() { return limite2; }
	ETSIDI::Vector2D getSize() { return limite2-limite1; }
};

