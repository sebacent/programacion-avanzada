#include <iostream>
#include "ICollection/interfaces/ICollectible.h"
#include "ICollection/interfaces/ICollection.h"
#include "ICollection/interfaces/IDictionary.h"
#include "ICollection/collections/List.h"
#include "Date.h"
#include "RangoSueldo.h"

class OfertaLaboral : public ICollectible {
  private:
    int idExpediente;   
    std::string titulo;
    std::string descripcion;
    int horas;
    RangoSueldo rangoSalarial;
    Date fechaInicio;
    Date fechaFin;
    int cantPuestos;
    IDictionary *asignaturas;
    

  public:
    OfertaLaboral( std::string _titulo, std::string _descripcion, int _cantPuestos, int _idExpediente, int _horas, Date _fechaInicio, Date _fechaFin, RangoSueldo _rangoSalarial) {
      this->descripcion = _descripcion;
      this->titulo = _titulo;
      this->cantPuestos = _cantPuestos;
      this->idExpediente = _idExpediente;
      this->horas = _horas;
      this->fechaInicio = _fechaInicio;
      this->fechaFin = _fechaFin;
      this->rangoSalarial = _rangoSalarial;
    }
    int getIdExpediente() {
      return idExpediente;
    }
    std::string getTitulo() {
      return titulo;
    }
    std::string getDescripcion() {
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
        this->idExpediente = _idExpediente;
    }
    void setTitulo(std::string _titulo){
        this->titulo = _titulo;
    }
    void setDescripcion(std::string _descripcion){
        this->descripcion = _descripcion;
    }
    void setRangoSalarial(RangoSueldo _rangoSalarial){
        this->rangoSalarial = _rangoSalarial;
    }
    void setFechaInicio(Date _fechaInicio){
        this->fechaInicio = _fechaInicio;
    }
    void setFechaFin(Date _fechaFin){
        this->fechaFin = _fechaFin;
    }
};