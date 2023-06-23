#ifndef SISTEMA_H
#define SISTEMA_H

#include <iostream>
#include "Date.h"
#include "ICollection/interfaces/ICollectible.h"
#include "ICollection/interfaces/ICollection.h"
#include "ICollection/interfaces/IDictionary.h"
#include "ICollection/collections/OrderedDictionary.h"
#include "ICollection/interfaces/IKey.h"
//FORWARD DECLARATION PARA QUE NO ME TIRE ERRRORES
#include "Empresa.h"
#include "Estudiante.h"
#include "Oferta.h"
#include "Asignatura.h"
#include "Carrera.h"
//#include "ISistema.h"
// class Empresa;
//: public ISistema
class Sistema  {
    private:
        static Sistema * instancia;
        Sistema ();
        
        // IDictionary* empresas;
        // IDictionary* estudiantes;
        // IDictionary* ofertas;
        // IDictionary* asignaturas;    
        OrderedDictionary* carreras;
        OrderedDictionary* empresas;
        OrderedDictionary* estudiantes;
        OrderedDictionary* ofertas;
        OrderedDictionary* asignaturas;        
    public:
        static Sistema * getInstancia();
        ~Sistema ();
        //AGREGAR A COLECCIONES
        void addEmpresa(int rut,std::string nombre);
        void addEstudiante(std::string ci, std::string nombre, Date* fechaNac, std::string telefono, int creditos);
        void addOferta(int idExpediente, std::string titulo, std::string descripcion, int cantPuestos, int horas, Date* fechaInicio, Date* fechaFin, RangoSueldo* rangoSalarial, int idEmpresa, int idSucursal, int idSeccion, int idAsignatura[50]);
        void addAsignatura(std::string nombre, int idAsignatura, int creditos, int idCarrera);
        void addCarrera(std::string nombre, int idCarrera);

        //QUITAR DE COLECCIONES
        void deleteEmpresa(int rut);
        void deleteEstudiante(std::string ci);
        void deleteOferta(int idOferta);
        void deleteAsignatura(int idAsignatura);

        //GETS/SETS
        void ListarEmpresas();
        void ListarSucursales(int);
        //DtEmpresa* buscarEmpresa(int _rut);
        IDictionary* getEmpresas();
        IDictionary* getPersonas();
        IDictionary* getOfertas();
        IDictionary* getAsignaturas();

        //OPERACIONES DE EMPRESA
        void addSucursal(int idSucursal, std::string sucNombre,std::string telefono, std::string direccion, int idEmpresa);
        void deleteSucursal(int idEmpresa, int idSucursal);
        void ListarSecciones(int idEmpresa, int idSucursal);
        void addSeccion(int _idSuc, int _idSecc, std::string _nombre, std::string _telefono, int _idEmp);
       
        //void addSeccion(int idSucursal, int idSeccion, std::string nombre, std::string telefono, int idEmpresa);
        void deleteSeccion(int idEmpresa, int idSucursal, int idSeccion);
        Empresa* buscarEmpresa(int _rut);
        Carrera* buscarCarrera(int _id);
        
        //OPERACIONES DE ASIGNATURAS
        // void addAsignaturaOferta(int idOferta, int idAsignatura);
        // void deleteAsignaturaOferta(int idOferta, int idAsignatura);
        void ListarAsignaturas();
        void ListarOfertas();
        void ListarOfertas(int idEmpresa, int idSuc, int idSecc);
        //OPERACIONES DE ESTUDIANTE



        //OPERACIONES DE CARRERAS
        

        // int comprarPuntos(int,int){};//IdCuenta, monto
};

#endif /* SISTEMA_H */