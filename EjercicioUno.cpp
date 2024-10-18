#include <iostream>

using namespace std;
/**
    Utilizando las funciones de ListasSE provistas en clase haga un programa que permita
    al usuario:
        - Insertar un elemento ordenadamente en la lista
        - Buscar el mayor elemento
        - Calcular el promedio de la lista
**/

struct NodoListaSE
{
    int info;
    NodoListaSE *sgte;
};


void InsertarNuevoValorAlPrincipio(NodoListaSE *&lista)
{
    NodoListaSE *aux = lista;
    int valor = 0;

    cout << "Ingrese el valor que desea: " << endl;
    cin >> valor;

    lista = new NodoListaSE();
    lista ->info = valor;
    lista -> sgte = aux;

    return;
}

void InsertarNuevoValorAlFinal(NodoListaSE *&lista)
{
    NodoListaSE *aux = lista;


    if(lista)
    {
        while(aux -> sgte)
        {
            aux = aux -> sgte;
        }

        aux -> sgte = new NodoListaSE ();
        aux = aux -> sgte;

        cout << "Ingrese el valor que desea insertar al final: " << endl;
        cin >> aux -> info;

    }else InsertarNuevoValorAlPrincipio(lista);

}

void MostrarListaCompleta(NodoListaSE *lista)
{
    while(lista)
    {
        cout << "-------------------------------------" << endl;
        cout << "       Direc: " << lista << endl;
        cout << "       Valor: " << lista -> info << endl;
        lista = lista -> sgte;
        cout << "-------------------------------------" << endl;


    }
    return;

}

NodoListaSE *BuscarValorMayor(NodoListaSE *lista)
{
    NodoListaSE *valorMayor = lista ;

    while(lista)
    {
        if(valorMayor -> info < lista -> info)
        {
            valorMayor = lista;
        }

        lista = lista -> sgte;
    }

    return valorMayor;

}

void CalcularPromedio (NodoListaSE *lista)
{
    int total, i = 0;
    float promedio;

    if(lista)
    {

        while(lista)
        {
            total+= lista -> info;
            lista = lista -> sgte;
            i++;
        }

        promedio = total / i;

        cout << "El promedio de los valores es: " << promedio << endl;
    }
    else cout << "LISTA VACIA" << endl;

    return;



}


int main()
{
    NodoListaSE *lista = NULL;
    NodoListaSE *aux;
    int res = 0;


    do{
        res = 0;
        cout << "----------- BIENVENIDO -----------" << endl << "------> Menu: " << endl;
        cout << "1. Insertar un numero al PRINCIPIO de la lista " << endl;
        cout << "2. Insertar un numero al FINAL de la lista " << endl;
        cout << "3. Buscar el numero MAYOR " << endl;
        cout << "4. Calcular el promedio " << endl;
        cout << "5. BONUS: MOSTRAR LISTA" << endl;
        cout << "6. Salir" << endl;

        cin >> res;

        switch(res)
        {
        case 1:
            InsertarNuevoValorAlPrincipio(lista);
            cout << "Se registro Correctamente! " << endl;

            break;

        case 2:
            InsertarNuevoValorAlFinal(lista);
            cout << "Se registro Correctamente! " << endl;
            break;

        case 3:
            NodoListaSE *mayor;

            mayor = BuscarValorMayor(lista);
            cout << "El valor mayor es: " << mayor -> info << endl << "Con una direccion de memoria: " << mayor << endl;

            break;

        case 4:
            CalcularPromedio(lista);
            break;

        case 5:
            MostrarListaCompleta(lista);
            cout << "gol" ;
            break;

        case 6:
            cout << "Chau :(" << endl;
            break;

        }


    }while(res != 6);



    return 0;
}
