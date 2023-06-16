#include "Empleado.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;
Empleado::Empleado(){};
Empleado::~Empleado(){};

//EMPLEADO SETS
void Empleado::setNombre(string nombre){
    this->nombre = nombre;
}
void Empleado::setCi(string ci){
    this->ci = ci;
}
void Empleado::setValorHora(Paga _valorHora){
    // cout<< "SETEO MONTO " << _valorHora.getMonto()<<endl;
    // cout<< "SETEO MONEDA " << _valorHora.getMoneda()<<endl;
    this->valorHora = _valorHora;
}
void Empleado::setEdad(int edad){
    this->edad = edad;
}

void Empleado::setEmpresa(Empresa * miemp){
    this->miemp=miemp;
}


//EMPLEADO GETS
string Empleado::getNombre(){
    return this->nombre;
}

string Empleado::getCi(){
    return this->ci;
}

Paga Empleado::getValorHora(){
    return this->valorHora;
}

// Paga getSueldoPeso(){
//     // if(valorHora.getMoneda() == Moneda::USD){
//     //     return Paga(Cambio::a_pesos(valorHora.getMonto()), Moneda::US);
//     // }
//     // else{
//     //     return valorHora;
//     // }
// }

int Empleado::getEdad(){
    return this->edad;
}

Empresa* Empleado::getEmpresa(){
    return this->miemp;
}

double Empleado:: getPaga(){
    // Paga _valorHora = this->getValorHora();
    // return _valorHora.getMonto();
    cout << "RETORNO 777 FILO DA PUTA" << endl;
    cout<<"ACA LLEGO"<< endl;
    
    cout<<"Y ACA NO LLEGO"<< endl;
    return 777.01;
}

Empleado::Empleado(string nombre, string ci, int edad, Paga valorHora, Empresa *miemp){
    this->nombre = nombre;
    this->ci = ci;
    this->edad = edad;
    this->valorHora = valorHora;
    this->miemp = miemp;
}

//DEBERIAN DE EXISTIR ESTAS 2?????? YA LAS TENGO EN SUS HIJOS
//NO NO DEBO DECLARARLAS DE NUEVO, SE DECLARAN COMO VIRTUALES PURAS EN EL Empleado.h igualandolas a 0
// float Empleado::getSueldoPeso(){
//     Paga valorHora = this->getValorHora();
//     if(valorHora.getMoneda() == 0){  //SI ES USD
//         return 40 * Cambio::aPeso(valorHora.getMonto());
//     } else {
//         return 40 * valorHora.getMonto();
//     }
// }

// float Empleado::getSueldoDolar(){
//     Paga valorHora = this->getValorHora();
//     if(valorHora.getMoneda() == 0){  //SI ES USD
//         return 40 * valorHora.getMonto();
//     } else {
//         return 40 * Cambio::aDolar(valorHora.getMonto());
//     }
// }

// void Empleado::imprimirEmpleado(){
//     string nombre = this->getNombre();
//     string ci = this->getCi();
//     int edad = this->getEdad();
//     Paga valorHora = this->getValorHora();
//     float sueldo =  valorHora.getMonto();
    

//     float sueldoPeso = this->getSueldoPeso();
//     float sueldoDolar = this->getSueldoDolar();
//     cout << sueldo <<endl;
//     INICIO -------------DEBUG
    
    

//     FIN -------------DEBUG
//     cout << "---------------------------------- "<<endl;  
//     cout << "INFORMACION DEL EMPLEADO: "<<endl;  

//     cout << "CI: " <<ci<<endl;
//     cout << "Nombre: " <<nombre<<endl;
//     cout << "Edad: " <<edad<<endl;
//     cout << "Valor Hora: " << sueldo <<endl;
//     cout << "Valor Peso: " << sueldoPeso << endl;
//     cout << "Valor Dolar: " << sueldoDolar << endl;
//     cout << "Empresa, Nombre: " << this->miemp->getNombre() << endl;
//     cout << "Empresa, Nombre Legal:  " << this->miemp->getNombreLegal() << endl;
//     cout << "---------------------------------- "<<endl;  
// }

// ------ FIN ------------------------------- FUNCIONES EMPLEADO --------------------------------


// VA TODO EN UN MISMO .h Y .cpp (NO LOGRE QUE FUNCIONARA DE OTRA FORMA)


// ------ INICIO ------------------------------- FUNCIONES JORNALERO --------------------------------
Jornalero::Jornalero(std::string nombre, std::string ci, int edad, Paga valorHoras, int horas, Empresa *miemp){
    setNombre(nombre);
    setCi(ci);
    setEdad(edad);
    setValorHora(valorHoras);
    setEmpresa(miemp);
    setHoras(horas);
}
Jornalero::~Jornalero(){}

