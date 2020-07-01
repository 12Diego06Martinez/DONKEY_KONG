#pragma once
#include <ETSIDI.h>


class Enemigo {
private:
	enum enemigo_t { NORMAL_D, NORMAL_I, VULNERABLE_D, VULNERABLE_I };
	enemigo_t estado;
	char* path;
	float ancho;
	float alto;
	ETSIDI::Vector2D posicion;
	ETSIDI::Vector2D velocidad;
	ETSIDI::Vector2D limite1;
	ETSIDI::Vector2D limite2;
	friend class Interaccion;
public:
	Enemigo(){}
	Enemigo(float px, float py, float ancho, float alto);
	virtual ~Enemigo();
	void Dibuja();
	void Mueve(float t);
	void generaAleatorio();
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
