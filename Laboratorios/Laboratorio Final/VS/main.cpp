#include "RangoSueldo.h"
//#include <string.h>
#include <iostream>
#include "Empresa.h"
#include "Encargado.h"
#include "Estudiante.h"
// #include "Factory.h"
// #include "ISistema.h"
//using namespace std;
#include "Sistema.h"
#include "Carrera.h"

void precargaDatosPrueba(Sistema* sistema) {
    Carrera * pCarrera1 = NULL;
    Carrera * pCarrera2 = NULL;
        //--------- CARRERAS -------------------
    //     C1,1010,Ingenieria Electrica
    sistema->addCarrera("Ingenieria Electrica", 1010);
    pCarrera1 = sistema->buscarCarrera(1010);
    //     C2,1011,Ingenieria en Computacion
    sistema->addCarrera("Ingenieria en Computacion", 1011);
    pCarrera2 = sistema->buscarCarrera(1011);
        
    // ----------- ASIGNATURAS -------------------

    // A1,1686,Calculo I,16,C1 C2
    sistema->addAsignatura("Calculo I", 1686, 16,1010);
    sistema->addAsignatura("Calculo I", 1686, 16,1011);


    // A2,6598,Programacion 1,10,C1 C2
    sistema->addAsignatura("Programacion 1", 6598, 10,1011);

    // A3,5698,Programacion 2,12,C2
    sistema->addAsignatura("Programacion 2", 5698, 12,1011);

    // A4,4875,Programacion 3,15,C2
    sistema->addAsignatura("Programacion 3", 4875, 15,1011);

    // A5,1689,Calculo II,16,C1 C2
    sistema->addAsignatura("Calculo II", 1689, 16,1010);
    sistema->addAsignatura("Calculo II", 1689, 16,1011);


    // A6,8683,Electromagnetismo,12,C1
    sistema->addAsignatura("Electromagnetismo", 8683, 12,1010);


    // A7,6943,Bases de datos,15,C2
    sistema->addAsignatura("Bases de datos", 6943, 15,1011);


    // A8,6879,Redes de computadoras,12,C2
    sistema->addAsignatura("Redes de computadoras", 6879, 12,1011);


    // A9,3216,Ecuaciones diferenciales,12,C1
    sistema->addAsignatura("Ecuaciones diferenciales", 3216, 12,1010);


    // A10,9171,Fundamentos de seguridad informatica,12,C2
    sistema->addAsignatura("Fundamentos de seguridad informatica", 9171, 12,1011);


    // A11,1698,Robotica basada en comportamientos,15,C1 C2
    sistema->addAsignatura("Robotica basada en comportamientos", 1698, 15,1010);
    sistema->addAsignatura("Robotica basada en comportamientos", 1698, 15,1011);


    // A12,6416,Ciencia tecnologia y sociedad,8,C1 C2
    sistema->addAsignatura("Ciencia tecnologia y sociedad", 6416, 8,1010);
    sistema->addAsignatura("Ciencia tecnologia y sociedad", 6416, 8,1011);



    // A13,6587,Proyecto de Ingenieria de software,15,C2
    sistema->addAsignatura("Proyecto de Ingenieria de software", 6587, 15,1011);

    // A14,5498,Arquitectura de computadoras,12,C2
    sistema->addAsignatura("Arquitectura de computadoras", 5498, 12,1011);

    // A15,1889,Taller de programacion,15,C2
    sistema->addAsignatura("Taller de programacion", 1889, 15,1011);


    // E1,1112335684,Segurol S.A.
    sistema->addEmpresa(1112335684, "Segurol S.A.");

    // E2,5464897,Ingenieros Electricos Unidos
    sistema->addEmpresa(5464897, "Ingenieros Electricos Unidos");

    // E3,1265498765,MiniSoft Uy
    sistema->addEmpresa(1265498765, "MiniSoft Uy");

    // E4,1298865497,RoboTI
    sistema->addEmpresa(1298865497, "RoboTI");

    // E5,1326548654,Academia Yotexplico
    sistema->addEmpresa(1326548654, "Academia Yotexplico");


    // SU1,Casa central,24598765,Ciudad Vieja,E1
    sistema->addSucursal(01, "Casa central", "24598765", "Ciudad Vieja", 1112335684);
    // SU2,Sucursal comercial,25225323,Malvin,E2
    sistema->addSucursal(02,"Sucursal comercial", "25225323", "Malvin", 5464897);
    // SU3,Sucursal San Carlos,42668350,San Carlos,E2
    sistema->addSucursal(03, "Sucursal San Carlos", "42668350", "San Carlos", 5464897);
    // SU4,Sede Montevideo,25468932,Buceo,E3
    sistema->addSucursal(04, "Sede Montevideo", "25468932", "Buceo", 1265498765);
    // SU5,Sede Ciudad de la Costa,43764232,Solymar,E3
    sistema->addSucursal(05, "Sede Ciudad de la Costa", "43764232", "Solymar", 1265498765);
    // SU6,Oficina central,25495878,Centro,E4
    sistema->addSucursal(06, "Oficina central", "25495878", "Centro", 1298865497);
    // SU7,Academia,24594565,Parque Rodo,E5
    sistema->addSucursal(07, "Academia", "24594565", "Parque Rodo", 1326548654);
    //SU1 = 1112335684
    //SU2 = 5464897
    //SU3 = 5464897
    //SU4 = 1265498765
    //SU5 = 1265498765
    //SU6 = 1298865497
    //SU7 = 1326548654

    // SE1,Contaduria,101,SU1
    sistema->addSeccion(01,101, "Contaduria","101",1112335684);
    // SE2,Recursos humanos,102,SU1
    sistema->addSeccion(01,102, "Recursos humanos","102",1112335684);
    // SE3,Recepcion,103,SU1
    sistema->addSeccion(01,103, "Recepcion","103",1112335684);
    // SE4,Desarrollo,104,SU1
    sistema->addSeccion(01,104, "Desarrollo","104",1112335684);
    // SE5,Pentesting,105,SU1
    sistema->addSeccion(01,105, "Pentesting","105",1112335684);
    // SE6,Marketing,1201,SU2
    sistema->addSeccion(02,1201, "Marketing","1201",5464897);
    // SE7,Atencion al cliente,1202,SU2
    sistema->addSeccion(02,1202, "Atencion al cliente","1202",5464897);
    // SE8,Tesoreria,1203,SU2
    sistema->addSeccion(02,1203, "Tesoreria","1203",5464897);
    // SE9,Ventas,1204,SU2
    sistema->addSeccion(02,1204, "Ventas","1204",5464897);
    // SE10,Seccion tecnica,1205,SU2
    sistema->addSeccion(02,1205, "Seccion tecnica","1205",5464897);
    // SE11,Seccion tecnica,1009,SU3
    sistema->addSeccion(03,1009, "Seccion tecnica","1009",5464897);
    // SE12,I+D,1008,SU3
    sistema->addSeccion(03,1008, "I+D","1008",5464897);
    // SE13,Recepcion,1000,SU3
    sistema->addSeccion(03,1000, "Recepcion","1000",5464897);
    // SE14,Secretaria,100,SU4
    sistema->addSeccion(04,1000, "Secretaria","100",1265498765);
    // SE15,Desarrollo,1001,SU4
    sistema->addSeccion(04,1001, "Desarrollo","1001",1265498765);
    // SE16,Testing,1002,SU4
    sistema->addSeccion(04,1002, "Testing","1002",1265498765);
    // SE17,Secretaria,100,SU5
    sistema->addSeccion(05,1010, "Secretaria","100",1265498765);
    // SE18,Desarrollo,1001,SU5
    sistema->addSeccion(05,1011, "Desarrollo","1001",1265498765);
    // SE19,Testing,1002,SU5
    sistema->addSeccion(05,1012, "Testing","1002",1265498765);
    // SE20,Laboratorio,10,SU6
    sistema->addSeccion(06,10, "Laboratorio","10",1298865497);
    // SE21,Atencion comercial,11,SU6
    sistema->addSeccion(06,11, "Atencion comercial","11",1298865497);
    // SE22,Direccion,101,SU7
    sistema->addSeccion(07,201, "Direccion","101",1326548654);
    // SE23,Inscripciones,102,SU7
    sistema->addSeccion(07,202, "Inscripciones","102",1326548654);

    Date * fechaInicio = new Date(01,06,2015);
    Date * fechaFin = new Date(20,07,2015);
    RangoSueldo * rangoSueldo = new RangoSueldo(2000,3000);
    int asignRequeridas[50] = {0};
    asignRequeridas[0] = 6598;
    asignRequeridas[1] = 5698;
    asignRequeridas[2] = 4875;
    asignRequeridas[3] = 9171;

    sistema->addOferta(555,"Auditor de seguridad part-time junior","Segurol S.A. busca estudiantes de Ingenieria en Computacion para unirse a su equipo. Se requiere un nivel minimo de conocimiento en seguridad informatica y programacion. Interesados enviar cv a oportunidades@segurol.com.uy",5,20,fechaInicio,fechaFin,rangoSueldo,1112335684,01,102,asignRequeridas);
    std::cout << "Agregue oferta 555" << std::endl;
    
    //O2,12356,Ayudante de Ingeniero,Estamos buscando estudiantes avanzados de Ingenieria Electrica con perfil potencia. Es imprescindible tener disponibilidad para viajar al interior del pais una vez por mes. Se pagan viaticos ademas de sueldo. Llamar al 25225323 int 1205 para mas detalles.
    //,30,2,4000,5000,20 05 2015,30 06 2015,SE10
    
    Date * fechaInicio2 = new Date(20,05,2015);
    Date *  fechaFin2 = new Date(30,06,2015);
    RangoSueldo * rangoSueldo2  = new RangoSueldo(4000,5000);
    int asignRequeridas2[50] = {0};
    asignRequeridas2[0] = 8683;
    asignRequeridas2[1] = 3216;

    sistema->addOferta(12356,"Ayudante de Ingeniero","Estamos buscando estudiantes avanzados de Ingenieria Electrica con perfil potencia. Es imprescindible tener disponibilidad para viajar al interior del pais una vez por mes. Se pagan viaticos ademas de sueldo. Llamar al 25225323 int 1205 para mas detalles.",30,2,fechaInicio2,fechaFin2,rangoSueldo2,5464897,02,1205,asignRequeridas2);
    


    //O3,88890,Desarrollador C++,Buscamos desarrollador C++ para importante proyecto internacional. Llenar formulario con datos personales y cv en minisoft.uy/careers.,40,4,5000,6000,05 06 2015,06 08 2015,SE15
    // fechaInicio = new Date(05,06,2015);
    // fechaFin = new Date(06,07,2015);
    // rangoSueldo = new RangoSueldo(5000,6000);
    // asignRequeridas[50] = {0};
    // asignRequeridas[0] = 6598;//A2
    // asignRequeridas[1] = 5698;//A3
    // asignRequeridas[2] = 4875;//A4
    // asignRequeridas[3] = 6943;//A7
    // asignRequeridas[4] = 6587;//A13
    // asignRequeridas[5] = 1889;//A15

    // sistema->addOferta(88890,"Desarrollador C++","Buscamos desarrollador C++ para importante proyecto internacional. Llenar formulario con datos personales y cv en minisoft.uy/careers.",40,4,fechaInicio,fechaFin,rangoSueldo,1265498765,04,1001,asignRequeridas);

    sistema->ListarOfertas();

    std::cout<<"TERMINO PRECARGA"<<std::endl;
    // delete fechaFin;
    // delete fechaInicio;
    // delete rangoSueldo;
    // delete pCarrera1;
    // delete pCarrera2;
    // // delete asignRequeridas2;
    // // delete asignRequeridas;
    // delete rangoSueldo2;
    // delete fechaInicio2;
    // delete fechaFin2;

}


