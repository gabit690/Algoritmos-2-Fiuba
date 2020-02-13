
#ifndef CONJUNTO_CONJUNTO_H_
#define CONJUNTO_CONJUNTO_H_

#ifndef NULL
#define NULL 0
#endif

#include "../Arbol/ArbolBinario.h"

/*
 * Un conjunto es una coleccion de enteros que no tiene
 * valores repetidos.
 */
class Conjunto {

	private:

		ArbolBinario* datos;

		unsigned int elementos;

	public:

		/*
		 * POST: Crea un conjunto con 0 elementos contenidos.
		 */
		Conjunto();

		/*
		 * POST: Indica si 'elemento' esta dentro del conjunto.
		 */
		bool esta(int elemento);

		/*
		 * PRE: la funcion esta(nuevo) devuelve false.
		 * POST: Agrega a 'nuevo' en el conjunto aumentando
		 * su tamanio en una unidad.
		 * Si el elemento ya existia previamente entonces
		 * no realiza ningun cambio.
		 */
		void agregar(int nuevo);

		/*
		 * PRE: la funcion esta(elemento) devuelve true.
		 * POST: quita a 'elemento' y reduce el tamanio
		 * del conjunto en una unidad.
		 */
		void quitar(int elemento);

		/*
		 * POST: Indica la cantidad de elementos que
		 * contiene el conjunto.
		 */
		unsigned int obtenerCantidadDeElementos();

		/*
		 * POST: Muestra por pantalla los elementos que
		 * estan en el conjunto de menor a mayor.
		 */
		void mostrarElementos();

		/*
		 * POST: Libera los recursos tomados por el conjunto.
		 */
		~Conjunto();
};

#endif /* CONJUNTO_CONJUNTO_H_ */
