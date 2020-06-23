#include "ListaEstaticos.h"

////////////////////////////////////CONSTRUCTOR//////////////////////////
ListaEstaticos::ListaEstaticos() {
	//Lista vacia
	num = 0;
	for (int i = 0; i < MAX_NUM; i++) {
		lista[i] = 0;
	}
}

ListaEstaticos::~ListaEstaticos() {

}

///////////////////////////////////METODOS///////////////////////////////
void ListaEstaticos::Dibuja() {
	for (int i = 0; i < num; i++) {
		lista[i]->Dibuja();
	}
}

bool ListaEstaticos::Agregar(ElementoEstatico* elemento) {
	if (num < MAX_NUM) {
		for (int i = 0; i < num; i++) {
			if (lista[i] == elemento) {
				return false;
			}
		}
		lista[num] = elemento;
		num++;
		return true;
	}
	return false;
}

void ListaEstaticos::destruirContenido() {
	for (int i = 0; i < num; i++) {
		delete lista[i];
	}
	num = 0;
}

void ListaEstaticos::Eliminar(int index) {
	if ((index < 0) || (index >= num)) {
		return;
	}
	delete lista[index];
	num--;

	for (int i = index; i < num; i++) {
		//Movemos los objetos una posición a partir del indice eliminado
		lista[i] = lista[i + 1];
	}
}

void ListaEstaticos::Eliminar(ElementoEstatico* elemento) {
	for (int i = 0; i < num; i++) {
		if (lista[i] == elemento) {
			Eliminar(i);
			return;
		}
	}
}

ElementoEstatico* ListaEstaticos::operator[](int pos) {
	if (pos >= num)//si me paso, devuelvo la ultima   
		pos = num - 1;

	if (pos < 0) //si el indice es negativo, devuelvo la primera   
		pos = 0;

	return lista[pos];
}
