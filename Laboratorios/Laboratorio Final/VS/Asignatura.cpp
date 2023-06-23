#include "Asignatura.h"

  Asignatura::Asignatura(std::string _nombre, int _id, int _creditos) {
      this->nombre = _nombre;
      this->id = _id;
      this->creditos = _creditos;
      this->ofertas = new OrderedDictionary();
    }

    Asignatura::~Asignatura(){};
    
    std::string Asignatura::getNombre() {
      return nombre;
    }

    int Asignatura::getId() {
      return id;
    }
    int Asignatura::getcreditos() {
      return creditos;
    }
    void Asignatura::linkOferta(OfertaLaboral *_oferta)
    {
      IKey* key = new Integer(_oferta->getIdExpediente());
      this->ofertas->add(key, _oferta);

    }

    void Asignatura::unlinkOferta(int _idOferta)
    {
      IKey* key = new Integer(_idOferta);
      this->ofertas->remove(key);
      delete key;
    }