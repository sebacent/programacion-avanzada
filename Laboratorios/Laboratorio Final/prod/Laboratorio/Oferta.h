// #include <iostream>

#ifndef OFERTALABORAL_H
#define OFERTALABORAL_H
// #include "ICollection/interfaces/IDictionary.h"
// #include "ICollection/collections/List.h"
#include "DtOferta.h"
//#include "Contratacion.h"
#include "Inscripcion.h"
#include "Seccion.h"

//FWD
class Asignatura;
class Inscripcion;
class Contratacion;
class Seccion;

class OfertaLaboral : public ICollectible {
  private:
    int idExpediente;   
    std::string titulo;
    std::string descripcion;
    int horas;
    RangoSueldo* rangoSalarial;
    Date* fechaInicio;
    Date* fechaFin;
    int cantPuestos;
    OrderedDictionary *asignaturas;
    OrderedDictionary *inscripciones;
    Seccion* seccion;
    //ICollection *contrataciones;
  public:
    OfertaLaboral(int _idExpediente, std::string _titulo, std::string _descripcion, int _cantPuestos, int _horas, Date* _fechaInicio, Date* _fechaFin, RangoSueldo* _rangoSalarial);
    ~OfertaLaboral();
    
    int getIdExpediente();
    std::string getTitulo();
    std::string getDescripcion();
    int getHoras();
    RangoSueldo* getRangoSalarial();
    int getSueldoMin();
    int getSueldoMax();
    Date* getFechaInicio();
    Date* getFechaFin();
    int getCantPuestos();
    Seccion * getSeccion();
    bool activa(Date* _fechaHoy);
    
    void setIdExpediente(int _idExpediente);
    void setTitulo(std::string _titulo);
    void setDescripcion(std::string _descripcion);
    void setRangoSalarial(RangoSueldo* _rangoSalarial);
    void setFechaInicio(Date* _fechaInicio);
    void setFechaFin(Date* _fechaFin);
    void setHoras(int _horas);
    void setCantPuestos(int _cantPuestos);
    void setSeccion(Seccion* _seccion);
    
    void agregarAsignatura(Asignatura* _asignatura);
    void agregarInscripcion(Inscripcion* _inscripcion);
    //void agregarContratacion(Contratacion* _contratacion);
    
    void eliminarAsignatura(Asignatura* _asignatura);
    void eliminarInscripcion(Inscripcion* _inscripcion);
    //void eliminarContratacion(Contratacion* _contratacion);

    OrderedDictionary* getAsignaturas();
    OrderedDictionary* getInscripciones();
    //ICollection* getContrataciones();

    //DtOferta* getDtOferta();
};
#endif /* OFERTALABORAL_H */