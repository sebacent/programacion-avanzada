// #include "Jornalero.h"

// // ------ INICIO ------------------------------- FUNCIONES JORNALERO --------------------------------
// Jornalero::Jornalero(std::string nombre, std::string ci, int edad, Paga valorHoras, Empresa *miemp){
//     setNombre(nombre);
//     setCi(ci);
//     setEdad(edad);
//     setValorHora(valorHoras);
// }
// Jornalero::~Jornalero(){}

// float Jornalero::getSueldoPeso(){
//     Paga valorHora = this->getValorHora();
//     if(valorHora.getMoneda() == 0){  //SI ES USD
//         return this->getHoras() * Cambio::aPeso(valorHora.getMonto());
//     } else {
//         return this->getHoras() * valorHora.getMonto();
//     }
    
// }

// float Jornalero::getSueldoDolar(){
//     Paga valorHora = this->getValorHora();
//     if(valorHora.getMoneda() == 0){  //SI ES USD
//         return this->getHoras() * valorHora.getMonto();
//     } else {
//         return this->getHoras() * Cambio::aDolar(valorHora.getMonto());
//     }
    
// }  


// void Jornalero::setHoras(int horas){ 
//     this->horas = horas;
// }

// int Jornalero::getHoras(){
//     return this->horas;
// }
// // ------ FIN ------------------------------- FUNCIONES JORNALERO --------------------------------
