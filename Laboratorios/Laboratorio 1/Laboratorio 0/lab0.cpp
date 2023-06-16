#include<lab0.h>
#include<stdio.h>
#include<iostream>
using namespace std;

float cambio::a_peso(float paga){
    Moneda cambio = 0;
    return paga * cambio;
}
float cambio::a_dolar(float paga){
    Moneda cambio = 1;
    try {
        if (paga < 0) throw 1;
        if (paga == 0) throw 0;
        return paga / cambio;
    }
    catch (int ex){
        if (ex == 0)
            cout << "Se esta intentando hacer el cambio de Peso a Dólares utilizando un valor igual a 0." <<endl;

        if (ex < 0)
            cout << "Se esta intentando hacer el cambio de Peso a Dólares utilizando un valor menor a 0." <<endl;            
    }
    
    
}

Paga::paga(){
    this->monto = 0;
    this->moneda = 1;

}


paga Paga::a_dolar(float sueldoP){
    return cambio::a_dolar(sueldoP);
}

paga Paga::a_peso(float sueldoUS){
    return cambio::a_peso(sueldoUS);
}


empleado::empleado(string nombre, string ci, int edad, paga valor_hora){
    this->nombre = nombre;
    this->ci = ci;
    this->edad = edad;
    this->valor_hora = valor_hora;
}
empresa::empresa(string nombre,string nombre_legal,int rut,empleado emp,int nro){
    this->nombre = nombre;
    this->nombre_legal = nombre_legal;
    this->rut=rut;
    this->empleados[nro]=emp;
}


fijo::fijo(string nombre, string ci, int edad, paga valor_paga){
    this->nombre = nombre;
    this->ci = ci;
    this->edad=edad;
    this->valor_paga=valor_paga;

}

jornalero::jornalero(string nombre, string ci, int edad,int  horas){
    this->nombre = nombre;
    this->ci = ci;
    this->edad=edad;
    this->paga =this->get_sueldo_peso();
}


jornalero::get_sueldo_peso(){
    return this->valor_paga * this->horas;
}

jornalero::get_sueldo_dolar(){
    var= this->get_sueldo_peso();
    return var/40.15;
}

fijo::get_sueldo_peso(){
    return this->valor_paga * 40;
}

fijo::get_sueldo_dolar(){
    var= this->get_sueldo_peso();
    return var/40.15;
}  

empleado::imprimir_empleado(){
    cout << "Nombre: " << this->nombre << endl;
    cout << "CI: " << this->ci << endl;
    cout << "Edad: " << this->edad << endl;
    cout << "Valor Hora: " << this->valor_hora << endl;
    cout << "Valor Peso: " << this->get_sueldo_peso() << endl;
    cout << "Valor Dolar: " << this->get_sueldo_dolar() << endl;
}

int main(){ 

cout<<"Sueld"<<endl;







}

void imprimir_empleado()
{
}

paga empresa::total_sueldo_peso()
{
return paga();
}
