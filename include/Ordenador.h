#include <cstring>

#ifndef Ordenador_h
#define Ordenador_h

class Ordenador
{
private:
	// Defina aquí los métodos auxiliares de los algoritmos de ordenamiento solamente.
	// Puede definir cuantos métodos quiera.

	// Intercambia los valores de dos variables enteras utilizando punteros como parámetros
	void cambio(int *a, int *b)
	{
		int temporal = *b; // Operador de desreferenciación (*) para acceder al valor apuntado por el puntero 'b'
		*b = *a;
		*a = temporal;
	} // Fin cambio

	/* Divide recursivamente el arreglo en subarreglos más pequeños, hasta que cada subarreglo
	tenga uno o ningún elemento. Luego, combina los subarreglos ordenados de manera consecutiva
	utilizando la función merge */
	void mergeRecursivo(int *A, int inicio, int final)
	{
		// Verifica si el índice de inicio es menor que el índice final, indicando que hay elementos en el subarreglo a ordenar
		if (inicio < final)
		{
			// Se calcula el punto medio del subarreglo
			int divido = inicio + (final - inicio) / 2;
			// Ordenar la primera mitad del subarreglo
			mergeRecursivo(A, inicio, divido);
			// Ordenar la segunda mitad del subarreglo
			mergeRecursivo(A, divido + 1, final);
			// Merge para combinar las dos mitades ordenadas del subarreglo
			merge(A, inicio, divido, final);
		} // Fin if
	} // Fin mergeRecursivo

	// Combinar dos subarreglos ordenados en uno solo
	void merge(int *A, int izquierda, int divido, int derecha)
	{
		// Calcular los tamaños de los dos subarreglos a fusionar
		int tamano1 = divido - izquierda + 1;
		int tamano2 = derecha - divido;
		// Arreglos temporales para almacenar los elementos de los subarreglos
		int arreglo1[tamano1], arreglo2[tamano2];

		// Se copian los elementos de los subarreglos originales en los arreglos temporales
		for (int i = 0; i < tamano1; i++)
		{
			arreglo1[i] = A[izquierda + i];
		} // Fin for

		for (int j = 0; j < tamano2; j++)
		{
			arreglo2[j] = A[divido + 1 + j];
		} // Fin for

		// Fusionar los dos arreglos temporales en el arreglo original
		int i = 0;
		int j = 0;
		int k = izquierda;

		while (i < tamano1 && j < tamano2)
		{
			if (arreglo1[i] <= arreglo2[j])
			{
				A[k] = arreglo1[i];
				i++;
			}
			else
			{
				A[k] = arreglo2[j];
				j++;
			} // Fin if
			k++;
		} // Fin while

		// Copiar los elementos restantes del primer subarreglo, si hay
		while (i < tamano1)
		{
			A[k] = arreglo1[i];
			i++;
			k++;
		} // Fin while

		// Se copian los elementos restantes del segundo subarreglo, si hay
		while (j < tamano2)
		{
			A[k] = arreglo2[j];
			j++;
			k++;
		} // Fin while
	} // Fin merge

	/* Divide el arreglo en dos subarreglos alrededor de un pivote
	y coloca los elementos menores a su izquierda y los mayores a su derecha */
	int particion(int *A, int inicio, int fin)
	{
		// Selecciona el último elemento del arreglo como pivote
		int pivote = A[fin];
		// Inicializa el índice del elemento más pequeño, que se incrementará 
		//cuando se encuentre un elemento menor que el pivote
		int i = (inicio - 1);

		// Itera sobre el subarreglo desde el índice de inicio hasta el índice de fin - 1
		for (int j = inicio; j <= fin - 1; j++)
		{
			if (A[j] < pivote) // Si actual menor que pivote
			{
				i++; // Incremente el indice del elemento mas pequeno
				cambio(&A[i], &A[j]);
			} // Fin if
		} // Fin for
		cambio(&A[i + 1], &A[fin]);
		return (i + 1); // Indice del pivote
	} // Fin particion

	/* Ordenar los subarreglos izquierdo y derecho del pivote, hasta que todos
	los subarreglos sean de longitud uno o cero, lo que significa que
	el arreglo está ordenado */
	void actualQuickSort(int *A, int inicio, int fin)
	{
		// Verifica si el índice de inicio es menor que el índice final, lo 
		//que indica que hay más de un elemento en el subarreglo
		if (inicio < fin)
		{
			// Divide el arreglo en dos subarreglos y obtiene el índice del elemento pivote
			int medio = particion(A, inicio, fin);
			// Ordenar el subarreglo izquierdo del pivote
			actualQuickSort(A, inicio, medio - 1);
			// Ordenar el subarreglo derecho del pivote
			actualQuickSort(A, medio + 1, fin);
		} // Fin if
	} // Fin actualQuickSort

	// Garantiza que la propiedad del montículo se cumpla en un subárbol con raíz en el nodo i
	void monticulos(int *A, int n, int i)
	{
		// Selecciona el nodo actual como el máximo
		int maximo = i;
		int izquierda = (2 * i) + 1;
		int derecha = (2 * i) + 2;

		// Comparación con el hijo izquierdo
		if (izquierda < n && A[izquierda] > A[maximo])
		{
			maximo = izquierda;
		} // Fin if

		// Comparación con el hijo derecho
		if (derecha < n && A[derecha] > A[maximo])
		{
			maximo = derecha;
		} // Fin if

		// Si el máximo no es el nodo actual, se intercambia y se realiza la recursión
		if (maximo != i)
		{
			cambio(&A[i], &A[maximo]);
			monticulos(A, n, maximo);
		} // Fin if
	} // Fin monticulos

public:
	Ordenador(){};
	~Ordenador(){};
	// Si no implementa algunos de los métodos de ordenamiento no lo borre;
	// déjelo con el cuerpo vacío para evitar errores de compilación, ya
	// que se va a ejecutar el mismo «main» para todas las tareas.
	// Implemente los algoritmos en este archivo, no en un CPP.

