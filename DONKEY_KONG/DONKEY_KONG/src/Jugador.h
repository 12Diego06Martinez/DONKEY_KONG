#pragma once
#include <ETSIDI.h>


class Jugador
{
private:
	char* path;
	bool isOnPlatform;
	bool saltoAllowed;
	bool isGoingUp;
	bool isGoingDown;
	bool isFalling;
	float ancho;
	float alto;
	int vidas = 3;
	ETSIDI::Vector2D posicion;
	ETSIDI::Vector2D velocidad;
	ETSIDI::Vector2D aceleracion;
	ETSIDI::Vector2D limite1;
	ETSIDI::Vector2D limite2;
	friend class Interaccion;
public:
	Jugador();
	virtual ~Jugador();
	void Dibuja();
	void Mueve(float t);
	//Setters
	void setPath(const char* p);
	void setPos(float px, float py);
	void setVel(float vx, float vy);
	void setAcel(float ax, float ay);
	void setSalto(bool salto) { saltoAllowed = salto; }
	void setUp(bool up) { isGoingUp = up; }
	void setDown(bool down) { isGoingDown = down; }
	void setFalling(bool falling) { isFalling = falling; }
	void setPlatform(bool platform) { isOnPlatform = platform; }
	void setReposo();
	void setVidas(float num) { vidas = num; }
	//Getters
	ETSIDI::Vector2D getPos() { return posicion; }
	ETSIDI::Vector2D getVel() { return velocidad; }
	ETSIDI::Vector2D getAcel() { return aceleracion; }
	bool getSalto() { return saltoAllowed; }
	bool getUp() { return isGoingUp; }
	bool getDown() { return isGoingDown; }
	bool getFalling() { return isFalling; }
	int getVidas() { return vidas; }
};
