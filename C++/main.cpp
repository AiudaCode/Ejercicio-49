#include <iostream>
#include "Facturacion.h"
#include "Casa.h"

using namespace std;

// método para validar el costo
void validar(Facturacion *obj, int pos)
{
    double costo = (obj->getVector(pos)->getKilovatios() * 3);
    double descuento = (obj->getVector(pos)->getKilovatios() * obj->getVector(pos)->getCosto()) * 0.08;
    // si los kilovatios de la casa de la posicion pos es superior a 350 kilovatios
    if (obj->getVector(pos)->getKilovatios() > 350)
    {
        // entonces se le cobrara el triple al costo
        cout << "Se le cobrara el triple al costo por kilovatios" << endl;
        cout << "Nuevo costo: $" << costo << endl;
    }
    else
    {
        // sino el municipio le dara un subsidio
        cout << "El municipio le ha subsidiado un 0.8% al subtotal" << endl;
        cout << "Descuento: $" << descuento << endl;
    }
}

// método para mostrar el vector
void mostrarVector(Facturacion *obj)
{
    // recorremos el vector con el ciclo for
    for (int i = 0; i < obj->getTamano(); i++)
    {
        cout << "Nomenclatura: " << obj->getVector(i)->getNomenclatura() << endl;
        cout << "Kilovatios consumidos: " << obj->getVector(i)->getKilovatios() << endl;
        cout << "Costo basico: $" << obj->getVector(i)->getCosto() << endl;
        validar(obj, i);
        cout << "Subtotal: " << obj->getVector(i)->getSubtotal() << endl << endl;
    }
}

// método para llenar los datos de la casa
void llenar(Casa *cas)
{
    string nom;
    int kil, cos;
    cout << "Digite nomenclatura de la casa" << endl;
    cout << ">> ";
    cin >> nom;
    cas->setNomenclatura(nom);
    cout << "Digite kilovatios consumidos de la casa" << endl;
    cout << ">> ";
    cin >> kil;
    cas->setKilovatios(kil);
    cout << "Digite costo basico por kilovatio" << endl;
    cout << ">> ";
    cin >> cos;
    cas->setCosto(cos);
}

int main(void)
{
    // se crea un objeto de la clase Facturacion (Instanciación)
    Facturacion *obj = new Facturacion();
    // se declara un objeto de tipo Casa
    Casa *cas;
    // pedimos el tamaño del vector
    int numeroElementos;
    cout << "Digite tamano del Vector" << endl;
    cout << ">> ";
    cin >> numeroElementos;
    // encapsumalos la variable numeroElementos
    obj->setTamano(numeroElementos);
    // creamos el vector
    obj->crearVector();
    // recorremos el vector con ciclo for
    for (int i = 0; i < obj->getTamano(); i++)
    {
        // creamos una nueva instancia de tipo Casa
        cas = new Casa();
        cout << "Llene la informacion de la casa " << i << endl;
        // se llena la informacion del objeto cas
        llenar(cas);
        // guardamos en la posicion i el objeto cas
        obj->setVector(i, cas);
    }
    // calculamos el subtotal
    obj->calcularSubtotal();
    // mostramos el vector
    mostrarVector(obj);
}
