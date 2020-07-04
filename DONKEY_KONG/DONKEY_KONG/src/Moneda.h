#pragma once
#include "ElementoFijo.h"

class Moneda:public ElementoFijo
{
public:
	Moneda(float px, float py, float ancho, float alto, const char* path="imagenes/Mascarilla.png"):ElementoFijo(px, py, ancho, alto, path){}
};
