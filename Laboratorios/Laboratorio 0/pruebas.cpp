#include"lab0.h"
#include<stdio.h>
#include<iostream>
using namespace std;


// ------ INICIO ------------------------------ FUNCIONES CAMBIO --------------------------------

float cambio::a_peso(float paga){
    return paga * cUSD;
}

float cambio::a_dolar(float paga){
    return paga / cUSD;

}

// ------ FIN ------------------------------ FUNCIONES CAMBIO --------------------------------


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


float Paga::a_dolar(float sueldoP){
//    return cambio::a_dolar(sueldoP);
}

float Paga::a_peso(float sueldoUS){
//     return cambio::a_peso(sueldoUS);
 }

// ------ FIN ------------------------------ FUNCIONES PAGA  --------------------------------

// ------ INICIO ------------------------------ FUNCIONES EMPLEADO --------------------------------
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
float empleado::get_sueldo_peso(){

}
float empleado::get_sueldo_dolar(){
    
}

void empleado::imprimir_empleado(){
    string nombre = this->getNombre();
    string ci = this->getCi();
    int edad = this->getEdad();
    Paga valor_hora = this->getValor_hora();
    float sueldo =  valor_hora.getMonto();
    
    cout << "---------------------------------- "<<endl;  
    cout << "INFORMACION DEL EMPLEADO: "<<endl;  

    cout << "Nombre: " <<nombre<<endl;
    cout << "CI: " <<ci<<endl;
    cout << "Edad: " <<edad<<endl;
    cout << "Valor Hora: " <<sueldo <<endl;
    cout << "Valor Peso: " << this->get_sueldo_peso() << endl;
    cout << "Valor Dolar: " << this->get_sueldo_dolar() << endl;

    cout << "---------------------------------- "<<endl;  
}
        



// ------ FIN ------------------------------- FUNCIONES EMPLEADO --------------------------------

// empresa::empresa(string nombre,string nombre_legal,int rut,empleado emp,int nro){
//     this->nombre = nombre;
//     this->nombre_legal = nombre_legal;
//     this->rut=rut;
//     this->empleados[nro]=emp;

// }

// ------ INICIO ------------------------------- FUNCIONES FIJO --------------------------------
fijo::fijo(string nombre, string ci, int edad, Paga valor_paga){
    setNombre(nombre);
    setCi(ci);
    setEdad(edad);
    setValor_hora(valor_paga);
}
fijo::~fijo(){}

float fijo::get_sueldo_peso(){
    Paga valor_hora = this->getValor_hora();
    if(valor_hora.getMoneda() == 0){  //SI ES USD
        return 40 * cambio::a_peso(valor_hora.getMonto());
    } else {
        return 40 * valor_hora.getMonto();
    }
    
}

float fijo::get_sueldo_dolar(){
    Paga valor_hora = this->getValor_hora();
    if(valor_hora.getMoneda() == 0){  //SI ES USD
        return 40 * valor_hora.getMonto();
    } else {
        return 40 * cambio::a_dolar(valor_hora.getMonto());
    }
    
}  



// ------ FIN ------------------------------- FUNCIONES FIJO --------------------------------

// ------ INICIO ------------------------------- FUNCIONES JORNALERO --------------------------------
jornalero::jornalero(string nombre, string ci, int edad, Paga valor_horas){
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

int main(){ 
   
    string nombre_empleado = " JORGE";
    string nombre_legal = " EMRESARIO";
    string ci = "50151411";
    int edad = 22;
    Paga valor = Paga();
    int rut = 158451;

    empleado emp = empleado(nombre_empleado,ci,edad,valor);
    emp.imprimir_empleado();
    ci = "8888888";
    fijo fij = fijo(nombre_empleado, ci, edad, valor);
    fij.imprimir_empleado();


    Paga val2 = Paga(129,US);
    ci = "99999999";
    jornalero jorna = jornalero(nombre_empleado, ci, edad, val2);
    jorna.set_horas(100);
    jorna.imprimir_empleado();


}