void printMenu(){
        std::cout<<std::endl<<std::endl;
        std::cout<<"--- MENU ---"<<std::endl<<std::endl;

        std::cout<<"--- TRABAJAR CON EMPRESAS ---"<<std::endl<<std::endl;
        std::cout<<"1. Crear Empresa"<<std::endl;
        // std::cout<<"2. Eliminar Empresa"<<std::endl;
        std::cout<<"2. Listar Empresas"<<std::endl;

        std::cout<<"--- TRABAJAR CON SUCURSALES ---"<<std::endl<<std::endl;
        std::cout<<"3. Agregar Sucursal"<<std::endl;
        // std::cout<<"6. Eliminar Sucursal"<<std::endl;
        std::cout<<"4. Listar Sucursales"<<std::endl;

        std::cout<<"--- TRABAJAR CON SECCIONES ---"<<std::endl<<std::endl;
        std::cout<<"5. Agregar Seccion"<<std::endl;
//        std::cout<<"8. Eliminar Seccion"<<std::endl;
        std::cout<<"6. Listar Secciones"<<std::endl;
        std::cout<<"7. Listar Ofertas"<<std::endl;
        std::cout<<"8. Listar Todas las Ofertas"<<std::endl;
        std::cout<<"0. Salir"<<std::endl;
        std::cout<<std::endl<<std::endl;
        std::cout<<"Ingrese una opcion: ";
        std::cout<<std::endl;
}   

