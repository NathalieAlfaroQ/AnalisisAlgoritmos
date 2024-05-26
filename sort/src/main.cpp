// g++ -o main src/*.cpp -Iinclude/ -g -Werror -Wall -O3
// ./main 

#include "../include/Ordenador.h"
#include <iostream>
#include <chrono>
#include <ctime>
#include <cstdlib>
#include <limits>
#include <cstring>

using namespace std;
using namespace chrono;

// Funcion para llenar los arreglos con numeros aleatorios
void llenarArreglo(int arreglo[], int n)
{
    srand(time(nullptr));
    int minimo = -100;
    int maximo = 100;

    for (int i = 0; i < n; ++i)
    {
        arreglo[i] = minimo + rand() % (maximo - minimo + 1);
    } // Fin for
} // Fin llenarArreglo

int main()
{
    Ordenador ordenador;

    // Creacion del arreglo
    // 50 000 - 100 000 - 150 000 - 200 000
    const int tamano = 10000000;
    int* vector = new int[tamano](); //pasar al heap
    llenarArreglo(vector, tamano);

    // Medir el tiempo del ordenamiento
    auto tiempo1 = high_resolution_clock::now();
    ordenador.radixsort(vector, tamano);
    auto tiempo2 = high_resolution_clock::now();
    auto duracion = duration_cast<milliseconds>(tiempo2 - tiempo1);

    // Prueba que indica que falla
    for (int i = 1; i < tamano; i++)
    {
        if (vector[i] < vector[i - 1])
        {
            cout << "FALLA" << endl;
        } // Fin if
    }     // Fin for

    cout << "Correcto." << endl;
    cout << "Tiempo " << duracion.count() << " milisegundos." << endl;

    delete vector;
} // Fin main

