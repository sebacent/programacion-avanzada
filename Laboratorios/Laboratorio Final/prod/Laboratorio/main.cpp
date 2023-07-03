#include "RangoSueldo.h"
//#include <string.h>
#include <stdlib.h>
#include <iostream>
#include "Empresa.h"
#include "Encargado.h"
#include "Estudiante.h"
// #include "Factory.h"
// #include "ISistema.h"
//using namespace std;
#include "Sistema.h"
#include "Carrera.h"

const std::string clear = "clear";
int corrInscripciones = 0;

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
    // **** LAS ASIGNATURAS QUEDARON DUPLICADAS PORQUE LAS CREO UNA VEZ PARA CADA CARRERA ****
    //TODO: Primero Crear la ASIGNATURA Y DESPUES LINKEARLA  ALA CARRERA
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
    Date * fechaInicio3 = new Date(05,06,2015);
    Date *  fechaFin3 = new Date(06,07,2015);
    RangoSueldo * rangoSueldo3  = new RangoSueldo(5000,6000);
    //O3,A2 A3 A4 A7 A13 A15
    int asignRequeridas3[50] = {0};
    asignRequeridas3[0] = 6598;
    asignRequeridas3[1] = 5698;
    asignRequeridas3[2] = 4875;
    asignRequeridas3[3] = 6943;
    asignRequeridas3[4] = 6587;
    asignRequeridas3[5] = 1889;
    
    sistema->addOferta(88890,"Desarrollador C++","Buscamos desarrollador C++ para importante proyecto internacional. Llenar formulario con datos personales y cv en minisoft.uy/careers.",40,4,fechaInicio3,fechaFin3,rangoSueldo3,1265498765,04,1001,asignRequeridas3);
    

    //O4,49563,Estudiantes para dictar clases de Calculo I y II,Buscamos estudiantes de Ingenieria con Calculo 1 y 2 aprobadas. Deben tener disponibilidad horaria y gusto por enseñar. Enviar mail a academiayotexplico@gmail.com.,5,10,500,2000,10 09 2015,20 12 2015,SE22
    Date * fechaInicio4 = new Date(10,9,2015);
    Date *  fechaFin4 = new Date(20,12,2015);
    RangoSueldo * rangoSueldo4  = new RangoSueldo(500,2000);
    int asignRequeridas4[50] = {0};
    asignRequeridas4[0] = 1686;
    asignRequeridas4[1] = 1689;

    
    sistema->addOferta(49563,"Estudiantes para dictar clases de Calculo I y II","Buscamos estudiantes de Ingenieria con Calculo 1 y 2 aprobadas. Deben tener disponibilidad horaria y gusto por enseñar. Enviar mail a academiayotexplico@gmail.com",5,10,fechaInicio4,fechaFin4,rangoSueldo4,1326548654,07,201,asignRequeridas4);

    sistema->ListarOfertas();

    OrderedDictionary * listEstudiantes = sistema->getEstudiantes();
    Estudiante * _estudiante = NULL;
    IKey * _key = NULL;
    ICollectible * _asignatura = NULL;
    //PRECARGA ESTUDIANTES y NOTAS
    //     ES1,4516231,Esteban,Perez,10 02 1990,099111222
    sistema->addEstudiante("4516231","Esteban Perez",new Date(10,2,1990),"99111222");
        //_key = new String("4516231");
        //_estudiante = (Estudiante*) listEstudiantes->find(_key);
        //NOTASlistEstudiantes
        // ES1,A1,8,10 11 2013
        //_asignatura = sistema->getAsignaturas()->find(new Integer(1686));
        //_estudiante->addAsignatura(1,new Date(10,11,2013),8,_asignatura);
        // ES1,A5,5,20 08 2014
        // ES1,A6,10,12 11 2014
        // ES1,A9,11,10 12 2014


    // ES2,5111235,Felipe Garcia,20 08 1992,24035612
    sistema->addEstudiante("5111235","Felipe Garcia",new Date(20,8,1992),"24035612");

    // ES3,3594561,Juan Wolf,30 01 1980,091222223
    sistema->addEstudiante("3594561","Juan Wolf",new Date(30,1,1980),"91222223");
    
    // ES4,2784531,Alfonsina Ramirez,05 06 1975,43712345
    sistema->addEstudiante("2784531","Alfonsina Ramirez",new Date(5,6,1975),"43712345");
    
    // ES5,1956234,Hector Otonello,10 10 1969,098334456
    sistema->addEstudiante("1956234","Hector Otonello",new Date(10,10,1969),"98334456");
    
    // ES6,5005684,Lorena Nuñez,03 01 1994,092659878
    sistema->addEstudiante("5005684","Lorena Nuñez",new Date(3,1,1994),"92659878");
    
    // ES7,4686231,Hector Lorenzo,09 03 1993,21656498
    sistema->addEstudiante("4686231","Hector Lorenzo",new Date(9,3,1993),"21656498");
    
    // ES8,4987623,Julio Lee,05 08 1992,26984899
    sistema->addEstudiante("4987623","Julio Lee",new Date(5,8,1992),"26984899");
    
    // ES9,4986313,Rodrigo Fernandez,07 09 1990,22233346
    sistema->addEstudiante("4986313","Rodrigo Fernandez",new Date(7,9,1990),"22233346");
    
    // ES10,3659532,Noelia Pereira,02 09 1990,099112233
    sistema->addEstudiante("3659532","Noelia Pereira",new Date(2,9,1990),"99112233");
    
    // ES11,3665492,Cecilia Garrido,30 03 1984,094698568
    sistema->addEstudiante("3665492","Cecilia Garrido",new Date(30,3,1984),"94698568");
    
    // ES12,3335689,Roman Gul,09 12 1983,096677889
    sistema->addEstudiante("3335689","Roman Gul",new Date(9,12,1983),"96677889");
    
    sistema->ListarEstudiantesSimple();

    //PRECARGA APROBACIONES
    // ES1,A1,8,10 11 2013
    sistema->linkEstudianteAsignatura("4516231",1686,8,new Date(10,11,2013),1);
    // ES1,A5,5,20 08 2014
    sistema->linkEstudianteAsignatura("4516231",1689,5,new Date(20,8,2014),2);
    // ES1,A6,10,12 11 2014
    sistema->linkEstudianteAsignatura("4516231",8683,10,new Date(12,11,2014),3);
    // ES1,A9,11,10 12 2014
    sistema->linkEstudianteAsignatura("4516231",3216,11,new Date(10,12,2014),4);
    
    // ES2,A2,9,10 06 2014
    sistema->linkEstudianteAsignatura("5111235",6598,9,new Date(10,6,2014),5);
    // ES2,A3,12,15 06 2014
    sistema->linkEstudianteAsignatura("5111235",5698,12,new Date(15,6,2014),6);
    // ES2,A4,7,02 02 2015
    sistema->linkEstudianteAsignatura("5111235",4875,7,new Date(2,2,2015),7);
    // ES2,A12,6,11 08 2014
    sistema->linkEstudianteAsignatura("5111235",6416,6,new Date(11,8,2014),8);
    
    // ES3,A1,3,20 07 2005
    sistema->linkEstudianteAsignatura("3594561",1686,3,new Date(20,7,2005),9);
    // ES3,A2,10,12 12 2005
    sistema->linkEstudianteAsignatura("3594561",6598,10,new Date(12,12,2005),10);
    // ES3,A3,9,30 07 2006
    sistema->linkEstudianteAsignatura("3594561",5698,9,new Date(30,7,2006),11);
    // ES3,A4,7,02 02 2007
    sistema->linkEstudianteAsignatura("3594561",4875,7,new Date(2,2,2007),12);
    // ES3,A5,8,10 12 2007
    sistema->linkEstudianteAsignatura("3594561",1689,8,new Date(10,12,2007),13);
    // ES3,A7,10,05 12 2008
    sistema->linkEstudianteAsignatura("3594561",6943,10,new Date(5,12,2008),14);
    // ES3,A8,11,15 12 2008
    sistema->linkEstudianteAsignatura("3594561",6879,11,new Date(15,12,2008),15);
    // ES3,A12,8,12 02 2009
    sistema->linkEstudianteAsignatura("3594561",6416,8,new Date(12,2,2009),16);
    // ES3,A13,10,20 11 2010
    sistema->linkEstudianteAsignatura("3594561",6587,10,new Date(20,11,2010),17);
    // ES3,A14,6,15 11 2007
    sistema->linkEstudianteAsignatura("3594561",5498,6,new Date(15,11,2007),18);
    // ES3,A15,10,25 11 2009
    sistema->linkEstudianteAsignatura("3594561",1889,10,new Date(25,11,2009),19);
    
    // ES4,A2,8,10 06 2010
    sistema->linkEstudianteAsignatura("2784531",6598,8,new Date(10,6,2010),20);
    // ES4,A3,6,30 07 2010
    sistema->linkEstudianteAsignatura("2784531",5698,6,new Date(30,7,2010),21);
    
    // ES5,A1,3,10 11 1993
    sistema->linkEstudianteAsignatura("1956234",1686,3,new Date(10,11,1993),22);
    // ES5,A5,3,20 08 1994
    sistema->linkEstudianteAsignatura("1956234",1689,3,new Date(20,8,1994),23);
    // ES5,A9,10,10 12 1994
    sistema->linkEstudianteAsignatura("1956234",3216,10,new Date(10,12,1994),24);
    // ES5,A12,12,11 08 1995
    sistema->linkEstudianteAsignatura("1956234",6416,12,new Date(11,8,1995),25);

    
    // ES7,A1,10,10 11 2013
    sistema->linkEstudianteAsignatura("4686231",1686,10,new Date(10,11,2013),26);
    // ES7,A2,8,10 06 2014
    sistema->linkEstudianteAsignatura("4686231",6598,8,new Date(10,6,2014),27);
    
    // ES8,A1,8,10 07 2011
    sistema->linkEstudianteAsignatura("4987623",1686,8,new Date(10,7,2011),28);
    // ES8,A2,7,10 11 2011
    sistema->linkEstudianteAsignatura("4987623",6598,7,new Date(10,11,2011),29);
    // ES8,A3,10,30 07 2012
    sistema->linkEstudianteAsignatura("4987623",5698,10,new Date(30,7,2012),30);
    // ES8,A4,9,25 11 2012
    sistema->linkEstudianteAsignatura("4987623",4875,9,new Date(25,11,2012),31);
    // ES8,A7,10,05 12 2013
    sistema->linkEstudianteAsignatura("4987623",6943,10,new Date(5,12,2013),32);
    // ES8,A8,12,15 12 2013
    sistema->linkEstudianteAsignatura("4987623",6879,12,new Date(15,12,2013),33);
    // ES8,A11,12,15 11 2014
    sistema->linkEstudianteAsignatura("4987623",9171,12,new Date(15,11,2014),34);
    // ES8,A15,10,25 11 2013
    sistema->linkEstudianteAsignatura("4987623",1889,10,new Date(25,11,2013),35);
    
    // ES9,A1,5,10 11 2014
    sistema->linkEstudianteAsignatura("4986313",1686,5,new Date(10,11,2014),36);
    
    // ES10,A1,8,10 11 2007
    sistema->linkEstudianteAsignatura("3659532",1686,8,new Date(10,11,2007),37);
    // ES10,A2,9,10 06 2008
    sistema->linkEstudianteAsignatura("3659532",6598,9,new Date(10,6,2008),38);
    // ES10,A3,3,30 07 2009
    sistema->linkEstudianteAsignatura("3659532",5698,3,new Date(30,7,2009),39);
    
    // ES11,A1,4,10 11 2003
    sistema->linkEstudianteAsignatura("3665492",1686,4,new Date(10,11,2003),40);
    // ES11,A2,5,10 06 2004
    sistema->linkEstudianteAsignatura("3665492",6598,5,new Date(10,6,2004),41);
    // ES11,A3,10,30 07 2004
    sistema->linkEstudianteAsignatura("3665492",5698,10,new Date(30,7,2004),42);
    // ES11,A4,8,02 02 2005
    sistema->linkEstudianteAsignatura("3665492",4875,8,new Date(2,2,2005),43);
    // ES11,A5,7,20 08 2004
    sistema->linkEstudianteAsignatura("3665492",1689,7,new Date(20,8,2004),44);
    // ES11,A6,10,12 11 2005
    sistema->linkEstudianteAsignatura("3665492",1691,10,new Date(12,11,2005),45);
    // ES11,A7,9,04 12 2005
    sistema->linkEstudianteAsignatura("3665492",6943,9,new Date(4,12,2005),46);

    // ES12,A1,7,10 11 2003
    sistema->linkEstudianteAsignatura("3335689",1686,7,new Date(10,11,2003),47);
    // ES12,A5,8,10 12 2003
    sistema->linkEstudianteAsignatura("3335689",1689,8,new Date(10,12,2003),48);

    sistema->ListarEstudiantes();


    std::cout<<"TERMINO PRECARGA"<<std::endl;


}


