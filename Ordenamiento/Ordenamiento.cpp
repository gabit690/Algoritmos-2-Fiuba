
#include <iostream>
#include "Ordenamiento.h"

using namespace std;

void Ordenamiento::selectionSort(int* arr, int tope)
{
	for (int elemento = 1; elemento < tope-1; elemento++)
	{
		Ordenamiento::acomodarSS(arr, tope, elemento);
	}
}

void Ordenamiento::acomodarSS(int* arr, int tope, int posAnalizada)
{
	int posMasChico = posAnalizada;

	for (int indice = posMasChico + 1; indice < tope; indice++)
	{
		if (arr[posMasChico] > arr[indice])
		{
			posMasChico = indice;
		}
	}

	if (arr[posMasChico] < arr[posAnalizada - 1])
	{
		int valorAuxiliar = arr[posAnalizada - 1];

		arr[posAnalizada - 1] = arr[posMasChico];

		arr[posMasChico] = valorAuxiliar;
	}
}

void Ordenamiento::insertionSort(int* arr, int tope)
{
	for (int elemento = 1; elemento <= tope; elemento++)
	{
		Ordenamiento::acomodarIS(arr, tope, elemento);
	}
}

void Ordenamiento::acomodarIS(int* arr, int tope, int posAnalizada)
{
	bool acomodado = posAnalizada == 1;

	while (!acomodado && posAnalizada > 1)
	{
		acomodado = arr[posAnalizada - 1] >= arr[posAnalizada - 2];

		if (!acomodado)
		{
			int valorAuxiliar = arr[posAnalizada - 1];

			arr[posAnalizada - 1] =  arr[posAnalizada - 2];

			arr[posAnalizada - 2] = valorAuxiliar;

			posAnalizada--;
		}

	}
}

void Ordenamiento::shellSort(int *arr, int tope)
{
	int separacion = tope / 2;

	while (separacion > 0)
	{
		for (int elemento = 1; elemento <= tope; elemento++)
		{
			if ((elemento - 1) + separacion < tope)
			{
				if (arr[(elemento - 1) + separacion] < arr[elemento - 1])
				{
					int valorElemento = arr[elemento - 1];

					arr[elemento - 1] = arr[(elemento - 1) + separacion];

					arr[(elemento - 1) + separacion] = valorElemento;

				}
			}
		}

		separacion /= 2;
	}

	for (int indice = 0; indice < tope - 1; indice++) {

		if (arr[indice + 1] < arr[indice])
		{
			int valorElemento = arr[indice + 1];

			arr[indice + 1] = arr[indice];

			arr[indice] = valorElemento;

		}
	}
}

void Ordenamiento::bubbleSort(int* arr, int tope)
{
	for (int recorrido = 1; recorrido <= tope - 1 ; recorrido++)
	{
		for (int indice = 0; indice < tope -1; indice++)
		{
			if (arr[indice] > arr[indice + 1]) {

				int valorAuxiliar = arr[indice + 1];

				arr[indice + 1] = arr[indice];

				arr[indice] = valorAuxiliar;
			}
		}
	}
}

void Ordenamiento::bubbleSortWF(int *arr, int tope)
{
	bool vectorFueModificado = false;

	do {

		for (int indice = 0; indice < tope - 1; indice++)
		{
			if (arr[indice] > arr[indice + 1])
			{
				int valorAuxiliar = arr[indice + 1];

				arr[indice + 1 ] = arr[indice];

				arr[indice] = valorAuxiliar;

				vectorFueModificado = true;
			}
		}

		tope--;

	} while (vectorFueModificado && tope > 1);
}

void Ordenamiento::quickSort(int* arr, int indiceIzquierdo, int indiceDerecho)
{
	if (indiceIzquierdo < indiceDerecho)
	{
		int posicionPivote = Ordenamiento::ubicarPivote(arr, indiceIzquierdo, indiceDerecho);

		Ordenamiento::quickSort(arr, indiceIzquierdo, posicionPivote-1);

		Ordenamiento::quickSort(arr, posicionPivote + 1, indiceDerecho);
	}
}

int Ordenamiento::ubicarPivote(int* arr, int indiceIzquierdo, int indiceDerecho)
{
	int posicionPivote = (indiceIzquierdo + indiceDerecho) / 2;

	while (indiceIzquierdo < indiceDerecho)
	{
		if (arr[indiceIzquierdo] >= arr[posicionPivote] && arr[indiceDerecho] <= arr[posicionPivote])
		{
			if (indiceIzquierdo == posicionPivote)
			{
				posicionPivote = indiceDerecho;
			}
			else
			{
				if (indiceDerecho == posicionPivote)
				{
					posicionPivote = indiceIzquierdo;
				}
			}


			int valorAuxiliar = arr[indiceDerecho];

			arr[indiceDerecho] = arr[indiceIzquierdo];

			arr[indiceIzquierdo] = valorAuxiliar;

			indiceIzquierdo++;

			indiceDerecho--;
		}
		else
		{
			if (arr[indiceIzquierdo] < arr[posicionPivote])
			{
				indiceIzquierdo++;
			}
			if (arr[indiceDerecho] > arr[posicionPivote])
			{
				indiceDerecho--;
			}
		}
	}
	return posicionPivote;
}

void Ordenamiento::showContent(int* arr, int tope)
{
	for (int indice = 0; indice < tope; indice++)
	{
		cout << arr[indice] << endl;
	}

}
