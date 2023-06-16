#include "RangoSueldo.h"
//#include <string.h>
#include <iostream>
#include "Empresa.h"
#include "Encargado.h"
#include "Estudiante.h"
//using namespace std;


int main(){
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