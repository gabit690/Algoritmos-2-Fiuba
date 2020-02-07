
#ifndef ORDENAMIENTO_H_
#define ORDENAMIENTO_H_

class Ordenamiento {

	public:

		static void selectionSort(int* arr, int tope);

		static void insertionSort(int* arr, int tope);

		static void shellSort(int* arr, int tope);

		static void bubbleSort(int* arr, int tope);

		static void bubbleSortWF(int* arr, int tope);

		static void quickSort(int* arr, int indiceIzquierdo, int indiceDerecho);

		static void showContent(int* arr, int tope);

	private:

		static void acomodarSS(int* arr, int tope, int posAnalizada);

		static void acomodarIS(int* arr, int tope, int posAnalizada);

		static int ubicarPivote(int* arr, int indiceIzquierdo, int indiceDerecho);
};

#endif /* ORDENAMIENTO_H_ */
