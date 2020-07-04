#include "GestorNiveles.h"
#include "ETSIDI.h"
#include "Paths.h"
#include "InteraccionListas.h"
#include "Interaccion.h"
#include "glut.h"

//////////////////////////////////////////DESTRUCTOR////////////////////////
GestorNiveles::~GestorNiveles() {
	
}

//////////////////////////////////////////METODOS///////////////////////////
void GestorNiveles::cargaNivel() {
	//Posición del ojo
	x_ojo = 0;
	y_ojo = 7.5;
	z_ojo = 30;
	//Control juego
	nivel = 1;
	vidas = 3;
	monedas_recogidas = 0;
	pasar_nivel = false;
	//Valores iniciales cada nivel
	if (nivel == 1) {
		player.setPos(-8, -1.85);
		//Pared
		suelo.setLimites(-9, -4, 9, -3);
		hueco1.setLimites(-0.9, 1.85, 0.9, 2.15);
		hueco2.setLimites(-2, 9.75, 0, 10.15);
		//Plataformas
		plataformas.Agregar(new Plataforma(0, -2, 18, 0.3, plataforma_18));
		plataformas.Agregar(new Plataforma(5, 2, 8, 0.3, plataforma_8_5));
		plataformas.Agregar(new Plataforma(-5, 2, 8, 0.3, plataforma_8_5));
		plataformas.Agregar(new Plataforma(0, 6, 18, 0.3, plataforma_18));
		plataformas.Agregar(new Plataforma(4.5, 10, 9, 0.3, plataforma_8_5));
		plataformas.Agregar(new Plataforma(-5.5, 10, 7, 0.3, plataforma_7));
		plataformas.Agregar(new Plataforma(0, 14, 18, 0.3, plataforma_18));
		//Escaleras
		escaleras.Agregar(new Escalera(6, 0, 0.5, 4));
		escaleras.Agregar(new Escalera(3, 4, 0.5, 4));
		escaleras.Agregar(new Escalera(-8, 4, 0.5, 4));
		escaleras.Agregar(new Escalera(-5, 8, 0.5, 4));
		escaleras.Agregar(new Escalera(1, 12, 0.5, 4));
		escaleras.Agregar(new Escalera(-3, 16, 0.5, 4));
		//Monedas
		monedas.Agregar(new Moneda(-1, -1.4, 0.7, 0.7));
		monedas.Agregar(new Moneda(6, 0.25, 0.7, 0.7));
		monedas.Agregar(new Moneda(-4, 2.65, 0.7, 0.7));
		monedas.Agregar(new Moneda(0, 2.25, 0.7, 0.7));
		monedas.Agregar(new Moneda(2, 6.65, 0.7, 0.7));
		monedas.Agregar(new Moneda(8, 10.65, 0.7, 0.7));
		monedas.Agregar(new Moneda(-1, 10.65, 0.7, 0.7));
		monedas.Agregar(new Moneda(-6, 14.65, 0.7, 0.7));
		monedas.Agregar(new Moneda(4, 14.65, 0.7, 0.7));
		//Enemigos
		enemigos.Agregar(new Enemigo(2, -1.85));
		enemigos.Agregar(new Enemigo(6, 2.25));
		enemigos.Agregar(new Enemigo(-3, 2.25));
		enemigos.Agregar(new Enemigo(-1, 6.25));
		enemigos.Agregar(new Enemigo(6, 6.25));
		enemigos.Agregar(new Enemigo(-4, 10.25));
		enemigos.Agregar(new Enemigo(-8, 14.25));
		enemigos.Agregar(new Enemigo(0, 14.25));
		enemigos.Agregar(new Enemigo(5, 14.25));
	}
}