void printMenu(){

        system(clear.c_str()); // LIMPIO LA PANTALLA PARA MOSTRAR EL MENU

        std::cout<<std::endl<<std::endl;
        std::cout<<"--- MENU ---"<<std::endl;

        std::cout<<std::endl<<"--- TRABAJAR CON EMPRESAS ---"<<std::endl;
        std::cout<<"1. Crear Empresa"<<std::endl;
        // std::cout<<"2. Eliminar Empresa"<<std::endl;
        std::cout<<"2. Listar Empresas"<<std::endl;

        std::cout<<std::endl<<std::endl<<"--- TRABAJAR CON SUCURSALES ---"<<std::endl;
        std::cout<<"3. Agregar Sucursal"<<std::endl;
        // std::cout<<"6. Eliminar Sucursal"<<std::endl;
        std::cout<<"4. Listar Sucursales"<<std::endl;

        std::cout<<std::endl<<std::endl<<"--- TRABAJAR CON SECCIONES ---"<<std::endl;
        std::cout<<"5. Agregar Seccion"<<std::endl;
//        std::cout<<"8. Eliminar Seccion"<<std::endl;
        std::cout<<"6. Listar Secciones"<<std::endl;

        std::cout<<std::endl<<std::endl<<"--- TRABAJAR CON ASIGNATURAS ---"<<std::endl;
        std::cout<<"7. Agregar Asignatura"<<std::endl;
        std::cout<<"8. Eliminar Asignatura"<<std::endl;
        std::cout<<"9. Listar Asignaturas"<<std::endl;

        std::cout<<std::endl<<std::endl<<"--- TRABAJAR CON ESTUDIANTES ---"<<std::endl;
        std::cout<<"10. Agregar Estudiante"<<std::endl;
        std::cout<<"11. Eliminar Estudiante"<<std::endl;
        std::cout<<"12. Listar Estudiantes"<<std::endl;



        std::cout<<std::endl<<std::endl<<"--- TRABAJAR CON OFERTAS ---"<<std::endl;
        std::cout<<"13. Agregar Oferta"<<std::endl;
        std::cout<<"14. Eliminar Oferta"<<std::endl;
       // std::cout<<"7. Listar Ofertas"<<std::endl;
        std::cout<<"15. Listar Todas las Ofertas(ACTIVAS)"<<std::endl;

        // TRABAJAR CON ENLACES 
        std::cout<<std::endl<<std::endl<<"--- TRABAJAR CON ENLACES ---"<<std::endl;
        std::cout<<"16. Inscribirse a Oferta"<<std::endl;
        std::cout<<"17. Eliminar Inscripcion"<<std::endl;
        std::cout<<"18. Listar Inscripciones"<<std::endl;


        std::cout<<"0. Salir"<<std::endl;
        std::cout<<std::endl<<std::endl;
        std::cout<<"Ingrese una opcion: ";
        std::cout<<std::endl;
}   

