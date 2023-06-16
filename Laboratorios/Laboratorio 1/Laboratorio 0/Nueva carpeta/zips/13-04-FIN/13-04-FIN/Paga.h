#ifndef PAGA_H
#define PAGA_H
#include <iostream>
#define MAX_EMPLEADOS 50
#define cUSD 40.15
#define cUS 1


enum Moneda{
    USD,
    US 
};

class Cambio{
    public:
        static double cPeso(double);
        static double cDolar(double);
};

class Paga{
    private:
        double monto;
        Moneda moneda;
    public:
        Paga();
        Paga(double, Moneda);
        ~Paga();
        void setMonto(double);
        void setMoneda(Moneda);
        double getMonto() const;
        Moneda getMoneda() const;
        double aDolar(double);
        double aPeso(double);
        //Paga operator+ (const Paga&,int);  
        Paga operator+ (const Paga& paga2);
        Paga operator* (int mult);
        Paga operator= (const Paga&);
        friend std::ostream& operator<<(std::ostream& os, const Paga& paga);
};
#endif