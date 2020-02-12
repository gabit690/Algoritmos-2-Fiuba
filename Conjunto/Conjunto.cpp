
#include <iostream>
#include "Conjunto.h"

using namespace std;

Conjunto::Conjunto()
{
	this->primero = NULL;

	this->elementos = 0;
}

bool Conjunto::pertenece(int elemento)
{
	bool encontrado = false;

	NodoAB<int>* analizado = this->primero;

	while((analizado != NULL) && !encontrado)
	{
		encontrado = (analizado->obtenerDato() == elemento);

		if (!encontrado)
		{
			if ( elemento < analizado->obtenerDato())
			{
				analizado = analizado->obtenerHijoIzquierdo();
			}
			else
			{
				analizado = analizado->obtenerHijoDerecho();
			}
		}
	}

	return encontrado;
}

void Conjunto::altaIterativa(int nuevo)
{
	if (this->primero == NULL)
	{
		NodoAB<int>* nuevoElemento = new NodoAB<int>(nuevo);

		this->primero = nuevoElemento;

		this->elementos++;
	}
	else
	{
		if(!pertenece(nuevo))
		{
			bool agregado = false;

			NodoAB<int>* analizado = this->primero;

			while (!agregado)
			{
				if (nuevo < analizado->obtenerDato())
				{
					if (analizado->obtenerHijoIzquierdo() == NULL)
					{
						NodoAB<int>* nuevoElemento = new NodoAB<int>(nuevo, analizado);

						analizado->asignarHijoIzquierdo(nuevoElemento);

						this->elementos++;

						agregado = true;
					}
					else
					{
						analizado = analizado->obtenerHijoIzquierdo();
					}

				}
				else
				{
					if (analizado->obtenerHijoDerecho() == NULL)
					{
						NodoAB<int>* nuevoElemento = new NodoAB<int>(nuevo, analizado);

						analizado->asignarHijoDerecho(nuevoElemento);

						this->elementos++;

						agregado = true;
					}
					else
					{
						analizado = analizado->obtenerHijoIzquierdo();
					}
				}
			}
		}
	}
}

void Conjunto::altaRecursiva(int nuevo)
{
	if (this->primero == NULL)
	{
		NodoAB<int>* nuevoNodo = new NodoAB<int>(nuevo);

		this->primero = nuevoNodo;

		this->elementos++;
	}
	else{
		if (!pertenece(nuevo))
		{
			alta(this->primero, nuevo);
		}
	}
}

NodoAB<int>* Conjunto::buscarNodo(NodoAB<int>* nodo, int elemento)
{
	if(nodo != NULL){
		if (nodo->obtenerDato() == elemento)
		{
			return nodo;
		}
		else
		{
			if (nodo->obtenerDato() < elemento)
			{
				buscarNodo(nodo->obtenerHijoDerecho(), elemento);
			}
			else
			{
				buscarNodo(nodo->obtenerHijoIzquierdo(), elemento);
			}
			return buscarNodo(nodo, elemento);
		}
	}
	else
	{
		return NULL;
	}
}

void Conjunto::alta(NodoAB<int>* nodo, int nuevo)
{
	if (nodo->obtenerDato() > nuevo)
	{
		if (nodo->obtenerHijoIzquierdo() == NULL)
		{
			nodo->asignarHijoIzquierdo(new NodoAB<int>(nuevo, nodo));

			this->elementos++;
		}
		else
		{
			alta(nodo->obtenerHijoIzquierdo(), nuevo);
		}
	}
	else
	{
		if (nodo->obtenerHijoDerecho() == NULL)
		{
			nodo->asignarHijoDerecho(new NodoAB<int>(nuevo, nodo));

			this->elementos++;
		}
		else
		{
			alta(nodo->obtenerHijoDerecho(), nuevo);
		}
	}
}

void Conjunto::bajaIterativa(int elemento)
{
	if (pertenece(elemento))
	{
		bool encontrado = false;

		NodoAB<int>* candidato = this->primero;

		while (!encontrado)
		{
			if(elemento == candidato->obtenerDato())
			{
				encontrado = true;
			}
			else
			{
				if (elemento < candidato->obtenerDato())
				{
					candidato = candidato->obtenerHijoIzquierdo();
				}
				else {
					candidato = candidato->obtenerHijoDerecho();
				}
			}

		}

		switch (candidato->contarHijos())
		{
			case 0: borrarNodoSinHijos(candidato);
					break;
			case 1: borrarNodoCon1Hijo(candidato);
					break;
			case 2: borrarNodoCon2Hijos(candidato);
		}
	}
}
void Conjunto::borrarNodoSinHijos(NodoAB<int>* nodo)
{
	if (this->primero != nodo)
	{
		NodoAB<int>* padre = nodo->obtenerPadre();

		if (padre->obtenerHijoIzquierdo() == nodo)
		{
			padre->asignarHijoIzquierdo(NULL);
		}
		else
		{
			padre->asignarHijoDerecho(NULL);
		}
	}
	else
	{
		this->primero = NULL;
	}

	delete nodo;

	this->elementos--;
}