void altaOferta(Sistema* sistema){
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
        return;
    }
    if( titulo == ""){
        std::cout<<"El titulo no puede ser nulo o vacio"<<std::endl;
        return;
    }
    if(descripcion == ""){
        std::cout<<"La descripcion no puede ser nula o vacia"<<std::endl;
        return;
    }
    if(cantPuestos == NULL || cantPuestos == 0){
        std::cout<<"La cantidad de puestos no puede ser nula o 0"<<std::endl;
        return;
    }
    if(horas == NULL || horas == 0){
        std::cout<<"La cantidad de horas no puede ser nula o 0"<<std::endl;
        return;
    }
    if(fechaInicio == NULL){
        std::cout<<"La fecha de inicio no puede ser nula"<<std::endl;
        return;
    }
    if(fechaFin == NULL){
        std::cout<<"La fecha de fin no puede ser nula"<<std::endl;
        return;
    }
    if(rangoSalarial == NULL){
        std::cout<<"El rango salarial no puede ser nulo"<<std::endl;
        return;
    }
    if(idEmpresa == NULL || idEmpresa == 0){
        std::cout<<"El id de la empresa no puede ser nulo o 0"<<std::endl;
        return;
    }
    if(idSucursal == NULL || idSucursal == 0){
        std::cout<<"El id de la sucursal no puede ser nulo o 0"<<std::endl;
        return;
    }
    if(idSeccion == NULL || idSeccion == 0){
        std::cout<<"El id de la seccion no puede ser nulo o 0"<<std::endl;
        return;
    }
    if(asignaturas == NULL){
        std::cout<<"Las asignaturas no pueden ser nulas"<<std::endl;
        return;
    }
    //FIN DE CHEQUEO DE NULLS


    sistema->addOferta(idExpediente, titulo, descripcion, cantPuestos, horas, fechaInicio, fechaFin, rangoSalarial, idEmpresa,  idSucursal,  idSeccion, asignaturas);
    return;
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
void altaEstudiante(Sistema *sistema){
    

    std::string nombre, cedula, telefono, str_dia, str_mes, str_anio, str_idCarrera, str_idAsignatura,str_nota;
    int idNota, dia, mes, anio, idAsignatura, idCarrera,nota, notas[10] = {0}, carreras[10] = {0}, asignaturas[20] = {0}, i = 0, j = 0;
    Date* fechaNacimiento, * fechaAprobacion;
    bool valido = false;
    bool listo = false;
    Date* fechas[10] = {NULL};

    //CEDULA
    while (!valido){
        std::cout<<"Ingrese la cedula del estudiante: "<< std::endl;
        std::getline(std::cin, cedula);
        valido = (cedula.length() <= 8 && cedula.length() >= 6);
        if (valido){
            for (int i = 0; i < cedula.length(); i++){
                if (!isdigit(cedula[i])){
                    valido = false;
                    break;
                }
            }
        }
        if (!valido)
            std::cout<<"Cedula invalida"<<std::endl;
    }

    //NOMBRE 
    valido = false;
    while(!valido){
        std::cout<<"Ingrese el nombre del estudiante: "<< std::endl;
        std::getline(std::cin, nombre);

    }

    //TELEFONO
    valido = false;
    while(!valido){
        std::cout<<"Ingrese el telefono del estudiante: (SIN ESPACIOS)"<< std::endl;
        std::getline(std::cin, telefono);
        valido = (telefono.length() <= 9 && telefono.length() >= 8);
        if (valido){
            for (int i = 0; i < telefono.length(); i++){
                if (!isdigit(telefono[i])){
                    valido = false;
                    break;
                }
            }
        }
        if (!valido)
            std::cout<<"Telefono invalido"<<std::endl;
    }

    //FECHA DE NACIMIENTO
    valido = false;
    while(!valido){
        std::cout<<"Ingrese la fecha de nacimiento del estudiante: "<< std::endl;
        std::cout<<"Dia: "<< std::endl;
        std::getline(std::cin, str_dia);
        dia = std::stoi(str_dia);
        std::cout<<"Mes: "<< std::endl;
        std::getline(std::cin, str_mes);
        mes = std::stoi(str_mes);
        std::cout<<"Anio: "<< std::endl;
        std::getline(std::cin, str_anio);
        anio = std::stoi(str_anio);
        valido = (dia >= 1 && dia <= 31 && mes >= 1 && mes <= 12 && anio >= 1900 && anio <= 2005);
        if (!valido){
            std::cout<<"Fecha invalida"<<std::endl;
        }    
    }
    fechaNacimiento = new Date(dia, mes, anio);
    
    sistema->addEstudiante(cedula, nombre, fechaNacimiento, telefono);
    
    //CARRERA   
    valido = false;
    sistema->ListarCarreras();
    while(!valido){
        std::cout<<"Ingrese el id de la carrera del estudiante: "<< std::endl;
        std::cout<<"Si desea salir ingrese X"<< std::endl;
        while(!listo){
            std::getline(std::cin, str_idCarrera);
            if(str_idCarrera == "X"){
                listo = true;
                break;
            }
            idCarrera = std::stoi(str_idCarrera);
            carreras[i] = idCarrera;
            i++;
            if(i == 10){
                std::cout<<"Se ha alcanzado el maximo de carreras"<<std::endl;
                break;
            }
        }


        valido = (idCarrera >= 1);
        if (!valido){
            std::cout<<"Id de carrera invalido"<<std::endl;
        }    
    }
    //TERMINO DE PEDIR DATOS Y AHORA SE ASIGNAN LAS CARRERAS
    for (int k = 0; k < i; k++){
        idCarrera = carreras[k];
        sistema->linkEstudianteCarrera(cedula, idCarrera);
    }

    //ASIGNATURAS PODRIA IR A UNA FUNCION NUEVA PARA NO REPETIR CODIGO
    valido = false;
    listo = false;
    sistema->ListarAsignaturas();
    while(!valido){
        std::cout<<"Ingrese el id de la asignatura del estudiante: "<< std::endl;
        std::cout<<"Si desea salir ingrese X"<< std::endl;
        while(!listo){
            std::getline(std::cin, str_idAsignatura);
            if(str_idAsignatura == "X"){
                listo = true;
                break;
            }
            idAsignatura = std::stoi(str_idAsignatura);
            asignaturas[j] = idAsignatura;

            std::cout<<"Ingrese la Nota de la asignatura"<<std::endl;
            std::getline(std::cin, str_nota);
            nota = std::stoi(str_nota);
            notas[j] = nota;
            
            std::cout<<"Ingrese la fecha de aprobacion de la asignatura: "<< std::endl;

            std::cout<<"Dia: "<< std::endl;
            std::getline(std::cin, str_dia);
            dia = std::stoi(str_dia);
            
            std::cout<<"Mes: "<< std::endl;
            std::getline(std::cin, str_mes);
            mes = std::stoi(str_mes);
            
            std::cout<<"Anio: "<< std::endl;
            std::getline(std::cin, str_anio);
            anio = std::stoi(str_anio);
            
            fechas[j] = new Date(dia, mes, anio);
            
            j++;
            if(j == 20){
                std::cout<<"No se pueden agregar mas asignaturas"<<std::endl;
                break;
            }
        } 
    }
    //TERMINO DE PEDIR DATOS Y AHORA SE ASIGNAN LAS ASIGNATURAS
    for (int k = 0; k < j; k++){
        idAsignatura = asignaturas[k];
        nota = notas[k];
        fechaAprobacion = fechas[k];
        
        sistema->linkEstudianteAsignatura(cedula, idAsignatura, nota, fechaAprobacion, idNota);
    }

    std::cout<<"Estudiante creado con exito"<<std::endl;
    std::cout<<"Presione enter para continuar"<<std::endl;
    std::cin.get();
    return;
}

