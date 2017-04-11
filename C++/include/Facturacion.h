#ifndef FACTURACION_H
#define FACTURACION_H
#include "Casa.h"
#include <iostream>

using namespace std;

class Facturacion
{
    public:
        Facturacion();
        virtual ~Facturacion();
        void crearVector();
        void setTamano(int n);
        int getTamano();;
        void setVector(int pos, Casa *n);
        Casa *getVector(int pos);
        void subsidioMunicipio(int pos);
        void cobroExtraordinario(int pos);
        void calcularSubtotal();
    protected:

    private:
        // se declaran los atributos privados de la clase
        int tamano;
        Casa *vector;
};

#endif // FACTURACION_H
