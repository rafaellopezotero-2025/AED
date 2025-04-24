/*
Dada una LSE de nombre L del tipo NListaSE, vacía, realice una función que
la cargue con los valores incluidos en un vector de enteros pasado como
argumento. A modo de ejemplo se pide probar esta función pasando como
parámetro el vector int v[] {9,1,3,2,8,7,6};
Nota: Implemente una función de consulta que muestre por consola la lista de la
siguiente manera:
 L --> 9 --> 1 --> 3 --> 2 --> 8 --> 7 --> 6 --> NULL

*/
#include <gc/gc.h> //Garbage collector
#include <iostream>
#include <vector>

using namespace std;

// Defino el struct
struct nodo_lista_se
{
    int dato;
    struct nodo_lista_se *link;
};

typedef nodo_lista_se NListaSE;

bool isEmpty(NListaSE *LSE)
{
    return (LSE == NULL) ? true : false;
}

// 1. Agregar elemento al final utilizando dos punteros (actual y anterior)
void agregar_final(NListaSE *&LSE, int n[], int t)
{
    for (int i = 0; i < t; i++)
    {
        NListaSE *aux = (NListaSE *)(GC_MALLOC(sizeof(NListaSE))); // Creo el nuevo nodo
        // GC_MALLOC es una función de la librería garbage collector que reserva memoria para un nuevo nodo (igual que new)
        // Usa sizeof para saber cuanto reservar según el tipo indicado
        aux->dato = n[i]; // Almaceno el nuevo valor
        aux->link = NULL; // Como lo agrego al final el nuevo nodo debe apuntar a NULL
        NListaSE *actual = LSE;
        NListaSE *anterior = NULL;
        // Evaluar si está vacía
        if (!isEmpty(LSE))
        { // Si no está vacía
            // Recorrer la lista hasta el último elemento
            while ((actual != NULL))
            {
                anterior = actual;     // Muevo anterior en una posición
                actual = actual->link; // Muevo actual a la siguiente posición
            }
            anterior->link = aux; // Hago que el último nodo de la lista apunte al nuevo nodo
        }
        else
            LSE = aux; // Si la lista está vacía LSE debe apuntar al nuevo nodo
    }
}

// 1. Imprimir todos los elementos de la lista
void imprimir(NListaSE *LSE)
{ // Paso por parámetro el puntero al primer elemento de la lista
    cout << "L --> ";
    while (LSE != NULL)
    {                                   // Mientras que mi puntero sea != NULL estoy recorriendo los nodos, cuando sea NULL es porque ya pasé el último
        cout << (LSE->dato) << " --> "; // Imprimo el dato del nodo
        LSE = LSE->link;                // Me muevo al siguiente nodo
    }
    cout << "NULL" << endl;
}

// 2. Promedio
double prom(NListaSE *LSE)
{
    double suma = 0;
    int cont = 0;
    while (LSE != NULL)
    {                        // Mientras que mi puntero sea != NULL estoy recorriendo los nodos, cuando sea NULL es porque ya pasé el último
        suma += (LSE->dato); // Imprimo el dato del nodo
        cont++;
        LSE = LSE->link; // Me muevo al siguiente nodo
    }
    return suma / cont;
}

// Par (cantidad) -- Ej de clase
int par(NListaSE *LSE)
{
    int cont = 0;
    while (LSE != NULL)
    { // Mientras que mi puntero sea != NULL estoy recorriendo los nodos, cuando sea NULL es porque ya pasé el último
        if ((LSE->dato) % 2 == 0)
        {
            cont++;
        }
        LSE = LSE->link; // Me muevo al siguiente nodo
    }
    return cont;
}

// 3. Duplicar valor de los elementos
void duplicar(NListaSE *&LSE)
{
    NListaSE *LSE_aux = LSE; // Creo un puntero auxiliar para poder avanzar entre los nodos
    // Evaluar si está vacía
    if (!isEmpty(LSE))
    { // Si no está vacía
        // Recorrer la lista hasta el último elemento
        while ((LSE_aux != NULL))
        {
            LSE_aux->dato = LSE_aux->dato * 2; // Duplico el valor del nodo
            LSE_aux = LSE_aux->link;           // Me muevo al siguiente nodo
        }
    }
}

// 4. a. Valor máximo de la lista
int max(NListaSE *LSE)
{
    int max = LSE->dato; // Inicializo el máximo con el primer elemento de la lista
    // Evaluar si está vacía
    if (!isEmpty(LSE))
    { // Si no está vacía
        // Recorrer la lista hasta el último elemento
        while ((LSE != NULL))
        {
            if (LSE->dato > max)
            {
                max = LSE->dato;
            }
            LSE = LSE->link; // Me muevo al siguiente nodo
        }
    }
    return max;
}

