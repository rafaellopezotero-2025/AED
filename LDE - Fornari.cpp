#include <iostream>

using namespace std;

struct nodo_lista_de
{
    int dato;
    struct nodo_lista_de *link_adelante;
    struct nodo_lista_de *link_atras;
};

typedef nodo_lista_de NListaDE;

// Verifica si la lista está vacía
bool isEmpty(NListaDE *LDE)
{
    return (LDE == NULL); // La lista está vacía si el nodo cabeza es NULL
}

// Agregar elemento a una lista doblemente enlazada
void agregar(NListaDE* &LDE, int dato)
{
    NListaDE *aux = new (NListaDE); // Creo el nuevo nodo
    aux->dato = dato;               // Almaceno el nuevo valor
    aux->link_adelante = NULL;      // Como lo agrego al final el nuevo nodo debe apuntar a NULL
   
    if (isEmpty(LDE))
    {
        aux->link_atras = NULL; //Si es el primer elemento, link_atras debe ser NULL
        LDE = aux; // Si la lista está vacía, el nodo principal apunta al nuevo nodo
    }
    
    else
    {
        NListaDE *LDE_aux = LDE; // Creo un puntero auxiliar para poder avanzar entre los nodos
        while(LDE_aux->link_adelante != NULL) // Recorro la lista hasta el último nodo
        {
            LDE_aux = LDE_aux->link_adelante; // Me muevo al siguiente nodo
        }
       
        LDE_aux ->link_adelante = aux; // Hago que el último nodo de la lista apunte al nuevo nodo
        aux->link_atras = LDE_aux; // Hago que el nuevo nodo apunte al último nodo (anterior) de la lista
        
    }
}

// Recorrer una lista doblemente enlazada de atrás hacia adelante
void imprimir(NListaDE *LDE)
{
    // Verificar si la lista está vacía
    if (!isEmpty(LDE)) // Si no está vacía
    {
        cout << "L --> ";
        while (LDE != NULL) // Mientras que mi puntero sea != NULL estoy recorriendo los nodos, cuando sea NULL es porque ya pasé el último
        {
            cout << (LDE->dato) << " --> "; // Imprimo el dato del nodo
            LDE = LDE->link_adelante;       // Me muevo al siguiente nodo
        }
        cout << "NULL";
    }
    else
    {
        cout << "La lista está vacía" << endl;
    }
}

//Imprimir los elementos de la lista al revés
void imprimir_reversa(NListaDE* LDE){
   
    // Verificar si la lista está vacía
    if (!isEmpty(LDE)) // Si no está vacía
    {
        cout << "NULL --> ";
        while ((LDE -> link_adelante) != NULL) // Mientras que mi puntero sea != NULL estoy recorriendo los nodos, cuando sea NULL es porque ya pasé el último
        {
            LDE = LDE->link_adelante;       // Me muevo al siguiente nodo
        }
        
        while (LDE != NULL) // Mientras que mi puntero sea != NULL estoy recorriendo los nodos, cuando sea NULL es porque pasé el primero
        {
            cout << (LDE->dato) << " --> "; // Imprimo el dato del nodo
            LDE = LDE->link_atras;       // Me muevo al siguiente nodo
        }

        cout << "L";
    }
    else
    {
        cout << "La lista está vacía" << endl;
    }
}

int main()
{
    NListaDE *LDE = NULL;         // Inicializo la lista como vacía
    agregar(LDE, 1);         // Agrego el primer elemento
    agregar(LDE, 2);         // Agrego el segundo elemento
    agregar(LDE, 3);         // Agrego el tercer elemento
    imprimir(LDE); // Imprimo la lista
    cout << endl;
    imprimir_reversa(LDE); // Imprimo la lista al revés

    return 0;
}