#include"lab0.h"
#include<stdio.h>
#include<iostream>
using namespace std;

// float cambio::a_peso(float paga){
//     Moneda cambio = US;
//     return paga * cambio;
// }

// float cambio::a_dolar(float paga){
//     Moneda cambio = 1;
//     try {
//         if (paga < 0) throw 1;
//         if (paga == 0) throw 0;
//         return paga / cambio;
//     }
//     catch (int ex){
//         if (ex == 0)
//             cout << "Se esta intentando hacer el cambio de Peso a Dólares utilizando un valor igual a 0." <<endl;

//         if (ex < 0)
//             cout << "Se esta intentando hacer el cambio de Peso a Dólares utilizando un valor menor a 0." <<endl;            
//     }
// }

Paga::Paga(){
    this->monto = 0;
    this->moneda = US;

}


// paga Paga::a_dolar(float sueldoP){
//     return cambio::a_dolar(sueldoP);
// }

// paga Paga::a_peso(float sueldoUS){
//     return cambio::a_peso(sueldoUS);
// }


// ------ INICIO ------------------------------ FUNCIONES EMPLEADO
empleado::empleado(){};
empleado::~empleado(){};
void empleado::setNombre(string nombre){
    this->nombre = nombre;
}
void empleado::setCi(string ci){
    this->ci = ci;
}
void empleado::setValor_hora(Paga valor_hora){
    this->valor_hora = valor_hora;
}
void empleado::setEdad(int edad){
    this->edad = edad;
}

string empleado::getNombre(){
    return this->nombre;
}

string empleado::getCi(){
    return this->ci;
}

Paga empleado::getValor_hora(){
    return this->valor_hora;
}

int empleado::getEdad(){
    return this->edad;
}

empleado::empleado(string nombre, string ci, int edad, Paga valor_hora){
    this->nombre = nombre;
    this->ci = ci;
    this->edad = edad;
    this->valor_hora = valor_hora;
}



// ------ FIN ------------------------------- FUNCIONES EMPLEADO

// empresa::empresa(string nombre,string nombre_legal,int rut,empleado emp,int nro){
//     this->nombre = nombre;
//     this->nombre_legal = nombre_legal;
//     this->rut=rut;
//     this->empleados[nro]=emp;
// }


fijo::fijo(string nombre, string ci, int edad, Paga valor_paga){
    setNombre(nombre);
    setCi(ci);
    setEdad(edad);
    setValor_hora(valor_paga);
}

jornalero::jornalero(string nombre, string ci, int edad, Paga valor_horas){
    setNombre(nombre);
    setCi(ci);
    setEdad(edad);
    setValor_hora(valor_horas);
}


float jornalero::get_sueldo_peso(){
   // return Paga getValor_hora() * this->horas;
}

float jornalero::get_sueldo_dolar(){
    // var= this->get_sueldo_peso();
    // return var/40.15;
}

float fijo::get_sueldo_peso(){
    // return this->valor_paga * 40;
}

float fijo::get_sueldo_dolar(){
    // var= this->get_sueldo_peso();
    // return var/40.15;
}  

// void empleado::imprimir_empleado(){


//     // cout << "Nombre: " << this->getNombre() << endl;
//     // cout << "CI: " << this->getCi() << endl;
//     // cout << "Edad: " << this->getEdad() << endl;
//     // cout << "Valor Hora: " << this->getValor_hora() << endl;
//     // cout << "Valor Peso: " << this->get_sueldo_peso() << endl;
//     // cout << "Valor Dolar: " << this->get_sueldo_dolar() << endl;
// }

int main(){ 
    cout<< "COMPIL:AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"<<endl;
    // string nombre_empleado = " JORGE";
    // string nombre_legal = " EMRESARIO";
    // string ci = "50151411";
    // int edad = 22;
    // paga valor = paga(float 185.000);
    // int rut = 158451;

    // empleado emp = empleado::empleado(nombre_empleado,nombre_legal,ci,edad,valor,rut);


}
