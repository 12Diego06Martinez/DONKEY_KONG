#pragma once
#include "Plataforma.h"

class PlataformaEvanescente :public Plataforma {
public:
	PlataformaEvanescente(float px, float py, float ancho, float alto, const char* path) :Plataforma(px, py, ancho, alto, path) {}
};