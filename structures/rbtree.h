//  rbtree.h
// Arbol roji negro

// Encabezado
#ifndef rbtree_h
#define rbtree_h

// Bibliotecas
#include <iostream>

enum colors {RED, BLACK};

// Nodos del arbol:
template <typename T>
class rbtnode
{
public:
    // Esta clase es usada por la clase rbtree. Por eficiencia se hacen los atributos publicos.
    T key;
    rbtnode<T> *p, *left, *right;
    enum colors color;
    
    // Constructor por omision.
    rbtnode() {
    };
    
    //Inicializacion de datos miembro.
    rbtnode (const T& k, rbtnode<T> *w = nullptr, rbtnode<T> *y = nullptr, rbtnode<T> *z = nullptr, enum colors c = RED): key(k), p(w), left(y), right(z), color(c) {};
    
    // Destructor
    ~rbtnode() {
    };
}; // End class rbtnode

// Arbol rojinegro:
template <typename T>
class rbtree {
public:
    rbtnode<T> *root;    // raiz del arbol
    rbtnode<T> *nil;     // nodo nil (hoja) del arbol
    
    rbtree() {
        // Constructor (crea un arbol vacio)
    };
    
    ~rbtree() {
        // Destructor (borra el arbol)
    };

    leftRotate (T, x) {
        y = x->right;
        x->right = y->left;

        if (y->left != T->nil) {
            y->left->p = x;
        } // End if

        y->p = x->p;

        if (x->p == T->nil) {
            T->root = y;
        } else if (x == x->p->left) {
            x->p->left = y;
        } else {
            x->p->right = y;
        } // End if

        y->left = x;
        x->p = y;
    } // End leftRotate
    
    insertFixUp(T, z) {
        while (z->p->color == RED) {

            if (z->p == z->p->p->left) {
                y = z->p->p->right;

                if (y->color == RED) {
                    z->p->color = BLACK;
                    y->color = BLACK;
                    z->p->p->color = RED;
                    z = z->p->p;
                } else {
                    if (z == z->p->right) {
                        z = z->p;
                        leftRotate(T, z);
                    } // End if
                    z->p->color = BLACK;
                    z->p->p->color = RED;
                    rightRotate(T, z->p->p);
                } // End if
            } else { 
                y = z->p->p->left;

                if (y->color == RED) {
                    z->p->color = BLACK;
                    y->color = BLACK;
                    z->p->p->color = RED;
                    z = z->p->p;
                } else {
                    if (z == z->p->left) {
                        z = z->p;
                        rightRotate(T, z);
                    } // End if
                    z->p->color = BLACK;
                    z->p->p->color = RED;
                    leftRotate(T, z->p->p);
                } // End if
            } // End if
        } // End while
        T->root->color = BLACK;
    } // End insertFixUp

    void Insert(rbtnode<T>* z) {
        // Inserta el nodo z en la posicion que le corresponde en el arbol.
        x = T->root;
        y = T->nil;

        while (x != T->nil) {
            y = x;

            if (z->key < x->key) {
                x = x->left;
            } else {
                x = x->right;
            } // End if
        } // End while

        z->p = y;

        if (y == T->nil) {
            T->root = z;
        } else if (z->key < y->key) {
            y->left = z;
        } else {
            y->right = z;
        } // End if

        z->left = T->nil;
        z->right = T->nil;
        z->color = RED;

        insertFixUp(T, z);
    };
    
    void InorderWalk(rbtnode<T> *x) {
        // Recorre en orden el subarbol con raiz x, imprimiendo la llave de cada nodo en en una nueva linea de la salida estandar despues de recorrido el subarbol izquierdo y antes de recorrer el subarbol derecho.
    };
    
    rbtnode<T>* Search(rbtnode<T> *x, const T& k) {
        // Busca la llave k iterativamente en el subarbol con raiz x. Si la encuentra devuelve un apuntador al nodo que la contiene, sino devuelve el nodo nil.
    };
    
    rbtnode<T>* IterativeSearch(rbtnode<T> *x, const T& k) {
        // Busca la llave k iterativamente en el subarbol con raiz x. Si la encuentra devuelve un apuntador al nodo que la contiene, sino devuelve el nodo nil.
    };
    
    rbtnode<T>* Minimum(rbtnode<T> *x) {
        // Devuelve el nodo que tiene la llave menor. Si el arbol esta vacio, devuelve el nodo nil.
    };
    
    rbtnode<T>* Maximum(rbtnode<T> *x) {
        // Devuelve el nodo que tiene la llave mayor. Si el arbol esta vacio devuelve el nodo nil.
    };
    
    rbtnode<T>* Successor(rbtnode<T> *x) {
        // Devuelve el nodo cuya llave es la que le sigue a la del nodo x. Si no existe el nodo, devuelve el nodo nil.
    };
}; // End class rbtree

#endif /* rbtree_h */
