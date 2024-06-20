//  chtable.h
// Tablas de dispersion, hash table

// Encabezado
#ifndef chtable_h
#define chtable_h

// Bibliotecas
#include <list>
#include <vector>

template <typename T>

// Tabla de dispersi�n con encadenamiento
class chtable
{
public:
    // Constructor que especifica el tama�o de la tabla
    chtable(int sz) : size(sz), table(sz){};

    // Destructor (borra la tabla)
    ~chtable(){
        // Se usan contenedores STL, no es necesario liberar la memoria
    };

    // Inserta el elemento en la tabla
    void Insert(const T &k)
    {
        int index = hashFunction(k);
        table[index].push_back(k);
    }; // End Insert

    // Retorna un puntero a la llave o nullptr si no se encuentra
    T *Search(const T &k)
    {
        int index = hashFunction(k);

        for (auto &element : table[index])
        {
            if (element == k)
            {
                return &element;
            } // End if
        } // End for
        return nullptr;
    }; // End Search

private:
    // N�mero de entradas en la tabla
    int size;

    // La tabla es un vector de listas de STL
    std::vector<std::list<T>> table;

    // Funcion de dispersion
    int hashFunction(const T &k) const { return k % size; }
}; // End class chtable

#endif /* chtable_h */
