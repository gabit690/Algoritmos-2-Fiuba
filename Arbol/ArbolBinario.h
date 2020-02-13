
#ifndef ARBOL_ARBOLBINARIO_H_
#define ARBOL_ARBOLBINARIO_H_

#include "NodoAB.h"

/*
 * Un arbol binario es una estructura jerarquica de nodos compuesta
 * por un nodo raiz que es el primero de la estructura.
 * Cada nodo excepto la raiz tiene un unico padre y puede
 * tener 0, 1 o 2 hijos.
 */
class ArbolBinario {

	private:

		NodoAB<int>* raiz;

	public:

		/*
		 * POST: Crea un arbol binario de enteros sin nodos.
		 */
		ArbolBinario();

		/*
		 * POST: Indica si el arbol tiene elementos almacenados.
		 */
		bool estaVacio();

		/*
		 * POST: Indica si 'elemento' esta dentro del arbol binario.
		 */
		bool pertenece(int elemento);

		/*
		 * PRE: el metodo pertenece(nuevo) devuelve false.
		 * POST: Agrega a 'nuevo' en el arbol binario.
		 * Si el elemento ya existia previamente entonces
		 * no realiza ningun cambio.
		 */
		void altaIterativa(int nuevo);

		/*
		 * PRE: el metodo pertenece(nuevo) devuelve false.
		 * POST: Agrega a 'nuevo' en el arbol binario.
		 * Si el elemento ya existia previamente entonces
		 * no realiza ningun cambio.
		 */
		void altaRecursiva(int nuevo);

		/*
		 * PRE: el metodo pertenece(elemento) devuelve true.
		 * POST: quita a 'elemento' del arbol binario
		 */
		void bajaIterativa(int elemento);

		/*
		 * PRE: el metodo pertenece(elemento) devuelve true.
		 * POST: quita a 'elemento' del arbol binario
		 */
		void bajaRecursiva(int elemento);

		/*
		 * POST: Muestra por pantalla los elementos que
		 * estan en el arbol binario siguiendo un recorrido
		 * y procesamiento pre orden.
		 */
		void mostrarElementosPreOrden();

		/*
		 * POST: Muestra por pantalla los elementos que
		 * estan en el arbol binario siguiendo un recorrido
		 * y procesamiento inorden.
		 */
		void mostrarElementosInOrden();

		/*
		 * POST: Muestra por pantalla los elementos que
		 * estan en el arbol binario siguiendo un recorrido
		 * y procesamiento post orden.
		 */
		void mostrarElementosPostOrden();

		///// Metodos de practica. Borrar los que luego no sean utiles

		/*
		 * PRE: El arbol tiene almacenado al menos un elemento.
		 * POST: Indica cual es el elemento mas chico de los almacenados.
		 */
		unsigned int elementoMasChico();

		/*
		 * PRE: El arbol tiene almacenado al menos un elemento.
		 * POST: Indica cual es el elemento mas grande de los almacenados.
		 */
		unsigned int elementoMasGrande();

		/*
		 * POST: Indica en que nivel del arbol se encuentra 'elemento'
		 * o -1 si no es un elemento dentro del arbol.
		 */
		unsigned int nivelDeElemento(int elemento);

		/*
		 * PRE: el metodo estaVacio() devuelve false.
		 * POST: Indica el nivel del arbol que tiene mas nodos que el resto.
		 * En el caso de que hayan otros nivel con la misma cantidad se
		 * indica el primer nivel de todos ellos.
		 */
		unsigned int nivelConMasNodos();

		/*
		 * POST: Indica la altura que tiene el arbol.
		 * Segun el autor Cormen la altura es la cantidad de enlaces desde la raiz
		 * de un arbol hasta su nodo mas lejano.
		 * Un arbol sin raiz se considera de altura 0.
		 */
		unsigned int obtenerAlturaCormen();

		/*
		 * POST: Indica la altura que tiene el arbol.
		 * Segun el autor Drozdek la altura es la cantidad de niveles del arbol.
		 * Un arbol sin raiz se considera de altura -1.
		 */
		unsigned int obtenerAlturaDrozdek();

