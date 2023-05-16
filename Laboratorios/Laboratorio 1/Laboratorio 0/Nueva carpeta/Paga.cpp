#include "Paga.h"
#include <iostream>
#include <stdio.h>

// ------ INICIO ------------------------------ FUNCIONES CAMBIO --------------------------------

double Cambio::aPeso(double paga){
    return paga * cUSD;
}

double Cambio::aDolar(double paga){
    return paga / cUSD;

}

// Paga Cambio::aPeso(Paga paga) {
//     if (paga.getMoneda() == Moneda::USD) {
//         return Paga(Cambio::aPeso(paga.getMonto()), Moneda::US);
//     }else {
//         return paga;
//     }
// }
// ------ FIN ------------------------------ FUNCIONES PAGA  --------------------------------

// ------ INICIO ------------------------------ FUNCIONES PAGA --------------------------------
Paga::Paga(){
    this->monto = 1177.48;
    this->moneda = US;

}
Paga::Paga(double monto, Moneda moneda){
    this->monto = monto; 
    this->moneda = moneda;
}

 Paga::~Paga(){};

// double Paga::getMonto(){
//     // std::cout << "Devuelvo monto: " << this->monto << std::endl;
//     return this->monto;
// }

void Paga::setMonto(double _monto){
    //std::cout<< "SETEO EL  monto: " << _monto << std::endl;
    this->monto = _monto;
    
}

Moneda Paga::getMoneda(){
    //std::cout << "Devuelvo moneda: " << this->moneda << std::endl;
    return this->moneda;
}

void Paga::setMoneda(Moneda moneda){
    this->moneda = moneda;
}


double Paga::aDolar(double sueldoP){
    return sueldoP / cUSD;
    // if (this->moneda == 0)
    //     return sueldoP;
    // else        
    //     return sueldoP;
}   

double Paga::aPeso(double sueldoUS){
     return sueldoUS * cUSD;
 }
// ------ FIN ------------------------------ FUNCIONES PAGA --------------------------------
 