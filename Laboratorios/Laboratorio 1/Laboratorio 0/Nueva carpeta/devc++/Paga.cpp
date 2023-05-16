#include "Paga.h"
// ------ INICIO ------------------------------ FUNCIONES PAGA --------------------------------
Paga::Paga(){
    this->monto = 250;
    this->moneda = US;

}
Paga::Paga(float monto, Moneda moneda){
    this->monto = monto; 
    this->moneda = moneda;
}

 Paga::~Paga(){};

float Paga::getMonto(){
    return this->monto;
}

void Paga::setMonto(float monto){
    this->monto = monto;
}

Moneda Paga::getMoneda(){
    return this->moneda;
}

void Paga::setMoneda(Moneda moneda){
    this->moneda = moneda;
}


float Paga::aDolar(float sueldoP){
//    return cambio::a_dolar(sueldoP);
}

float Paga::aPeso(float sueldoUS){
//     return cambio::a_peso(sueldoUS);
 }

// ------ INICIO ------------------------------ FUNCIONES CAMBIO --------------------------------

float Cambio::aPeso(float paga){
    return paga * cUSD;
}

float Cambio::aDolar(float paga){
    return paga / cUSD;

}
// ------ FIN ------------------------------ FUNCIONES PAGA  --------------------------------