// 4. b. Valor mínimo de la lista
int min(NListaSE *LSE)
{
    int min = LSE->dato; // Inicializo el mínimo con el primer elemento de la lista
    // Evaluar si está vacía
    if (!isEmpty(LSE))
    { // Si no está vacía
        // Recorrer la lista hasta el último elemento
        while ((LSE != NULL))
        {
            if (LSE->dato < min)
            {
                min = LSE->dato;
            }
            LSE = LSE->link; // Me muevo al siguiente nodo
        }
    }
    return min;
}

// 4. c. Máximo de la lista de forma recursiva
int max_rec(NListaSE *LSE)
{
    if (LSE == NULL)
        return 0;                 // Caso base: cuando la lista es NULL llegué al final
    int max = max_rec(LSE->link); // Defino max como el máximo de la lista
    if (LSE->dato > max)
        return LSE->dato; // Comparo el valor del nodo con el máximo de la lista
    else
        return max; // Si el valor del nodo es menor al máximo de la lista devuelvo el máximo
}

// 5. Generar enteros aleatorios entre dos números enteros dados.
// Rellenar la lista vacía con los números.
// La cantidad de elementos generados también debe ser ingresada como parámetro de la función
void add_random(NListaSE *&LSE, int n1, int n2, int t)
{
    for (int i = 0; i < t; i++)
    {
        NListaSE *aux = (NListaSE *)(GC_MALLOC(sizeof(NListaSE))); // Creo el nuevo nodo
        // GC_MALLOC es una función de la librería garbage collector que reserva memoria para un nuevo nodo (igual que new)
        // Usa sizeof para saber cuanto reservar según el tipo indicado
        aux->dato = rand() % (n2 - n1 + 1) + n1; // Genero un número aleatorio entre n1 y n2
        aux->link = NULL;                        // Como lo agrego al final el nuevo nodo debe apuntar a NULL
        NListaSE *actual = LSE;
        NListaSE *anterior = NULL;
        if (!isEmpty(LSE))
        {
            while (actual != NULL)
            {
                anterior = actual;
                actual = actual->link; // Muevo actual a la siguiente posición
            }
            anterior->link = aux; // Hago que el último nodo de la lista apunte al nuevo nodo
        }
        else
            LSE = aux; // Si la lista está vacía LSE debe apuntar al nuevo nodo
    }
}

// 6. Eliminar todos los elementos de la lista
/* bool remove(NListaSE* &LSE){
    if(isEmpty(LSE)) // Si la lista está vacía
        return false;
    // Si no está vacía
    NListaSE* aux;
    while (LSE != NULL){
        aux = LSE; // Guardo el nodo a eliminar
        LSE = LSE->link; // Muevo el puntero al siguiente nodo
        delete aux; // Elimino el nodo
    }
    return true; // Retorno true si se eliminó la lista
} */

// 7. Imprimir todos los elementos que superen el promedio
void imprimir_prom(NListaSE *LSE)
{
    if (isEmpty(LSE)) // Si la lista está vacía
        return;
    // Si no está vacía
    double promedio = prom(LSE);
    cout << "L --> ";
    while (LSE != NULL)
    { // Recorro la lista hasta el final
        if ((LSE->dato) > promedio)
        {                                 // Si el elemento es mayor al promedio
            cout << LSE->dato << " --> "; // Imprimo el dato del nodo
        }
        LSE = LSE->link; // Me muevo al siguiente nodo
    }
    cout << "NULL";
}

// 8. Insertar un nuevo elemento en la lista en una posición dada
int add_pos(NListaSE *&LSE, int n, int pos)
{
    // Posición negativa
    if (pos < 0)
        return 2; // Posición inválida

    NListaSE *aux = (NListaSE *)(GC_MALLOC(sizeof(NListaSE))); // Creo el nuevo nodo
    aux->dato = n;                                             // Almaceno el nuevo valor

    // Evaluar si está vacía
    if (isEmpty(LSE))
    {
        if (pos == 0) //Si la posición es 0 se agrega al principio
        {
            LSE = aux; // Si la lista está vacía LSE debe apuntar al nuevo nodo
            return 3;  // Retorno 3 si se insertó el nodo en lista vacía
        }
        return 2; // Si no, la posición es inválida para una lista vacía
    }

    // Insertar al inicio en una lista con elementos
    if (pos == 0)
    {
        aux->link = LSE; // Hago que el nuevo nodo apunte al primer nodo
        LSE = aux;       // Hago que LSE apunte al nuevo nodo
        return 1;        // Retorno 1 si se insertó el nodo
    }

    // Insertar en el medio
    NListaSE *actual = LSE;
    int cont = 0; // Contador para la posición

    // Mientras que mi puntero sea != NULL estoy recorriendo los nodos, continúo hasta el nodo anterior a la posición dond voy a  insertar
    while (actual != NULL && cont < pos - 1)
    {
        actual = actual->link; // Muevo actual a la siguiente posición
        cont++;
    }

    if (actual == NULL)
        return 2; // Posición inválida, excede el tamaño

    aux->link = actual->link;
    actual->link = aux;
    return 1; // Inserción exitosa
}


