
#include <iostream>
#include "Ordenamiento/Ordenamiento.h"

int main () {

	int tope = 8;

	int* arreglo = new int[tope];

	arreglo[0] = 4;
	arreglo[1] = 3;
	arreglo[2] = 1;
	arreglo[3] = 0;
	arreglo[4] = 2;
	arreglo[5] = 5;
	arreglo[6] = 1;
	arreglo[7] = 9;


	std::cout << "ARREGLO ORIGINAL." << std::endl << std::endl;

	Ordenamiento::showContent(arreglo, tope);

	Ordenamiento::quickSort(arreglo, 0, 7);

	std::cout << std::endl << "ARREGLO ORDENADO." << std::endl << std::endl;

	Ordenamiento::showContent(arreglo, tope);

	delete[] arreglo;

	return 0;
}


