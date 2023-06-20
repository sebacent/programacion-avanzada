#ifndef DATE_H
#define DATE_H

#include "ICollection/interfaces/ICollectible.h"
class Date : public ICollectible {
  public:
    int dia;
    int mes;
    int anio;
    Date(int dia, int mes, int anio);
    
};

#endif /* DATE_H */