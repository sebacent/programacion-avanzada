#ifndef PAGA_H
#define PAGA_H
#define MAX_EMPLEADOS 50
#define cUSD 40.15
#define cUS 1


enum Moneda{
    USD,
    US 
};


class Cambio{
    public:
        double aPeso(double);
        double aDolar(double);
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

        double getMonto(){return this->monto;};
        Moneda getMoneda();

        double aDolar(double);
        double aPeso(double);

};


#endif