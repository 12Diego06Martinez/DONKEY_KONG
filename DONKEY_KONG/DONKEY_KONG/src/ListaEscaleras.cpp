#include "ListaEscaleras.h"
#include "Interaccion.h"

///////////////////////////////////CONSTRUCTOR///////////////////////
ListaEscaleras::ListaEscaleras() {
	num = 0;
	for (int i = 0; i < MAX_NUM; i++) {
		lista[i] = 0;
	}
}

ListaEscaleras::~ListaEscaleras() {

}

///////////////////////////////////MÉTODOS//////////////////////////
bool ListaEscaleras::Agregar(Escalera* escalera) {
	if (num < MAX_NUM) {
		for (int i = 0; i < num; i++) {
			if (lista[i] == escalera) {
				return false;
			}
		}
		lista[num] = escalera;
		num++;
		return true;
	}
	else
		return false;
}

void ListaEscaleras::Dibuja() {
	for (int i = 0; i < num; i++) {
		lista[i]->Dibuja();
	}
}

void ListaEscaleras::Destruir() {
	for (int i = 0; i < num; i++) {
		delete lista[i];
	}
	num = 0;
}

void ListaEscaleras::Delete(int index) {
	if ((index < 0) || (index >= num)) {
		return;
	}
	delete lista[index];
	num--;
	for (int i = index; i < num; i++) {
		//Recorremos la lista desde la posición indicada hasta el 
		//final de la lista. Si por ejemplo eliminamos la Escalera en la posición 2, Muevemos 
		//la posición 3 a la 2, la 4 a la 3 y así sucesivamente hasta num
		lista[i] = lista[i + 1];
	}
}

void ListaEscaleras::Delete(Escalera* escalera) {
	for (int i = 0; i < num; i++) {
		if (lista[i] == escalera) {
			Delete(i);
			return;
		}
	}
}

Escalera* ListaEscaleras::operator[](int pos) {
	if (pos >= num)//si me paso, devuelvo la ultima   
		pos = num - 1;

	if (pos < 0) //si el indice es negativo, devuelvo la primera   
		pos = 0;

	return lista[pos];
}
///////////////////////////////////////////////////////////
Escalera* ListaEscaleras::detectaEscalerasSubir(Jugador& jugador){
	
	for (int i = 0; i < num; i++) {
		if (Interaccion::detectaEscaleraSubir(jugador, *lista[i]))
			return lista[i];
	}
	return 0;
}

Escalera* ListaEscaleras::detectaEscalerasBajar(Jugador& jugador) {

	for (int i = 0; i < num; i++) {
		if (Interaccion::detectaEscaleraBajar(jugador, *lista[i]))
			return lista[i];
	}
	return 0;
}


Escalera* ListaEscaleras::jugadorArriba(Jugador& jugador) {

	for (int i = 0; i < num; i++) {
		if (Interaccion::arribaEscalera(jugador, *lista[i]))
			return lista[i];
	}
	return 0;
}

Escalera* ListaEscaleras::jugadorAbajo(Jugador& jugador) {

	for (int i = 0; i < num; i++) {
		if (Interaccion::abajoEscalera(jugador, *lista[i]))
			return lista[i];
	}
	return 0;
}
