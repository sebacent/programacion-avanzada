#include <stdio.h>
using namespace std;
class A {
    private:   
        int a;
        string nombre;
    public:
        A();
        A(int x, string s);
        int getA();
        string getNombre();
        void setA(int);
        void setNombre(string);
        void imprimir();
        ~A();
};

//PARA LOS CONSTRUCTORES NI DESTRUCTORES NO SE PONE TIPO DE RETORNO
A::A() {
    a = 0;
    nombre = "Fulano";
}

A::A(int x, string nom) {
    this->a = x;
    this->nombre = nom;
}

int A::getA() {
    return this->a;
}

string A::getNombre() {
    return this->nombre;
}

void A::setA(int x) {
    this->a = x;
}

void A::setNombre(string x) {
    this->nombre = x;
}

void A::imprimir(){
    cout << "Valor: " << this->a << endl;
    cout << "Nombre: " << this->nombre << endl;
}
