#pragma once
#include "ElementoFijo.h"

class Vidas :public ElementoFijo {
public:
	Vidas(float px, float py, float ancho, float alto, const char* path="imagenes/vidas.png"):ElementoFijo(px,py,ancho,alto,path){}
};
