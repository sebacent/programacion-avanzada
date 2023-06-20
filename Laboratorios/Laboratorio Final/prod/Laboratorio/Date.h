#ifndef DATE_H
#define DATE_H

#include "ICollection/interfaces/ICollectible.h"
class Date : public ICollectible {
  private:
    int dia;
    int mes;
    int anio;
  public:
    Date(int dia, int mes, int anio);
    ~Date();

    //GETS
    int getDia();
    int getMes();
    int getAnio();

    //SETS
    void setDia(int _dia);
    void setMes(int _mes);
    void setAnio(int _anio);
    
    //SOBRECARGAS DE OPERADORES
    bool operator<(Date* _fecha);
    bool operator>(Date* _fecha);
    bool operator==(Date* _fecha);
    bool operator!=(Date* _fecha);
    bool operator<=(Date* _fecha);
    bool operator>=(Date* _fecha);
    
};

#endif /* DATE_H */