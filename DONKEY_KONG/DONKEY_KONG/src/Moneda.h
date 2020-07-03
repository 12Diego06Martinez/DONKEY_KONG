#pragma once
#include "ElementoFijo.h"

class Moneda:public ElementoFijo
{
public:
	Moneda(float px, float py, float ancho, float alto, const char* path="imagenes/coin.png"):ElementoFijo(px, py, ancho, alto, path){}
};
