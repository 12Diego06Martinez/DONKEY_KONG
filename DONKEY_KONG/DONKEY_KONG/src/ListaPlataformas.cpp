#include "ListaPlataformas.h"

////////////////////////////////////CONSTRUCTOR//////////////////////////
ListaPlataformas::ListaPlataformas() {
	//Lista vacia
	num = 0;
	for (int i = 0; i < MAX_NUM; i++) {
		lista[i] = 0;
	}
}

ListaPlataformas::~ListaPlataformas() {

}

///////////////////////////////////METODOS///////////////////////////////
void ListaPlataformas::Dibuja() {
	for (int i = 0; i < num; i++) {
		lista[i]->Dibuja();
	}
}

bool ListaPlataformas::Agregar(Plataforma* plataforma) {
	if (num < MAX_NUM) {
		for (int i = 0; i < num; i++) {
			if (lista[i] == plataforma) {
				return false;
			}
		}
		lista[num] = plataforma;
		num++;
		return true;
	}
	return false;
}

void ListaPlataformas::destruirContenido() {
	for (int i = 0; i < num; i++) {
		delete lista[i];
	}
	num = 0;
}

void ListaPlataformas::Eliminar(int index) {
	if ((index < 0) || (index >=num)) {
		return;
	}
	delete lista[index];
	num--;

	for (int i = index; i < num; i++) {
		//Movemos los objetos una posición a partir del indice eliminado
		lista[i] = lista[i + 1];
	}
}

void ListaPlataformas::Eliminar(Plataforma* plataforma) {
	for (int i = 0; i < num; i++) {
		if (lista[i] == plataforma) {
			Eliminar(i);
			return;
		}
	}
}

Plataforma* ListaPlataformas::operator[](int pos) {
	if (pos >= num)//si me paso, devuelvo la ultima   
		pos = num - 1;

	if (pos < 0) //si el indice es negativo, devuelvo la primera   
		pos = 0;

	return lista[pos];
}

