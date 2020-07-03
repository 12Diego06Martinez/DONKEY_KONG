#pragma once
#include "ElementoFijo.h"

class Escalera:public ElementoFijo
{
public:
	Escalera(float px, float py, float ancho, float alto, const char* path="imagenes/escalera_transparente.png"):ElementoFijo(px,py,ancho, alto, path){}
};

