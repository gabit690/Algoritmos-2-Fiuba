
#include <iostream>
#include "Conjunto.h"

using namespace std;

Conjunto::Conjunto()
{
	this->datos = new ArbolBinario();

	this->elementos = 0;
}

bool Conjunto::esta(int elemento)
{
	return this->datos->pertenece(elemento);
}

void Conjunto::agregar(int nuevo)
{
	if (!esta(nuevo))
	{
		this->datos->altaIterativa(nuevo);

		this->elementos++;
	}
}

void Conjunto::quitar(int elemento)
{
	if (esta(elemento))
	{
		this->datos->bajaIterativa(elemento);

		this->elementos--;
	}
}

unsigned int Conjunto::obtenerCantidadDeElementos()
{
	return this->elementos;
}

void Conjunto::mostrarElementos()
{
	this->datos->mostrarElementosInOrden();
}

Conjunto::~Conjunto()
{
	delete this->datos;
}
