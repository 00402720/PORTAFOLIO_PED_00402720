#include <iostream>

using namespace std;

struct nodo{
    int dato;
    nodo *ant;
    nodo *sig;
};

class ListaDoble{
    private:
        nodo *pInicio;
    
    public:
        ListaDoble();
        ~ListaDoble();
        void insertarEnLista(void);
        void mostrarLista(void);
        void insertarAntesDeElemento(int dato, int datoRef); // Función a elaborar.
        void buscarRec(int);
        bool buscarRecAux(nodo *pInicio, int datoB); // Función a elaborar.
        void sumaypromedio(void); // Función a elaborar.
};

ListaDoble::ListaDoble(void)
{
    pInicio = NULL;
}

ListaDoble::~ListaDoble(void)
{
    nodo *p;

    while(pInicio){
        p = pInicio;
        pInicio = pInicio->sig;
        delete p;
    }
}

void ListaDoble::insertarEnLista(void) //Necesitaba cambiar el metodo de recoleccion ya que no se el substituto de Ctrl-Z en macOS :(
{                                       //Ahora no se si tiene que ver con que tuve que cambiar esta parte del codigo :(((
    int dato, datoRef, cantidad_de_elementos = 0;
    cout << "¿Cuantos valores ingresara? "; cin >> cantidad_de_elementos;

    while(cantidad_de_elementos)
    {
        cout << "Digite un entero: ";
        cin >> dato;
        cout << "Digite el elemento antes del cual insertara: ";
        cin >> datoRef;
        insertarAntesDeElemento(dato, datoRef);
        cantidad_de_elementos--;
    }
}

// ESCRIBA AQUÍ LA FUNCIÓN DE INSERTAR NODOS ANTES DE UN ELEMENTO DETERMINADO:
void ListaDoble::insertarAntesDeElemento(int dato, int datoRef) //NO ENCUENTRO EL ERORERO
{
    //cout << "Insertando numero..." << endl;
    nodo *nuevo = new nodo;
    nuevo -> dato = dato;

    if(!pInicio)
    {
        pInicio = nuevo;
        pInicio -> sig = NULL;
        pInicio -> ant = NULL;
        //cout << "Se agrego un nuevo nodo :)" << endl;
    }
    else
    {
        //cout << "Hay mas de un nodo" << endl;
    nodo *busqueda = pInicio;
        while (busqueda -> sig && busqueda -> dato != datoRef)
        {
            busqueda = busqueda -> sig;
        }
        nuevo -> sig = busqueda -> sig;
        if(busqueda -> sig)
        {
            nuevo -> sig -> ant = nuevo;
            busqueda -> sig = nuevo;
        }
        busqueda -> sig = nuevo;
    }
}


void ListaDoble::mostrarLista(void)
{
    nodo *p;
    cout << "Los elementos de la lista son:" << endl;
    p = pInicio;
    while(p->sig){
        cout << p->dato << endl;
        p = p->sig;
    }
    while(p->ant){
        cout << p->dato << endl;
        p = p->ant;
    }
    cout << "Fin de mostrar lista" << endl;
}

void ListaDoble::buscarRec(int datoB)
{
    if(buscarRecAux(pInicio, datoB))
        cout << "Si lo encontre" << endl;
    else
        cout << "No lo encontre" << endl;
}

// ESCRIBA AQUÍ LA FUNCIÓN DE BÚSQUEDA RECURSIVA:
bool ListaDoble::buscarRecAux(nodo *pInicio, int datoB)
{
    nodo *busqueda = pInicio;
    while(busqueda)
    {
        if(busqueda -> dato == datoB)
        {
            return true;
        }
        busqueda = busqueda -> sig;
    }
    return false;
}


// ESCRIBA AQUÍ LA FUNCIÓN QUE CALCULA LA SUMA Y EL PROMEDIO:
void ListaDoble::sumaypromedio(void)
{
    nodo *recolectador = pInicio;
    int resultado_suma = 0, cantidad_elementos = 0;
    float resultado_promedio = 0;

    while (recolectador)
    {
        resultado_suma += recolectador -> dato;
        cantidad_elementos++;
    }
    resultado_promedio = resultado_suma / cantidad_elementos;
    cout << "La suma de los elementos ingresados es: " << resultado_suma << endl;
    cout << "El promedio de los elementos ingresados es: " << resultado_promedio << endl;
}


int main(void)
{
    ListaDoble objListaDoble;

    cout << endl;
    cout << "PROGRAMA DEL SEGUNDO EXAMEN PARCIAL" << endl << endl;

    cout << "Insercion de datos en la lista:" << endl;
    objListaDoble.insertarEnLista();

    objListaDoble.mostrarLista();

    cin.clear();
    int datoB;
    cout << "Que dato desea buscar? ";
    cin >> datoB;
    objListaDoble.buscarRec(datoB);
    cout << "Resultado de suma y promedio";
    objListaDoble.sumaypromedio();
    
    cout << endl;
    return 0;
}
// :(
// Estoy casi 100% seguro que las ultimas 2 funciones correrian y lograrian su objetivo pero son dependientes de la primera funcion (la que no funciona)
//Hice lo que pude pero se termino mi tiempo 11:24