//Intercambiar dos nodos de la lista
void intercambiar (NListaSE* &LSE, int n1, int n2){
    if (n1 == n2 || LSE == NULL) return; //Si el nodo a intercambiar es el mismo o la lista está vacía no hago nada

    // Intercambiar n1 y n2 si n1 es mayor para evitar entrar en un bucle infinito
    if (n1 > n2) {
        int aux = n1;
        n1 = n2;
        n2 = aux;
    }

    //Nod1 y Nod2 son los nodos a intercambiar
    NListaSE* Nod1 = NULL, * Nod2 = NULL;
    //prev1 es el nodo sgte a Nod1 y prev2 el anterior a Nod2
    NListaSE* prev1 = NULL, * prev2 = NULL;
    NListaSE* actual = LSE;
    int cont = 0;

    while (actual != NULL) //Recorro la lista
    {
        if (cont == n1) //Encontré el nodo 1
        {
            Nod1 = actual; //Lo guardo
        }
        if(cont == n2) //ENcontré el nodo 2
        {
            Nod2 = actual; //Lo guardo
        }

        // Actualizar prev1 hasta encontrar Nod1
        if (Nod1 == NULL) {
            prev1 = actual;
        }
        // Actualizar prev2 hasta encontrar Nod2
        if (Nod2 == NULL) {
            prev2 = actual;
        }

        actual = actual->link; //Me muevo al siguiente nodo
        cont++; //Aumento el contador
    }

    if (Nod1 == NULL || Nod2 == NULL)
        return; // Si no encontré los nodos no hago nada


    // Si los nodos son adyacentes
    if (Nod1->link == Nod2) { 
        Nod1->link = Nod2->link; // Conecto Nod1 al siguiente de Nod2
        Nod2->link = Nod1; // Conecto Nod2 a Nod1
        if (prev1 != NULL) { 
            prev1->link = Nod2; // Conecto el nodo anterior a Nod1 con Nod2
        } else {
            LSE = Nod2; // Si Nod1 es el primero de la lista, actualizo LSE
        }
        return;
    }
    
     // Intercambio los nodos
     NListaSE* aux = Nod2->link; // GUardo el siguiente de Nod2
    
     if (prev1 != NULL) { 
         prev1->link = Nod2;// Conecto el nodo sgte a Nod1 con Nod2
     } else {
         LSE = Nod2; //Si prev1 es null, Nod1 es el primero de la lista

     }
     Nod2->link = Nod1->link; // Conecto Nod2 al siguiente de Nod1
 
     if (prev2 != NULL) { 
         prev2->link = Nod1; // Conecto el nodo anterior a Nod2 con Nod1
     } else {
         LSE = Nod1; //Si prev2 es null, Nod2 es el primero de la lista
     }
     Nod1->link = aux; // Conecto Nod1 al siguiente de Nod2
    
}

int main()
{
    // Inicializar el garbage collector
    GC_INIT();
  
    NListaSE *lista = NULL;
    int v[]{9, 1, 3, 2, 8, 7, 6};
    int t = sizeof(v) / sizeof(v[0]);
    // agregar_final(lista, v, t);
    add_random(lista, 1, 10, 5); 
    imprimir(lista);
    cout << "Promedio: " << prom(lista) << endl;
    cout << "Pares: " << par(lista) << endl;
    duplicar(lista);
    cout << "Lista duplicada: ";
    imprimir(lista);
    cout << "Máximo: " << max(lista) << endl;
    cout << "Mínimo: " << min(lista) << endl;
    cout << "Máximo recursivo: " << max_rec(lista) << endl;
    /* if (remove(lista))
        cout << "Lista eliminada: ";
    imprimir(lista); */
    cout << "Elementos mayores al promedio: " << endl;
    imprimir_prom(lista);
    cout << endl;

    // Con try catch manejar los errores según la salida:
    // 1. Se insertó el nodo en una lista con elementos
    // 2. Posición inválida o fuera de rango
    // 3. Se insertó el nodo en una lista vacía

    int resultado = add_pos(lista, 10, 2);
    cout << "Añadir elemento en una posición dada: " << endl;

    try
    {
        if (resultado == 1)
        {
            imprimir(lista);
            throw "Inserción exitosa en lista con elementos";
        }
        else if (resultado == 2)
        {
            throw "Error: Posición inválida o fuera de rango";
        }
        else if (resultado == 3)
        {
            imprimir(lista);
            throw "Inserción exitosa en lista vacía";
        }
        else
        {
            throw "Error desconocido al insertar";
        }
    }
    catch (const char *msg)
    {
        cerr << msg << endl;
    }
    cout << endl;

    intercambiar(lista, 1, 5);
    cout << "Lista después de intercambiar nodos: ";
    imprimir(lista);
    cout << endl;

    GC_gcollect();

    return 0;
}
// valgrind --leak-check=full --show-leak-kinds=all ./prog //Evaluar si hay memory leaks
// g++ -g "Ejercicios guia 1 - Fornari.cpp" -o prog -lgc (preparar el programa para trabajar con el GC)