void inscripcionOferta(Sistema* sistema){
    std::string str_idOferta, str_cedula;
    int idOferta;
    bool valido = false;
    IKey * Koferta = NULL, * Kestudiante = NULL;
    OrderedDictionary* estudiantes = NULL;
    OrderedDictionary* ofertas = NULL;
    Estudiante* estudiante = NULL;
    OfertaLaboral* oferta = NULL;



    std::cout<<"Inscripcion de estudiante a oferta"<<std::endl;

    //OFERTAS
    sistema->ListarOfertas();
    while(!valido){
        std::cout<<"Ingrese el Id de la oferta: "<< std::endl;
        std::getline(std::cin, str_idOferta);
        idOferta = std::stoi(str_idOferta);
        Koferta = new Integer(idOferta);
        ofertas = sistema->getOfertas();
        valido = ofertas->member(Koferta);
        if (!valido){
            std::cout<<"No existe ninguna Oferta para el ID proporcionado."<<std::endl;
        }    
        oferta = (OfertaLaboral*) ofertas->find(Koferta);
    }

    //ESTUDIANTE
    valido = false;
    bool existe = false, primera = true;
    //sistema->ListarEstudiantesSimple();

    while(!existe){
        if(primera){
            primera = false;
//LISTAR ESTUDIANTES NO INSCRIPTOS
            std::cout<<"Estudiantes no inscriptos a la oferta: "<<std::endl;
            estudiantes = sistema->getEstudiantes();
            IIterator * it = estudiantes->getIterator();
            while(it->hasCurrent()){
                estudiante = (Estudiante*) it->getCurrent();
                if(!sistema->estaInscripto(oferta->getIdExpediente(), estudiante->getCedula())){
                    std::cout<<"Cedula: "<<estudiante->getCedula();
                    std::cout<<", Nombre: "<<estudiante->getNombre()<<std::endl;
                    std::cout<<"-----------------------------------"<<std::endl;
                }
                it->next();
            }
        }
        std::cout<<"Ingrese la cedula del estudiante: "<< std::endl;
        std::getline(std::cin, str_cedula);
        Kestudiante = new String(str_cedula.c_str());
        estudiantes = sistema->getEstudiantes();
        existe = estudiantes->member(Kestudiante); //NO COMPRUEBO QUE ESTE INSCRIPTO
        if (!existe){
            std::cout<<"No existe ningun Estudiante para la cedula proporcionada."<<std::endl;
            std::cout<<"Presione enter para continuar"<<std::endl;
            std::cin.get();
            return;
        }    
        estudiante = (Estudiante*) estudiantes->find(Kestudiante);
    }

    if(!sistema->cumpleRequisitos(estudiante->getAsignaturas(), oferta->getAsignaturas() )){
        std::cout<<"El estudiante no cumple con los requisitos para inscribirse a la oferta"<<std::endl;
        std::cout<<"Presione enter para continuar"<<std::endl;
        std::cin.get();
        return;
    }
    Date* fechaInscripcion = sistema->getFecha();
    corrInscripciones += 1;
    sistema->linkEstudianteOferta(str_cedula, idOferta,corrInscripciones, fechaInscripcion);
    std::cout<<"Estudiante inscripto con exito"<<std::endl;
    std::cout<<"Presione enter para continuar"<<std::endl;
    std::cin.get();
    return;

}

