#include "RangoSueldo.h"
//#include <string.h>
#include <iostream>
#include "Empresa.h"
#include "Encargado.h"
#include "Estudiante.h"
#include "Sistema.h"
//using namespace std;

int main(){

    int opc = 0;
    std::string opcString;
    std::cout<<"1. ALTA EMPRESA"<<std::endl;
    std::cout<<"2. BAJA EMPRESA"<<std::endl;
    std::cout<<"3. ALTA SUCURSAL"<<std::endl;
    std::cout<<"4. BAJA SUCURSAL"<<std::endl;
    std::cout<<"5. ALTA ENCARGADO"<<std::endl;
    std::cout<<"6. BAJA ENCARGADO"<<std::endl;
    std::cout<<"7. ALTA ESTUDIANTE"<<std::endl;
    std::cout<<"8. BAJA ESTUDIANTE"<<std::endl;
    std::cout<<"9. ALTA OFERTA"<<std::endl;
    std::cout<<"10. BAJA OFERTA"<<std::endl;
    std::cout<<"11. INSCRIPCION A OFERTA"<<std::endl;
    std::cout<<"12. CANCELACION DE INSCRIPCION"<<std::endl;
    std::cout<<"13. LISTAR EMPRESAS"<<std::endl;
    std::cout<<"14. LISTAR SUCURSALES"<<std::endl;
    std::cout<<"15. LISTAR ENCARGADOS"<<std::endl;
    std::cout<<"16. LISTAR ESTUDIANTES"<<std::endl;
    std::cout<<"17. LISTAR OFERTAS"<<std::endl;
    std::cout<<"18. LISTAR INSCRIPCIONES"<<std::endl;
    std::cout<<"19. SALIR"<<std::endl;
    std::cout<<"Ingrese una opcion: ";
    std::getline(std::cin, opcString);
    opc = std::stoi(opcString);
    std::cout<<"OPCION INGRESADA: "<<opc<<std::endl;
    
    //CASO DE USO: ALTA OFERTA
    Sistema * s = Sistema::getInstancia();    
    std::cout<<"COMPILA WACHO"<<std::endl;
    if (s == NULL)
        std::cout<<"SISTEMA ES NULL"<<std::endl;
    std::string nombre = "EMPRESA1";     
    s->addEmpresa(1234,nombre);
    std::cout<<"COMPILA WACHO1"<<std::endl;
    s->ListarEmpresas();

    std::string nombre2 = "EMPRESA2";
    std::cout<<"    INTRO"<<std::endl;
    s->addEmpresa(1235,nombre2);
    std::cout<<"COMPILA WACHO2"<<std::endl;


    std::string nombre3 = "EMPRESA3";
    s->addEmpresa(1236,nombre3);
    std::cout<<"COMPILA WACHO3"<<std::endl;
    s->ListarEmpresas();
    // Empresa * emp;
    // emp = (Empresa *) s->empresas->find(ew Integer(1234));
    Empresa * emp = s->buscarEmpresa(1234);
    emp->addSucursal("SUCURSAL1", "DIRECCION1", "TELEFONO1", 1);
    emp->addSucursal("SUCURSAL2", "DIRECCION2", "TELEFONO2", 2);
    emp->addSucursal("SUCURSAL3", "DIRECCION3", "TELEFONO3", 3);
    emp->addSucursal("SUCURSAL4", "DIRECCION4", "TELEFONO4", 4);
    emp->ListarSucursales();






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



int menu() {

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


    return 1;
}