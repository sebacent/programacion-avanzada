#include<stdio.h>
#include<iostream>
#include "Empresa.h"
#include "Paga.h"
#include "Fijo.h"
#include "Jornalero.h"
#include "Empleado.h"




using namespace std;






// ------ INICIO ------------------------------ FUNCIONES EMPLEADO --------------------------------

// empresa::empresa(string nombre,string nombre_legal,int rut,empleado emp,int nro){
//     this->nombre = nombre;
//     this->nombre_legal = nombre_legal;
//     this->rut=rut;
//     this->empleados[nro]=emp;

// }




// ------ INICIO ------------------------------- FUNCIONES EMPRESA --------------------------------


int main(){ 
    // LOS ERRORES QUE TIENE ES PORQUE NO ESTAN COMPILADOS LOS .CPP DE CADA CLASE 
    // https://stackoverflow.com/questions/43447960/error-message-undefined-reference-error-to-in-c
    Empresa pruebaEmpresa = Empresa();
    
    string nombre_empleado = " JORGE";
    string nombre_legal = " EMRESARIO";
    string ci = "50151411";
    int edad = 22;
    Paga valor = Paga();
    int rut = 158451;

    Empleado emp = Empleado(nombre_empleado,ci,edad,valor,&pruebaEmpresa);
    emp.imprimirEmpleado();
    ci = "8888888";
    Fijo fij = Fijo(nombre_empleado, ci, edad, valor,&pruebaEmpresa);
    fij.imprimirEmpleado();


    Paga val2 = Paga(129,US);
    ci = "99999999";
    Jornalero jorna = Jornalero(nombre_empleado, ci, edad, val2,&pruebaEmpresa);
    jorna.set_horas(100);
    jorna.imprimirEmpleado();



}

