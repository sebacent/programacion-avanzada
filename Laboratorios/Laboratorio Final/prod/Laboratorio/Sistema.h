#ifndef SISTEMA_H
#define SISTEMA_H

#include <iostream>
#include "Date.h"
#include "ICollection/interfaces/ICollectible.h"
#include "ICollection/interfaces/ICollection.h"
#include "ICollection/interfaces/IDictionary.h"
#include "ICollection/collections/OrderedDictionary.h"
#include "ICollection/interfaces/IKey.h"
#include "ICollection/String.h"
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
        Date* fechaActual;
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
        void setFecha(Date* _fechaActual);
        bool esFechaValida(Date* _fecha);
        Date* getFecha();

        ~Sistema ();
        //AGREGAR A COLECCIONES
        void addEmpresa(int rut,std::string nombre);
        void addEstudiante(std::string ci, std::string nombre, Date* fechaNac, std::string telefono);
        void addOferta(int idExpediente, std::string titulo, std::string descripcion, int cantPuestos, int horas, Date* fechaInicio, Date* fechaFin, RangoSueldo* rangoSalarial, int idEmpresa, int idSucursal, int idSeccion, int idAsignatura[50]);
        void addAsignatura(std::string nombre, int idAsignatura, int creditos, int idCarrera);
        void addCarrera(std::string nombre, int idCarrera);

        //QUITAR DE COLECCIONES
        void deleteEmpresa(int rut);
        void deleteEstudiante(std::string ci);
        void deleteOferta(OfertaLaboral* idOferta);
        void deleteAsignatura(int idAsignatura);

        //GETS/SETS
        void ListarEmpresas();
        void ListarSucursales(int);
        //DtEmpresa* buscarEmpresa(int _rut);
        OrderedDictionary* getEmpresas();
        OrderedDictionary* getEstudiantes();
        OrderedDictionary* getOfertas();
        OrderedDictionary* getAsignaturas();

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
        void ListarEstudiantes();
        void ListarEstudiantesSimple();
        void ListarCarreras();
        
        
        void linkEstudianteAsignatura(std::string ci, int idAsignatura, int nota, Date* fecha, int idNota);
        void linkEstudianteCarrera(std::string ci, int idCarrera);
        void linkEstudianteOferta(std::string ci, int idOferta, int idInscripcion, Date* fechaInscripcion);
        void linkOfertaAsignatura(int idOferta, int idAsignatura);


        void unlinkEstudianteAsignatura(std::string ci, int idAsignatura);
        void unlinkEstudianteCarrera(std::string ci, int idCarrera);
        void unlinkEstudianteOferta(std::string ci, int idOferta);
        void unlinkOfertaAsignatura(int idOferta, int idAsignatura);

        //OPERACIONES DE ESTUDIANTE
        
        bool cumpleRequisitos(OrderedDictionary * _asignaturas, OrderedDictionary * _ofertas); //asignaturas = Nota, ofertas = Aignaturas

        void ListarInscripciones(std::string ci);
        void ListarInscripciones();
        void ListarInscriptos(int idOferta);

        bool estaInscripto(int idOferta, std::string ci);

        //OPERACIONES DE CARRERAS
        

        // int comprarPuntos(int,int){};//IdCuenta, monto
};

#endif /* SISTEMA_H */