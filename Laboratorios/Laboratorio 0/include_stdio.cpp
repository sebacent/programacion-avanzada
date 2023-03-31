#include<lab0.h>
#include<stdio.h>

using namespace std;

float cambio::a_peso(float paga){
    Moneda cambio = 0;
    return paga * cambio;
}
float cambio::a_dolar(float paga){
    Moneda cambio = 1;
    if (paga != 0){
        return paga / cambio;
    } else {
        return paga;
    }
    
}

Paga::paga(){
    this->monto = 0;
    this->moneda = 1;

}


paga Paga::a_dolar(float sueldoP){
    return cambio::a_dolar(sueldoP);
}

paga Paga::a_peso(float sueldoUS){
    return cambio::a_peso(sueldoUS);
}


empleado::empleado(string nombre, string ci, int edad, paga valor_hora){
    this->nombre = nombre;
    this->ci = ci;
    this->edad = edad;
    this->valor_hora = valor_hora;
}