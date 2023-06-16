//#include"lab0.h"
#include<stdio.h>
#include<iostream>
#include "Empresa.h"
#include "Paga.h"
#include "Fijo.h"
#include "Jornalero.h"
#include "Empleado.h"
#include <stdlib.h>

#include <cstdio>
#include <cstring>

using namespace std;

// LOS ERRORES QUE TIENE ES PORQUE NO ESTAN COMPILADOS LOS .CPP DE CADA CLASE 
    // HAY QUE VER COMO SE COMPILA CADA CPP Y COMO EJECUTAR ESTE 
    // https://stackoverflow.com/questions/43447960/error-message-undefined-reference-error-to-in-c


    // FORMA DE COMPILAR: 
/* 
COMPILO CON DEBUG HABILITADO:
g++ -Wall -DTEST --debug .\Paga.cpp .\Empleado.cpp .\Empresa.cpp .\Jornalero.cpp .\Fijo.cpp .\pruebas.cpp -o pruebasComp.exe

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


// int main() {
        
//  //PRECARGA
//     if (1==2){
//         Empresa empresa = Empresa();
//         Fijo* empFij = new Fijo("JORGE MARTINEZ","50151411",22,Paga(185.8,Moneda::US),&empresa);
//         Fijo* empFij1 = new Fijo("PEDRO GUTIERREZ","547636",50,Paga(350.4,Moneda::US),&empresa);
//         Fijo* empFij2 = new Fijo("MARCELO VIERA","5411174",33,Paga(120.2,Moneda::US),&empresa);
//         Fijo* empFij3 = new Fijo("LUIS SUAREZ","425183",27,Paga(280.0,Moneda::US),&empresa);
//         empresa.AddEmpleado(empFij);
//         empresa.AddEmpleado(empFij1);
//         empresa.AddEmpleado(empFij2);
//         empresa.AddEmpleado(empFij3);

//         Jornalero* jorna = new Jornalero("PEDRO DOMINGUEZ","4587454",43, Paga(500.8,Moneda::US),45,&empresa);
//         Jornalero* jorna1 =  new Jornalero("JULIAN RIOS","8985840",19, Paga(230.8,Moneda::US),50,&empresa);
//         Jornalero* jorna2 =  new Jornalero("LUIS PEREZ","65465456",25, Paga(156.8,Moneda::US),55,&empresa);
//         Jornalero* jorna3 =  new Jornalero("ANIBAL DIAZ","58463510",35, Paga(171.8,Moneda::US),60,&empresa);    

//         empresa.AddEmpleado(jorna);
//         empresa.AddEmpleado(jorna1);
//         empresa.AddEmpleado(jorna2);
//         empresa.AddEmpleado(jorna3);
//         empresa.listarEmpleados();
//     }
//     //FINPRECARGA
//     Empresa empresa;
//     int opcion = 0;

   
//     do {
//         std::cout << "Menu" << std::endl;
//         std::cout << "1. Dar de alta una empresa" << std::endl;
//         std::cout << "2. Agregar empleado a la empresa" << std::endl;
//         std::cout << "3. Calcular total de sueldos en pesos" << std::endl;
//         std::cout << "4. Calcular total de sueldos en dolares" << std::endl;
//         std::cout << "5. Listar empleados de la empresa" << std::endl;
//         std::cout << "6. Salir" << std::endl;
//         std::cout << "Ingrese una opcion: ";
//         std::cin >> opcion;
//         switch (opcion) {
//             case 1: {
//                 char nombre[50], nombre_legal[50];
//                 int rut;

//                 printf("Ingrese nombre de la empresa: ");
//                 scanf("%s", nombre);
//                 printf("Ingrese nombre legal de la empresa: ");
//                 scanf("%s", nombre_legal);
//                 printf("Ingrese RUT de la empresa: ");
//                 scanf("%d", &rut);

//                 // Verificación de entrada
//                 if (strlen(nombre) > 20 || strlen(nombre_legal) > 20 || rut < 1 || rut > 99999999) {
//                     printf("Entrada inválida.\n");
//                     return 0;
//                 }

//                 empresa = Empresa(nombre, nombre_legal, rut);
//                 break;
//             }
//             case 2: {
//                 char nombre[50], ci[8];
//                 int edad, tipo, horas,moneda;
//                 double valorHora;

//                 printf("Ingrese nombre del empleado: ");
//                 scanf("%s", nombre);


//                 printf("Ingrese CI del empleado: ");
//                 scanf("%s", ci);

//                 // Verificación de entrada
//                 if (strlen(nombre) > 20 || strlen(ci) > 8 || strlen(ci) < 7) {
//                     printf("Entrada inválida.\n");
//                     return 0;
//                 }

//                 // Verificación de entrada
//                 for (int i = 0; ci[i] != '\0'; i++) {
//                     if (!isdigit(ci[i])) {
//                         printf("Entrada inválida. La cédula debe contener solo dígitos.\n");
//                         return 0;
//                     }
//                 }

//                 printf("Ingrese edad del empleado: ");
//                 scanf("%d", &edad);

//                 printf("Ingrese valor hora del empleado: ");
//                 scanf("%lf", &valorHora);
                
//                 // Verificación de entrada
//                 if (valorHora <= 0 ) {
//                     printf("Entrada inválida.\n");
//                     return 0;
//                 }


//                 printf("Ingrese moneda de paga (0 = USD, 1 = US): ");
//                 scanf("%d", &moneda);

//                 // Verificación de entrada
//                 if (moneda != 0 && moneda != 1 ) {
//                     printf("Entrada inválida.\n");
//                     return 0;
//                 }
//                 Moneda empMoneda;

//                 if (moneda == 0)
//                     empMoneda = Moneda::USD;
//                 else 
//                     empMoneda = Moneda::USD;


//                 Paga empPaga = Paga(valorHora, empMoneda);

//                 printf("Ingrese tipo de empleado (1. Jornalero, 2. Fijo): ");
//                 scanf("%d", &tipo);
                

//                 if (tipo == 1) {
//                     printf("Ingrese horas trabajadas del empleado: ");
//                     scanf("%d", &horas);

//                     Jornalero* empleado = new Jornalero(nombre, ci, edad, empPaga, horas, &empresa);
//                     empresa.AddEmpleado(empleado);
//                 } else if (tipo == 2) {
//                     cout<<"ANTES LLAMAR NEW EMPLEADO"<<endl<<endl;
//                     Fijo* empleado = new Fijo(nombre, ci, edad, empPaga, &empresa);
//                     cout<<"DESPUES LLAMAR NEW EMPLEADO"<<endl<<endl;
//                     empresa.AddEmpleado(empleado);
//                 } else {
//                     printf("Tipo de empleado no válido.\n");
//                     return 0;
//                 }
//                 break;
//             }
//             case 3: {
//                 Paga totalSueldoPeso = empresa.totalSueldoPeso();
//                 std::cout << "Total de sueldos en pesos: " << totalSueldoPeso.getMonto() << std::endl;
//                 break;
//             }
//             case 4: {
//                 Paga totalSueldoDolar = empresa.totalSueldoDolar();
//                 std::cout << "Total de sueldos en dolares: " << totalSueldoDolar.getMonto() << std::endl;
//                 break;
//             }
//             case 5: {
//                 empresa.listarEmpleados();
//                 break;
//             }
//             case 6:
//                 return 0;
//             default:
//                 std::cout << "Opcion invalida." << std::endl;
//                 break;
//         }
//     } while (opcion != 6);
//     return 0;
// }

 //OLD MAIN PRUEBAS

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
            
            Fijo* fij = new Fijo(nombre_empleado,ci,edad,Paga(185.8,Moneda::US),&pruebaEmpresa);
            fij->imprimirEmpleado();
    } catch (...) {
        cout << "Ocurrió una excepción" << endl;
    }
    cout<<pruebaEmpresa.getNombre()<<endl; //&pruebaEmpresa
    cout<<"Llego linea 69"<<endl;
    Empresa nuevaEmpresa = Empresa();
    cout<<"Llego linea 70"<<endl;
       try {
           

            Jornalero * jorna = new Jornalero("JORGE MARTINEZ","50151411",22,Paga(350.8,Moneda::US) ,50,&nuevaEmpresa);
            nuevaEmpresa.AddEmpleado(jorna);
            jorna->setHoras(100);

            jorna->imprimirEmpleado();
    } catch (...) {
        cout << "Ocurrió una excepción" << endl;
    }
     if (&nuevaEmpresa == nullptr)
                cout<<"PUNTERO EMPRESA NULL"<<endl;
    cout<<"Llego linea 267"<<endl;
   // new Jornalero("JORGE MARTINEZ","50151411",22,valor ,50,&pruebaEmpresa);
  
    
cout<<"Llego linea 272"<<endl;
    pruebaEmpresa.AddEmpleado(empFij);
    
    pruebaEmpresa.listarEmpleados();  
    nuevaEmpresa.listarEmpleados();  

      cout<<"Llego linea 275"<<endl;
    ci = "99999999";
    nombre_empleado = " PEDRO";
    
    
       
        
        
        
      
    


    return 0;
}
