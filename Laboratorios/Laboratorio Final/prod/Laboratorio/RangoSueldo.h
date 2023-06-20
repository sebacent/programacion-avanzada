#ifndef RANGOSUELDO_H
#define RANGOSUELDO_H
#include "ICollection/interfaces/ICollectible.h"

class RangoSueldo : public ICollectible {
    private:
        int sueldoMin;
        int sueldoMax;
    public:
        RangoSueldo(int _sueldoMin, int _sueldoMax): sueldoMin(_sueldoMin), sueldoMax(_sueldoMax) {};
        int getMinimo();
        int getMaximo();
        ~RangoSueldo(){};
        void setMinimo(int _sueldoMin);
        void setMaximo(int _sueldoMax);
};


#endif /* RANGOSUELDO_H */