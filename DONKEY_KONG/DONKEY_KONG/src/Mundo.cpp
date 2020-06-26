#include "Mundo.h"
#include "ETSIDI.h"
#include "glut.h"

///////////////////////////////////DESTRUCTOR////////////////////////////
Mundo::~Mundo() {

}

////////////////////////////////////METODOS////////////////////////////
void Mundo::Inicializa() {
	//Posición del ojo
	x_ojo = 0;
	y_ojo = 7.5;
	z_ojo = 30;

	//Inicializamos jugador
	player.setPos(-8,-2);
	//Inicializamos plataforma
	plataforma1.setPos(0, -2);
	plataforma1.setSize(9,0.15);
	plataforma2.setPos(-5, 2);
	plataforma2.setSize(4,0.15);
	plataforma3.setPos(5, 2);
	plataforma3.setSize(4,0.15);
	plataforma4.setPos(0, 6);
	plataforma4.setSize(9,0.15);
	plataforma5.setPos(-6, 10);
	plataforma5.setSize(3,0.15);
	plataforma6.setPos(4, 10);
	plataforma6.setSize(5,0.15);
	plataforma7.setPos(0, 14);
	plataforma7.setSize(9,0.15);
	//Inicializamos escaleras
	escalera1.setPos(6, 0);
	escalera1.setSize(0.25, 2);
	escalera2.setPos(3, 4);
	escalera2.setSize(0.25, 2);
	escalera3.setPos(-8, 4);
	escalera3.setSize(0.25, 2);
	escalera4.setPos(-5, 8);
	escalera4.setSize(0.25, 2);
	escalera5.setPos(1,12);
	escalera5.setSize(0.25, 2);
	escalera6.setPos(-3, 16);
	escalera6.setSize(0.25, 2);
}

void Mundo::Dibuja() {
	//Punto de vista
	gluLookAt(x_ojo, y_ojo, z_ojo,//posición del ojo
		0.0, y_ojo, 0.0, //Miramos al centro de la escena
		0.0, 1.0, 0.0); //orientación del mundo hacia arriba

	player.Dibuja();
	plataforma1.Dibuja();
	plataforma2.Dibuja();
	plataforma3.Dibuja();
	plataforma4.Dibuja();
	plataforma5.Dibuja();
	plataforma6.Dibuja();
	plataforma7.Dibuja();
	escalera1.Dibuja();
	escalera2.Dibuja();
	escalera3.Dibuja();
	escalera4.Dibuja();
	escalera5.Dibuja();
	escalera6.Dibuja();
}

void Mundo::Mueve() {
	player.Desplaza(0.025f);

	if (player.LimitePlataforma(plataforma1)) {
		player.Interaccion(plataforma1);
		//player.setReposo();
	}

	if (player.LimitePlataforma(plataforma3)) {
		player.Interaccion(plataforma3);
		//player.setReposo();
	}
	

	if (player.Interaccion(escalera1)|| player.Interaccion(escalera2)) {
		ETSIDI::play("sonidos/contactoPared.wav");
	}
}

void Mundo::TeclaEspecial(unsigned char key) {

	switch (key) {
	case GLUT_KEY_RIGHT:
		if(player.LimitePlataforma(plataforma1) || player.LimitePlataforma(plataforma3))
			player.setVel(5.0f, 0.0f);
		break;
	case GLUT_KEY_LEFT:
		if (player.LimitePlataforma(plataforma1) || player.LimitePlataforma(plataforma3))
			player.setVel(-5.0f, 0.0f);
		break;
	case GLUT_KEY_UP:
		if (player.Interaccion(escalera1) && !player.LimitePlataforma(plataforma3))
			player.setVel(0.0f, 5.0f);
		if (player.LimitePlataforma(plataforma3))
			player.setVel(0, 0);
		/*if (player.Interaccion(escalera2)) {
			if (!player.LimitePlataforma(plataforma4))
				player.setVel(0.0f, 5.0f);
		}*/
		break;
	case GLUT_KEY_DOWN:
		if (player.Interaccion(escalera1)) {
			if (!player.LimitePlataforma(plataforma1))
				player.setVel(0.0f, -5.0f);
		}
		break;
	}
}

void Mundo::Tecla(unsigned char key) {

	switch (key) {
	case ' ':
		//player.Salto(0.025f, 60);
		break;
	}
}