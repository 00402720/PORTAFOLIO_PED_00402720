#include <iostream>

using namespace std;

struct estudiante{
    string nombre_completo, carnet;
    int nivel_carrera, horas_sociales;
    int llegadas;
};

struct nodo{
    estudiante datosRegistro;
    nodo *sig;
};

class manejoEstudiantes
{
    private:
    nodo *pPila, *pCola;

    void Pila_Insertar_Datos(estudiante est);
    void Cola_Insertar_Datos(estudiante est);

    public:
    manejoEstudiantes()
    {
        pPila = NULL;
        pCola = NULL;
    }

    ~manejoEstudiantes()
    {
        delete pPila;
        delete pCola;
    }

    void Pila_Datos();
    void Cola_Datos();

    void Filtrar_Datos_Estudiantes(string carnet);
    void Mostrar_Datos_Pila();
    void Mostrar_Datos_Cola();
    void Asistencia_estudiantes(string carnet);
};

void manejoEstudiantes::Pila_Datos()
{
    estudiante est;
    int final = 0;

    do
    {
        cout << endl; //Estetica
        cout << "Nombre Completo: "; cin >> est.nombre_completo;
        cout << "Numero de carnet: "; cin >> est.carnet;
        cout << "Nivel de carrera: "; cin >> est.nivel_carrera;
        cout << "Cantidad de horas sociales: "; cin >> est.horas_sociales;
        cin.clear(); cin.ignore(1000, '\n');
        Pila_Insertar_Datos(est);
        cout << endl; //Estetica
        cout << "Seleccione 1 si desea continuar o 2 si ha finalizado. "; cin >> final;
    } while (final == 1);
    
}

void manejoEstudiantes::Pila_Insertar_Datos(estudiante est)
{
    nodo *n = new nodo;
    n -> datosRegistro = est;
    n -> sig = pPila;
    pPila = n;
}

void manejoEstudiantes::Cola_Datos()
{
    estudiante est;
    int final = 0;

    do
    {
        cout << endl; //Estetica
        cout << "Nombre Completo: "; cin >> est.nombre_completo;
        cout << "Numero de carnet: "; cin >> est.carnet;
        cout << "Nivel de carrera: "; cin >> est.nivel_carrera;
        cout << "Cantidad de horas sociales: "; cin >> est.horas_sociales;
        cin.clear(); cin.ignore(1000, '\n');
        Cola_Insertar_Datos(est);
        cout << endl; //Estetica
        cout << "Seleccione 1 si desea continuar o 2 si ha finalizado. "; cin >> final;
    } while (final == 1);

}

void manejoEstudiantes::Cola_Insertar_Datos(estudiante est)
{
    nodo *n = new nodo;
    n -> datosRegistro = est;
    n -> sig = NULL;

    if (!pCola)
    {
        pCola = n;
    }
    else
    {
        nodo *aux = pCola;

        while (aux -> sig)
        {
            aux = aux -> sig;
        }
        aux -> sig = n;
    }
}

void manejoEstudiantes::Filtrar_Datos_Estudiantes(string carnet)
{
    bool BINGO = false;

    //Busqueda en primera lista (pPila)
    nodo *aux = pPila;

    while (aux)
    {
        if (aux -> datosRegistro.carnet == carnet)
        {
            cout << "Nombre completo: " << aux -> datosRegistro.nombre_completo << endl;
            cout << "Nivel de carrera: " << aux -> datosRegistro.nivel_carrera << endl;
            cout << "Cantidad de horas sociales: " << aux -> datosRegistro.horas_sociales << endl;
            BINGO = true;
            break;
        }
        aux = aux -> sig;
    }

        if (BINGO)
        {
            return;
        }

        //Busqueda en segunda lista (pCola)
        aux = pCola;
        
        while(aux)
        {
            if (aux ->datosRegistro.carnet == carnet)
            {
                cout << "Nombre completo: " << aux -> datosRegistro.nombre_completo << endl;
                cout << "Nivel de carrera: " << aux -> datosRegistro.nivel_carrera << endl;
                cout << "Cantidad de horas sociales: " << aux -> datosRegistro.horas_sociales << endl;
                BINGO = true;
                break;
            }
            aux = aux -> sig;
        }

        if (!BINGO)
        {
            cout << "No se ha encontrado el carnet ingresado.";
        }
}

