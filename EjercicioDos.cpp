#include <iostream>

using namespace std;

/*
    EJERCICIO 2:
        Realice un procedimiento o función que al recibir dos listas como parámetro, devuelva
        una tercer lista que concatene las mismas.

 */


struct NodoListaSE
{
    int info;
    NodoListaSE *sgte;
};

void MostrarLista(NodoListaSE *lista)
{
    while(lista)
    {
        cout << "-------------------------------------" << endl;
        cout << "       Direccion del primer valor: " << lista << endl;
        cout << "       Valor: " << lista -> info << endl;
        lista = lista -> sgte;
        cout << "-------------------------------------" << endl;
    }
    cout << "Vaciaaaa" << endl;
    return;
}

void CargarDatos (NodoListaSE *&lista, int valor)
{
    NodoListaSE *aux = lista;

    lista = new NodoListaSE;
    lista -> sgte = aux;
    lista -> info = valor;

    return;
}

NodoListaSE *EnlazarListas(NodoListaSE *lista1, NodoListaSE *lista2)
{
    NodoListaSE *tercerLista = NULL;

    if(lista1 && lista2)
    {
        while(lista1)
        {
            NodoListaSE *aux = tercerLista;     //Cramos el auxiliar para no perder datos

            tercerLista = new NodoListaSE;
            tercerLista -> sgte = aux;
            tercerLista -> info = lista1 -> info;

            lista1 = lista1 -> sgte;
        }
        while(lista2)
        {
            NodoListaSE *aux = tercerLista;

            tercerLista = new NodoListaSE;
            tercerLista -> sgte = aux;
            tercerLista -> info = lista2 -> info;

            lista2 = lista2 -> sgte;
        }
    } else cout << "estan vacias" << endl;

    return tercerLista;
}

int main()
{
    NodoListaSE *lista1 = NULL, *lista2 = NULL, *lista3 = NULL;

    //CARGA DE DATOS DE LA PRIMERA LISTA:
    CargarDatos(lista1, 15);
    CargarDatos(lista1, 19);
    CargarDatos(lista1, 1);

    //CARGA DE DATOS DE LA SEGUNDA LISTA:
    CargarDatos(lista2, 90);
    CargarDatos(lista2, 25);
    CargarDatos(lista2, 5);

    cout << "=========================" << endl;

    lista3 = EnlazarListas(lista1, lista2);
    MostrarLista(lista3);

    cout << "=========================" << endl;

}

