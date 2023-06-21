#ifndef ASIGNATURA_H
#define ASIGNATURA_H

// #include <iostream>
// 
// #include "ICollection/interfaces/ICollection.h"
// #include "ICollection/interfaces/IDictionary.h"
// #include "ICollection/collections/List.h"
// #include "Carrera.h"
#include <string>
#include "ICollection/interfaces/ICollectible.h"
#include "ICollection/collections/OrderedDictionary.h"
#include "Oferta.h"

class OfertaLaboral;

class Asignatura : public  ICollectible {
  private:
    std::string nombre;
    int id;
    int creditos;
    OrderedDictionary* ofertas; 
  public:
    Asignatura(std::string _nombre, int _id, int _creditos);
    ~Asignatura();
    std::string getNombre();
    int getId();
    int getcreditos();
    void linkOferta(OfertaLaboral* _oferta);
    void unlinkOferta(int _idOferta);
};

#endif /* ASIGNATURA_H */
