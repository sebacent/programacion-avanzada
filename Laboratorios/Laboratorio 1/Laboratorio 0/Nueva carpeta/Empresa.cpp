#include "Empresa.h"
#include "Empleado.h"
#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;

Empresa::Empresa(){
    this->nombre= "NOMBRE DEFAULT";
    this->nombreLegal= "LEGALMENTE";
    this->rut= 10; 
    this->cantEmpleados = 0;
    misEmpleados = new Empleado*;
    for (int i = 0; i < MAX_EMPLEADOS; i++) {
        misEmpleados[i] = nullptr;
    
    }

}

Empresa::Empresa(string nombre,string nombre_legal,int rut){
    this->nombre= nombre;
    this->nombreLegal= nombre_legal;
    this->rut= rut; 
    this->cantEmpleados = 0;
    misEmpleados = new Empleado*;
    for (int i = 0; i < MAX_EMPLEADOS; i++) {
        misEmpleados[i] = nullptr;
    
    }
}

void Empresa::listarEmpleados(){
    cout << "LISTA DE EMPLEADOS: "<< endl;
    for (int i = 0; i < 50; i++) {
        if (misEmpleados[i]!= nullptr) {
            string empNombre = misEmpleados[i]->getNombre();            
            cout << empNombre << endl;            
        } else {
           cout << "---------------------" << endl;
           cout << "CANTIDAD DE EMPLEADOS: " << this->getCantEmpleados()<<endl;
           cout << "---------------------" << endl;
           break;     
        }
    }
}

Empresa::~Empresa(){}

void Empresa::AddEmpleado(Empleado* empleado){
    if (cantEmpleados < MAX_EMPLEADOS) {
    misEmpleados[cantEmpleados++] = empleado;
    }
    //cantEmpleados++; NO ES NECESARIO, YA LO HACE ARRIBA
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

void Empresa::empresaImprimir(){
    string _nombre = this->getNombre();
    string _nombreLegal = this->getNombreLegal();
    int _rut = this->getRut();
    int _empleados = this->getCantEmpleados();
    
    cout << "---------------------------------- "<<endl;  
    cout << "INFORMACION DE EMPRESA: "<<endl;  
    cout << "Nombre: " <<_nombre<<endl;
    cout << "Nombre Legal: " <<_nombreLegal<<endl;
    cout << "RUT: " <<_rut<<endl;
    cout << "Cantidad de empleados: " <<_empleados <<endl;
    cout << "---------------------------------- "<<endl;  
}

Paga Empresa::totalSueldoPeso() {
    double total = 0;
    for (int i = 0; i < cantEmpleados; i++) {
        total += misEmpleados[i]->getSueldoPeso();
    }
    Paga totalPaga(total, US);
    Cambio c;
    return Paga(c.aPeso(totalPaga.getMonto()), US);
}

Paga Empresa::totalSueldoDolar() {
    double total = 0;
    for (int i = 0; i < cantEmpleados; i++) {
        total += misEmpleados[i]->getSueldoDolar();
    }
    Paga totalPaga(total, USD);
    Cambio c;
    return Paga(c.aDolar(totalPaga.getMonto()), USD);
}



// void Empleado::imprimirEmpleado(){
//     string nombre = this->getNombre();
//     string ci = this->getCi();
//     int edad = this->getEdad();
//     Paga valor_hora = this->getValor_hora();
//     float sueldo =  valor_hora.getMonto();
    
//     cout << "---------------------------------- "<<endl;  
//     cout << "INFORMACION DEL EMPLEADO: "<<endl;  

//     cout << "Nombre: " <<nombre<<endl;
//     cout << "CI: " <<ci<<endl;
//     cout << "Edad: " <<edad<<endl;
//     cout << "Valor Hora: " <<sueldo <<endl;
//     cout << "Valor Peso: " << this->get_sueldo_peso() << endl;
//     cout << "Valor Dolar: " << this->get_sueldo_dolar() << endl;

//     cout << "---------------------------------- "<<endl;  
// }