void eliminarOferta(Sistema* sistema){
    std::string str_idOferta;
    int idOferta;
    bool valido = false;
    IKey * Koferta = NULL;
    OrderedDictionary* ofertas = NULL;
    OfertaLaboral* oferta = NULL;

    std::cout<<"Eliminacion de oferta"<<std::endl;

    //OFERTAS
    sistema->ListarOfertas();
    while(!valido){
        std::cout<<"Ingrese el Id de la oferta: "<< std::endl;
        std::getline(std::cin, str_idOferta);
        idOferta = std::stoi(str_idOferta);
        Koferta = new Integer(idOferta);
        ofertas = sistema->getOfertas();
        valido = ofertas->member(Koferta);
        if (!valido){
            std::cout<<"No existe ninguna Oferta para el ID proporcionado."<<std::endl;
        }    
        oferta = (OfertaLaboral*) ofertas->find(Koferta);
    }
    sistema->deleteOferta(oferta);
    std::cout<<"Oferta eliminada con exito"<<std::endl;
    std::cout<<"Presione enter para continuar"<<std::endl;
    std::cin.get();
    return;


}

void eliminarInscripcion(Sistema* sistema){
    std::cout<<"Eliminacion de inscripcion"<<std::endl;
    std::string str_idOferta, str_cedula;
    int idOferta;
    bool valido = false;
    IKey * Koferta = NULL, * Kestudiante = NULL;
    OrderedDictionary* estudiantes = NULL;
    OrderedDictionary* ofertas = NULL;
    //Estudiante* estudiante = NULL;
    OfertaLaboral* oferta = NULL;

    //OFERTAS
    sistema->ListarOfertas();
    while(!valido){
        std::cout<<"Ingrese el Id de la oferta: "<< std::endl;
        std::getline(std::cin, str_idOferta);
        idOferta = std::stoi(str_idOferta);
        Koferta = new Integer(idOferta);
        ofertas = sistema->getOfertas();
        valido = ofertas->member(Koferta);
        if (!valido){
            std::cout<<"No existe ninguna Oferta para el ID proporcionado."<<std::endl;
        }    
        oferta = (OfertaLaboral*) ofertas->find(Koferta);
    }

    //ESTUDIANTE
    valido = false;
    bool existe = false;
    if(oferta != NULL){
        sistema->ListarInscriptos(oferta->getIdExpediente());
        while(!existe){
            std::cout<<"Ingrese la CI:"<<std::endl;
            std::getline(std::cin, str_cedula);
            Kestudiante = new String(str_cedula.c_str());
            existe = sistema->getEstudiantes()->member(Kestudiante);
            if (!existe){
                std::cout<<"No existe ningun Estudiante para la cedula proporcionada."<<std::endl;
            } else {
                sistema->unlinkEstudianteOferta(str_cedula, idOferta);
            }
        }    
    }

    std::cout<<"Inscripcion eliminada con exito"<<std::endl;
    std::cout<<"Presione enter para continuar"<<std::endl;
    std::cin.get();
    return;

}

