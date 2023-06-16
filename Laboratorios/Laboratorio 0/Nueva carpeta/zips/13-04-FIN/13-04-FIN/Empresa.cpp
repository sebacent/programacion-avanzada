#include "Empresa.h"
#include "Empleado.h"
#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;

Empresa::Empresa(){
    this->nombre= "NOMBRE DEFAULT";
    this->nombreLegal= "LEGALMENTE";
    this->rut= 0; 
    this->cantEmpleados = 0;
    this->misEmpleados = new Empleado*[MAX_EMPLEADOS];
    for (int i = 0; i < MAX_EMPLEADOS; i++) {
        this->misEmpleados[i] = nullptr;
    }
}

Empresa::Empresa(string nombre,string nombre_legal,int rut){
    this->nombre= nombre;
    this->nombreLegal= nombre_legal;
    this->rut= rut; 
    this->cantEmpleados = 0;
    this->misEmpleados = new Empleado*[MAX_EMPLEADOS];
    for (int i = 0; i < MAX_EMPLEADOS; i++) {
        this->misEmpleados[i] = nullptr;
    }
}

void Empresa::listarEmpleados(){
    cout << "LISTA DE EMPLEADOS: "<< endl;
    int i = 0;    
    while (this->misEmpleados[i] != nullptr && i < MAX_EMPLEADOS) {
        if (this->misEmpleados[i]!= nullptr) {
            string empNombre = this->misEmpleados[i]->getNombre();            
            cout << empNombre << endl;            
        }
        i++;
    }
    cout << "---------------------" << endl;
    cout << "CANTIDAD DE EMPLEADOS: " << this->getCantEmpleados()<<endl;
    cout << "---------------------" << endl;    
}
void Empresa::empresaImprimir(){
    string _nombre = this->getNombre();
    string _nombreLegal = this->getNombreLegal();
    int _rut = this->getRut();
    int _empleados = this->getCantEmpleados();
    
    cout << "---------------------------------- "<<endl;  
    cout << "INFORMACION DE EMPRESA: "<<endl<<"________________________"<<endl;  
    cout << "Nombre: " <<_nombre<<endl;
    cout << "Nombre Legal: " <<_nombreLegal<<endl;
    cout << "RUT: " <<_rut<<endl;
    cout << "Cantidad de Empleados: " <<_empleados<<endl;
    cout << "---------------------------------- "<<endl;  
}

Empresa::~Empresa(){}

void Empresa::AddEmpleado(Empleado* empleado){

    try {
       if (empleado == nullptr) {
            throw std::invalid_argument("No se puede agregar al empleado porque no hay datos");
        }
 
        if (this->cantEmpleados < MAX_EMPLEADOS) {
            this->misEmpleados[this->cantEmpleados] = empleado;
            this->cantEmpleados++;
        }
    }
    catch (std::exception& e) {
        std::cout << "Ocurrio un error al intentar agregar un empleado: " << e.what() << std::endl;
    }
   
}

void Empresa::setNombre(string _nombre){
    this->nombre = _nombre;
}

void Empresa::setNombreLegal(string _nombreLegal){
    this->nombreLegal = _nombreLegal;
}

void Empresa::setRut(int _rut){
    this->rut = _rut;
}

string Empresa::getNombre(){
    return this->nombre;
}

string Empresa::getNombreLegal(){
    return this->nombreLegal;
}

int Empresa::getRut(){
    return this->rut;
}

int Empresa::getCantEmpleados(){
    return this->cantEmpleados;
}

void Empresa::setCantEmpleados(){
    this->cantEmpleados++;
}


Paga Empresa::totalSueldoPeso() {
    double total = 0;
    for (int i = 0; i < cantEmpleados; i++) {
        total += misEmpleados[i]->getSueldoPeso();
    }
    Paga totalPaga(total, US);
    //Cambio c;
    return totalPaga; //Paga(c.aPeso(totalPaga.getMonto()), US);
}

Paga Empresa::totalSueldoDolar() {
    double total = 0;
    for (int i = 0; i < cantEmpleados; i++) {
        total += misEmpleados[i]->getSueldoDolar();
    }
    Paga totalPaga(total, USD);
    return totalPaga;
}
