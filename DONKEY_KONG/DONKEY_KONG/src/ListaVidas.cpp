#include "ListaVidas.h"

///////////////////////////////////CONSTRUCTOR///////////////////////
ListaVidas::ListaVidas() {
	num = 0;
	for (int i = 0; i < MAX_NUM; i++) {
		lista[i] = 0;
	}
}

ListaVidas::~ListaVidas() {

}

///////////////////////////////////MÉTODOS//////////////////////////
bool ListaVidas::Agregar(Vidas* vida) {
	if (num < MAX_NUM) {
		for (int i = 0; i < num; i++) {
			if (lista[i] == vida) {
				return false;
			}
		}
		lista[num] = vida;
		num++;
		return true;
	}
	else
		return false;
}

void ListaVidas::Dibuja() {
	for (int i = 0; i < num; i++) {
		lista[i]->Dibuja();
	}
}

void ListaVidas::Destruir() {
	for (int i = 0; i < num; i++) {
		delete lista[i];
	}
	num = 0;
}

void ListaVidas::Delete(int index) {
	if ((index < 0) || (index >= num)) {
		return;
	}
	delete lista[index];
	num--;
	for (int i = index; i < num; i++) {
		//Recorremos la lista desde la posición indicada hasta el 
		//final de la lista. Si por ejemplo eliminamos la Vida en la posición 2, Muevemos 
		//la posición 3 a la 2, la 4 a la 3 y así sucesivamente hasta num
		lista[i] = lista[i + 1];
	}
}

void ListaVidas::Delete(Vidas* vida) {
	for (int i = 0; i < num; i++) {
		if (lista[i] == vida) {
			Delete(i);
			return;
		}
	}
}

Vidas* ListaVidas::operator[](int pos) {
	if (pos >= num)//si me paso, devuelvo la ultima   
		pos = num - 1;

	if (pos < 0) //si el indice es negativo, devuelvo la primera   
		pos = 0;

	return lista[pos];
}