int main(){
    //CASO DE USO: ALTA OFERTA
    Sistema * s = Sistema::getInstancia();    
    std::cout<<"COMPILA WACHO"<<std::endl;
    if (s == NULL)
        std::cout<<"SISTEMA ES NULL"<<std::endl;
    precargaDatosPrueba(s);    
    if(true){
        int opcion, empresaRut, sucId, seccId;
        std::string sOpcion, empresaNombre, sucursalDireccion,sucursalTelefono, sucursalNombre, seccionNombre,seccionTelefono, nombreAsignatura;

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
                    
                    std::cout<<"Presione ENTER para continuar"<<std::endl;
                    std::cin.get();
                    break;

                //LISTAR EMPRESAS
                case 2: 
                    std::cout<<std::endl<<std::endl;
                    s->ListarEmpresas();
                    std::cout<<std::endl<<std::endl;
                    
                    std::cout<<"Presione ENTER para continuar"<<std::endl;
                    std::cin.get();
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
                    sucId = std::stoi(sOpcion);

                    std::cout<<"Ingrese el NOMBRE de la sucursal: "<<std::endl;
                    std::getline(std::cin, sucursalNombre);

                    std::cout<<"Ingrese el TELEFONO de la sucursal: "<<std::endl;
                    std::getline(std::cin, sucursalTelefono);

                    std::cout<<"Ingrese la DIRECCION de la sucursal: "<<std::endl;
                    std::getline(std::cin, sucursalDireccion);


                    s->addSucursal(sucId, sucursalNombre, sucursalTelefono, sucursalDireccion, empresaRut);
                    std::cout<<std::endl<<std::endl;

                    std::cout<<"Presione ENTER para continuar"<<std::endl;
                    std::cin.get();
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

                    std::cout<<"Presione ENTER para continuar"<<std::endl;
                    std::cin.get();
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
                    sucId = std::stoi(sOpcion);
                    
                    std::cout<<"Ingrese el id de la seccion: "<<std::endl;
                    std::getline(std::cin, sOpcion);
                    seccId = std::stoi(sOpcion);

                    std::cout<<"Ingrese el NOMBRE de la seccion: "<<std::endl;
                    std::getline(std::cin, seccionNombre);

                    std::cout<<"Ingrese el TELEFONO de la seccion: "<<std::endl;
                    std::getline(std::cin, seccionTelefono);


                    s->addSeccion(sucId, seccId, seccionNombre, seccionTelefono, empresaRut);
                    std::cout<<std::endl<<std::endl;
                    
                    std::cout<<"Presione ENTER para continuar"<<std::endl;
                    std::cin.get();
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
                    sucId = std::stoi(sOpcion);

                    std::cout<<std::endl<<std::endl;
                    s->ListarSecciones(empresaRut,sucId);
                    std::cout<<std::endl<<std::endl;
                    
                    
                    std::cout<<"Presione ENTER para continuar"<<std::endl;
                    std::cin.get();
                    break;

                        //Agregar asignatura
                case 7: 
                    int codigoAsignatura, creditosAsignatura,codigoCarrera;
                    

                    std::cout<<std::endl<<std::endl;
                    s->ListarCarreras();
                    
                    std::cout<<"Ingrese el codigo de la carrera: "<<std::endl;
                    std::getline(std::cin, sOpcion);
                    codigoCarrera = std::stoi(sOpcion);
                    
                    std::cout<<"Ingrese el codigo de la asignatura: "<<std::endl;
                    std::getline(std::cin, sOpcion);
                    codigoAsignatura = std::stoi(sOpcion);
                    
                    
                    std::cout<<"Ingrese el nombre de la asignatura: "<<std::endl;
                    std::getline(std::cin, nombreAsignatura);

                    std::cout<<"Ingrese la cantidad de creditos de la asignatura: "<<std::endl;
                    std::getline(std::cin, sOpcion);
                    creditosAsignatura = std::stoi(sOpcion);

                    s->addAsignatura(nombreAsignatura, codigoAsignatura , creditosAsignatura, codigoCarrera);
                    std::cout<<std::endl<<std::endl;
                    std::cout<<"Asignatura agregada con exito"<<std::endl;
                    
                    std::cout<<"Presione ENTER para continuar"<<std::endl;
                    std::cin.get();
                    break;

                //Eliminar asignatura        
                case 8: 
                    std::cout<<std::endl<<std::endl;
                    s->ListarAsignaturas();
                    std::cout<<"Ingrese el codigo de la asignatura: "<<std::endl;
                    std::getline(std::cin, sOpcion);
                    codigoAsignatura = std::stoi(sOpcion);
                    s->deleteAsignatura(codigoAsignatura);
                    std::cout<<std::endl<<std::endl;
                    std::cout<<"Asignatura eliminada con exito"<<std::endl;
                    std::cout<<std::endl<<std::endl;
                    
                    std::cout<<"Presione ENTER para continuar"<<std::endl;
                    std::cin.get();
                    break;
                    
                    //Listar asignaturas
                case 9: 
                    std::cout<<std::endl<<std::endl;
                    s->ListarAsignaturas();
                    std::cout<<std::endl<<std::endl;
                    
                    std::cout<<"Presione ENTER para continuar"<<std::endl;
                    std::cin.get();                    
                    break;

                        //Agregar Estudiante
                case 10: 
                        altaEstudiante(s);
                        std::cout<<std::endl<<std::endl;
                        std::cout<<"Estudiante agregado con exito"<<std::endl;
                        
                        std::cout<<"Presione ENTER para continuar"<<std::endl;
                        std::cin.get();
                        break;

                        //Eliminar Estudiante
                case 11:         
                        std::cout<<std::endl<<std::endl;
                        s->ListarEstudiantesSimple();
                        std::cout<<"Ingrese la CI del estudiante: "<<std::endl;
                        std::getline(std::cin, sOpcion);
                        std::cout<<"Elimino al estudiante: "<<sOpcion <<std::endl;
                        //s->deleteEstudiante(sOpcion);

                        //Liastar Estudiantes
                case 12: 
                        std::cout<<std::endl<<std::endl;
                        s->ListarEstudiantes();
                        std::cout<<std::endl<<std::endl;
                        std::cout<<"Presione ENTER para continuar"<<std::endl;
                        std::cin.get();

                    break;

                        
                        //Agregar Oferta
                case 13: 
                        std::cout<<std::endl<<std::endl;
                        altaOferta(s);
                        std::cout<<"Oferta agregada con exito"<<std::endl;
                        std::cout<<std::endl<<std::endl;
                        std::cout<<"Presione ENTER para continuar"<<std::endl;
                        std::cin.get();
                    break;

                        // Eliminar Oferta
                case 14: 
                        eliminarOferta(s);
                        break;
                        
                        // Listar todas las ofertas 
                case 15:                       
                        s->ListarOfertas();
                        std::cout<<std::endl<<std::endl;
                        std::cout<<"Presione ENTER para continuar"<<std::endl;
                        std::cin.get();

                    break;
                        

                        //Inscribirse Oferta
                case 16:     
                        inscripcionOferta(s);
                        std::cout<<std::endl<<std::endl;
                        std::cout<<"Presione ENTER para continuar"<<std::endl;
                        std::cin.get();
                    break;
                        //Eliminar Inscripcion
                case 17:    
                        eliminarInscripcion(s);
                        std::cout<<std::endl<<std::endl;
                        std::cout<<"Presione ENTER para continuar"<<std::endl;
                        std::cin.get();
                    break;
                        //Listar Inscriptos
                case 18:
                        std::cout<<std::endl<<std::endl;
                        s->ListarOfertas();
                        
                        std::cout<<"Ingrese ID de la Oferta"<<std::endl;
                        std::getline(std::cin, sOpcion);
                        opcion = std::stoi(sOpcion);
                        
                        s->ListarInscriptos(opcion);
                        
                        std::cout<<std::endl<<std::endl;
                        std::cout<<"Presione ENTER para continuar"<<std::endl;
                        std::cin.get();
                    break;
                        //Listar Inscripciones por estudiante


                // //LISTAR OFERTAS
                // case 16: 
                //     // std::cout<<std::endl<<std::endl;
                //     // s->ListarEmpresas();
                //     // std::cout<<"Ingrese el RUT de la empresa: "<<std::endl;
                //     // std::getline(std::cin, sOpcion);
                //     // empresaRut = std::stoi(sOpcion);

                //     // std::cout<<std::endl<<std::endl;
                //     // s->ListarSucursales(empresaRut);
                //     // std::cout<<"Ingrese el ID de la sucursal: "<<std::endl;
                //     // std::getline(std::cin, sOpcion);
                //     // sucId = std::stoi(sOpcion);

                //     // std::cout<<std::endl<<std::endl;
                //     // s->ListarSecciones(empresaRut,sucId);
                //     // std::cout<<"Ingrese el id de la seccion: "<<std::endl;
                //     // std::getline(std::cin, sOpcion);
                //     // seccId = std::stoi(sOpcion);

                //     // s->ListarOfertas(empresaRut,sucId,seccId);
                //     // std::cout<<std::endl<<std::endl;
                //     break;



                //         // AGREGAR OFERTA
                // case 9: 
                //         // altaOferta(s);
                //         // break;
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

    return 0;
}