#include "Facturacion.h"

Facturacion::Facturacion()
{
    // se le asignan valores por defecto en el constructor de la clase a los atributos
    tamano = 0;
    vector = NULL;
}

Facturacion::~Facturacion()
{
    //dtor
}

// método para crear el vector
void Facturacion::crearVector()
{
    vector = new Casa[tamano];
}

// métodos Setters y Getters de los atributos de la clase
void Facturacion::setTamano(int n)
{
    tamano = n;
}
int Facturacion::getTamano()
{
    return tamano;
}
void Facturacion::setVector(int pos, Casa* n)
{
    vector[pos] = *n;
}

Casa *Facturacion::getVector(int pos)
{
    return &vector[pos];
}

// método para calcular el subsidio que dara el municipio
void Facturacion::subsidioMunicipio(int pos)
{
    // se inicializa una variable de tipo double descuento, y se le asigna el valor de kilovatios por
    // el costo de la casa en la posicion pos y se multiplica ese valor por 0.08
    double descuento = (getVector(pos)->getKilovatios() * getVector(pos)->getCosto()) * 0.08;
    // se inicializa una variable de tipo double resultado, se le asigna el valor de kilovatios consumidos
    // por el costo de la casa en la posicion pos y a ese valor se le restara el valor de la variable descuento
    double resultado =  (getVector(pos)->getKilovatios() * getVector(pos)->getCosto()) - descuento;
    // se modifica el subtotal de la posicion pos
    getVector(pos)->setSubtotal(resultado);
}

// método para calcular el cobro extraordinario
void Facturacion::cobroExtraordinario(int pos)
{
    // se declara una variable de tipo double resultado
    double resultado;
    // se le asigna el los kilovatios consumidos por el costo de la casa en posicion pos, ese valor se multiplicara por 3
    resultado = getVector(pos)->getKilovatios() * (getVector(pos)->getCosto() * 3);
    // se modifica el subtotal de la posicion pos
    getVector(pos)->setSubtotal(resultado);
}

// método para calcular el subtotal
void Facturacion::calcularSubtotal()
{
    // recorremos el vector con el ciclo for
    for (int i = 0; i < getTamano(); i++)
    {
        // si los kilovatios consumidos por la casa en la posicion i es mayor a 350
        if (getVector(i)->getKilovatios() > 350)
        {
            // entonces se le hara un cobro extraordinario a esa casa (se le multiplicara por 3 el costo)
            cobroExtraordinario(i);
        }
        else
        {
            // sino, entonces se le dara el subsidio del municipio a esa casa
            subsidioMunicipio(i);
        }
    }
}
