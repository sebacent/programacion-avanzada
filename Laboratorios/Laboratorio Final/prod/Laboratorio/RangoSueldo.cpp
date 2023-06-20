#include "RangoSueldo.h"

int RangoSueldo::getMinimo(){
    return sueldoMin;

};

int RangoSueldo::getMaximo(){
    return sueldoMax;
}; 

void RangoSueldo::setMinimo(int _sueldoMin){
    sueldoMin = _sueldoMin;
};

void RangoSueldo::setMaximo(int _sueldoMax){
    sueldoMax = _sueldoMax;
};

