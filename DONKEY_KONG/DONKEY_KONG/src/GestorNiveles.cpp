#include "GestorNiveles.h"
#include "ETSIDI.h"
#include "Paths.h"
#include "InteraccionListas.h"
#include "Interaccion.h"
#include "glut.h"

//////////////////////////////////////////DESTRUCTOR////////////////////////
GestorNiveles::GestorNiveles() {
	//Control juego
	nivel = 1;
}

GestorNiveles::~GestorNiveles() {
	
}

//////////////////////////////////////////METODOS///////////////////////////
void GestorNiveles::cargaNivel() {
	//Posición del ojo
	x_ojo = 0;
	y_ojo = 7.5;
	z_ojo = 30;
	//Inicializa
	vidas = 5;
	monedas_recogidas = 0;
	pasar_nivel = false;
	//Icono de vidas
	for (int i = 0; i < 3; i++) {
		vidas_icono.Agregar(new Vidas(10.5 + i, 16, 1.0f, 1.0f));
	}
	//Valores iniciales cada nivel
	if (nivel == 1) {
		player.setPos(-8, -1.85);
		player.setVel(0.0f, 0.0f);
		//Pared
		suelo.setLimites(-9, -4, 9, -3);
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

	if (nivel == 2) {
		player.setPos(-8, -1.85);
		player.setVel(0.0f, 0.0f);
		//Pared
		suelo.setLimites(-13, -4, 13, -3);
		caja.Agregar(new Plataforma(-3, 12, 0.3, 4, plataforma_evanescente));
		caja.Agregar(new Plataforma(3, 12, 0.3, 4, plataforma_evanescente));
		//Plataformas
		plataformas.Agregar(new Plataforma(0, -2, 26, 0.3, plataforma_18));
		plataformas.Agregar(new Plataforma(-9, 2, 6, 0.3, plataforma_7));
		plataformas.Agregar(new Plataforma(9, 2, 6, 0.3, plataforma_7));
		plataformas.Agregar(new Plataforma(-8.5, 6, 5, 0.3, plataforma_7));
		plataformas.Agregar(new Plataforma(8.5, 6, 5, 0.3, plataforma_7));
		plataformas.Agregar(new Plataforma(-8, 10, 4, 0.3, plataforma_7));
		plataformas.Agregar(new Plataforma(8, 10, 4, 0.3, plataforma_7));
		for (int i = 0; i < 4; i++) {
			moviles.Agregar(new PlataformaMovil(0, 2 + 4 * i, 8, 0.3, plataforma_11));
		}
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 4; j++) {
				evanescentes.Agregar(new PlataformaEvanescente(-5 + 10 * i, -2 + 4 * j, 2, 0.3, plataforma_evanescente));
			}
		}
		//Escaleras
		escaleras.Agregar(new Escalera(-3, -4, 0.5, 4));
		escaleras.Agregar(new Escalera(-11.75, 0, 0.5, 4));
		escaleras.Agregar(new Escalera(11.75, 0, 0.5, 4));
		escaleras.Agregar(new Escalera(0, 0, 0.5, 4));
		escaleras.Agregar(new Escalera(-10.75, 4, 0.5, 4));
		escaleras.Agregar(new Escalera(10.75, 4, 0.5, 4));
		escaleras.Agregar(new Escalera(-3.5, 4, 0.5, 4));
		escaleras.Agregar(new Escalera(3.5, 4, 0.5, 4));
		escaleras.Agregar(new Escalera(-9.75, 8, 0.5, 4));
		escaleras.Agregar(new Escalera(9.75, 8, 0.5, 4));
		//Monedas
		monedas.Agregar(new Moneda(-4, -1.4, 0.7, 0.7));
		monedas.Agregar(new Moneda(1, -1.4, 0.7, 0.7));
		monedas.Agregar(new Moneda(-11, 2.65, 0.7, 0.7));
		monedas.Agregar(new Moneda(0, 2.65, 0.7, 0.7));
		monedas.Agregar(new Moneda(8, 2.65, 0.7, 0.7));
		monedas.Agregar(new Moneda(-3, 6.65, 0.7, 0.7));
		monedas.Agregar(new Moneda(8, 6.65, 0.7, 0.7));
		monedas.Agregar(new Moneda(-6.5, 6.65, 0.7, 0.7));
		monedas.Agregar(new Moneda(-7, 10.65, 0.7, 0.7));
		monedas.Agregar(new Moneda(7, 10.65, 0.7, 0.7));
		//Enemigos
		enemigos.Agregar(new Enemigo(1, 2.25));
		enemigos.Agregar(new Enemigo(8, 2.25));
		enemigos.Agregar(new Enemigo(-7, 2.25));
		enemigos.Agregar(new Enemigo(-2, 6.25));
		enemigos.Agregar(new Enemigo(3, 6.25));
		enemigos.Agregar(new Enemigo(-7.5, 10.25));
		enemigos.Agregar(new Enemigo(8, 10.25));
	}
}