	// Los comento porque fue la forma en la que me compila

	/*void seleccion(int *A, int n);
	void insercion(int *A, int n);
	void mergesort(int *A, int n);
	void heapsort(int *A, int n);
	void quicksort(int *A, int n);
	void radixsort(int *A, int n);*/

	// Recorre el arreglo y en cada iteración selecciona el elemento más pequeño y lo pone al inicio
	void seleccion(int *A, int n)
	{
		// Itera sobre todo el arreglo, menos el último elemento
		for (int i = 0; i < n - 1; i++)
		{
			int min = i; // Se asume que el elemento actual es el mínimo
			// Itera sobre el resto del arreglo para encontrar el mínimo
			for (int j = i + 1; j < n; j++)
			{
				if (A[j] < A[min]) // Si actual es menor que el minimo encontrado
				{
					min = j; // Actualiza el índice del mínimo
				} // Fin if
			} // Fin for

			if (min != i) // Mínimo no está en su posición original
			{
				cambio(&A[i], &A[min]);
			} // Fin if
		} // Fin for
	} // Fin seleccion

	/* Recorre el arreglo y en cada iteración coloca el elemento actual
	en la posición correcta dentro de la parte ya ordenada del arreglo */
	void insercion(int *A, int n)
	{
		// Itera sobre todo el arreglo, comenzando desde el segundo elemento
		for (int i = 1; i < n; i++)
		{
			int j = i;
			while (j > 0 && A[j - 1] > A[j])
			{
				cambio(&A[j], &A[j - 1]);
				j--;
			} // Fin while
		} // Fin for
	} // Fin insercion

	// Algoritmo de ordenamiento Merge Sort
	void mergesort(int *A, int n)
	{
		mergeRecursivo(A, 0, n - 1);
	} // Fin mergesort

	/* Algoritmo de ordenamiento no comparativo que funciona separando los
	elementos a ordenar en "dígitos" y ordenándolos de manera sucesiva en
	función de cada uno */
	void radixsort(int *A, int n)
	{
		// Arreglo temporal para almacenar resultados intermedios
		auto *arregloTemporal = new int[n];
		int largoBit = sizeof(int) * 8;
		int contador[2];
		int prefijo[2];

		// Máscara para manejo de números negativos
		int mascara = 1;
		int numerosNegativos = 0;
		int numerosPositivos = 0;
		unsigned int valorBit;

		// Unión que contiene float e int 
		union ufi
		{
			float f;
			int i;
		} ufi;

		// Itera de bit menos significativo a más significativo
		for (int shift = 0; shift < largoBit; ++shift)
		{
			// Inicializa arreglo
			for (int i = 0; i < 2; ++i)
			{
				contador[i] = 0;
			} // Fin for

			// Cuenta cuántas veces aparece el valor del bit en el arreglo
			for (int i = 0; i < n; ++i)
			{
				ufi.f = A[i];
				valorBit = (ufi.i >> shift) & mascara;
				contador[valorBit]++;
				// Cuenta número negativos durante primera iteración
				if (shift == 0 && A[i] < 0)
				{
					numerosNegativos++;
				} // Fin if
			}

			// Cuenta números positivos
			if (shift == 0)
			{
				numerosPositivos = n - numerosNegativos;
			} // Fin if

			// Calcula prefijos acumulativos en "contador"
			prefijo[0] = 0;
			for (int i = 1; i < 2; ++i)
			{
				prefijo[i] = prefijo[i - 1] + contador[i - 1];
			} // Fin for

			// Distribuye números en A basándose en valor de bit actual
			for (int i = 0; i < n; ++i)
			{
				ufi.f = A[i];
				valorBit = (ufi.i >> shift) & mascara;
				int index = prefijo[valorBit]++;
				// Ajusta índices para manejar negativos en última iteración
				if (shift == largoBit - 1)
				{
					if (A[i] < 0)
					{
						index = numerosPositivos - (index - numerosNegativos) - 1;
					}
					else
					{
						index += numerosNegativos;
					} // Fin if
				} // Fin if
				// Almacena elemento en arreglo temporal (en posición calculada)
				arregloTemporal[index] = A[i];
			} // Fin for
			// Copia elementos de "arregloTemporal" en A
			memcpy(A, arregloTemporal, sizeof(int) * n);
		} // Fin for
		delete[] arregloTemporal; // Libera memoria
	} // Fin radixsort

	//  Algoritmo de ordenamiento Quicksort
	void quicksort(int *A, int n)
	{
		actualQuickSort(A, 0, n);
	} // Fin quicksort

	void heapSort(int *A, int n)
	{
		// Hace el monticulo
		for (int i = (n / 2 - 1); i >= 0; i--)
		{
			monticulos(A, n, i);
		} // Fin for

		// Ordena el monticulo
		for (int i = (n - 1); i > 0; i--)
		{
			cambio(&A[0], &A[i]);
			monticulos(A, i, 0); // Restaura la propiedad del montículo en el subárbol restante
		} // Fin for
	} // Fin heapSort
}; // Fin class
#endif
