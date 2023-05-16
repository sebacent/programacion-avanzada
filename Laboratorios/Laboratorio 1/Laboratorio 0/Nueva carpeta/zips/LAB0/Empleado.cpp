#include "Empleado.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

Empleado::Empleado(string nombre, string ci, int edad, Paga valorHora, Empresa *miemp){
    this->nombre = nombre;
    this->ci = ci;
    this->edad = edad;
    this->valorHora = valorHora;
    this->miemp = miemp;
}

void Empleado::setNombre(string nombre){
    this->nombre = nombre;
}
void Empleado::setCi(string ci){
    this->ci = ci;
}
void Empleado::setValorHora(Paga _valorHora){
    try
    {
        if(_valorHora.getMonto() < 0)
            throw std::invalid_argument("Error: el monto del valor hora no puede ser un monto negativo.");

        if(_valorHora.getMoneda() != 0 && _valorHora.getMoneda() != 1) 
            throw std::invalid_argument("Error: la moneda del valor hora no es correcta.");
        this->valorHora = _valorHora;
    }
   catch (std::exception& e) {
        std::cout << "Ocurrio un error al asignar el valor hora: " << e.what() << std::endl;
    }
}

void Empleado::setEdad(int edad){
    try
    {
        if(edad <= 18)
            throw std::invalid_argument("Error: la edad no puede ser negativa ni menor de 18");
        
        this->edad = edad;
    }
    catch (std::exception& e) {
        std::cout << "Ocurrio un error al asignar la edad: " << e.what() << std::endl;
    }
}

void Empleado::setEmpresa(Empresa * miemp){
    this->miemp=miemp;
}
//-----------------EMPLEADO GETS
string Empleado::getNombre(){
    return this->nombre;
}

string Empleado::getCi(){
    return this->ci;
}

Paga Empleado::getValorHora(){
    return this->valorHora;
}

int Empleado::getEdad(){
    return this->edad;
}

Empresa* Empleado::getEmpresa(){
    return this->miemp;
}

double Empleado:: getPaga(){
    Paga _valorHora = this->getValorHora();
    return _valorHora.getMonto();
}

// ------ INICIO ------------------------------- FUNCIONES JORNALERO --------------------------------
Jornalero::Jornalero(std::string nombre, std::string ci, int edad, Paga valorHoras, int horas, Empresa *miemp){
    this->setNombre(nombre);
    this->setCi(ci);
    this->setEdad(edad);   
    this->setValorHora(valorHoras);
    this->setHoras(horas);
    this->setEmpresa(miemp);
}

double Jornalero::getSueldoPeso() {
    Paga valorHora = this->getValorHora();
    if(valorHora.getMoneda() == 0){  //SI ES USD
        return this->getHoras() * valorHora.getMonto() * cUSD;
    } else {
        return this->getHoras() * valorHora.getMonto();
    }
}

double Jornalero::getSueldoDolar() {
    Paga valorHora = this->getValorHora();
    if(valorHora.getMoneda() == 0){  //SI ES USD
        return this->getHoras() * valorHora.getMonto();
    } else {
        return this->getHoras() * valorHora.getMonto() / cUSD;
    }
}  

void Jornalero::setHoras(int horas){ 
    try
    {   
        if(horas <= 0)
            throw std::invalid_argument("Error: las horas no pueden ser 0 ni menores"); 
        this->horas = horas;
    }
    catch (std::exception& e) {
        std::cout << "Ocurrio un error al asignar las horas al Jornalero: " << e.what() << std::endl;
    }
}
    
    


int Jornalero::getHoras(){
    return this->horas;
}

void Jornalero::imprimirEmpleado() {
    string nombre = this->getNombre();
    string ci = this->getCi();
    int edad = this->getEdad();
    Paga valorHora = this->getValorHora();
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
    cout << "Valor Hora: " << sueldo;
       if (valorHora.getMoneda() == USD) 
       cout <<" USD"<< endl;
    else 
        cout <<" US"<< endl;
    cout << "Sueldo Peso: " << sueldoPeso << endl;
    cout << "Sueldo Dolar: " << sueldoDolar << endl;
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
}

double Fijo::getSueldoPeso() {
    Paga valorHora = this->getValorHora();
    if(valorHora.getMoneda() == 0){  //SI ES USD
        return 40 * cUSD * valorHora.getMonto();
    } else {
        return 40 * valorHora.getMonto();
    }
}

double Fijo::getSueldoDolar() {
    Paga valorHora = this->getValorHora();
    if(valorHora.getMoneda() == 0){  //SI ES USD
        return  valorHora.getMonto() * 40;
    } else {
        return 40 * valorHora.getMonto() / cUSD;
    }
}  

void Fijo::imprimirEmpleado() {
    string nombre = this->getNombre();
    string ci = this->getCi();
    int edad = this->getEdad();
    Paga valorHora = this->getValorHora();
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
    cout << "Valor Hora: "<< sueldo;
    if (valorHora.getMoneda() == USD) 
       cout <<" USD"<< endl;
    else 
        cout <<"US"<< endl;
    
    cout << "Sueldo Peso: " << sueldoPeso << endl;
    cout << "Sueldo Dolar: " << sueldoDolar << endl;
    
    cout << "Empresa, Nombre: " << miEmp->getNombre() << endl;
    cout << "Empresa, Nombre Legal:  " << miEmp->getNombreLegal() << endl;
    cout << "---------------------------------- "<<endl;     
}