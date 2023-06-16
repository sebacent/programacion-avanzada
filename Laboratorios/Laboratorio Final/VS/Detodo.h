// #include <iostream>
#include <string>
using namespace std;


//agregar std::string en todas las ocurrencias de string














/*


class Empresa {
  public:
    ICollection<Sucursal> Sucursal;
};
class Sucursal {
  public:
    ICollection<Seccion> Seccion;
};
class Seccion {
  public:
    ICollection<OfertaLaboral> OfertaLaboral;
    ICollection<Encargado> Encargado;
};
class OfertaLaboral {
  public:
    ICollection<Asignatura> Asignatura;
    ICollection<Estudiante> Estudiante;
};
class Estudiante {
  public:
    ICollection<Asignatura> Asignatura;
    ICollection<Carrera> Carrera;
};
class Asignatura {
  public:
    ICollection<Carrera> Carrera;
};*/

/*OFERTA LABORAL OPTIMIZADO

class OfertaLaboral {
  private:
    int idExpediente;   
    string titulo;
    string descripcion;
    int horas;
    RangoSueldo rangoSalarial;
    Date fechaInicio;
    Date fechaFin;
    int cantPuestos;

  public:
    OfertaLaboral(string _titulo, string _descripcion, int _cantPuestos, int _idExpediente, int _horas, Date _fechaInicio, Date _fechaFin, RangoSueldo _rangoSalarial) :
      idExpediente(_idExpediente), titulo(_titulo), descripcion(_descripcion), horas(_horas), rangoSalarial(_rangoSalarial), fechaInicio(_fechaInicio), fechaFin(_fechaFin), cantPuestos(_cantPuestos) {}
    int getIdExpediente() {
      return idExpediente;
    }
    string getTitulo() {
      return titulo;
    }
    string getDescripcion() {
      return descripcion;
    }
    int getHoras() {
        return horas;
    }
    RangoSueldo getRangoSalarial() {
        return rangoSalarial;
    }
    Date getFechaInicio() {
        return fechaInicio;
    }   
    Date getFechaFin() {
        return fechaFin;
    }
    int getCantPuestos() {
      return cantPuestos;
    }
    void setIdExpediente(int _idExpediente){
        idExpediente = _idExpediente;
    }
    void setTitulo(string _titulo){
        titulo = _titulo;
    }
    void setDescripcion(string _descripcion){
        descripcion = _descripcion;
    }
    void setRangoSalarial(RangoSueldo _rangoSalarial){
        rangoSalarial = _rangoSalarial;
    }
    void setFechaInicio(Date _fechaInicio){
        fechaInicio = _fechaInicio;
    }
    void setFechaFin(Date _fechaFin){
        fechaFin = _fechaFin;
    }*/