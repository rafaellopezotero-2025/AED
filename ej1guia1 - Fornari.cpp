/*
Dada una LSE de nombre L del tipo NListaSE, vacía, realice una función que
la cargue con los valores incluidos en un vector de enteros pasado como
argumento. A modo de ejemplo se pide probar esta función pasando como
parámetro el vector int v[] {9,1,3,2,8,7,6};
Nota: Implemente una función de consulta que muestre por consola la lista de la
siguiente manera:
 L --> 9 --> 1 --> 3 --> 2 --> 8 --> 7 --> 6 --> NULL

*/

#include <iostream>
#include <vector>


using namespace std;

//Defino el struct
struct nodo_lista_se{
    int dato;
    struct nodo_lista_se* link;
};

typedef nodo_lista_se NListaSE;

bool isEmpty(NListaSE* LSE){
    return (LSE == NULL) ? true : false;
}

//Agregar elemento al final utilizando dos punteros (actual y anterior)
void agregar_final (NListaSE *&LSE, int n[], int     t){
    for (int i = 0; i < t; i++){

    NListaSE* aux = new(NListaSE); //Creo el nuevo nodo
    aux -> dato = n[i]; //Almaceno el nuevo valor
    aux -> link = NULL; //Como lo agrego al final el nuevo nodo debe apuntar a NULL
    NListaSE* actual = LSE;
    NListaSE* anterior = NULL;
    //Evaluar si está vacía
    if (!isEmpty(LSE)){ //Si no está vacía
        //Recorrer la lista hasta el último elemento
        while ((actual != NULL)){
            anterior = actual; //Muevo anterior en una posición
            actual = actual -> link; //Muevo actual a la siguiente posición
        }
        anterior -> link = aux; //Hago que el último nodo de la lista apunte al nuevo nodo
    }
    else LSE = aux; //Si la lista está vacía LSE debe apuntar al nuevo nodo
    }
}

//Imprimir todos los elementos de la lista
void imprimir(NListaSE* LSE){ //Paso por parámetro el puntero al primer elemento de la lista
    NListaSE* LSE_aux = LSE; //Creo un puntero auxiliar para poder avanzar entre los nodos
    cout << "L --> ";
    while (LSE_aux != NULL){ //Mientras que mi puntero sea != NULL estoy recorriendo los nodos, cuando sea NULL es porque ya pasé el último
        cout << (LSE_aux -> dato) << " --> "; //Imprimo el dato del nodo
        LSE_aux = LSE_aux -> link; //Me muevo al siguiente nodo
    }
    cout << "NULL";
}


//Promedio
double prom (NListaSE* LSE){
    NListaSE* LSE_aux = LSE; //Creo un puntero auxiliar para poder avanzar entre los nodos
    double suma = 0;
    int cont = 0;
    while (LSE_aux != NULL){ //Mientras que mi puntero sea != NULL estoy recorriendo los nodos, cuando sea NULL es porque ya pasé el último
        suma += (LSE_aux -> dato); //Imprimo el dato del nodo
        cont++;
        LSE_aux = LSE_aux -> link; //Me muevo al siguiente nodo
    }
    return suma/cont;
}


int main(){
    NListaSE* lista = NULL;
    int v[] {9,1,3,2,8,7,6};
    int t = sizeof(v)/sizeof(v[0]);
    agregar_final(lista, v, t);
    imprimir(lista);
    return 0;
}