		/*
		 * PRE: 'diferencia' es un numero positivo y el metodo estaVacio() devuelve false.
		 * POST: Indica si el arbol esta balanceado segun la diferencia evaluada.
		 * El balanceo de un arbol tiene que cumplir:
		 * |altura de subarbol izquierdo de raiz - altura de subarbol derecho de raiz | <= diferencia.
		 */
		bool estaBalanceado(unsigned int diferencia);

		/*
		 * PRE: 'otroArbol' es un arbol binario no vacio de enteros.
		 * POST: Indica si el arbol es simetrico en forma al arbol pasado por parametro.
		 */
		bool sonSimetricos(const ArbolBinario* otroArbol);

		/*
		 * PRE: 'otroArbol' es un arbol binario no vacio de enteros.
		 * POST: Devuelve la union de los elementos entre los arboles.
		 */
		ArbolBinario* obtenerUnion(const ArbolBinario* otroArbol);

		/*
		 * PRE: 'otroArbol' es un arbol binario no vacio de enteros.
		 * POST: Devuelve la interseccion de los elementos entre los arboles.
		 */
		ArbolBinario* obtenerInterseccion(const ArbolBinario* otroArbol);

		////**************************************************************************


		/*
		 * POST: Libera los recursos tomados por el arbol binario.
		 */
		~ArbolBinario();

	private:

		/*
		 * PRE: el metodo pertenece(elemento) devuelve true.
		 * POST: Indica el nodo que tiene como dato a 'elemento'.
		 */
		NodoAB<int>* buscarNodo(NodoAB<int>* nodo, int elemento);

		/*
		 * PRE: Se invoco al metodo altaRecursiva(nuevo) para agregar un elemento.
		 * POST: Agrega a 'nuevo' en el arbol binario.
		 * Si el elemento ya existia previamente entonces
		 * no realiza ningun cambio.
		 */
		void alta(NodoAB<int>* nodo, int nuevo);

		/*
		 * PRE: Se invoco al metodo bajaRecursiva(elemento) para sacar un elemento.
		 * POST: Quita a 'elemento' del arbol binario.
		 */
		void baja(NodoAB<int>* nodo, int elemento);

		/*
		 * PRE: 'nodo' no tiene hijo izquierdo ni derecho.
		 * POST: Quita a 'nodo' del arbol binario.
		 */
		void borrarNodoSinHijos(NodoAB<int>* nodo);

		/*
		 * PRE: 'nodo' solo tiene un hijo.
		 * POST: Quita a 'nodo' manteniendo la estructura de
		 * arbol binario de busqueda.
		 */
		void borrarNodoCon1Hijo(NodoAB<int>* nodo);

		/*
		 * PRE: 'nodo' tiene hijo izquierdo y derecho.
		 * POST: Quita a 'nodo' manteniendo la estructura de
		 * arbol binario de busqueda.
		 */
		void borrarNodoCon2Hijos(NodoAB<int>* nodo);

		/*
		 * POST: muestra por pantalla los elementos del arbol binario
		 * procesando de la siguiente manera:
		 * 1° procesa a 'apuntado'.
		 * 2° procesa su subarbol izquierdo.
		 * 3° procesa su subarbol derecho.
		 */
		void mostrarPreOrden(NodoAB<int>* apuntado);

		/*
		 * POST: muestra por pantalla los elementos del arbol binario
		 * procesando de la siguiente manera:
		 * 1° procesa su subarbol izquierdo.
		 * 2° procesa a 'apuntado'.
		 * 3° procesa su subarbol derecho.
		 */
		void mostrarInOrden(NodoAB<int>* apuntado);

		/*
		 * POST: muestra por pantalla los elementos del arbol binario
		 * procesando de la siguiente manera:
		 * 1° procesa su subarbol izquierdo.
		 * 2° procesa su subarbol derecho.
		 * 3° procesa a 'apuntado'.
		 */
		void mostrarPostOrden(NodoAB<int>* apuntado);

		/*
		 * POST: elimina los nodos del arbol binario y libera la
		 * memoria pedida siguiendo este orden:
		 * 1° procesa su subarbol izquierdo.
		 * 2° procesa su subarbol derecho.
		 * 3° procesa a 'apuntado'.
		 */
		void borrarPostOrden(NodoAB<int>* apuntado);
};

#endif /* ARBOL_ARBOLBINARIO_H_ */
