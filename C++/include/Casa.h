#ifndef CASA_H
#define CASA_H
#include <iostream>

using namespace std;

class Casa
{
    public:
        Casa();
        virtual ~Casa();
        void setNomenclatura(string val);
        string getNomenclatura();
        void setKilovatios(int val);
        int getKilovatios();
        void setCosto(int val);
        int getCosto();
        void setSubtotal(double val);
        double getSubtotal();
    protected:

    private:
        // se declaran los atributos privados de la clase
        string nomenclatura;
        int kilovatios;
        int costo;
        double subtotal;
};

#endif // CASA_H