double Jornalero::getSueldoPeso() {
    // Paga valorHora = this->getValorHora();
    // if(valorHora.getMoneda() == 0){  //SI ES USD
    //     return this->getHoras() * Cambio::aPeso(valorHora.getMonto());
    // } else {
    //     return this->getHoras() * valorHora.getMonto();
    // }
    return 10;
    
}

double Jornalero::getSueldoDolar() {
    return 10;
    // Paga valorHora = this->getValorHora();
    // if(valorHora.getMoneda() == 0){  //SI ES USD
    //     return this->getHoras() * valorHora.getMonto();
    // } else {
    //     return 10;
        //return this->getHoras() * Cambio::aDolar(valorHora.getMonto());
    //}
    
}  


void Jornalero::setHoras(int horas){ 
    this->horas = horas;
}

int Jornalero::getHoras(){
    return this->horas;
}


void Jornalero::imprimirEmpleado() {
    string nombre = this->getNombre();
    string ci = this->getCi();
    int edad = this->getEdad();
    Paga valorHora = Paga(129,US);//this->getValorHora();
    double sueldo =  valorHora.getMonto();
    double sueldoPeso = this->getSueldoPeso();
    double sueldoDolar = this->getSueldoDolar();
    Empresa * miEmp = this->getEmpresa();
    //INICIO -------------DEBUG

    //FIN -------------DEBUG
    cout << "---------------------------------- "<<endl;  
    cout << "INFORMACION DEL EMPLEADO: "<<endl;  

    cout << "CI: " <<ci<<endl;
    cout << "Nombre: " <<nombre<<endl;
    cout << "Edad: " <<edad<<endl;
    // cout << "Valor Hora: " << sueldo <<endl;
    // cout << "Valor Peso: " << sueldoPeso << endl;
    // cout << "Valor Dolar: " << sueldoDolar << endl;
    cout << "Empresa, Nombre: " << miEmp->getNombre() << endl;
    cout << "Empresa, Nombre Legal:  " << miEmp->getNombreLegal() << endl;
    cout << "---------------------------------- "<<endl;  
}
// ------ FIN ------------------------------- FUNCIONES JORNALERO --------------------------------



// ------ INICIO ------------------------------- FUNCIONES FIJO --------------------------------
Fijo::Fijo(std::string nombre, std::string ci, int edad, Paga valorPaga, Empresa *miemp){
    setNombre(nombre);
    setCi(ci);
    setEdad(edad);
    setValorHora(valorPaga);
    setEmpresa(miemp);
    // if(int i=miemp->getCantEmpleados()< MAX_EMPLEADOS){
    //     miemp->misempleados[i+1]=;
    //     miemp->setCantEmpleados();
    // }
}
Fijo::~Fijo(){}

double Fijo::getSueldoPeso() {
    return 10;
    // Paga valorHora = this->getValorHora();
    // if(valorHora.getMoneda() == 0){  //SI ES USD
    //     return 40.15 * valorHora.getMonto();
    //     //return 40 * Cambio::aPeso(valorHora.getMonto());
    // } else {
    //     return valorHora.getMonto();
    // }
    
}

double Fijo::getSueldoDolar() {
    return 10;
   // Paga valorHora = this->getValorHora();
    // if(valorHora.getMoneda() == 0){  //SI ES USD
    //     return 40 * valorHora.getMonto();
    // } else {
     //   return 10;
        //return 40 * Cambio::aDolar(valorHora.getMonto());
    // }

    
}  

void Fijo::imprimirEmpleado() {
    string nombre = this->getNombre();
    string ci = this->getCi();
    int edad = this->getEdad();
    Paga valorHora = Paga(129,US); //this->getValorHora();
    double sueldo =  valorHora.getMonto();
    double sueldoPeso = this->getSueldoPeso();
    double sueldoDolar = this->getSueldoDolar();
    Empresa * miEmp = this->getEmpresa();
    //INICIO -------------DEBUG

    

    //FIN -------------DEBUG
    cout << "---------------------------------- "<<endl;  
    cout << "INFORMACION DEL EMPLEADO: "<<endl;  

    cout << "CI: " <<ci<<endl;
    cout << "Nombre: " <<nombre<<endl;
    cout << "Edad: " <<edad<<endl;
    // cout << "Valor Hora: "<< 10 << endl;
    //cout << fixed << setprecision(2) << sueldo <<endl;
    
    // cout << "Valor Peso: " << sueldoPeso << endl;
    // cout << "Valor Dolar: " << sueldoDolar << endl;
    
    cout << "Empresa, Nombre: " << miEmp->getNombre() << endl;
    cout << "Empresa, Nombre Legal:  " << miEmp->getNombreLegal() << endl;
    cout << "---------------------------------- "<<endl;  
    
}


// ------ FIN ------------------------------- FUNCIONES FIJO --------------------------------