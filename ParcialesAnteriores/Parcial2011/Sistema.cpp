#include"Sistema.h"
#include<iostream>



Sistema* Sistema::getInstancia(){
    if(instancia == nullptr)
        instancia = new Sistema();
    return instancia;
}   

int Sistema::comprarPuntos(int idCuenta, int monto){
    KeyInteger* key = new KeyInteger(idCuenta);
    ICollectible* cuenta = cuentas->find(key);

    cuenta->

}