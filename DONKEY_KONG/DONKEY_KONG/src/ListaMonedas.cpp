#include "ListaMonedas.h"
#include "Interaccion.h"

///////////////////////////////////CONSTRUCTOR///////////////////////
ListaMonedas::ListaMonedas() {
	num = 0;
	for (int i = 0; i < MAX_NUM; i++) {
		lista[i] = 0;
	}
}

ListaMonedas::~ListaMonedas() {

}

///////////////////////////////////MÉTODOS//////////////////////////
bool ListaMonedas::Agregar(Moneda* moneda) {
	if (num < MAX_NUM) {
		for (int i = 0; i < num; i++) {
			if (lista[i] == moneda) {
				return false;
			}
		}
		lista[num] = moneda;
		num++;
		return true;
	}
	else
		return false;
}

void ListaMonedas::Dibuja() {
	for (int i = 0; i < num; i++) {
		lista[i]->Dibuja();
	}
}

void ListaMonedas::Destruir() {
	for (int i = 0; i < num; i++) {
		delete lista[i];
	}
	num = 0;
}

void ListaMonedas::Delete(int index) {
	if ((index < 0) || (index >= num)) {
		return;
	}
	delete lista[index];
	num--;
	for (int i = index; i < num; i++) {
		//Recorremos la lista desde la posición indicada hasta el 
		//final de la lista. Si por ejemplo eliminamos la Moneda en la posición 2, Muevemos 
		//la posición 3 a la 2, la 4 a la 3 y así sucesivamente hasta num
		lista[i] = lista[i + 1];
	}
}

void ListaMonedas::Delete(Moneda* moneda) {
	for (int i = 0; i < num; i++) {
		if (lista[i] == moneda) {
			Delete(i);
			return;
		}
	}
}

Moneda* ListaMonedas::operator[](int pos) {
	if (pos >= num)//si me paso, devuelvo la ultima   
		pos = num - 1;

	if (pos < 0) //si el indice es negativo, devuelvo la primera   
		pos = 0;

	return lista[pos];
}

/////////////////////////////////////////////////////////
Moneda* ListaMonedas::cogeMonedas(Jugador& jugador) {
	for (int i = 0; i < num; i++) {
		if (Interaccion::detectaMoneda(jugador, *lista[i]))
			return lista[i];
	}
	return 0;
}