void Conjunto::borrarNodoCon1Hijo(NodoAB<int>* nodo)
{
	if (this->primero != nodo)
	{
		NodoAB<int>* padre = nodo->obtenerPadre();

		if (padre->obtenerHijoIzquierdo() == nodo)
		{
			if (nodo->obtenerHijoIzquierdo() != NULL)
			{
				padre->asignarHijoIzquierdo(nodo->obtenerHijoIzquierdo());

				nodo->obtenerHijoIzquierdo()->asignarPadre(padre);
			}
			else
			{
				padre->asignarHijoIzquierdo(nodo->obtenerHijoDerecho());

				nodo->obtenerHijoDerecho()->asignarPadre(padre);
			}
		}
		else
		{
			if (nodo->obtenerHijoIzquierdo() != NULL)
			{
				padre->asignarHijoDerecho(nodo->obtenerHijoIzquierdo());

				nodo->obtenerHijoIzquierdo()->asignarPadre(padre);
			}
			else
			{
				padre->asignarHijoDerecho(nodo->obtenerHijoDerecho());

				nodo->obtenerHijoDerecho()->asignarPadre(padre);
			}
		}
	}
	else
	{
		if (this->primero->obtenerHijoIzquierdo() != NULL)
		{
			this->primero = this->primero->obtenerHijoIzquierdo();
		}
		else
		{
			this->primero = this->primero->obtenerHijoDerecho();
		}
		this->primero->asignarPadre(NULL);
	}

	delete nodo;

	this->elementos--;
}

void Conjunto::borrarNodoCon2Hijos(NodoAB<int>* nodo)
{
	NodoAB<int>* borrado = nodo->obtenerHijoIzquierdo();

	while (borrado->obtenerHijoDerecho() != NULL)
	{
		borrado = borrado->obtenerHijoDerecho();
	}

	nodo->cambiarDato(borrado->obtenerDato());

	if (borrado->contarHijos() != 0)
	{
		borrarNodoCon1Hijo(borrado);
	}
	else
	{
		borrarNodoSinHijos(borrado);
	}
}

void Conjunto::bajaRecursiva(int elemento)
{
	if (pertenece(elemento))
	{
		baja(this->primero, elemento);
	}
}

void Conjunto::baja(NodoAB<int>* nodo, int elemento)
{
	if (nodo->obtenerDato() == elemento)
	{
		switch(nodo->contarHijos())
		{
			case 0: borrarNodoSinHijos(nodo);
					break;
			case 1: borrarNodoCon1Hijo(nodo);
					break;
			case 2: borrarNodoCon2Hijos(nodo);
		}
	}
	else
	{
		if (nodo->obtenerDato() > elemento)
		{
			baja(nodo->obtenerHijoIzquierdo(), elemento);
		}
		else
		{
			baja(nodo->obtenerHijoDerecho(), elemento);
		}
	}
}

unsigned int Conjunto::obtenerCantidadDeElementos()
{
	return this->elementos;
}

void Conjunto::mostrarElementosPreOrden()
{
	mostrarPreOrden(this->primero);
}

void Conjunto::mostrarPreOrden(NodoAB<int>* nodo)
{
	if (nodo != NULL)
	{
		cout << "Elemento: " << nodo->obtenerDato() << endl;

		mostrarPreOrden(nodo->obtenerHijoIzquierdo());

		mostrarPreOrden(nodo->obtenerHijoDerecho());
	}
}

void Conjunto::mostrarElementosInOrden()
{
	mostrarInOrden(this->primero);
}

void Conjunto::mostrarInOrden(NodoAB<int>* nodo)
{
	if (nodo != NULL)
	{
		mostrarInOrden(nodo->obtenerHijoIzquierdo());

		cout << "Elemento: " << nodo->obtenerDato() << endl;

		mostrarInOrden(nodo->obtenerHijoDerecho());
	}
}

void Conjunto::mostrarElementosPostOrden()
{
	mostrarPostOrden(this->primero);
}

void Conjunto::mostrarPostOrden(NodoAB<int>* nodo)
{
	if (nodo != NULL)
	{
		mostrarPostOrden(nodo->obtenerHijoIzquierdo());

		mostrarPostOrden(nodo->obtenerHijoDerecho());

		cout << "Elemento: " << nodo->obtenerDato() << endl;
	}
}

void Conjunto::borrarPostOrden(NodoAB<int>* nodo)
{
	if (nodo != NULL)
	{
		borrarPostOrden(nodo->obtenerHijoIzquierdo());

		borrarPostOrden(nodo->obtenerHijoDerecho());

		delete nodo;
	}
}

Conjunto::~Conjunto()
{
	borrarPostOrden(this->primero);
}
