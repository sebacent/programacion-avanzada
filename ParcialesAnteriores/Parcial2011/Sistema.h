#include<iostream>
#include"Cuenta.h"

class Sistema {
    private:
        static Sistema* instancia;
        Sistema (){};
    public:
        static Sistema* getInstancia(){};
        int comprarPuntos(int,int){};//IdCuenta, monto
        IDictionary* cuentas;
        IDictionary* organizacion;
};

