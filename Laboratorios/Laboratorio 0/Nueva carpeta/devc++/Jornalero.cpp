#include "Jornalero.h"

// ------ INICIO ------------------------------- FUNCIONES JORNALERO --------------------------------
jornalero::jornalero(string nombre, string ci, int edad, Paga valor_horas, empresa *miemp){
    setNombre(nombre);
    setCi(ci);
    setEdad(edad);
    setValor_hora(valor_horas);
}
jornalero::~jornalero(){}

float jornalero::get_sueldo_peso(){
    Paga valor_hora = this->getValor_hora();
    if(valor_hora.getMoneda() == 0){  //SI ES USD
        return this->get_horas() * cambio::a_peso(valor_hora.getMonto());
    } else {
        return this->get_horas() * valor_hora.getMonto();
    }
    
}

float jornalero::get_sueldo_dolar(){
    Paga valor_hora = this->getValor_hora();
    if(valor_hora.getMoneda() == 0){  //SI ES USD
        return this->get_horas() * valor_hora.getMonto();
    } else {
        return this->get_horas() * cambio::a_dolar(valor_hora.getMonto());
    }
    
}  


void jornalero::set_horas(int horas){ 
    this->horas = horas;
}

int jornalero::get_horas(){
    return this->horas;
}
// ------ FIN ------------------------------- FUNCIONES JORNALERO --------------------------------
