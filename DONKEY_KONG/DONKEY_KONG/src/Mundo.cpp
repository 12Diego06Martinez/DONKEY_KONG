#include "Mundo.h",
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
	player.setPos(-8,-1.75);
	//Inicializamos plataforma
	plataforma.setLimites(-9, -2, 9, -1.75);
	for (int i = 0; i < 3; i++) {
		Plataforma* aux = new Plataforma();
		aux->setLimites(-9, -2 + 8 * i, 9, -1.75 + 8 * i);
		plataformas.Agregar(aux);
	}

	for (int i = 0; i < 2; i++) {
		Plataforma* aux = new Plataforma();
		aux->setLimites(-9 + 10 * i, 2, -1 + 10 * i, 2.25);
		plataformas.Agregar(aux);
	}

	for (int i = 0; i < 2; i++) {
		Plataforma* aux = new Plataforma();
		aux->setLimites(-9 + 8 * i, 10, -3 + 12 * i, 10.25);
		plataformas.Agregar(aux);
	}
}

void Mundo::Dibuja() {
	//Punto de vista
	gluLookAt(x_ojo, y_ojo, z_ojo,//posición del ojo
		0.0, y_ojo, 0.0, //Miramos al centro de la escena
		0.0, 1.0, 0.0); //orientación del mundo hacia arriba

	player.Dibuja();
	plataforma.Dibuja();
	//plataformas.Dibuja();
	//escaleras.Dibuja();
}

void Mundo::Mueve() {
	player.Mueve(0.025f);
	player.Rebote(plataforma);
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