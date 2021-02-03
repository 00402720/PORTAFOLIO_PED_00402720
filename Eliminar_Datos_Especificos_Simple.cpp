#include <iostream>

using namespace std;

struct nodo
{
    int dato;
    nodo *sig;
};

class manejoDatos
{
    private:
    nodo *Inicio;
    void Insertar_Datos(int dato);

    public:
    manejoDatos()
    {
        Inicio = NULL;
    }
    ~manejoDatos()
    {
        delete Inicio;
    }

    void Ingreso_Datos();
    void Terminator(int dato_a_buscar);
    void Mostrar_numeros_pares();
    void Mostrar_numeros_impares();

};

int main(void)
{
    manejoDatos dt;
    int dato_a_buscar = 0;

    cout << endl << "BASE DE DATOS 101" << endl << endl;
    dt.Ingreso_Datos();

    cout << "Valor a eliminar: "; cin >> dato_a_buscar;
    dt.Terminator(dato_a_buscar);
    cout << endl;
    cout << "Numeros pares: " << endl;
    dt.Mostrar_numeros_pares();
    cout << endl;
    cout << "Numeros Impares: " << endl;
    dt.Mostrar_numeros_impares();
    cout << endl;

    return 0;
}

void manejoDatos::Ingreso_Datos()
{
    int dato, finalizar_0 = 0;

    cout << "¿Cuantos datos desea ingresar? "; cin >> finalizar_0;

    while(finalizar_0 > 0)
    {
        cout << "Valor: "; cin >> dato;
        Insertar_Datos(dato);
        finalizar_0--;
    }
}

void manejoDatos::Insertar_Datos(int dato)
{
    nodo *n = new nodo;
    n -> dato = dato;
    n -> sig = Inicio;
    Inicio = n;
}

void manejoDatos::Terminator(int dato_a_buscar)
{
    nodo *buscador = Inicio;
    while (buscador)
    {
        if(buscador-> dato == dato_a_buscar)
        {
            while(buscador -> sig)
            {
                buscador -> dato = buscador -> sig ->dato;
                buscador = buscador -> sig;
            }
            delete (buscador -> sig);
            cout << "Lo encontre :)";
        }
        buscador = buscador -> sig;
    }
    
}

void manejoDatos::Mostrar_numeros_pares()
{
    nodo *busqueda = Inicio;
    while(busqueda)
    {
        if(busqueda -> dato % 2 == 0)
        {
            cout << busqueda -> dato << endl;
        }
        busqueda = busqueda -> sig;
    }
    
}

void manejoDatos::Mostrar_numeros_impares()
{
    nodo *busqueda = Inicio;
    while(busqueda)
    {
        if(busqueda -> dato % 2 != 0)
        {
            cout << busqueda -> dato << endl;
        }
        busqueda = busqueda -> sig;
    }
}
