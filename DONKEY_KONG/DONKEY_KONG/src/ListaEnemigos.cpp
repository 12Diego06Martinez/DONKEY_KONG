#include "ListaEnemigos.h"
#include "Interaccion.h"

///////////////////////////////////CONSTRUCTOR///////////////////////
ListaEnemigos::ListaEnemigos() {
	num = 0;
	for (int i = 0; i < MAX_NUM; i++) {
		lista[i] = 0;
	}
}

ListaEnemigos::~ListaEnemigos() {

}

///////////////////////////////////MÉTODOS//////////////////////////
bool ListaEnemigos::Agregar(Enemigo* enemigo) {
	if (num < MAX_NUM) {
		for (int i = 0; i < num; i++) {
			if (lista[i] == enemigo) {
				return false;
			}
		}
		lista[num] = enemigo;
		num++;
		return true;
	}
	else
		return false;
}

void ListaEnemigos::Dibuja() {
	for (int i = 0; i < num; i++) {
		lista[i]->Dibuja();
	}
}

void ListaEnemigos::Mueve(float t) {
	for (int i = 0; i < num; i++) {
		lista[i]->Mueve(t);
	}
}

void ListaEnemigos::Destruir() {
	for (int i = 0; i < num; i++) {
		delete lista[i];
	}
	num = 0;
}

void ListaEnemigos::Delete(int index) {
	if ((index < 0) || (index >= num)) {
		return;
	}
	delete lista[index];
	num--;
	for (int i = index; i < num; i++) {
		//Recorremos la lista desde la posición indicada hasta el 
		//final de la lista. Si por ejemplo eliminamos la Enemigo en la posición 2, Muevemos 
		//la posición 3 a la 2, la 4 a la 3 y así sucesivamente hasta num
		lista[i] = lista[i + 1];
	}
}

void ListaEnemigos::Delete(Enemigo* enemigo) {
	for (int i = 0; i < num; i++) {
		if (lista[i] == enemigo) {
			Delete(i);
			return;
		}
	}
}

Enemigo* ListaEnemigos::operator[](int pos) {
	if (pos >= num)//si me paso, devuelvo la ultima   
		pos = num - 1;

	if (pos < 0) //si el indice es negativo, devuelvo la primera   
		pos = 0;

	return lista[pos];
}

///////////////////////////////////////////////////////////
Enemigo* ListaEnemigos::colisionEnemigos(Jugador& jugador) {
	for (int i = 0; i < num; i++) {
		if (Interaccion::colisionEnemigo(jugador, *lista[i]))
			return lista[i];
	}
	return 0;
}