void GestorNiveles::dibujaNivel() {
	gluLookAt(x_ojo, y_ojo, z_ojo,//posición del ojo
		0.0, y_ojo, 0.0, //Miramos al centro de la escena
		0.0, 1.0, 0.0); //orientación del mundo hacia arriba
	//Iconos vidas
	vidas_icono.Dibuja();

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

	if (nivel == 2) {
		//Jugador
		player.Dibuja();
		//Plataformas
		suelo.Dibuja();
		caja.Dibuja();
		plataformas.Dibuja();
		evanescentes.Dibuja();
		moviles.Dibuja();
		//Escaleras
		escaleras.Dibuja();
		//Monedas
		monedas.Dibuja();
		//Enemigos
		enemigos.Dibuja();
		//Vacuna
		cura.Dibuja();
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
			dj.playLose();
			vidas--;
			for (int i = 0; i < vidas_icono.getNum(); i++) {
				vidas_icono.Delete(i);
			}
		}
		//InteraccionListas::persiguenJugador(player, enemigos);
		//Jugador con plataformas
		Interaccion::reboteExterior(player, suelo);
		if (InteraccionListas::caidaVacio(player, plataformas) != 0){
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
		}
		monedas.Delete(aux);
		if (monedas_recogidas > 8 && player.getPos().y > 18) {
			pasar_nivel = true;
		}
	}

	if(nivel==2){
		//Enemigos
		enemigos.Mueve(0.025f);
		InteraccionListas::rebotePlataformas(plataformas, enemigos);
		InteraccionListas::rebotePlataformas(moviles, enemigos);
		InteraccionListas::colisionEnemigos(enemigos);
		//Jugador con enemigos
	/*	if (InteraccionListas::colisionJugador(player, enemigos) != 0) {
			dj.playLose();
			vidas--;
		}*/
		//InteraccionListas::persiguenJugador(player, enemigos);
		//Jugador con plataformas
		Interaccion::reboteExterior(player, suelo);
		InteraccionListas::detectaCaja(player,caja);

		if (InteraccionListas::caidaVacio(player, plataformas) != 0 || InteraccionListas::caidaVacio(player, moviles) != 0) {
			player.setAcel(0.0, -20.0f);
			player.setFalling(true);
		}

		Plataforma* aux2 = InteraccionListas::detectaEvanescente(player, evanescentes);
		if ( aux2 != 0) {
			if (evanescentes.getNum() < 6) {
				dj.playDesaparece();
			}	
		}
		evanescentes.Delete(aux2);
		if (evanescentes.getNum() == 0 && monedas_recogidas > 9) {
			caja.Destruir();
		}
		if (monedas_recogidas > 9 && Interaccion::cogeVacuna(player, cura)) {
			pasar_nivel = true;
		}
		//Salto
		if (player.getSalto() || player.getFalling()) {
			if (InteraccionListas::sobrePlataforma(player, plataformas) != 0 || InteraccionListas::sobrePlataforma(player, moviles) != 0 || InteraccionListas::sobrePlataforma(player, evanescentes)) {
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
			if (monedas_recogidas < 10)
				monedas_recogidas++;
		}
		monedas.Delete(aux);
	
	}
}

void GestorNiveles::teclasNivel(unsigned char key) {
	switch (key) {
	case ' ':
		if (InteraccionListas::sobrePlataforma(player, plataformas) != 0 || InteraccionListas::sobrePlataforma(player, moviles) != 0 || InteraccionListas::sobrePlataforma(player, evanescentes)) {
			player.setAcel(0, -15);
			player.setVel(player.getVel().x, 4.0f);
			player.setSalto(true);
			dj.playSalto();
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
		if (InteraccionListas::detectaEscalerasSubir(player, escaleras) != 0 && (InteraccionListas::sobrePlataforma(player, plataformas) != 0 || InteraccionListas::sobrePlataforma(player, moviles) != 0)) {
			player.setVel(0.0f, 5.0f);
			player.setUp(true);
			dj.playSube();
		}
		break;

	case GLUT_KEY_DOWN:
		if (InteraccionListas::detectaEscalerasBajar(player, escaleras) != 0 && (InteraccionListas::sobrePlataforma(player, plataformas) != 0 || InteraccionListas::sobrePlataforma(player, moviles) != 0)) {
			player.setVel(0.0f, -5.0f);
			player.setDown(true);
			dj.playBaja();
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