void manejoEstudiantes::Mostrar_Datos_Pila()
{
    nodo *aux = pPila;

    while (aux)
    {
        cout << endl;
        cout << "Nombre completo: " << aux -> datosRegistro.nombre_completo << endl;
        cout << "Numero de Carnet: " << aux -> datosRegistro.carnet << endl;
        cout << "Nivel de carrera: " << aux -> datosRegistro.nivel_carrera << endl;
        cout << "Cantidad de horas sociales: " << aux -> datosRegistro.horas_sociales << endl;
        if(aux -> datosRegistro.llegadas)
        {
            cout << "Asistencias: " << aux -> datosRegistro.llegadas << endl;
        }
        aux = aux -> sig;
    }
    
}

void manejoEstudiantes::Mostrar_Datos_Cola()
{
    nodo *aux = pCola;

    while (aux)
    {
        cout << endl;
        cout << "Nombre completo: " << aux -> datosRegistro.nombre_completo << endl;
        cout << "Numero de Carnet: " << aux -> datosRegistro.carnet << endl;
        cout << "Nivel de carrera: " << aux -> datosRegistro.nivel_carrera << endl;
        cout << "Cantidad de horas sociales: " << aux -> datosRegistro.horas_sociales << endl;
        if(aux -> datosRegistro.llegadas)
        {
            cout << "Asistencias: " << aux -> datosRegistro.llegadas << endl;
        }
        aux = aux -> sig;
    }
}

void manejoEstudiantes::Asistencia_estudiantes(string carnet)
{
    nodo *aux = pPila;
    bool BINGO = false;

    while(aux)
    {
        if(aux -> datosRegistro.carnet == carnet)
        {
            cout << "Asistencias: " ; cin >> aux -> datosRegistro.llegadas;
            BINGO = true;
        }
        aux = aux -> sig;
    }

    if(BINGO)
    {
        return;
    }

    aux = pCola;

    while(aux)
    {
        if(aux -> datosRegistro.carnet == carnet)
        {
            cout << "Asistencias: " ; cin >> aux -> datosRegistro.llegadas;
            BINGO = true;
        }
        aux = aux -> sig;
    }

    if(!BINGO)
    {
        cout << "No se ha encontrado el carnet ingresado. ";
        return;
    }
    return;

}

int main(void)
{

    manejoEstudiantes est;
    int opcion = 0;
    string carnet_a_buscar = "";

    cout << endl << endl << "SISTEMA DE REGISTROS UNIVERSIDAD CENTROAMERICANA 'JOSE SIMEON CAÑAS'" << endl;

    do
    {
        cout << endl;
        cout << "1) Ingresar datos del estudiante al inicio" << endl;
        cout << "2) Ingresar datos de estudiante por orden de llegada" << endl;
        cout << "3) Buscar estudiante por carnet" << endl;
        cout << "4) Ver todos los estudiantes" << endl;
        cout << "5) Ingresar asistencia de alumnos" << endl;
        cout << "6) Ver estudiantes por orden de llegada" << endl;
        cout << "0) Salir" << endl;
        cout << "Opcion: "; cin >> opcion;

        cin.clear(), cin.ignore(1000, '\n');

        switch (opcion)
        {
        case 1:
            est.Pila_Datos(); //Ingresar datos de estudiantes en Pila
            break;

        case 2:
        est.Cola_Datos(); //Insertar datos de estudiantes en Cola
        break;

        case 3:
        cout << endl << "Carnet a buscar: "; cin >> carnet_a_buscar; //Buscar estudiante por carnet
        est.Filtrar_Datos_Estudiantes(carnet_a_buscar);
        break;

        case 4:
        cout << endl << "Estudiantes ingresados al inicio "; //Ver lista de estudiantes
        est.Mostrar_Datos_Pila();
        break;

        case 5:
        cout << endl << "Ingresar asistencia de alumnos" << endl; //Ingresar cantidad total de asistencias de alumnos
        cout << "Carnet de estudiante: "; cin >> carnet_a_buscar;
        est.Asistencia_estudiantes(carnet_a_buscar);
        break;

        case 6:
        cout << endl << "Estudiantes por orden de llegada "; //Ver lista de estudiantes segun el orden de ingreso
        est.Mostrar_Datos_Cola();
        break;

        default:
            break;
        }
    } while (opcion != 0);

    cout << endl;
    return 0;
}
// :)