int altaOferta(Sistema* sistema){
    std::string titulo, str_idExpediente, descripcion, str_cantPuestos, str_horas, str_DiaFechaInicio,str_MesFechaInicio,str_AnioFechaInicio, str_DiaFechaFin,str_MesFechaFin,str_AnioFechaFin, str_rangoMinSalarial, str_rangoMaxSalarial, str_idAsignatura;
    int cantPuestos, horas, idExpediente, rangoMinSalarial, rangoMaxSalarial, idAsignatura, diaFechaInicio, mesFechaInicio, anioFechaInicio, diaFechaFin, mesFechaFin, anioFechaFin, idEmpresa, idSeccion, idSucursal;
    Date* fechaInicio;
    Date* fechaFin;
    RangoSueldo* rangoSalarial;
    int asignaturas[50] = {0};
    int i = 0;
    bool salgo = false;
    std::string str_idEmpresa, str_idSeccion, str_idSucursal;
    
    std::cout<<"Ingrese el id de la empresa: "<< std::endl;
    sistema->ListarEmpresas();
    std::getline(std::cin, str_idEmpresa);
    idEmpresa = std::stoi(str_idEmpresa);

    std::cout<<"Ingrese el id de la sucursal: "<< std::endl;
    sistema->ListarSucursales(idEmpresa);
    std::getline(std::cin, str_idSucursal);
    idSucursal = std::stoi(str_idSucursal);

    std::cout<<"Ingrese el id de la seccion: "<< std::endl;
    sistema->ListarSecciones(idEmpresa, idSucursal);
    std::getline(std::cin, str_idSeccion);
    idSeccion = std::stoi(str_idSeccion);

    std::cout<<"Ingrese el id del expediente de la oferta: "<< std::endl;
    std::getline(std::cin, str_idExpediente);
    idExpediente = std::stoi(str_idExpediente);

    std::cout<<"Ingrese el titulo de la oferta: "<< std::endl;
    std::getline(std::cin, titulo);

    std::cout<<"Ingrese la descripcion de la oferta: "<< std::endl;
    std::getline(std::cin, descripcion);

    std::cout<<"Ingrese la cantidad de puestos de la oferta: "<< std::endl;
    std::getline(std::cin, str_cantPuestos);
    cantPuestos = std::stoi(str_cantPuestos);

    std::cout<<"Ingrese la cantidad de horas de la oferta: "<< std::endl;
    std::getline(std::cin, str_horas);
    horas = std::stoi(str_horas);

    std::cout<<"Ingrese la fecha de inicio de la oferta: "<< std::endl;
        std::cout<<"Ingrese el dia: "<< std::endl;
        std::getline(std::cin, str_DiaFechaInicio);
        std::cout<<"Ingrese el mes: "<< std::endl;
        std::getline(std::cin, str_MesFechaInicio);
        std::cout<<"Ingrese el anio: "<< std::endl;
        std::getline(std::cin, str_AnioFechaInicio);
        fechaInicio = new Date(std::stoi(str_DiaFechaInicio), std::stoi(str_MesFechaInicio), std::stoi(str_AnioFechaInicio));

    std::cout<<"Ingrese la fecha de fin de la oferta: "<< std::endl;
        std::cout<<"Ingrese el dia: "<< std::endl;
        std::getline(std::cin, str_DiaFechaFin);
        std::cout<<"Ingrese el mes: "<< std::endl;
        std::getline(std::cin, str_MesFechaFin);
        std::cout<<"Ingrese el anio: "<< std::endl;
        std::getline(std::cin, str_AnioFechaFin);
        fechaFin = new Date(std::stoi(str_DiaFechaFin), std::stoi(str_MesFechaFin), std::stoi(str_AnioFechaFin));

    std::cout<<"Ingrese el rango salarial de la oferta: "<< std::endl;
        std::cout<<"Ingrese el rango minimo: "<< std::endl;
        std::getline(std::cin, str_rangoMinSalarial);
        std::cout<<"Ingrese el rango maximo: "<< std::endl;
        std::getline(std::cin, str_rangoMaxSalarial);
        rangoSalarial = new RangoSueldo(std::stoi(str_rangoMinSalarial), std::stoi(str_rangoMaxSalarial));

    std::cout<<"Ingrese las asignaturas de la oferta de una en una: (INGRESE X PARA SALIR)"<< std::endl;
        sistema->ListarAsignaturas();
        while(!salgo){
            std::getline(std::cin, str_idAsignatura);
            if(str_idAsignatura == "X" || str_idAsignatura == "x"){
                salgo = true;
                break;
            }else{
                asignaturas[i] = std::stoi(str_idAsignatura);
                i++;
            }    
        }
        std::cout<<"Asignaturas ingresadas: "<< std::endl;
        for(int j = 0; j < i; j++){
            if(asignaturas[j] != NULL && asignaturas[j] != 0)
                std::cout<<"    "<<asignaturas[j]<<std::endl;
        }
    //CHEQUEO DE NULLS UNO POR UNO:
    if(idExpediente == NULL || idExpediente == 0){
        std::cout<<"El id del expediente no puede ser nulo o 0"<<std::endl;
        return 1;
    }
    if( titulo == ""){
        std::cout<<"El titulo no puede ser nulo o vacio"<<std::endl;
        return 1;
    }
    if(descripcion == ""){
        std::cout<<"La descripcion no puede ser nula o vacia"<<std::endl;
        return 1;
    }
    if(cantPuestos == NULL || cantPuestos == 0){
        std::cout<<"La cantidad de puestos no puede ser nula o 0"<<std::endl;
        return 1;
    }
    if(horas == NULL || horas == 0){
        std::cout<<"La cantidad de horas no puede ser nula o 0"<<std::endl;
        return 1;
    }
    if(fechaInicio == NULL){
        std::cout<<"La fecha de inicio no puede ser nula"<<std::endl;
        return 1;
    }
    if(fechaFin == NULL){
        std::cout<<"La fecha de fin no puede ser nula"<<std::endl;
        return 1;
    }
    if(rangoSalarial == NULL){
        std::cout<<"El rango salarial no puede ser nulo"<<std::endl;
        return 1;
    }
    if(idEmpresa == NULL || idEmpresa == 0){
        std::cout<<"El id de la empresa no puede ser nulo o 0"<<std::endl;
        return 1;
    }
    if(idSucursal == NULL || idSucursal == 0){
        std::cout<<"El id de la sucursal no puede ser nulo o 0"<<std::endl;
        return 1;
    }
    if(idSeccion == NULL || idSeccion == 0){
        std::cout<<"El id de la seccion no puede ser nulo o 0"<<std::endl;
        return 1;
    }
    if(asignaturas == NULL){
        std::cout<<"Las asignaturas no pueden ser nulas"<<std::endl;
        return 1;
    }
    //FIN DE CHEQUEO DE NULLS


    sistema->addOferta(idExpediente, titulo, descripcion, cantPuestos, horas, fechaInicio, fechaFin, rangoSalarial, idEmpresa,  idSucursal,  idSeccion, asignaturas);
    return 0;
}
void crearAsignaturas(Sistema *sistema){
    std::string nombre, str_idAsignatura, str_creditos;
    int idAsignatura, creditos, idCarrera;

    // std::cout<<"Ingrese el id de la asignatura: "<< std::endl;
    // std::getline(std::cin, str_idAsignatura);
    // idAsignatura = std::stoi(str_idAsignatura);

    // std::cout<<"Ingrese el nombre de la asignatura: "<< std::endl;
    // std::getline(std::cin, nombre);

    // std::cout<<"Ingrese la cantidad de creditos de la asignatura: "<< std::endl;
    // std::getline(std::cin, str_creditos);
    // creditos = std::stoi(str_creditos);

    nombre = "Matematica";
    idAsignatura = 1;
    creditos = 10;
    idCarrera = 1;
    sistema->addAsignatura(nombre, idAsignatura, creditos,idCarrera );    

    nombre = "Fisica";
    idAsignatura = 2;
    creditos = 10;
    sistema->addAsignatura(nombre, idAsignatura, creditos, idCarrera);

    nombre = "Quimica";
    idAsignatura = 3;
    creditos = 10;
    sistema->addAsignatura(nombre, idAsignatura, creditos, idCarrera);

}


