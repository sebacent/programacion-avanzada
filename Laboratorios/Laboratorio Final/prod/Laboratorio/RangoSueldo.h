
class RangoSueldo {
    public:
        int sueldoMin;
        int sueldoMax;
        RangoSueldo(int _sueldoMin, int _sueldoMax): sueldoMin(_sueldoMin), sueldoMax(_sueldoMax) {};
        int getMinimo();
        int getMaximo();
};

int RangoSueldo::getMinimo(){
    return sueldoMin;
};

int RangoSueldo::getMaximo(){
    return sueldoMax;
};

