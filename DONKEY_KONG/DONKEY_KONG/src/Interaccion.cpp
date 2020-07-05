#include "Interaccion.h"

using namespace ETSIDI;

/////////////////////////////////////CONSTRUCTOR////////////////////////////
Interaccion::Interaccion() {

}

Interaccion::~Interaccion() {

}

/////////////////////////////////////METODOS////////////////////////////////
void Interaccion::reboteExterior(Jugador& jugador, Pared pared) {
	
	if (jugador.posicion.x > pared.limite2.x) {
		jugador.posicion.x = pared.limite2.x;
	}
	if (jugador.posicion.x < pared.limite1.x) {
		jugador.posicion.x = pared.limite1.x;
	}
}

bool Interaccion::sobrePlataforma(Jugador& jugador, Plataforma plataforma) {
	float x_max = plataforma.limite2.x;
	float x_min = plataforma.limite1.x;
	float y_max = plataforma.limite2.y;
	float y_min = plataforma.limite1.y;
	if (jugador.posicion.y <= y_max && jugador.posicion.y > y_min && jugador.posicion.x >= x_min && jugador.posicion.x<=x_max) {
		jugador.setPos(jugador.posicion.x, plataforma.limite2.y);
		return true;
	}
	
	else
		return false;
}

bool Interaccion::arribaEscalera(Jugador& jugador, Escalera escalera){
	float distancia = (escalera.limite1 - jugador.posicion).module();
	if (distancia > 4.15 && distancia < 4.16 && jugador.isGoingUp==true) {
		jugador.setPos(jugador.posicion.x, (escalera.limite2.y + 0.15));
		return true;
	}
	else
		return false;
}

bool Interaccion::abajoEscalera(Jugador& jugador, Escalera escalera) {
	float distancia = (escalera.limite1 - jugador.posicion).module();
	if (distancia > 0.24 && distancia < 0.26 && jugador.isGoingDown == true) {
		jugador.setPos(jugador.posicion.x, (escalera.limite1.y + 0.15));
		return true;
	}
	else
		return false;
}

bool Interaccion::detectaEscaleraSubir(Jugador& jugador, Escalera escalera) {
	float distancia = (escalera.posicion - jugador.posicion).module();
	if (distancia > 1.849 && distancia < 1.852) {
		return true;
	}
	else
		return false;
}

bool Interaccion::detectaEscaleraBajar(Jugador& jugador, Escalera escalera) {
	float distancia = (escalera.posicion - jugador.posicion).module();
	if (distancia > 2.148 && distancia < 2.153)
		return true;
	else
		return false;
}

bool Interaccion::caidaHueco(Jugador& jugador, Pared pared) {
	float x_max = pared.limite2.x;
	float x_min = pared.limite1.x;
	float y_max = pared.limite2.y;

	if (jugador.posicion.x < x_max  && jugador.posicion.x > x_min && jugador.posicion.y == y_max) 
		return true;
	else
		return false;
}

bool Interaccion::colisionMoneda(Jugador& jugador, Moneda moneda) {
	float distancia = (moneda.posicion - jugador.posicion).module();
	if (distancia < 0.7)
		return true;
	else
		return false;
}

bool Interaccion::colisionEnemigo(Jugador& jugador, Enemigo& enemigo) {
	float distancia = (jugador.posicion - enemigo.posicion).module();
	if (distancia < 0.26 && !jugador.getSalto())
		return true;
	else if (distancia < 0.18 && jugador.getSalto())
		return true;
	else
		return false;
}


void Interaccion::colisionEnemigos(Enemigo& enemigo1, Enemigo& enemigo2) {
	float distancia = (enemigo1.posicion - enemigo2.posicion).module();
	if (distancia < 0.2f) {
		enemigo1.setVel(-enemigo1.velocidad.x, 0.0f);
		enemigo2.setVel(-enemigo2.velocidad.x, 0.0f);
	}
}

void Interaccion::reboteEnemigos(Enemigo& enemigo, Plataforma plataforma) {
	float distancia_lim2= (enemigo.posicion - plataforma.limite2).module();
	float distancia_lim1 = (enemigo.posicion - plataforma.limite1).module();
	if (distancia_lim2 < 0.5)
		enemigo.setVel(-enemigo.velocidad.x, 0.0f);
	if (distancia_lim1 < 0.5)
		enemigo.setVel(-enemigo.velocidad.x, 0.0f);
}

bool Interaccion::caidaVacio(Jugador& jugador, Plataforma plataforma) {
	float x_max = plataforma.limite2.x;
	float x_min = plataforma.limite1.x;
	float y_max = plataforma.limite2.y;

	if (jugador.posicion.x > x_max&& jugador.posicion.y == y_max || jugador.posicion.x < x_min && jugador.posicion.y == y_max)
		return true;
	else
		return false;
}

bool Interaccion::detectaEvanescente(Jugador& jugador, Plataforma plataforma) {
	float x_max = plataforma.limite2.x;
	float x_min = plataforma.limite1.x;
	float y_max = plataforma.limite2.y;

	if (jugador.posicion.x < x_max && jugador.posicion.x > x_min && jugador.posicion.y == y_max)
		return true;
	else
		return false;
}
////////////////////////////////////////////////////////
void Interaccion::persigueJugador(Jugador& jugador, Enemigo& enemigo) {
	if (enemigo.posicion.x > jugador.posicion.x) {
		if (jugador.velocidad.x > 0 && enemigo.velocidad.x > 0)
			enemigo.setVel(-enemigo.velocidad.x, 0.0f);
	}
	
	if (enemigo.posicion.x < jugador.posicion.x) {
		if (jugador.velocidad.x < 0 && enemigo.velocidad.x < 0)
			enemigo.setVel(-enemigo.velocidad.x, 0.0f);
	}
}