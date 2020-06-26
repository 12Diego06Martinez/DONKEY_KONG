#pragma once
class Vector2D
{
public:
	Vector2D(float xv = 0.0f, float yv = 0.0f);//si se omite el segundo o ambos parametros, se considerarán nulos
	virtual ~Vector2D();
	float x;
	float y;
	float Modulo(); //módulo del vector
	float Argumento();//argumento del vector
	Vector2D Unitario();//devuelve un vector unitario
	Vector2D operator-(const Vector2D& v);//resta de vectores
	Vector2D operator +(const Vector2D& v);//suma de vectores
	float operator*(const Vector2D& v);//producto escalar
	Vector2D operator*(float);//producto por un escalar
	Vector2D operator +(float r);
	bool operator > (const Vector2D& v);
};

