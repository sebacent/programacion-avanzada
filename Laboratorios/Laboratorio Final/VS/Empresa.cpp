#include "Empresa.h"

// using the Empresa.h create the getters and setters   for the class Empresa
Empresa::Empresa(std::string _nombre, int _rut) {
    this->nombre = _nombre;
    this->RUT = _rut;
    this->sucursales = new OrderedDictionary(); 
}
//Empresa::Empresa(){};
Empresa::~Empresa() {
    //delete sucursales; 
    delete sucursales; 
};

std::string Empresa::getNombre()
{
    return nombre;
};
 
void Empresa::setNombre(std::string _nombre)
{
    this->nombre = _nombre;
};

int Empresa::getRUT()
{
    return RUT;
};

void Empresa::setRUT(int _rut)
{
    this->RUT = _rut;
};

void Empresa::addSucursal(Sucursal * _sucursal)
{
    IKey * key = new Integer(_sucursal->getidSucursal());
    this->sucursales->add(key,_sucursal);
    delete key;
};

void Empresa::deleteSucursal(int _idSuc)
{
    IKey * key = new Integer(_idSuc);
    this->sucursales->remove(key);
    delete key;
};

std::string Empresa::getInfoSuc(int _idSuc)
{
    IKey * key = new Integer (_idSuc);
    Sucursal * suc = dynamic_cast<Sucursal*>(this->sucursales->find(key));
    std::cout<<"Sucursal: "<<suc->getNombre()<<std::endl;
    return suc->getNombre();
};

void Empresa::ListarSucursales(){
    
    IIterator * it = this->sucursales->getIterator();
    while(it->hasCurrent()){
        Sucursal * suc = dynamic_cast<Sucursal*>(it->getCurrent());
        std::cout<<"Sucursal: "<<suc->getNombre()<<std::endl;
        std::cout<<"ID: "<<suc->getidSucursal()<<std::endl;
        it->next();
    }
    delete it;
};

void Empresa::eliminarSucursales(){
    IIterator * it = this->sucursales->getIterator();
    while(it->hasCurrent()){
        Sucursal * suc = dynamic_cast<Sucursal*>(it->getCurrent());
        suc->eliminarSecciones();
        this->sucursales->remove(suc);
        it->next();
    }
    delete it;
};
