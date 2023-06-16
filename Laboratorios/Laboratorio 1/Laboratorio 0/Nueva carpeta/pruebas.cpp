//#include"lab0.h"
#include<stdio.h>
#include<iostream>
#include "Empresa.h"
#include "Paga.h"
#include "Fijo.h"
#include "Jornalero.h"
#include "Empleado.h"

using namespace std;

// LOS ERRORES QUE TIENE ES PORQUE NO ESTAN COMPILADOS LOS .CPP DE CADA CLASE 
    // HAY QUE VER COMO SE COMPILA CADA CPP Y COMO EJECUTAR ESTE 
    // https://stackoverflow.com/questions/43447960/error-message-undefined-reference-error-to-in-c


    // FORMA DE COMPILAR: 
/* 
COMPILO CON DEBUG HABILITADO:
    g++ -Wall -DTEST --debug .\Paga.cpp .\Empleado.cpp .\Empresa.cpp .\Jornalero.cpp .\Fijo.cpp .\pruebas.cpp -o pr...

EJECUTAR CON DEBUG:
    gdb pruebaComp1.exe
    run
    break linea
    next
    step (para funciones)
    backtrace (para ver en donde rompe)
    list (veo el codigo)

EJECUTAR COMUN:
    .\pruebaComp1.exe
*/


int main() {
    int opcion = 0;
    Empresa empresa;
    do {
        std::cout << "Menu" << std::endl;
        std::cout << "1. Dar de alta una empresa" << std::endl;
        std::cout << "2. Agregar empleado a la empresa" << std::endl;
        std::cout << "3. Calcular total de sueldos en pesos" << std::endl;
        std::cout << "4. Calcular total de sueldos en dolares" << std::endl;
        std::cout << "5. Listar empleados de la empresa" << std::endl;
        std::cout << "6. Salir" << std::endl;
        std::cout << "Ingrese una opcion: ";
        std::cin >> opcion;
        switch (opcion) {
            case 1: {
                std::string nombre, nombre_legal;
                int rut;
                std::cout << "Ingrese nombre de la empresa: ";
                std::cin >> nombre;
                std::cout << "Ingrese nombre legal de la empresa: ";
                std::cin >> nombre_legal;
                std::cout << "Ingrese RUT de la empresa: ";
                std::cin >> rut;
                empresa = Empresa(nombre, nombre_legal, rut);
                break;
            }
            case 2: {
                std::string nombre, ci;
                int edad, tipo;
                double valorHora;
                std::cout << "Ingrese nombre del empleado: ";
                std::cin >> nombre;
                std::cout << "Ingrese CI del empleado: ";
                std::cin >> ci;
                std::cout << "Ingrese edad del empleado: ";
                std::cin >> edad;
                std::cout << "Ingrese valor hora del empleado: ";
                std::cin >> valorHora;
                std::cout << "Ingrese tipo de empleado (1. Jornalero, 2. Fijo): ";
                std::cin >> tipo;
                Empleado* empleado = nullptr;
                if (tipo == 1) {
                    int horas;
                    std::cout << "Ingrese horas trabajadas del empleado: ";
                    std::cin >> horas;
                    empleado = new Jornalero(nombre, ci, edad, Paga(valorHora, Moneda::US), horas, &empresa);
                } else if (tipo == 2) {
                    empleado = new Fijo(nombre, ci, edad, Paga(valorHora, Moneda::US), &empresa);
                }
                empresa.AddEmpleado(empleado);
                break;
            }
            case 3: {
                Paga totalSueldoPeso = empresa.totalSueldoPeso();
                std::cout << "Total de sueldos en pesos: " << totalSueldoPeso.getMonto() << std::endl;
                break;
            }
            case 4: {
                Paga totalSueldoDolar = empresa.totalSueldoDolar();
                std::cout << "Total de sueldos en dolares: " << totalSueldoDolar.getMonto() << std::endl;
                break;
            }
            case 5: {
                empresa.listarEmpleados();
                break;
            }
            case 6:
                break;
            default:
                std::cout << "Opcion invalida." << std::endl;
                break;
        }
    } while (opcion != 6);
    return 0;
}

/* OLD MAIN PRUEBAS

    // FALTA:MENU, POR LO TANTO TAMBIEN MANEJO DE EXCEPCIONES, SOBRECARGA
int main(){ 
    
    Empresa pruebaEmpresa = Empresa();
    
    string nombre_empleado = " JORGE";
    string nombre_legal = " EMRESARIO";
    string ci = "50151411";
    int edad = 22;
    Paga valor = Paga(185.8,Moneda::US);
    // cout<<valor.getMoneda()<< endl;
    // cout<<valor.getMonto()<<endl;
    // valor.setMoneda(Moneda::USD);
    // valor.setMonto(177.58);    


   // int rut = 158451;
    cout<<"Llego linea: 34"<<endl;
    Fijo* empFij = new Fijo(nombre_empleado,ci,edad,Paga(185.8,Moneda::US),&pruebaEmpresa);
    pruebaEmpresa.empresaImprimir();
    empFij->imprimirEmpleado();
    cout<<"Llego linea: 36"<<endl;
    //   try {
    //     double sueldoPrueba = empFij->getPaga();
    //     cout<<"SUELDO PRUEBA"<<endl;
    //     cout<<sueldoPrueba<<endl;
    // } catch (...) {
    //     cout << "Ocurrió una excepción" << endl;
    // }

     cout<<"Llego linea: 44"<<endl;
    // cout<< "LLEGGOOOOOOOOOO2"    <<endl;
    // float monto = prueba.getMonto();
    // cout<< "LLEGGOOOOOOOOOO3"    <<endl;
    // if (monto != 0)
    //     cout << monto <<endl;
    // cout<< "LLEGGOOOOOOOOOO4"    <<endl;
    // cout << prueba.getMonto() <<endl;
    // cout<< "LLEGGOOOOOOOOOO5"    <<endl;
    // cout << prueba.getMoneda()<<endl;
    // cout<< "LLEGGOOOOOOOOOO6"    <<endl;
    // cout<<empFij->getSueldoPeso()<<endl;
    // empFij->imprimirEmpleado();
    
    ci = "8888888";
    nombre_empleado = " RAUL";
    cout<< "Nombre empleado"<< nombre_empleado<<endl;

     try {
            cout<<pruebaEmpresa.getNombre()<<endl; //&pruebaEmpresa
            Fijo* fij = new Fijo(nombre_empleado, ci, edad, valor,&pruebaEmpresa);
            fij->imprimirEmpleado();
            pruebaEmpresa.AddEmpleado(fij);

    } catch (...) {
        cout << "Ocurrió una excepción" << endl;
    }
    cout<<"Llego linea 70"<<endl;
   
    

    Paga val2 = Paga(129,US);
    ci = "99999999";
    nombre_empleado = " PEDRO";
    Jornalero* jorna = new Jornalero(nombre_empleado, ci, edad, val2,50,&pruebaEmpresa);
    jorna->setHoras(100);
    jorna->imprimirEmpleado();

    pruebaEmpresa.AddEmpleado(empFij);
   
    pruebaEmpresa.AddEmpleado(jorna);
    pruebaEmpresa.listarEmpleados();    


    return 0;
}
*/