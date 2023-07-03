#ifndef INSCRIPCION_H
#define INSCRIPCION_H

#include "Date.h"
#include "ICollection/interfaces/ICollectible.h"
//#include "ICollection/collections/List.h"
#include "ICollection/collections/OrderedDictionary.h"
#include "ICollection/Integer.h"
#include "Estudiante.h"
#include "Oferta.h"
// #include "ICollection/interfaces/ICollection.h"

class OfertaLaboral;
class Estudiante;
//const int idInscripcion = 0;
class Inscripcion : public ICollectible {
    private:
        int id;
        Date* fecha;
        OrderedDictionary* entrevistas;
        //Estudiante* estudiante;
        OfertaLaboral* oferta;
        Estudiante * estudiante;
    public:
        Inscripcion(int _id, Date* _fecha, Estudiante* _estudiante, OfertaLaboral* _oferta);
        ~Inscripcion();
        Date* getFecha();
        int getId();
        void setId(int _id);
        void setFecha(Date* _fecha);
        OrderedDictionary* getEntrevistas();
        void setEntrevistas(OrderedDictionary* _entrevistas);    
        void agregarEntrevista(Date* _fecha);
        void eliminarEntrevista(Date* _fecha);
        Estudiante* getEstudiante();
        OfertaLaboral* getOferta();
        
};

#endif /* INSCRIPCION_H */