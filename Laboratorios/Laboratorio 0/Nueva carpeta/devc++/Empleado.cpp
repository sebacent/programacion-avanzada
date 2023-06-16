#include "Empleado.h"
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

void empleado::setempresa(empresa * miemp){
    this->miemp=miemp;
}


empleado::empleado(string nombre, string ci, int edad, Paga valor_hora, empresa *miemp){
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
