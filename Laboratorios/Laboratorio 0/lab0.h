#include <iostream>
#ifndef LAB0_H
#define LAB0_H
using namespace std;

const MAX_EMPLEADOS = 50;


class empleado (
    private:
        string nombre;
        string ci;
        int edad;
        paga valor_hora;
    public:
        float  get_sueldo_peso();
        float  get_sueldo_dolar();
);


class fijo : public empleado(

public:
    float get_sueldo_peso();
    float get_sueldo_dolar();

);



class jornalero: public empleado(
    private:
        int horas;

    public:
        float get_sueldo_peso();
        float get_sueldo_dolar();

);


class empresa (

    private:
        string nombre;
        string nombre_legal;
        int rut;
    public:
        paga  total_sueldo_peso();
        paga  total_sueldo_dolar();

);

class Paga(

    public:
        float monto;
        Moneda moneda;
    private:
        paga a_dolar();
        paga a_peso();


);

class cambio(
    public:
        float a_peso(float);
        float a_dolar(float);
);

enum Moneda{
    usd =40.15;
    us =1;
};

