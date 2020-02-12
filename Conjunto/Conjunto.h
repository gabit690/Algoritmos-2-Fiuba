
#ifndef CONJUNTO_CONJUNTO_H_
#define CONJUNTO_CONJUNTO_H_

#ifndef NULL
#define NULL 0
#endif

#include "NodoAB.h"

/*
 * Un conjunto es una colecion de elementos que no tiene
 * elementos repetidos.
 */
class Conjunto {

	private:

		NodoAB<int>* primero;

		unsigned int elementos;

	public:

		/*
		 * POST: Crea un conjunto con 0 elementos contenidos.
		 */
		Conjunto();

		/*
		 * POST: Indica si 'elemento' esta dentro del conjunto.
		 */
		bool pertenece(int elemento);

		/*
		 * PRE: la funcion pertenece(nuevo) devuelve false.
		 * POST: Agrega a 'nuevo' en el conjunto.
		 * Si el elemento ya existia previamente entonces
		 * no realiza ningun cambio.
		 */
		void altaIterativa(int nuevo);

		/*
		 * PRE: la funcion pertenece(nuevo) devuelve false.
		 * POST: Agrega a 'nuevo' en el conjunto.
		 * Si el elemento ya existia previamente entonces
		 * no realiza ningun cambio.
		 */
		void altaRecursiva(int nuevo);

		/*
		 * PRE: la funcion pertenece(elemento) devuelve true.
		 * POST: quita a 'elemento' del conjunto
		 */
		void bajaIterativa(int elemento);

		/*
		 * PRE: la funcion pertenece(elemento) devuelve true.
		 * POST: quita a 'elemento' del conjunto
		 */
		void bajaRecursiva(int elemento);

		/*
		 * POST: Indica la cantidad de elementos que
		 * contiene el conjunto.
		 */
		unsigned int obtenerCantidadDeElementos();

		/*
		 * POST: Muestra por pantalla los elementos que
		 * estan en el conjunto siguiendo un recorrido
		 * y procesamiento pre orden.
		 */
		void mostrarElementosPreOrden();

		/*
		 * POST: Muestra por pantalla los elementos que
		 * estan en el conjunto siguiendo un recorrido
		 * y procesamiento inorden.
		 */
		void mostrarElementosInOrden();

		/*
		 * POST: Muestra por pantalla los elementos que
		 * estan en el conjunto siguiendo un recorrido
		 * y procesamiento post orden.
		 */
		void mostrarElementosPostOrden();

		/*
		 * POST: Libera los recursos tomados por el conjunto.
		 */
		~Conjunto();

	private:

		/*
		 * PRE: la funcion pertenece(elemento) devuelve true.
		 * POST: Devuelve el nodo que tiene como dato a 'elemento'.
		 */
		NodoAB<int>* buscarNodo(NodoAB<int>* nodo, int elemento);

		/*
		 * PRE: Se invoco al metodo altaRecursiva(nuevo) para agregar un elemento.
		 * POST: Agrega a 'nuevo' en el conjunto.
		 * Si el elemento ya existia previamente entonces
		 * no realiza ningun cambio.
		 */
		void alta(NodoAB<int>* nodo, int nuevo);

		/*
		 * PRE: Se invoco al metodo bajaRecursiva() para sacar un elemento.
		 * POST: Quita a 'elemento' del conjunto.
		 */
		void baja(NodoAB<int>* nodo, int elemento);

		/*
		 * PRE: 'nodo' no tiene hijo izquierdo ni derecho.
		 * POST: Quita a 'nodo' del conjunto disminuyendo el tamanio
		 * del conjunto en una unidad.
		 */
		void borrarNodoSinHijos(NodoAB<int>* nodo);

		/*
		 * PRE: 'nodo' solo tiene un hijo.
		 * POST: Quita a 'nodo' del conjunto disminuyendo el tamanio
		 * del conjunto en una unidad y manteniendo la estructura de
		 * arbol binario de busqueda.
		 */
		void borrarNodoCon1Hijo(NodoAB<int>* nodo);

		/*
		 * PRE: 'nodo' tiene hijo izquierdo y derecho.
		 * POST: Quita a 'nodo' del conjunto disminuyendo el tamanio
		 * del conjunto en una unidad y manteniendo la estructura de
		 * arbol binario de busqueda.
		 */
		void borrarNodoCon2Hijos(NodoAB<int>* nodo);

		/*
		 * POST: muestra por pantalla los elementos del conjunto
		 * procesando de la siguiente manera:
		 * 1° procesa a 'apuntado'.
		 * 2° procesa su subarbol izquierdo.
		 * 3° procesa su subarbol derecho.
		 */
		void mostrarPreOrden(NodoAB<int>* apuntado);

		/*
		 * POST: muestra por pantalla los elementos del conjunto
		 * procesando de la siguiente manera:
		 * 1° procesa su subarbol izquierdo.
		 * 2° procesa a 'apuntado'.
		 * 3° procesa su subarbol derecho.
		 */
		void mostrarInOrden(NodoAB<int>* apuntado);

		/*
		 * POST: muestra por pantalla los elementos del conjunto
		 * procesando de la siguiente manera:
		 * 1° procesa su subarbol izquierdo.
		 * 2° procesa su subarbol derecho.
		 * 3° procesa a 'apuntado'.
		 */
		void mostrarPostOrden(NodoAB<int>* apuntado);

		/*
		 * POST: elimina los nodos del conjunto y libera la
		 * memoria pedida siguiendo este orden:
		 * 1° procesa su subarbol izquierdo.
		 * 2° procesa su subarbol derecho.
		 * 3° procesa a 'apuntado'.
		 */
		void borrarPostOrden(NodoAB<int>* apuntado);

};

#endif /* CONJUNTO_CONJUNTO_H_ */
