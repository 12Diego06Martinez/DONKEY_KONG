#include "ListaEscaleras.h"

////////////////////////////////////CONSTRUCTOR//////////////////////////
ListaEscaleras::ListaEscaleras() {
	//Lista vacia
	num = 0;
	for (int i = 0; i < MAX_NUM; i++) {
		lista[i] = 0;
	}
}

ListaEscaleras::~ListaEscaleras() {

}

///////////////////////////////////METODOS///////////////////////////////
void ListaEscaleras::Dibuja() {
	for (int i = 0; i < num; i++) {
		lista[i]->Dibuja();
	}
}

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
	return false;
}

void ListaEscaleras::destruirContenido() {
	for (int i = 0; i < num; i++) {
		delete lista[i];
	}
	num = 0;
}

void ListaEscaleras::Eliminar(int index) {
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

void ListaEscaleras::Eliminar(Escalera* escalera) {
	for (int i = 0; i < num; i++) {
		if (lista[i] == escalera) {
			Eliminar(i);
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
