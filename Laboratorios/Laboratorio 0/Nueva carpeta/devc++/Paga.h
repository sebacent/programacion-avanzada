#ifndef PAGA_H
#define PAGA_H
#define MAX_EMPLEADOS 50
#define cUSD 40.15;
#define cUS 1;


enum Moneda{
    USD,
    US 
};



class Cambio{
    public:
        static float aPeso(float);
        static float aDolar(float);
};

class Paga{

    private:
        float monto;
        Moneda moneda;
    public:
        Paga();
        Paga(float monto, Moneda moneda);
        ~Paga();
        void setMonto(float);
        void setMoneda(Moneda);
        float getMonto();
        Moneda getMoneda();

        float aDolar(float);
        float aPeso(float);

};
#endif