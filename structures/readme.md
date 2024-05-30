Lista enlazada con nodo centinela:

1. Implemente la clase lista enlazada con nodo centinela usando la plantilla llist.h.
Los métodos a implementar son los siguientes: construcción [1 pto.], destrucción
[3 pts.], inserción [4 pts.], búsqueda [3 pts.] y borrado [4 pts.].

2. Inserte en una lista vacía n = 1 000 000 de nodos cuyas llaves sean enteros seleccio-
nados aleatoriamente en el rango [0, 2n). Seleccione elementos al azar en el mismo
rango [0, 2n) y búsquelos en la lista (estén o no en ella) registrando el número de
búsquedas realizadas en un lapso de un segundo. [1 pto.]

3. Inserte en una lista vacía las llaves 0, 1, ..., n−1, en ese orden. Seleccione elementos
al azar en el rango [0, 2n), y registre el número de búsquedas que se logró hacer en
un lapso de un segundo. [1 pto.]

4. Indique si en alguno de los dos casos (inserción de números aleatorios o inserción
de números secuenciales) se realizó una cantidad de búsquedas (exitosas o fallidas,
no importa) sustancialmente mayor que en el otro (más del doble), e indique si
esto corresponde a lo esperado. Explique. [3 pts.]



Arbol de busqueda binaria:

1. Implemente la clase árbol de búsqueda binario, usando la plantilla bstree.h. Los
métodos a implementar son: construcción [1 pto.], destrucción [3 pts.], inserción
[4 pts.], borrado [5 pts.], búsqueda de llave recursiva [2 pto.] e iterativa [3 pts.], bús-
queda del máximo [1 pts.], mínimo [1 pts.], sucesor de un nodo [2 pts.] y recorrido
del árbol en orden [3 pts.].

2. Repita el punto 2 de la sección 2.1 usando un árbol de búsqueda binario que tenga
la misma cantidad de llaves que en esa sección. [1 pto.]

3. Repita el punto 3 de la sección 2.1 usando un árbol de búsqueda binario que tengan
la misma cantidad de llaves que en esa sección. (Insertar n llaves ordenadas en
un árbol de búsqueda binario puede tomar demasiado tiempo si n es grande —¿por
qué?—. Para evitar la larga espera, considere crear un método que produzca un
árbol idéntico al que se crearía si se insertaran en él las llaves 0, 1, ..., n − 1, en ese
orden, pero sin usar el método de inserción —¿cómo?—). [1 pto.]

4. Compare el número de búsquedas realizadas en el punto 2 de las secciones anteriores
e indique si alguna de las estructuras de datos (lista enlazada o árbol de búsqueda
binario) fue sustancialmente mejor que la otra (es decir, si permitió realizar más
del doble de búsquedas). [1 pto.]

5. Compare el número de búsquedas realizadas en el punto 3 de las secciones ante-
riores, e indique si alguna de las estructuras de datos (lista enlazada o árbol de
búsqueda binario) fue sustancialmente mejor que la otra (es decir, si permitió rea-
lizar más del doble de búsquedas) y si esto corresponde a lo esperado. Explique.