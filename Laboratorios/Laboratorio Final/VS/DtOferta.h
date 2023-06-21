#ifndef DTOFERTA_H
#define DTOFERTA_H
#include "ICollection/interfaces/ICollectible.h"
#include "ICollection/interfaces/ICollection.h"
#include "ICollection/collections/OrderedDictionary.h"
#include "ICollection/Integer.h"

#include "Date.h"
#include "RangoSueldo.h"
#include <string>
#include "Asignatura.h"
//

class DtOferta {
  private:
    int idExpediente;   
    std::string titulo;
    std::string descripcion;
    int horas;
    RangoSueldo* rangoSalarial;
    Date* fechaInicio;
    Date* fechaFin;
    int cantPuestos;
    OrderedDictionary* asignaturas;
    //OrderedDictionary *inscripciones;   
  public:
    DtOferta(std::string _titulo, std::string _descripcion, int _cantPuestos, int _idExpediente, int _horas, Date* _fechaInicio, Date* _fechaFin, RangoSueldo* _rangoSalarial, OrderedDictionary* _asignaturas);
    DtOferta();
    ~DtOferta();
    int getIdExpediente();
    std::string getTitulo();
    std::string getDescripcion();
    int getHoras();
    RangoSueldo* getRangoSalarial();
    Date* getFechaInicio();
    Date* getFechaFin();
    int getCantPuestos();
};




#endif /* DT_OFERTA_H */