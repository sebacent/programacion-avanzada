#include "Empresa.h"
#include <string>
#include <iostream>
#include<stdio.h>
Empresa::Empresa(){
    this->nombre= "NOMBRE DEFAULT";
    this->nombreLegal= "LEGALMENTE";
    this->rut= 10; 
    this->misEmpleados = new Empleado * [MAX_EMPLEADOS];
    this->cantEmpleados = 0;
}

Empresa::Empresa(string nombre,string nombre_legal,int rut){
    this->nombre= nombre;
    this->nombreLegal= nombre_legal;
    this->rut= rut; 
    this->misEmpleados = new Empleado * [MAX_EMPLEADOS];
    this->cantEmpleados = 0;

}
Empresa::~Empresa(){}

void Empresa::agregarEmpleados(Empleado *empl){
    int cantidad= getCantEmpleados();
    this->misEmpleados[cantidad]= *empl;

}

void Empresa::setNombre(string nombre)
{
    this->nombre = nombre;
}

void Empresa::setNombreLegal(string nombre_legal)
{
    this->nombreLegal = nombre_legal;
}

void empresa::setRut(int rut){
    this->rut = rut;
}

string empresa::getNombre(){
    return this->nombre;
}

string empresa::getNombreLegal(){
    return this->nombreLegal;
}

int empresa::getRut(){
    return this->rut;
}

int empresa::getCantEmpleados(){
    return this->cantEmpleados;
}

void empresa::setCantEmpleados(){
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