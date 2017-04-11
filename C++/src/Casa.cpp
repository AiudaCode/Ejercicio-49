#include "Casa.h"

Casa::Casa()
{
    // se le asignan valores por defecto en el constructor de la clase a los atributos
    nomenclatura = "";
    kilovatios = 0;
    costo = 0;
    subtotal = 0;
}

Casa::~Casa()
{
    //dtor
}

void Casa::setNomenclatura(string val)
{
    nomenclatura = val;
}

string Casa::getNomenclatura()
{
    return nomenclatura;
}

void Casa::setKilovatios(int val)
{
    kilovatios = val;
}

int Casa::getKilovatios()
{
    return kilovatios;
}

void Casa::setCosto(int val)
{
    costo = val;
}

int Casa::getCosto()
{
    return costo;
}

void Casa::setSubtotal(double val)
{
    subtotal = val;
}

double Casa::getSubtotal()
{
    return subtotal;
}
