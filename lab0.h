#include <iostream>
#ifndef LAB0_H
#endif
#define LAB0_H
using namespace std;

const int MAX_EMPLEADOS = 50;
const float cUSD = 40.15;
const float cUS = 1;

enum Moneda{
    USD,
    US 
};


class Paga{

    private:
        float monto;
        Moneda moneda;
    public:
        Paga();
        Paga a_dolar();
        Paga a_peso();

};

// class cambio{

//     private:
//         static inline float const  USD = 40.15;
//         static inline  float const US = 1;
//     public:
//         float a_peso(float);
//         float a_dolar(float);
// };



class empleado {
    private:
        string nombre;
        string ci;
        int edad;
        Paga valor_hora;
    public:
        empleado();
        empleado(string nombre, string ci, int edad, Paga valor_hora);
        ~empleado();

        //SET FUNCTION
        void setNombre(string nombre);
        void setCi(string ci);
        void setEdad(int edad);
        void setValor_hora(Paga valor_hora);

        //GET FUNCTION
        string getNombre();
        string getCi();
        int getEdad();
        Paga getValor_hora();
        
        float  get_sueldo_peso();
        float  get_sueldo_dolar();
       // void imprimir_empleado();
};



class fijo : public empleado{

    public:
        fijo(string nombre, string ci, int edad, Paga valor_hora);
        void imprimir_fijo();
        float get_sueldo_peso();
        float get_sueldo_dolar();
};



class jornalero: public empleado {
    

    private:
        int horas;

    public:
        jornalero(string nombre, string ci, int edad, Paga valor_hora);
        float get_sueldo_peso();
        float get_sueldo_dolar();

};


class empresa{

    private:
        string nombre;
        string nombre_legal;
        int rut;
    public:
        Paga  total_sueldo_peso();
        Paga  total_sueldo_dolar();

};


