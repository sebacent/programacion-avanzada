#ifndef NOTA_H
#define NOTA_H

#include "Estudiante.h"
#include "Asignatura.h"

class Asignatura;
class Estudiante;

class Nota : public ICollectible {

private:
    Estudiante* estudiante;
    Asignatura* asignatura;
    Date* fecha;
    int nota;
    int id;
    

public:
    Nota(Estudiante* _estudiante, ICollectible* _asignatura, Date* _fecha, int _nota, int _id);
    ~Nota();
    
    //GETS
    Estudiante* getEstudiante();
    Asignatura* getAsignatura();
    Date* getFecha();
    int getNota();
    int getCreditos();
    //SETS
    void setEstudiante(Estudiante* _estudiante);
    void setAsignatura(Asignatura* _asignatura);
    void setFecha(Date* _fecha);
    void setNota(int _nota);
    
    //SOBRECARGAS DE OPERADORES
    // bool operator<(Nota* _nota);
    // bool operator>(Nota* _nota);
    // bool operator==(Nota* _nota);
    // bool operator!=(Nota* _nota);
    // bool operator<=(Nota* _nota);
    bool operator>=(Nota* _nota);
};
#endif /* NOTA_H */