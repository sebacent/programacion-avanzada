#include "Paga.h"
//#include <iostream>
#include <stdio.h>
#include <iomanip>

// ------ INICIO ------------------------------ FUNCIONES CAMBIO --------------------------------

double Cambio::cPeso(double paga){
    return paga * cUSD;
}

double Cambio::cDolar(double paga){
    return paga / cUSD;

}
// ------ FIN ------------------------------ FUNCIONES PAGA  --------------------------------

// ------ INICIO ------------------------------ FUNCIONES PAGA --------------------------------
Paga::Paga(){
    this->monto = 0;
    this->moneda = US;

}

Paga::Paga(double monto, Moneda moneda){
    this->monto = monto; 
    this->moneda = moneda;
}

Paga::~Paga(){};

double Paga::getMonto() const {
    return this->monto;
}

void Paga::setMonto(double _monto){
    this->monto = _monto;   
}

Moneda Paga::getMoneda() const {
    return this->moneda;
}

void Paga::setMoneda(Moneda moneda){
    this->moneda = moneda;
}

double Paga::aDolar(double sueldoP){
    if(this->moneda == USD)
        return sueldoP;
    else
        return Cambio::cDolar(sueldoP);
}   

double Paga::aPeso(double sueldoP){
    if(this->moneda == US)
        return sueldoP;
    else
     return Cambio::cDolar(sueldoP);
}

//SOBRECARGAS 


Paga Paga::operator+ (const Paga& paga2){
   try {
       if (this->moneda != paga2.moneda) {
            throw std::invalid_argument("Error: no se pueden sumar 2 Pagas con diferentes monedas");
        }
        double res = this->monto + paga2.monto;
        Paga resultado = Paga(res, this->moneda);
        return resultado;
    }
    catch (std::exception& e) {
        std::cout << "Ocurrio un error del operador +: " << e.what() << std::endl;
        return Paga();
    }
    

}


Paga Paga::operator= (const Paga& nueva){
    this->monto = nueva.monto;
    this->moneda = nueva.moneda;
    return *this;
}
// Paga operator* (int mult){
    

// std::ostream& operator<<(std::ostream& os, const Paga& paga) {
//     os << "Monto: " << paga.getMonto() << " ";
//     os << "Moneda: ";
//     if (paga.getMoneda() == USD) {
//         os << "USD";
//     } else {
//         os << "US";
//     }
//     return os;
// }
std::ostream& operator<<(std::ostream& os, const Paga& paga) {
   os << "Monto: " << std::fixed << std::setprecision(3) << paga.monto;
    if (paga.getMoneda() == USD) 
        os << " USD";    
    else
       os << " US";    
    return os;
}


// }
// ------ FIN ------------------------------ FUNCIONES PAGA --------------------------------