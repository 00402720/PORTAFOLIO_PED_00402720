#include <iostream>

using namespace std;

//Referencias de finciones
int calculador_de_mcm(int valor1, int valor2);

int main(void)
{
    cout << endl << "Algoritmo de Euclides" << endl << endl;

    //Variables
    int primer_valor, segundo_valor;

    //Ingreso de datos
    cout << "Favor ingresar los valores a utilizar " << endl;
    cout << "Valor 1: "; cin >> primer_valor;
    cout << "Valor 2: "; cin >> segundo_valor;

    if(primer_valor >= segundo_valor)
    {
       //Resultado
        cout << "El maximo comun divisor es " << calculador_de_mcm(primer_valor, segundo_valor);

        cout << endl;
        return 0;
    }
    cout << "El primer valor debe ser mayor o igual al segundo valor";

    cout << endl;
    return 1;
}

int calculador_de_mcm(int valor1, int valor2)
{
    if (valor1 == 0)
    {
        return valor2;
    }
    return calculador_de_mcm(valor2 % valor1, valor1) ;
}