int main(){
    //CASO DE USO: ALTA OFERTA
    Sistema * s = Sistema::getInstancia();    
    std::cout<<"COMPILA WACHO"<<std::endl;
    if (s == NULL)
        std::cout<<"SISTEMA ES NULL"<<std::endl;
    precargaDatosPrueba(s);    
    if(true){
        int opcion, empresaRut, val1, val2;
        std::string sOpcion, empresaNombre, sucursalDireccion,sucursalTelefono, sucursalNombre, seccionNombre,seccionTelefono;

        bool salir = false;
        while (!salir){            
            printMenu();
            std::getline(std::cin, sOpcion);
            opcion = std::stoi(sOpcion);
            switch(opcion){
                //CREAR EMPRESA
                case 1: 
                    std::cout<<"Ingrese el RUT de la empresa: "<<std::endl;
                    std::getline(std::cin, sOpcion);
                    empresaRut = std::stoi(sOpcion);
                    std::cout<<"Ingrese el NOMBRE de la empresa: "<<std::endl;
                    std::getline(std::cin, empresaNombre);
                    s->addEmpresa(empresaRut, empresaNombre);
                    std::cout<<std::endl<<std::endl;
                    break;
                //LISTAR EMPRESAS
                case 2: 
                    std::cout<<std::endl<<std::endl;
                    s->ListarEmpresas();
                    std::cout<<std::endl<<std::endl;
                    break;
                //AGREGAR SUCURSAL    
                case 3: 
                    std::cout<<std::endl<<std::endl;
                    s->ListarEmpresas();
                    std::cout<<"Ingrese el RUT de la empresa: "<<std::endl;
                    std::getline(std::cin, sOpcion);
                    empresaRut = std::stoi(sOpcion);

                    std::cout<<"Ingrese el ID de la sucursal: "<<std::endl;
                    std::getline(std::cin, sOpcion);
                    val1 = std::stoi(sOpcion);

                    std::cout<<"Ingrese el NOMBRE de la sucursal: "<<std::endl;
                    std::getline(std::cin, sucursalNombre);

                    std::cout<<"Ingrese el TELEFONO de la sucursal: "<<std::endl;
                    std::getline(std::cin, sucursalTelefono);

                    std::cout<<"Ingrese la DIRECCION de la sucursal: "<<std::endl;
                    std::getline(std::cin, sucursalDireccion);


                    s->addSucursal(val1, sucursalNombre, sucursalTelefono, sucursalDireccion, empresaRut);
                    std::cout<<std::endl<<std::endl;
                    break;
                //LISTAR SUCURSALES
                case 4: 
                    std::cout<<std::endl<<std::endl;
                    s->ListarEmpresas();
                    std::cout<<"Ingrese el rut de la empresa: "<<std::endl;
                    std::getline(std::cin, sOpcion);
                    empresaRut = std::stoi(sOpcion);
                    s->ListarSucursales(empresaRut);
                    std::cout<<std::endl<<std::endl;
                    break;

                //AGREGAR SECCION
                case 5: 
                    std::cout<<std::endl<<std::endl;
                    s->ListarEmpresas();
                    
                    std::cout<<"Ingrese el rut de la empresa: "<<std::endl;
                    std::getline(std::cin, sOpcion);
                    empresaRut = std::stoi(sOpcion);
                    s->ListarSucursales(empresaRut);
                    
                    std::cout<<"Ingrese el id de la sucursal: "<<std::endl;
                    std::getline(std::cin, sOpcion);
                    val1 = std::stoi(sOpcion);
                    
                    std::cout<<"Ingrese el id de la seccion: "<<std::endl;
                    std::getline(std::cin, sOpcion);
                    val2 = std::stoi(sOpcion);

                    std::cout<<"Ingrese el NOMBRE de la seccion: "<<std::endl;
                    std::getline(std::cin, seccionNombre);

                    std::cout<<"Ingrese el TELEFONO de la seccion: "<<std::endl;
                    std::getline(std::cin, seccionTelefono);


                    s->addSeccion(val1, val2, seccionNombre, seccionTelefono, empresaRut);
                    std::cout<<std::endl<<std::endl;
                    break;    
                
                //LISTAR SECCIONES
                case 6: 
                std::cout<<std::endl<<std::endl;
                    s->ListarEmpresas();
                    std::cout<<std::endl<<std::endl;

                    std::cout<<"Ingrese el rut de la empresa: "<<std::endl;
                    std::getline(std::cin, sOpcion);
                    empresaRut = std::stoi(sOpcion);
                    s->ListarSucursales(empresaRut);
                    std::cout<<std::endl<<std::endl;

                    std::cout<<"Ingrese el id de la sucursal: "<<std::endl;
                    std::getline(std::cin, sOpcion);
                    val1 = std::stoi(sOpcion);

                    std::cout<<std::endl<<std::endl;
                    s->ListarSecciones(empresaRut,val1);
                    std::cout<<std::endl<<std::endl;
                    break;

                //LISTAR OFERTAS
                case 7: 
                    std::cout<<std::endl<<std::endl;
                    s->ListarEmpresas();
                    std::cout<<"Ingrese el RUT de la empresa: "<<std::endl;
                    std::getline(std::cin, sOpcion);
                    empresaRut = std::stoi(sOpcion);

                    std::cout<<std::endl<<std::endl;
                    s->ListarSucursales(empresaRut);
                    std::cout<<"Ingrese el ID de la sucursal: "<<std::endl;
                    std::getline(std::cin, sOpcion);
                    val1 = std::stoi(sOpcion);

                    std::cout<<std::endl<<std::endl;
                    s->ListarSecciones(empresaRut,val1);
                    std::cout<<"Ingrese el id de la seccion: "<<std::endl;
                    std::getline(std::cin, sOpcion);
                    val2 = std::stoi(sOpcion);

                    s->ListarOfertas(empresaRut,val1,val2);
                    std::cout<<std::endl<<std::endl;
                    break;
                //Listar todas las ofertas
                case 8:
                    s->ListarOfertas();
                    break;
                //SALIR
                case 0:
                    salir = true;
                    break;

                default:        
                    std::cout<<"Opcion no valida"<<std::endl;
                    break;
            }        
        }
    }
    //menu();

    // std::string nombre = "EMPRESA1";     
    // s->addEmpresa(1234,nombre);
    // std::cout<<"COMPILA WACHO1"<<std::endl;
    // s->ListarEmpresas();

    // std::string nombre2 = "EMPRESA2";
    // std::cout<<"    INTRO"<<std::endl;
    // s->addEmpresa(1235,nombre2);
    // std::cout<<"COMPILA WACHO2"<<std::endl;


    // std::string nombre3 = "EMPRESA3";
    // s->addEmpresa(1236,nombre3);
    // std::cout<<"COMPILA WACHO3"<<std::endl;
    // s->ListarEmpresas();

    // //Empresa * emp;
    
    // //emp = (Empresa *) s->empresas->find(new Integer(1234));
    // Empresa * emp = s->buscarEmpresa(1234);
    // if (emp == NULL)
    //     std::cout<<"EMPRESA ES NULL"<<std::endl;

    // emp->addSucursal("SUCURSAL1", "DIRECCION1", "TELEFONO1", 1);
    // emp->addSucursal("SUCURSAL2", "DIRECCION2", "TELEFONO2", 2);
    // emp->addSucursal("SUCURSAL3", "DIRECCION3", "TELEFONO3", 3);
    // emp->addSucursal("SUCURSAL4", "DIRECCION4", "TELEFONO4", 4);
    // emp->ListarSucursales();
    
    // Sucursal * suc = emp->buscarSucursal(1);
    // if (suc == NULL)
    //     std::cout<<"SUCURSAL ES NULL"<<std::endl;

    // suc->agregarSeccion("SECCION1", "12456" , 1);
    // suc->agregarSeccion("SECCION2","098753", 2);
    // std::cout<<"LLEGO A CREAR LA SECCION1"<<std::endl;
    // precargaDatosPrueba(s);
    // s->ListarEmpresas();
    // std::cout<<"TERMINO DE LISTAR EMPRESAS"<<std::endl;
    // s->ListarSucursales(1112335684);
    // s->ListarSucursales(1265498765);
    // s->ListarSecciones(1112335684, 01);

    // Seccion * sec = suc->buscarSeccion(1);
    // if (sec == NULL)
    //     std::cout<<"SECCION ES NULL"<<std::endl;  
    // //sec->agregarEncargado("ENCARGADO1", "DIRECCION1", "TELEFONO1", 1);
    // sec->ListarOfertas();
    // crearAsignaturas(s);
    
    // s->ListarAsignaturas();
    // int func = altaOferta(s);


    return 0;
}
/*
int OlDmain(){


    RangoSueldo* rango = new RangoSueldo(1000, 2000);
    std::cout << rango->getMinimo() << std::endl;
    std::cout << rango->getMaximo() << std::endl;
    Empresa* empresa = new Empresa("nombre", 1234);
    std::cout<<empresa->getNombre()<<std::endl;
    std::cout<<"COMPILA WACHO"<<std::endl;
    //Sucursal(std::string _nombre, std::string _direccion, std::string _telefono, int _idSucursal); 
    Sucursal* suc = new Sucursal("SUCURSAL", "25 de agosto", "14151", 555);
    std::cout<<suc->getNombre()<<std::endl;
    std::cout<<suc->getDireccion()<<std::endl;
    std::cout<<suc->getTelefono()<<std::endl;
    std::cout<<suc->getidSucursal()<<std::endl;
    empresa->addSucursal(suc);
    empresa->getInfoSuc(555);
    
    empresa->ListarSucursales();
    Seccion* seccion = new Seccion("SECCION", "098651223", 1);
    std::cout<<"INFO SECCION"<<std::endl;
    std::cout<<seccion->getNombre()<<std::endl;
    std::cout<<seccion->getTelefono()<<std::endl;
    std::cout<<seccion->getidSeccion()<<std::endl;
    Sucursal* suc2 = new Sucursal("SEGUNDAA", "25 de MAYO", "77777", 722);
    std::cout<<"CREO SUCURSAL"<<std::endl;
    empresa->addSucursal(suc2);
    
    std::cout<<"AGREGO SECCION"<<std::endl;
    suc2->agregarSeccion(seccion);
    suc2->buscarSeccion(1);
    suc2->listarSecciones();
    std::cout<<"ELIMINO SECCION"<<std::endl;
    suc2->eliminarSeccion(1);
    suc2->listarSecciones();

    Date* fecha = new Date(01,01,01);
    std::cout<<"FECHA"<<std::endl;  
    std::cout<<fecha->getDia()<<std::endl;
    std::cout<<fecha->getMes()<<std::endl;
    std::cout<<fecha->getAnio()<<std::endl;
    empresa = new Empresa("segunda", 1122);

    Estudiante * estudiante = new Estudiante("nombre", "1234", "direccion", Date(1,1,1), "telefono", 1); 
    std::cout<<"ESTUDIANTE"<<std::endl;
    std::cout<<estudiante->getNombre()<<std::endl;
    std::cout<<estudiante->getCedula()<<std::endl;
    std::cout<<estudiante->getDireccion()<<std::endl;
    std::cout<<estudiante->getFechaNacimiento().getDia()<<std::endl;
    std::cout<<estudiante->getFechaNacimiento().getMes()<<std::endl;
    std::cout<<estudiante->getFechaNacimiento().getAnio()<<std::endl;
    std::cout<<estudiante->getTelefono()<<std::endl;
    std::cout<<estudiante->getCreditos()<<std::endl;

    std::cout<<"FINISH"<<std::endl;
    return 0;
}
*/

