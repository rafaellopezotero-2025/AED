#include <iostream>

using namespace std;

// Definición de la estructura del nodo
struct nodo_pila
{
    char dato;
    struct nodo_pila *link;
};
typedef struct nodo_pila NPila;

//Evaluar si esta vacía
bool isEmpty(NPila *pila)
{
    return (pila == NULL);
}

// Agregar un nodo
void add(NPila *&pila, char cad)
{
    NPila *aux = new NPila; // Nuevo nodo
    aux->dato = cad;        // Asignar el dato al nuevo nodo
    aux->link = pila;       // El nuevo nodo apunta al que era 1er nodo
    pila = aux;             // El puntero al primer elem apunta al nuevo nodo
}

//Sacar un nodo
char sacar(NPila *&pila)
{
    if (isEmpty(pila))
    { // Si la pila está vacía
        return '\0'; // Retornar un valor nulo
    }
    NPila *aux = pila; // Guardar el nodo a eliminar
    char dato = aux->dato; // Guardar el dato del nodo
    pila = pila->link; // Mover el puntero al siguiente nodo
    delete aux;        // Eliminar el nodo

    return dato; // Retornar el dato del nodo eliminado
}


// Dado un char * evaluar que los paréntesis estén balanceados
bool evaluar(NPila *&pila)
{
    int cont1 = 0, cont2 = 0;
    // No se si es correcto recorrer la pila así
    while (!isEmpty(pila))
    {
        char aux = sacar(pila); // Sacar el elemento de la pila

        if (aux == '(')
        {            // Si es un paréntesis de apertura
            cont1++; // Aumento el contador de apertura
        }
        else if (aux == ')')
        {            // Si es un paréntesis de cierre
            cont2++; // Aumento el contador de cierre
        }
    }
    return (cont1 == cont2); // Si los contadores son iguales, están balanceados
}

// Forma 2
bool evaluar2(char *cad)
{
    NPila *pila = NULL; // Inicializar la pila
    for (int i = 0; cad[i] != '\0'; i++)
    { // Recorrer la cadena
        if (cad[i] == '(') // Si es un paréntesis de apertura
            add(pila, cad[i]); // Agregar a la pila
        else if (cad[i] == ')') // Si es un paréntesis de cierre
        { 
            if (pila == NULL) // Si la pila está vacía, no hay paréntesis de apertura
                return false; // No están balanceados
            sacar(pila); // Si la pila no está vacía, eliminar el paréntesis de apertura
        }
    }
    return isEmpty(pila); // Si la pila está vacía, están balanceados
}

int main()
{
    NPila *pila = NULL, *pila2 = NULL; // Inicializar las pilas
    char cad[] = "Hola";
    int t = 0;

    // Tomar un char*, introducirlo en una pila y luego imprimirlo
    //  Agregar nodos a la pila recorriendo la cadena
    for (int i = 0; cad[i] != '\0'; i++)
    {
        add(pila, cad[i]);
        t++;
    }

    // Imprimir la pila
    cout << "Pila: ";
    for(int i = 0; i < t; i++)
    {
        cout<<sacar(pila)<<" ";
    }
    cout << endl;

    // Evaluar si los paréntesis están balanceados
    char cad2[] = "(a + b) * (c - d)";
    for (int i = 0; cad2[i] != '\0'; i++)
    {
        add(pila2, cad2[i]);
    }
    if (evaluar(pila2))
        cout << "Los paréntesis están balanceados." << endl;
    else  cout << "Los paréntesis no están balanceados." << endl;

    // Evaluar si los paréntesis están balanceados
    char cad3[] = "a + b) * (c - d)";
    for (int i = 0; cad3[i] != '\0'; i++)
    {
        add(pila2, cad3[i]);
    }
    if (evaluar(pila2))
        cout << "Los paréntesis están balanceados." << endl;
    else cout << "Los paréntesis no están balanceados." << endl;

    return 0;
}