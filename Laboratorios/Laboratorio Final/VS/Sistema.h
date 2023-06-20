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
#include "ISistema.h"
// class Empresa;

class Sistema : public ISistema {
    private:
        static Sistema * instancia;
        Sistema ();
        ~Sistema ();
        // IDictionary* empresas;
        // IDictionary* estudiantes;
        // IDictionary* ofertas;
        // IDictionary* asignaturas;    
        OrderedDictionary* empresas;
        OrderedDictionary* estudiantes;
        OrderedDictionary* ofertas;
        OrderedDictionary* asignaturas;        
    public:
        static Sistema * getInstancia();

        //AGREGAR A COLECCIONES
        void addEmpresa(int rut,std::string nombre);
        void addEstudiante(std::string ci, std::string nombre, Date fechaNac, std::string telefono, int creditos);
        void addOferta(int idOferta, int idEmpresa, int idSucursal, int idSeccion, int idAsignatura, int precio, int cantidad);
        void addAsignatura(int idAsignatura, std::string nombre);

        //QUITAR DE COLECCIONES
        void deleteEmpresa(int rut);
        void deleteEstudiante(std::string ci);
        void deleteOferta(int idOferta);
        void deleteAsignatura(int idAsignatura);

        //GETS/SETS
        void ListarEmpresas();
        void ListarSucursales(int _rut);
        Empresa* buscarEmpresa(int _rut);
        IDictionary* getEmpresas();
        IDictionary* getPersonas();
        IDictionary* getOfertas();
        IDictionary* getAsignaturas();

        //OPERACIONES DE EMPRESA
        void addSucursal(int idEmpresa, int idSucursal, std::string sucNombre, std::string telefono, std::string direccion);
        void deleteSucursal(int idEmpresa, int idSucursal);
        void ListarSecciones(int idEmpresa, int idSucursal);
        void addSeccion(int idEmpresa, int idSucursal, int idSeccion, std::string nombre, std::string telefono);
        void deleteSeccion(int idEmpresa, int idSucursal, int idSeccion);

        // CREAR INSTANCIA    
        
        // int comprarPuntos(int,int){};//IdCuenta, monto
};

#endif /* SISTEMA_H */