#include "Mundo.h"
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
	player.setPos(-10,0);
	//Inicializamos plataforma
	for (int i = 0; i < 3; i++) {
		Plataforma* aux = new Plataforma(false);
		aux->setPos(0, 8 * i - 2);
		aux->setSize(18, 0.25);
		plataformasLargas.Agregar(aux);
	}

	for (int i = 0; i < 2; i++) {
		Plataforma* aux = new Plataforma(false);
		aux->setPos(10 * i - 5, 2);
		aux->setSize(8, 0.25);
		plataformasCortas.Agregar(aux);
	}

	for (int i = 2; i < 4;i++) {
		Plataforma* aux = new Plataforma(false);
		aux->setPos(10 * i - 26, 10);
		aux->setSize(4 * i - 2, 0.25);
		plataformasCortas.Agregar(aux);
	}
		
	for (int i = 1; i < 4; i++) {
		for (int j = 1; j < 3; j++) {
			Escalera* aux = new Escalera(false);
			aux->setPos(13 - 5 * i - 3 * j, 12 + 4 * i - 8 * j);
			aux->setSize(0.5, 4);
			escaleras.Agregar(aux);
		}	
	}
}

void Mundo::Dibuja() {
	//Punto de vista
	gluLookAt(x_ojo, y_ojo, z_ojo,//posición del ojo
		0.0, y_ojo, 0.0, //Miramos al centro de la escena
		0.0, 1.0, 0.0); //orientación del mundo hacia arriba

	player.Dibuja();
	plataformasLargas.Dibuja();
	plataformasCortas.Dibuja();
	escaleras.Dibuja();
}

void Mundo::Mueve() {
	player.Mueve(0.025f);
}

void Mundo::TeclaEspecial(unsigned char key) {

	switch (key) {
		case GLUT_KEY_RIGHT:
			player.setVel(5.0f, 0.0f);
			break;
		case GLUT_KEY_LEFT:
			player.setVel(-5.0f, 0.0f);
			break;
	}
}