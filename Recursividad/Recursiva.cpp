/*
 * Recursiva.cpp
 *
 *  Created on: 27 ene. 2020
 *      Author: Josecito
 */

#include "Recursiva.h"

int Recursiva::factorial(int numero) {

	if ( numero == 0 || numero == 1) {

		return 1;

	} else {

		return factorial(numero - 1) * numero;
	}
}

int Recursiva::fibonacci(int posicion) {

	if (posicion == 0 || posicion == 1) {

		return 1;

	} else {

		return fibonacci(posicion - 1) + fibonacci(posicion -2);
	}
}

int Recursiva::mcd(int valor1, int valor2) {

	if (valor1 < valor2){

		return mcd(valor2, valor1);

	} else {

	   if( valor1 % valor2 == 0) {

		   return valor2;

	   } else {

		   return mcd(valor2, valor1 % valor2);

	   }
	}

}

bool Recursiva::esPar(int num) {
    if (num == 1)
        return false;
    else
        return Recursiva::esImpar(num-1);
}

bool Recursiva::esImpar(int num){
    if (num == 1)
        return true;
    else
        return Recursiva::esPar(num-1);
}

int Recursiva::ackerman(int valor1, int valor2) {
	if(valor1==0) {

		return valor2 + 1;

	} else {

		if(valor2 == 0) {

			return ackerman(valor1-1, 1);

		} else

			return ackerman(valor1-1, ackerman(valor1, valor2-1));

	    }

	}
