
#include <iostream>
#include "Ordenamiento/Ordenamiento.h"
#include "Conjunto/Conjunto.h"

int main () {

	Conjunto* coleccion1 = new Conjunto();

	coleccion1->agregar(5);
	coleccion1->agregar(1);
	coleccion1->agregar(10);

	std::cout << "Contenido:" << std::endl << std::endl;

	coleccion1->mostrarElementos();

	std::cout << "Tamanio: " << coleccion1->obtenerCantidadDeElementos();

	delete coleccion1;

	return 0;
}


