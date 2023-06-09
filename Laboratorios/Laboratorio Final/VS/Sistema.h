#include<iostream>
#include "Date.h"
#include "ICollection/interfaces/ICollectible.h"
#include "ICollection/interfaces/ICollection.h"
#include "ICollection/interfaces/IDictionary.h"
#include "ICollection/collections/List.h"
//FORWARD DECLARATION PARA QUE NO ME TIRE ERRRORES

class Empresa;

class Sistema {
    private:
        static Sistema* instancia;
        Sistema ();
        ~Sistema ();
        IDictionary* empresas;
        IDictionary* estudiantes;
        IDictionary* ofertas;
        IDictionary* asignaturas;    
        // List* empresas;
        // List* estudiantes;
        // List* ofertas;
        // List* asignaturas;        
    public:
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
        IDictionary* getEmpresas();
        IDictionary* getPersonas();
        IDictionary* getOfertas();
        IDictionary* getAsignaturas();

        // CREAR INSTANCIA    
        static Sistema* getInstancia();
        // int comprarPuntos(int,int){};//IdCuenta, monto
};