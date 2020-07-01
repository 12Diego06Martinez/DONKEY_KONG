#include "Vector2D.h"
#include <math.h>

////////////////////////CONSTRUCTOR////////////////////////////
Vector2D::Vector2D(float xv, float yv) {
	x = xv;
	y = yv;
}

Vector2D::~Vector2D() {

}

//////////////////////MÉTODOS////////////////////////////
float Vector2D::Modulo() {
	//modulo=sqrt(x^2 + y^2)
	return (float)sqrt(x * x + y * y);
}

float Vector2D::Argumento() {
	//angulo=arctag(y/x)
	return (float)atan2(y, x);
}

Vector2D Vector2D::Unitario() {
	//vector director=v/modulo(v)
	Vector2D retorno(x, y);
	float mod = Modulo();
	if (mod > 0.00001) {
		retorno.x /= mod;
		retorno.y /= mod;
	}
	return retorno;
}

Vector2D Vector2D::operator-(const Vector2D& v) {
	Vector2D res;
	res.x = x - v.x;
	res.y = y - v.y;
	return res;
}

Vector2D Vector2D::operator +(const Vector2D& v)
{
	Vector2D res;
	res.x = x + v.x;
	res.y = y + v.y;
	return res;
}



float Vector2D::operator*(const Vector2D& v) {
	Vector2D vector;
	vector.x = x * v.x;
	vector.y = y * v.y;
	return vector.x + vector.y;
}

Vector2D Vector2D::operator*(float num) {
	Vector2D vector;
	vector.x = num * x;
	vector.y = num * y;
	return vector;
}

Vector2D Vector2D::operator +(float r) {
	Vector2D res;
	res.x = x + r;
	res.y = y + r;
	return res;
}

bool Vector2D::operator >(const Vector2D& v) {
	if (this->x > v.x && this->y > v.y)
		return true;
	else
		return false;
}