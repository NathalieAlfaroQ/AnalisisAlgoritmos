// bstree.h
// Arbol de busqueda binaria

#ifndef bstree_h
#define bstree_h

#include <iostream>

// Nodos del arbol de tipo T:
template <typename T>
class bstnode
{
public:
    // Esta clase es usada por otras clases
    // Para mayor eficiencia, los atributos se hacen publicos
    // Llave del nodo de tipo T
    T key;
    // Nodo padre, izquierdo y derecho de tipo T
    bstnode<T> *p, *left, *right;
    
    // Constructor por omision
    bstnode() {
    }; // End bstnode
    
    // Inicializacion de datos miembro
    bstnode(const T& k, bstnode<T> *w = nullptr, bstnode<T> *y = nullptr, bstnode<T> *z = nullptr):key(k), p(w), left(y), right(z) {};
    
    ~bstnode() {
    }; // End ~bstnode
}; // End class bstnode

// Arbol de busqueda binario de tipo T:
template <typename T>
class bstree
{
public:
    // Raiz del arbol
    bstnode<T> *root;    

    // Constructor (crea un arbol vacio)
    bstree() {
    }; // End bstree
    
    // Destructor (borra el arbol)
    ~bstree() {
    }; // End ~bstree
    
    // Inserta el nodo z en la posicion que le corresponde en el arbol
    void Insert(bstnode<T>* z) {
    }; // End Insert
    
    /*
    * Recorre en orden el subarbol con raiz x, imprimiendo la llave
    * de cada nodo en una nueva linea de la salida estandar despues 
    * del recorrido el subarbol izquierdo y antes de recorrer ek
    * subarbol derecho.
    */
    void InorderWalk(bstnode<T> *x) {
         if (x != nullptr) {
        // Recorrer el subarbol izquierdo
        InorderWalk(x->left);

        // Imprime nodo actual
        std::cout << x->key << std::endl;

        // Recorrer el subarbol derecho
        InorderWalk(x->right);
      } // End if
    }; // End InorderWalk
    
    /*
    * Busca la llave k recursivamente en el subarbol con raiz x.
    * Si la encuentra devuelve un apuntador al nodo que la contiene,
    * sino devuelve nullptr.
    */
    bstnode<T>* Search(bstnode<T> *x, const T& k) {
        if (x == nullptr || k == x->key) {
            return x;
        } else if (k < x->key) {
            return Search(x->left, k);
        } else {
            return Search(x->right, k);
        } // End if
    }; // End Search
    
    /*
    * Busca la llave k iterativamente en el subarbol con raiz x.
    * Si la encuentra devuelve un apuntador al nodo que la contiene, 
    * sino devuelve nullptr.
    */
    bstnode<T>* IterativeSearch(bstnode<T> *x, const T& k) {
        while (x != nullptr && k != x->key)
        {
            if (k < x->key) {
                x = x->left;
            } else {
                x = x->right;
            } // End if
        } // End while
        return x;
    }; // End IterativeSearch
    
    // Devuelve el nodo que tiene la llave menor. Si el arbol esta vacio, devuelve nullptr.
    bstnode<T>* Minimum(bstnode<T> *x) {
        while (x->left != nullptr) {
            x = x->left;
        } // End while
        return x;
    }; // End Minimum
    
    // Devuelve el nodo que tiene la llave mayor. Si el arbol esta vacio devuelve nullptr.
    bstnode<T>* Maximum(bstnode<T> *x) {
        while (x->right != nullptr) {
            x = x->right;
        } // End while
        return x;
    }; // End Maximum
    
    // Devuelve el nodo cuya llave es la que le sigue a la del nodo x. Si no existe el nodo, devuelve nullptr.
    bstnode<T>* Successor(bstnode<T> *x) {
        if (x->right != nullptr) {
            return Minimum(x->right);
        } else {
            bstnode<T>* y = x->p;
            while (y != nullptr && x == y->right) {
                x = y;
                y = y->p;
            } // End while
            return y;
        } // End if
    }; // End Successor
    
    // Saca del arbol la llave contenida en el nodo apuntado por z.
    void Delete(bstnode<T>* z) {
    }; // End Delete
}; // End class bstree

#endif /* bstree_h */