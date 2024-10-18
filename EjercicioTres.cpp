#include <iostream>

using namespace std;

/*
    EJERCICIO 3:
        Haga un procedimiento que reciba los mismos parámetros del punto 1 pero devuelva
    una tercer lista con el contenido de ambas intercalado (es decir un nodo de la lista 1
    seguido por un nodo de la lista 2, si una lista se finaliza primero quedan todos los
    demás nodos de la otra lista consecutivos).

*/


struct NodoListaSE
{
    int info;
    NodoListaSE *sgte;
};


int CantidadDeValoresPorLista(NodoListaSE *lista)
{

    int total = 0;
    while(lista)
    {

        lista = lista -> sgte;
        total++;
    }

    return total;
}

void IngresarValoresLista(NodoListaSE *&lista, int valor)
{
    NodoListaSE *aux = lista;

    lista = new NodoListaSE();

//    cout << "Ingrese el valor: " << endl;
//    cin >> lista -> info;


    lista -> info = valor;
    lista -> sgte = aux;

    return;
}

NodoListaSE *ObtenerElultimo(NodoListaSE *lista)
{
    if(lista)
    {
        //mientras que le siguiente no sea null
        while(lista->sgte)
        {
            lista = lista -> sgte;
        }
    }
    return lista;
}

void InsertarAlFinal(NodoListaSE *&lista, int valor)
{
    NodoListaSE *nuevo = new NodoListaSE();
    NodoListaSE *ultimo = NULL;

    nuevo -> info = valor;
    nuevo -> sgte = NULL;
    if(lista)
    {
        ultimo = ObtenerElultimo(lista);
        ultimo -> sgte = nuevo;
    }
    else
    {
        lista = nuevo;
    }
    return;

}

void MostrarLista(NodoListaSE *lista)
{
    while(lista)
    {
        cout << "========================" << endl;
        cout << "Direc: " << lista << endl;
        cout << "Valor: " << lista -> info << endl;
        lista = lista -> sgte;
        cout << "========================" << endl;

    }
    return;
}


void EnlazarListas(NodoListaSE *lista1, NodoListaSE *lista2, NodoListaSE *&lista3)
{
    while(lista1)
    {
        InsertarAlFinal(lista3, lista1 -> info);
        if(lista2)
        {
            InsertarAlFinal(lista3, lista2 -> info);
            lista2 = lista2 -> sgte;
        }
        lista1 = lista1 -> sgte;
    }

    while(lista2)
    {
        InsertarAlFinal(lista3, lista2-> info);
        lista2 = lista2 -> sgte;
    }


    return ;
}


int main()
{
    NodoListaSE *lista1 = NULL, *lista2 = NULL, *lista3 = NULL;
    int res = 0;

    do
    {
        res = 0;
        cout << "MENU: " <<endl;
        cout << "1. Ingresar Valores para Lista 1" << endl;
        cout << "2. Ingresar Valores para Lista 2" << endl;
        cout << "3. Mostrar Tablas Enlazadas" << endl;
        cout << "4. SALIR" << endl;
        cin >> res;


    switch(res)
    {
    case 1:
        IngresarValoresLista(lista1, 12);
        IngresarValoresLista(lista1, 15);
        IngresarValoresLista(lista1, 11);
        InsertarAlFinal(lista1, 9999999);

        break;
    case 2:
        IngresarValoresLista(lista2, 2);
        IngresarValoresLista(lista2, 9);
        IngresarValoresLista(lista2, 1);
        IngresarValoresLista(lista2, 5);
        InsertarAlFinal(lista2, 111111111);


        break;
    case 3:

        EnlazarListas(lista1, lista2, lista3);

        MostrarLista(lista3);

        break;



    case 4:
        cout << "Chau" <<endl;
        break;

    }


    }while(res != 4);


    return 0;
}
