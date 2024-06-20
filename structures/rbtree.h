//  rbtree.h
// Arbol roji negro

// Encabezado
#ifndef rbtree_h
#define rbtree_h

// Bibliotecas
#include <iostream>

enum colors
{
    RED,
    BLACK
};

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
    rbtnode() : p(nullptr), left(nullptr), right(nullptr), color(RED) {}

    // Inicializacion de datos miembro.
    rbtnode(const T &k, rbtnode<T> *w = nullptr, rbtnode<T> *y = nullptr, rbtnode<T> *z = nullptr, enum colors c = RED) : key(k), p(w), left(y), right(z), color(c){};

    // Destructor
    ~rbtnode(){};
}; // End class rbtnode

// Arbol rojinegro:
template <typename T>
class rbtree
{
public:
    rbtnode<T> *root; // raiz del arbol
    rbtnode<T> *nil;  // nodo nil (hoja) del arbol

    rbtree()
    {
        // Constructor (crea un arbol vacio)
        nil = new rbtnode<T>();
        nil->color = BLACK;
        root = nil;
    };

    ~rbtree()
    {
        // Destructor (borra el arbol)
        destroy_tree(root);
        delete nil;
    };

    void destroy_tree(rbtnode<T> *x)
    {
        if (x != nil)
        {
            destroy_tree(x->left);
            destroy_tree(x->right);
            delete x;
        } // End if
    } // End destroy_tree

    void rightRotate(rbtnode<T> *x)
    {
        rbtnode<T> *y = x->left;
        x->left = y->right;

        if (y->right != nullptr)
        {
            y->right->p = x;
        } // End if

        y->p = x->p;

        if (x->p == nullptr)
        {
            root = y;
        }
        else if (x == x->p->right)
        {
            x->p->left = y;
        }
        else
        {
            x->p->left = y;
        } // End if

        y->right = x;
        x->p = y;
    } // End rightRotate

    void leftRotate(rbtnode<T> *x)
    {
        rbtnode<T> *y = x->right;
        x->right = y->left;

        if (y->left != this->nil)
        {
            y->left->p = x;
        } // End if

        y->p = x->p;

        if (x->p == this->nil)
        {
            this->root = y;
        }
        else if (x == x->p->left)
        {
            x->p->left = y;
        }
        else
        {
            x->p->right = y;
        } // End if

        y->left = x;
        x->p = y;
    } // End leftRotate

    void insertFixUp(rbtnode<T> *z)
    {
        while (z->p->color == RED)
        {

            if (z->p == z->p->p->left)
            {
                rbtnode<T> *y = z->p->p->right;

                if (y->color == RED)
                {
                    z->p->color = BLACK;
                    y->color = BLACK;
                    z->p->p->color = RED;
                    z = z->p->p;
                }
                else
                {
                    if (z == z->p->right)
                    {
                        z = z->p;
                        leftRotate(z);
                    } // End if
                    z->p->color = BLACK;
                    z->p->p->color = RED;
                    rightRotate(z->p->p);
                } // End if
            }
            else
            {
                rbtnode<T> *y = z->p->p->left;

                if (y->color == RED)
                {
                    z->p->color = BLACK;
                    y->color = BLACK;
                    z->p->p->color = RED;
                    z = z->p->p;
                }
                else
                {
                    if (z == z->p->left)
                    {
                        z = z->p;
                        rightRotate(z);
                    } // End if
                    z->p->color = BLACK;
                    z->p->p->color = RED;
                    leftRotate(z->p->p);
                } // End if
            } // End if
        } // End while
        this->root->color = BLACK;
    } // End insertFixUp

    void Insert(rbtnode<T> *z)
    {
        // Inserta el nodo z en la posicion que le corresponde en el arbol.
        rbtnode<T> *x = this->root;
        rbtnode<T> *y = this->nil;

        while (x != this->nil)
        {
            y = x;

            if (z->key < x->key)
            {
                x = x->left;
            }
            else
            {
                x = x->right;
            } // End if
        } // End while

        z->p = y;

        if (y == this->nil)
        {
            this->root = z;
        }
        else if (z->key < y->key)
        {
            y->left = z;
        }
        else
        {
            y->right = z;
        } // End if

        z->left = this->nil;
        z->right = this->nil;
        z->color = RED;

        insertFixUp(z);
    }; // End Insert

    void InorderWalk(rbtnode<T> *x)
    {
        // Recorre en orden el subarbol con raiz x, imprimiendo la llave de cada nodo en en una nueva linea de la salida estandar despues de recorrido el subarbol izquierdo y antes de recorrer el subarbol derecho.
        if (x != nil)
        {
            InorderWalk(x->left);
            std::cout << x->key << std::endl;
            InorderWalk(x->right);
        } // End if
    }; // End InorderWalk

    rbtnode<T> *Search(rbtnode<T> *x, const T &k)
    {
        // Busca la llave k iterativamente en el subarbol con raiz x. Si la encuentra devuelve un apuntador al nodo que la contiene, sino devuelve el nodo nil.
        if (x == nil || k == x->key)
        {
            return x;
        } // End if

        if (k < x->key)
        {
            return Search(x->left, k);
        }
        else
        {
            return Search(x->right, k);
        } // End if
    }; // End Search

    rbtnode<T> *IterativeSearch(rbtnode<T> *x, const T &k)
    {
        // Busca la llave k iterativamente en el subarbol con raiz x. Si la encuentra devuelve un apuntador al nodo que la contiene, sino devuelve el nodo nil.
        while (x != nil && k != x->key)
        {
            if (k < x->key)
            {
                x = x->left;
            }
            else
            {
                x = x->right;
            } // End if
        } // End while
        return x;
    }; // End IterativeSearch

    rbtnode<T> *Minimum(rbtnode<T> *x)
    {
        // Devuelve el nodo que tiene la llave menor. Si el arbol esta vacio, devuelve el nodo nil.
        while (x->left != nil)
        {
            x = x->left;
        } // End while
        return x;
    }; // End Minimum

    rbtnode<T> *Maximum(rbtnode<T> *x)
    {
        // Devuelve el nodo que tiene la llave mayor. Si el arbol esta vacio devuelve el nodo nil.
        while (x->right != nil)
        {
            x = x->right;
        } // End while
        return x;
    }; // End Maximum

    rbtnode<T> *Successor(rbtnode<T> *x)
    {
        // Devuelve el nodo cuya llave es la que le sigue a la del nodo x. Si no existe el nodo, devuelve el nodo nil.
        if (x->right != nil)
        {
            return Minimum(x->right);
        } // End if

        rbtnode<T> *y = x->p;

        while (y != nil && x == y->right)
        {
            x = y;
            y = y->p;
        } // End while
        return y;
    }; // End Successor
}; // End class rbtree

#endif /* rbtree_h */
