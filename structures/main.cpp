// Bibliotecas
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <random>
#include <fstream>

using namespace std;

// Encabezados
#include "llist.h"

// Declaracion de variablees
llist<int> *listaAleatoria(int n);
void busquedaLista(llist<int> *lista, int n);
llist<int> *listaSecuencial(int n);

int main()
{
    // Cantidad de nodos a insertar en la lista
    // 1 000 000
    const int n = 100000;
    // Inicializa una lista enlazada de tipo int con el resultado de la funcion
    // Contiene numeros al azar
    llist<int> *lista1 = listaAleatoria(n);
    // Resultado de la cantidad de busquedas para encontrar a un X aleatorio en la lista
    cout << "Lista 1 de valores aleatorios:" << endl;
    busquedaLista(lista1, n);
    // Inicializa una lista enlazada de tipo int con el resultado de la funcion
    // Contiene numeros ordenados
    llist<int> *lista2 = listaSecuencial(n);
    // Resultado de la cantidad de busquedas para encontrar a un X aleatorio en la lista
    cout << "Lista 2 de valores secuenciales:" << endl;
    busquedaLista(lista2, n);
    // Fin del programa
    return 0;
} // End main

/*
* Esta funcion crea una lista doblemente enlazada de tipo int,
* a la cual se le insertan n nodos, los valores de los nodos
* son numeros aleatorios entre 0 y 2*n, al final se retorna
* la lista.
*/
llist<int> *listaAleatoria(int n)
{
    // Lista doble enlazada de tipo int
    auto lista = new llist<int>();
    // Generar numeros de tipo int al alzar entre 0 y 2*n
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, 2 * n);

    // Insertar n nodos de tipo int de valores aleatorios
    // a una lista doblemente enlazada de tipo int
    for (int i = 0; i < n; i++)
    {
        auto nuevoNodo = new llnode<int>(dist(rng));
        lista->Insert(nuevoNodo);
    } // End for
    return lista;
} // End listaAleatoria

/*
* Esta funcion crea una lista doblemente enlazada de tipo int
* con n nodos, los nodos son de tipo int y poseen valores
* secuenciales que empiezan desde 0 hasta n en orden y se
* retorna la lista.
*/
llist<int> *listaSecuencial(int n)
{
    // Lista doble enlazada de tipo int
    auto lista = new llist<int>();

    // Insertar n nodos de tipo int de valores secuenciales
    // a una lista doblemente enlazada de tipo int
    for (int i = 0; i < n; i++)
    {
        auto nuevoNodo = new llnode<int>(i);
        lista->Insert(nuevoNodo);
    } // End for
    return lista;
} // End listaSecuencial

/*
* Esta funcion vacia cuenta cuantas busquedas se hicieron en maximo 1 segundo
* para encontrar un numero al azar en una lista doblemente enlazada de
* tipo int. Entonces, se inicia el tiempo inicial y se genera un numero
* al azar para buscarlo en la lista con un ciclo, cada busqueda que se
* haga se cuenta y se detiene el tiempo para encontrar la duracion y asi
* verificar que sea como maximo 1 segundo, despues del ciclo se imprime
* la cantidad de busquedas hechas.
*/
void busquedaLista(llist<int> *lista, int n)
{
    // Para contar la cantidad de busquedas
    int busquedas = 0;
    // Inicia a tomar el tiempo
    auto inicio = std::chrono::high_resolution_clock::now();
    // Se genera un numero aleatorio tipo int entre el rango
    // de 0 a 2*n, este es el numero a buscar en la lista
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, 2 * n);

    while (true)
    {
        // Buscar en la lista el numero generado aleatoriamente
        lista->Search(dist(rng));
        // Contar esa busqueda como una unidad
        ++busquedas;
        // Se deja de contar el tiempo
        auto fin = std::chrono::high_resolution_clock::now();
        // Se calcula la duracion en segundos
        auto duracion = std::chrono::duration_cast<std::chrono::seconds>(fin - inicio).count();
        
        // Se verifica que no se exceda de 1 segundo
        if (duracion >= 1)
        {
            break;
        } // End if
    } // End for
    std::cout << "Cantidad de busquedas: " << busquedas << std::endl;
} // End busquedaLista
