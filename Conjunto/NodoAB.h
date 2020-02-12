
#ifndef CONJUNTO_NODOAB_H_
#define CONJUNTO_NODOAB_H_

#ifndef NULL
#define NULL 0
#endif

/*
 * Un nodoAB es la minima porcion de un arbol binario el cual
 * contiene un dato y puede tener un hijo izquierdo o derecho.
 */
template <typename T> class NodoAB {

	private:

		T dato;

		NodoAB<T>* padre;

		NodoAB<T>* izquierdo;

		NodoAB<T>* derecho;

	public:

		/*
		 * POST: Crea un nodo de un arbol binario que contiene
		 * el dato pasado por parametro.
		 * El nodo no tiene hijo izquierdo ni derecho.
		 */
		NodoAB(T dato, NodoAB<T>* padre = NULL);

		/*
		 * POST: El nodo cambia su contenido a 'dato'.
		 */
		void cambiarDato(T dato);

		/*
		 * POST: El nodo tiene a 'nodo' como padre.
		 */
		void asignarPadre(NodoAB<T>* nodo);

		/*
		 * POST: El nodo tiene a 'nodo' como hijo izquierdo.
		 */
		void asignarHijoIzquierdo(NodoAB<T>* nodo);

		/*
		 * POST: El nodo tiene a 'nodo' como hijo derecho.
		 */
		void asignarHijoDerecho(NodoAB<T>* nodo);

		/*
		 * POST: Devuelve el dato contenido en el nodo;
		 */
		T obtenerDato();

		/*
		 * POST: Devuelve su padre.
		 */
		NodoAB<T>* obtenerPadre();

		/*
		 * POST: Devuelve su hijo izquierdo.
		 */
		NodoAB<T>* obtenerHijoIzquierdo();

		/*
		 * POST: Devuelve su hijo derecho.
		 */
		NodoAB<T>* obtenerHijoDerecho();

		/*
		 * POST: Indica la cantidad de hijos que tiene.
		 */
		unsigned int contarHijos();
};

template <typename T> NodoAB<T>::NodoAB(T dato, NodoAB<T>* padre)
{
	this->dato = dato;

	this->padre = padre;

	this->izquierdo = NULL;

	this->derecho = NULL;
}

template <typename T> void NodoAB<T>::cambiarDato(T dato)
{
	this->dato = dato;
}

template <typename T> void NodoAB<T>::asignarPadre(NodoAB<T>* nodo)
{
	this->padre = nodo;
}

template <typename T> void NodoAB<T>::asignarHijoIzquierdo(NodoAB<T>* nodo)
{
	this->izquierdo = nodo;
}

template <typename T> void NodoAB<T>::asignarHijoDerecho(NodoAB<T>* nodo)
{
	this->derecho = nodo;
}

template <typename T> T NodoAB<T>::obtenerDato()
{
	return this->dato;
}

template <typename T> NodoAB<T>* NodoAB<T>::obtenerPadre()
{
	return this->padre;
}

template <typename T> NodoAB<T>* NodoAB<T>::obtenerHijoIzquierdo()
{
	return this->izquierdo;
}

template <typename T> NodoAB<T>* NodoAB<T>::obtenerHijoDerecho()
{
	return this->derecho;
}

template <typename T> unsigned int NodoAB<T>::contarHijos()
{
	unsigned int cantidadDeHijos = 0;

	if (this->izquierdo != NULL) {
		cantidadDeHijos++;
	}
	if (this->derecho != NULL) {
		cantidadDeHijos++;
	}

	return cantidadDeHijos;
}

#endif /* CONJUNTO_NODOAB_H_ */
