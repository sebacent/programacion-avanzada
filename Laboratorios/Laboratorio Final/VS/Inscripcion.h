#ifndef INSCRIPCION_H
#define INSCRIPCION_H

#include "Date.h"
#include "ICollection/interfaces/ICollectible.h"
//#include "ICollection/collections/List.h"
#include "ICollection/collections/OrderedDictionary.h"
#include "ICollection/Integer.h"
// #include "ICollection/interfaces/ICollection.h"

class Inscripcion : public ICollectible {
    private:
        int id;
        Date* fecha;
        OrderedDictionary* entrevistas;
    public:
        Inscripcion(int id, Date* _fecha, OrderedDictionary* _entrevistas);
        ~Inscripcion();
        Date* getFecha();
        int getId();
        void setId(int _id);
        void setFecha(Date* _fecha);
        OrderedDictionary* getEntrevistas();
        void setEntrevistas(OrderedDictionary* _entrevistas);    
        void agregarEntrevista(Date* _fecha);
        void eliminarEntrevista(Date* _fecha);
        
};

#endif /* INSCRIPCION_H */