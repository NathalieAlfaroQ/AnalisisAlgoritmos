// llist.h
//  Lista enlazada con nodo centinela
//

#ifndef llist_h
#define llist_h

#include <cstddef>

// Nodos de la lista:
template <typename T>
// Clase nodo
class llnode
{
public:
    // Esta clase es para ser usada por otras clases. Por eficiencia los atributos se dejan publicos.
    // Valor
    T key;
    // Anterior y siguiente
    llnode<T> *prev, *next;

    // Constructor por omision.
    llnode(){};

    // Inicializacion de los datos miembro.
    llnode(const T &k, llnode<T> *w = nullptr, llnode<T> *y = nullptr) : key(k), prev(w), next(y){};

    ~llnode(){};
}; // End class llnode

// Lista enlazada con nodo centinela:
template <typename T>

class llist
{
public:
    llnode<T> *nil; // nodo centinela

    llist()
    {
        // Constructor (crea una lista vacia)
        nil = NULL;
    }; //  End llist

    ~llist()
    {
        // Destructor (borra la lista)
        while (nil)
        {
            Delete(nil);
        } // End while
    }; // End ~llist

    // Inserta el nodo x en la lista.
    void Insert(llnode<T> *x)
    {
        // Si la lista esta vacia
        if (nil == NULL)
        {
            nil = x;
            nil->next = NULL;
        }
        else
        {
            // Sino esta vacia, va hasta el final de la lista y pone al nodo
            llnode<T> *nodo = nil;
            while (nodo->next != NULL)
            {
                nodo = nodo->next;
            } // End while
            x->next = NULL;
            x->prev = nodo;
            nodo->next = x;
        } // End if
    }; // End Insert

    // Busca un nodo con la llave k en la lista
    llnode<T> *Search(const T &k)
    {
        // Busca la llave iterativamente. Si la encuentra, devuelve un apuntador al nodo que la contiene; sino devuelve el nodo nil (el centinela).
        llnode<T> *node = nil;

        // Recorre la lista desde nil hasta encontrar un nodo con la clave k
        while (node != NULL)
        {
            if (node->key == k)
            {
                return node;
            }
            else
            {
                node = node->next;
            } // End if
        } // End while
        return nullptr;
    }; // End Search

    // Elimina nodo de la lista
    void Delete(llnode<T> *x)
    {
        // Saca de la lista la llave contenida en el nodo apuntado por x.
        // Si el anterior y el siguiente no son null
        if (x->prev != nullptr && x->next != nullptr)
        {
            // establezco los valores a sus nodos adyacentes y asi X desaparece
            llnode<T> *a = x->prev;
            llnode<T> *b = x->next;
            a->next = b;
            b->prev = a;
            delete x;
        }
        // Si X es el primer nodo
        else if (x->prev == NULL)
        {
            // pase al siguiente nodo
            nil = x->next;
            delete x;
        }
        else
        {
            delete x;
        } // End if
    }; // End Delete
}; // End class llist

#endif /* llist_h */
