#include "Fijo.h"


// ------ INICIO ------------------------------- FUNCIONES FIJO --------------------------------
Fijo::Fijo(string nombre, string ci, int edad, Paga valorPaga, Empresa *miemp){
    setNombre(nombre);
    setCi(ci);
    setEdad(edad);
    setValorHora(valorPaga);
    if(int i=miemp->getCantEmpleados()< MAX_EMPLEADOS)
{
   miemp->misempleados[i+1]=;
        miemp->setCantEmpleados();
}

}
Fijo::~Fijo(){}

float Fijo::getSueldoPeso(){
    Paga valorHora = this->getValorHora();
    if(valorHora.getMoneda() == 0){  //SI ES USD
        return 40 * cambio::aPeso(valorHora.getMonto());
    } else {
        return 40 * valorHora.getMonto();
    }
    
}

float Fijo::getSueldoDolar(){
    Paga valorHora = this->getValorHora();
    if(valor_hora.getMoneda() == 0){  //SI ES USD
        return 40 * valorHora.getMonto();
    } else {
        return 40 * Cambio::aDolar(valorHora.getMonto());
    }

    
}  



// ------ FIN ------------------------------- FUNCIONES FIJO --------------------------------
