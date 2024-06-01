// g++ -o main main.cpp
// ./main

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
#include "bstree.h"

// Declaracion de metodos:
// Para listas doblemente enlazadas
llist<int> *listaAleatoria(int n);
llist<int> *listaSecuencial(int n);
void busquedaLista(llist<int> *lista, int n);
// Para arboles de busqueda binaria
bstree<int> *arbolAleatorio(int n);
void busquedaArbol(bstree<int> *arbol, int n);
bstree<int> *arbolSecuencial(int n);

int main()
{
    // Cantidad de nodos a insertar en la lista
    // 1 000 000
    const int n = 1000000;

    // Listas doblemente enlazadas:
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

    cout << endl;

    // Arboles de busqueda binaria:
    // Hacer un arbol de tipo int con numeros aleatorios de n nodos
    bstree<int> *arbol1 = arbolAleatorio(n);
    // Resultado de la cantidad de busquedas para encontrar a un X aleatorio en el arbol
    cout << "Arbol 1 de valores aleatorios:" << endl;
    busquedaArbol(arbol1, n);
    // Hacer un arbol de tipo int con numeros en secuencia de n nodos
    bstree<int> *arbol2 = arbolSecuencial(n);
    // Resultado de la cantidad de busquedas para encontrar a un X aleatorio en el arbol
    cout << "Arbol 2 de valores secuenciales:" << endl;
    busquedaArbol(arbol2, n);

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

/*
 * Esta funcion crea un arbol de busqueda binaria de tipo
 * int con n nodos de tipo int, los nodos a insertar estan
 * en un rango de 0 a 2*n ya que seran aleatorios, al final
 * se retorna este arbol.
 */
bstree<int> *arbolAleatorio(int n)
{
    // Crea un arbol de tipo int
    auto arbol = new bstree<int>();
    // Generar numeros de tipo int al alzar entre 0 y 2*n
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, 2 * n);

    // Insertar n nodos de tipo int de valores aleatorios
    // a un arbol de busqueda binaria de tipo int
    for (int i = 0; i < n; i++)
    {
        auto nuevoNodo = new bstnode<int>(dist(rng));
        arbol->Insert(nuevoNodo);
    } // End for
    return arbol;
} // End arbolAleatorio

/*
 * Esta funcio crea un arbol de busqueda binaria de tipo int
 * con n nodos de tipo int, los nodos a insertar tienen
 * valores secuenciales, es decir, que estan ordenados y
 * al final se retorna dicho arbol.
 */
bstree<int> *arbolSecuencial(int n)
{
    // Crea un arbol de tipo int
    auto arbol = new bstree<int>();

    // Insertar n nodos de tipo int de valores secuenciales
    // a un arbol de busqueda binaria de tipo int
    for (int i = 0; i < n; i++)
    {
        auto nuevoNodo = new bstnode<int>(i);
        arbol->Insert(nuevoNodo);
    } // End for
    return arbol;
} // Eznd arbolSecuencial

/*
 * Esta funcion tiene un contador llamado busquedas que
 * contara la cantidad de busquedas que se hicieron en el
 * arbol para encontrar un valor especifico que se genero
 * aleatoriamente, ademas, se cuenta el tiempo en segundos
 * ya que no se puede tardar en buscar ese numero mas de 1
 * segundo y luego se imprime el resultado.
 */
void busquedaArbol(bstree<int> *arbol, int n)
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
        arbol->IterativeSearch(arbol->root, dist(rng));
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
} // End busquedaArbol