#pragma once
#include "ElementoFijo.h"

class Plataforma:public ElementoFijo
{
public:
	Plataforma(float px, float py, float ancho, float alto, const char* path):ElementoFijo(px,py,ancho,alto,path){}
};