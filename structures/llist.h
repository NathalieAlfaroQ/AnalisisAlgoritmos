// llist.h
// Lista doblemente enlazada con nodo centinela

/*
 * Permite insertar nodos al inicio de la lista, buscar nodos por su clave,
 * y eliminar nodos específicos. Los nodos se manejan mediante la clase llnode,
 * mientras que las operaciones sobre la lista se definen en la clase llist.
 * El nodo centinela (nil) actúa como la cabeza de la lista, facilitando la
 * gestión de la lista, especialmente cuando está vacía.
 */

#ifndef llist_h
#define llist_h

#include <cstddef>

// Nodos de la lista tipo T:
template <typename T>
class llnode
{
public:
    // Esta clase es para ser usada por otras clases
    // Por eficiencia los atributos se dejan públicos
    // Valor
    T key;
    // Anterior y siguiente
    llnode<T> *prev, *next;

    // Constructor por omisión
    llnode(){};

    // Inicialización de los datos miembro
    llnode(const T &k, llnode<T> *w = nullptr, llnode<T> *y = nullptr) : key(k), prev(w), next(y){};

    ~llnode(){};
}; // End class llnode

// Lista enlazada doble con nodo centinela:
template <typename T>
class llist
{
public:
    // Nodo centinela
    llnode<T> *nil;

    llist()
    {
        // Constructor (crea una lista vacía)
        nil = NULL;
    }; // End llist

    ~llist()
    {
        // Destructor (borra la lista)
        llnode<T> *current = nil->next;
        while (current != nil)
        {
            llnode<T> *next = current->next;
            delete current;
            current = next;
        } // End while
        delete nil;
    }; // End ~llist

    // Inserta el nodo x en la lista
    void Insert(llnode<T> *x)
    {
        // Si la lista está vacía
        if (nil == NULL)
        {
            nil = x;
            nil->next = NULL;
            nil->prev = NULL;
        }
        else
        {
            // Inserta al inicio de la lista
            x->next = nil;
            x->prev = NULL;
            nil->prev = x;
            nil = x;
        } // End if
    }; // End Insert

    // Busca un nodo con la llave k en la lista
    llnode<T> *Search(const T &k)
    {
        /*
         * Busca la llave iterativamente
         * Si la encuentra, devuelve un apuntador al nodo que la contiene,
         * sino devuelve el nodo nil
         */
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
        // Saca de la lista la llave contenida en el nodo apuntado por x
        // Si el anterior y el siguiente no son null
        if (x->prev != nullptr && x->next != nullptr)
        {
            // Establezco los valores a sus nodos adyacentes y así X desaparece
            llnode<T> *a = x->prev;
            llnode<T> *b = x->next;
            a->next = b;
            b->prev = a;
            delete x;
        }
        else if (x->prev == NULL)
        {
            nil = x->next;
            if (nil != NULL)
            {
                nil->prev = NULL;
            } // End if
            delete x;
        }
        else
        {
            if (x->next != NULL)
            {
                x->next->prev = x->prev;
            } // End if
            x->prev->next = x->next;
            delete x;
        } // End if
    }; // End Delete
}; // End class llist

#endif /* llist_h */
