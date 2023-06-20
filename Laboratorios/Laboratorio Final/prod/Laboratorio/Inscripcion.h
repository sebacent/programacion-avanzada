#ifndef INSCRIPCION_H
#define INSCRIPCION_H

#include "Date.h"
#include "ICollection/interfaces/ICollectible.h"
#include "ICollection/collections/List.h"
// #include "ICollection/interfaces/ICollection.h"

class Inscripcion : public ICollectible {
    private:
        int id;
        Date* fecha;
        List* entrevistas;
    public:
        Inscripcion(int id, Date* _fecha, List* _entrevistas);
        ~Inscripcion();
        Date* getFecha();
        int getId();
        void setId(int _id);
        void setFecha(Date* _fecha);
        List* getEntrevistas();
        void setEntrevistas(List* _entrevistas);    
        void agregarEntrevista(Date* _fecha);
        void eliminarEntrevista(Date* _fecha);
        
};

#endif /* INSCRIPCION_H */