
#include <iostream>
#include "Ordenamiento/Ordenamiento.h"
#include "Conjunto/Conjunto.h"

int main () {

	Conjunto* coleccion1 = new Conjunto();

	coleccion1->altaRecursiva(5);
	coleccion1->altaRecursiva(1);
	coleccion1->altaRecursiva(10);

	std::cout << "Contenido Pre Orden." << std::endl << std::endl;

	coleccion1->mostrarElementosPreOrden();

	std::cout << "Contenido In Orden." << std::endl << std::endl;

	coleccion1->mostrarElementosInOrden();

	std::cout << "Contenido Post Orden." << std::endl << std::endl;

	coleccion1->mostrarElementosPostOrden();

	delete coleccion1;

	return 0;
}