void GestorNiveles::dibujaNivel() {
	gluLookAt(x_ojo, y_ojo, z_ojo,//posición del ojo
		0.0, y_ojo, 0.0, //Miramos al centro de la escena
		0.0, 1.0, 0.0); //orientación del mundo hacia arriba
	if (nivel == 1) {
		//Jugador
		player.Dibuja();
		//Plataformas
		plataformas.Dibuja();
		//Escaleras
		escaleras.Dibuja();
		//Monedas
		monedas.Dibuja();
		//Enemigos
		enemigos.Dibuja();
	}
}

void GestorNiveles::mueveNivel() {
	player.Mueve(0.025f);
	if (nivel == 1) {
		//Enemigos
		enemigos.Mueve(0.025f);
		InteraccionListas::rebotePlataformas(plataformas, enemigos);
		InteraccionListas::colisionEnemigos(enemigos);
		//Jugador con enemigos
		if (InteraccionListas::colisionJugador(player, enemigos) != 0) {
			ETSIDI::play("sonidos/pierde.wav");
			vidas--;
		}
		//InteraccionListas::persiguenJugador(player, enemigos);
		//Jugador con pared
		Interaccion::reboteExterior(player, suelo);
		if (Interaccion::caidaHueco(player, hueco1) || Interaccion::caidaHueco(player, hueco2)) {
			player.setAcel(0.0, -20.0f);
			player.setFalling(true);
		}
		//Salto
		if (player.getSalto() || player.getFalling()) {
			if (InteraccionListas::sobrePlataforma(player, plataformas) != 0) {
				player.setAcel(0.0f, 0.0f);
				player.setVel(player.getVel().x, 0);
				player.setSalto(false);
				player.setFalling(false);
			}
		}
		//Jugador con escaleras
		if (InteraccionListas::jugadorArriba(player, escaleras) != 0) {
			player.setVel(0.0f, 0.0f);
			player.setUp(false);
		}

		if (InteraccionListas::jugadorAbajo(player, escaleras) != 0) {
			player.setVel(0.0f, 0.0f);
			player.setDown(false);
		}
		//Jugador con monedas
		Moneda* aux = InteraccionListas::cogeMonedas(player, monedas);
		if (aux != 0) {
			if (monedas_recogidas < 9)
				monedas_recogidas++;
			else
				pasar_nivel = true;
		}
		monedas.Delete(aux);
	}
}

void GestorNiveles::teclasNivel(unsigned char key) {
	switch (key) {
	case ' ':
		if (InteraccionListas::sobrePlataforma(player, plataformas) != 0) {
			player.setAcel(0, -15);
			player.setVel(player.getVel().x, 4.0f);
			player.setSalto(true);
			ETSIDI::play("sonidos/salto.wav");
		}
		break;
	}
}

void GestorNiveles::flechasNivel(unsigned char key) {
	switch (key) {
	case GLUT_KEY_RIGHT:
		player.setVel(5.0f, 0.0f);
		if (player.getUp() || player.getDown()) {
			player.setAcel(0.0f, -20.0f);
			player.setFalling(true);
		}
		break;

	case GLUT_KEY_LEFT:
		player.setVel(-5.0f, 0.0f);
		if (player.getUp() || player.getDown()) {
			player.setAcel(0.0f, -20.0f);
			player.setFalling(true);
		}
		break;

	case GLUT_KEY_UP:
		if (InteraccionListas::detectaEscalerasSubir(player, escaleras) != 0 && InteraccionListas::sobrePlataforma(player, plataformas) != 0) {
			player.setVel(0.0f, 5.0f);
			player.setUp(true);
			ETSIDI::play("sonidos/subir.wav");
		}
		break;

	case GLUT_KEY_DOWN:
		if (InteraccionListas::detectaEscalerasBajar(player, escaleras) != 0 && InteraccionListas::sobrePlataforma(player, plataformas) != 0) {
			player.setVel(0.0f, -5.0f);
			player.setDown(true);
			ETSIDI::play("sonidos/bajar.wav");
		}
		break;
	}
}

void GestorNiveles::recargaNivel() {
	enemigos.Destruir();
	plataformas.Destruir();
	monedas.Destruir();
	escaleras.Destruir();
}
