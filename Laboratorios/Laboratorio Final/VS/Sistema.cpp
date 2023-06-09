#include"Sistema.h"
#include<iostream>
#include "ICollection/interfaces/IKey.h"

Sistema* Sistema::getInstancia(){
    if(instancia == nullptr)
        instancia = new Sistema();
    return instancia;
}   

Sistema::~Sistema (){};

// int Sistema::comprarPuntos(int idCuenta, int monto){
//     IKey* key = new KeyInteger(idCuenta);
//     ICollectible* cuenta = cuentas->find(key);

// }

void Sistema::addEmpresa(int rut,std::string nombre){
    IKey* key = new Integer(rut);// <--- NO HAY CONSTRUCTOR DE IKEY????????
    Empresa* empresa = new Empresa(nombre,rut);
    empresas->add(key,empresa);
    delete key;
}

void Sistema::addEstudiante(std::string ciEstudiante, std::string nombre, Date fechaNac  ){
    IKey* key = new KeyString(ciEstudiante);
    ICollectible* estudiante = new Estudiante(ciEstudiante,nombre);
    estudiante->add(key,estudiante);
    delete key;
}