int altaOferta(){

    
    
    
    
    
    
    return 1;

}



void menu() {
    int opcion;
    std::string sOpcion;
    std::cout<<"--- MENU ---"<<std::endl<<std::endl;

    std::cout<<"--- TRABAJAR CON EMPRESAS ---"<<std::endl<<std::endl;
    std::cout<<"1. Crear Empresa"<<std::endl;
    std::cout<<"2. Eliminar Empresa"<<std::endl;
    std::cout<<"3. Listar Empresas"<<std::endl;

    std::cout<<"--- TRABAJAR CON SUCURSALES ---"<<std::endl<<std::endl;
    std::cout<<"4. Agregar Sucursal"<<std::endl;
    std::cout<<"5. Eliminar Sucursal"<<std::endl;
    std::cout<<"6. Listar Sucursales"<<std::endl;

    std::cout<<"--- TRABAJAR CON SECCIONES ---"<<std::endl<<std::endl;
    std::cout<<"7. Agregar Seccion"<<std::endl;
    std::cout<<"8. Eliminar Seccion"<<std::endl;
    std::cout<<"9. Listar Secciones"<<std::endl;
    std::cout<<"10. Listar Ofertas"<<std::endl;
    std::getline(std::cin, sOpcion);
    opcion = std::stoi(sOpcion);



    //TRABAJAR CON EMPRESAS
    //1. Crear Empresa
    //2. Eliminar Empresa
    //3. Listar Empresas
    //4. Agregar Sucursal
    //5. Eliminar Sucursal
    //6. Listar Sucursales
    //7. Agregar Seccion
    //8. Eliminar Seccion
    //9. Listar Secciones
    //10. Agregar Empleado
    //11. Eliminar Empleado
    //12. Listar Empleados
    
    //TRABAJAR CON PERSONAS
    //16. Agregar Estudiante
    //17. Eliminar Estudiante
    //18. Listar Estudiantes
    //19. Agregar Encargado
    //20. Eliminar Encargado
    //21. Listar Encargados
    //33. Vincular Estudiante con Carrera
    //34. Vincular Encargado con Seccion


    //TRABAJAR CON CARRERAS
    //22. Agregar Carrera
    //23. Eliminar Carrera
    //24. Listar Carreras
    //25. Agregar Curso
    //26. Eliminar Curso
    //27. Listar Cursos
    //28. Agregar Asignaturas
    //29. Eliminar Asignaturas
    //30. Listar Asignaturas
    //31. Vincular Asignatura con Curso
    //32. Vincular Curso con Carrera
}