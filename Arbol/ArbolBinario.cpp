
#include <iostream>
#include "ArbolBinario.h"


using namespace std;

ArbolBinario::ArbolBinario()
{
	this->raiz = NULL;
}

bool ArbolBinario::estaVacio()
{
	return (this->raiz == NULL);
}

bool ArbolBinario::pertenece(int elemento)
{
	bool encontrado = false;

	NodoAB<int>* analizado = this->raiz;

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

void ArbolBinario::altaIterativa(int nuevo)
{
	if (this->raiz == NULL)
	{
		NodoAB<int>* nuevoElemento = new NodoAB<int>(nuevo);

		this->raiz = nuevoElemento;
	}
	else
	{
		if(!pertenece(nuevo))
		{
			bool agregado = false;

			NodoAB<int>* analizado = this->raiz;

			while (!agregado)
			{
				if (nuevo < analizado->obtenerDato())
				{
					if (analizado->obtenerHijoIzquierdo() == NULL)
					{
						NodoAB<int>* nuevoElemento = new NodoAB<int>(nuevo, analizado);

						analizado->asignarHijoIzquierdo(nuevoElemento);

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

void ArbolBinario::altaRecursiva(int nuevo)
{
	if (this->raiz == NULL)
	{
		NodoAB<int>* nuevoNodo = new NodoAB<int>(nuevo);

		this->raiz = nuevoNodo;
	}
	else{
		if (!pertenece(nuevo))
		{
			alta(this->raiz, nuevo);
		}
	}
}

NodoAB<int>* ArbolBinario::buscarNodo(NodoAB<int>* nodo, int elemento)
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

void ArbolBinario::alta(NodoAB<int>* nodo, int nuevo)
{
	if (nodo->obtenerDato() > nuevo)
	{
		if (nodo->obtenerHijoIzquierdo() == NULL)
		{
			nodo->asignarHijoIzquierdo(new NodoAB<int>(nuevo, nodo));
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
		}
		else
		{
			alta(nodo->obtenerHijoDerecho(), nuevo);
		}
	}
}

void ArbolBinario::bajaIterativa(int elemento)
{
	if (pertenece(elemento))
	{
		bool encontrado = false;

		NodoAB<int>* candidato = this->raiz;

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
void ArbolBinario::borrarNodoSinHijos(NodoAB<int>* nodo)
{
	if (this->raiz != nodo)
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
		this->raiz = NULL;
	}

	delete nodo;
}


void ArbolBinario::borrarNodoCon1Hijo(NodoAB<int>* nodo)
{
	if (this->raiz != nodo)
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
		if (this->raiz->obtenerHijoIzquierdo() != NULL)
		{
			this->raiz = this->raiz->obtenerHijoIzquierdo();
		}
		else
		{
			this->raiz = this->raiz->obtenerHijoDerecho();
		}
		this->raiz->asignarPadre(NULL);
	}

	delete nodo;
}

void ArbolBinario::borrarNodoCon2Hijos(NodoAB<int>* nodo)
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

void ArbolBinario::bajaRecursiva(int elemento)
{
	if (pertenece(elemento))
	{
		baja(this->raiz, elemento);
	}
}

void ArbolBinario::baja(NodoAB<int>* nodo, int elemento)
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

void ArbolBinario::mostrarElementosPreOrden()
{
	mostrarPreOrden(this->raiz);
}

void ArbolBinario::mostrarPreOrden(NodoAB<int>* nodo)
{
	if (nodo != NULL)
	{
		cout << "Elemento: " << nodo->obtenerDato() << endl;

		mostrarPreOrden(nodo->obtenerHijoIzquierdo());

		mostrarPreOrden(nodo->obtenerHijoDerecho());
	}
}

void ArbolBinario::mostrarElementosInOrden()
{
	mostrarInOrden(this->raiz);
}

void ArbolBinario::mostrarInOrden(NodoAB<int>* nodo)
{
	if (nodo != NULL)
	{
		mostrarInOrden(nodo->obtenerHijoIzquierdo());

		cout << "Elemento: " << nodo->obtenerDato() << endl;

		mostrarInOrden(nodo->obtenerHijoDerecho());
	}
}

void ArbolBinario::mostrarElementosPostOrden()
{
	mostrarPostOrden(this->raiz);
}

void ArbolBinario::mostrarPostOrden(NodoAB<int>* nodo)
{
	if (nodo != NULL)
	{
		mostrarPostOrden(nodo->obtenerHijoIzquierdo());

		mostrarPostOrden(nodo->obtenerHijoDerecho());

		cout << "Elemento: " << nodo->obtenerDato() << endl;
	}
}

void ArbolBinario::borrarPostOrden(NodoAB<int>* nodo)
{
	if (nodo != NULL)
	{
		borrarPostOrden(nodo->obtenerHijoIzquierdo());

		borrarPostOrden(nodo->obtenerHijoDerecho());

		delete nodo;
	}
}

ArbolBinario::~ArbolBinario()
{
	borrarPostOrden(this->raiz);
}
