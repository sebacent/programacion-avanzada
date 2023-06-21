#include "DtEmpresa.h"

// using the DtEmpresa.h create the getters and setters   for the class DtEmpresa
DtEmpresa::DtEmpresa(int _rut,std::string _nombre) {
    this->nombre = _nombre;
    this->RUT = _rut;
    this->sucursales = new OrderedDictionary(); 
};
//DtEmpresa::DtEmpresa(){};
DtEmpresa::~DtEmpresa() {
    //delete sucursales; 
    delete sucursales; 
};

std::string DtEmpresa::getNombre()
{
    return nombre;
};
 
void DtEmpresa::setNombre(std::string _nombre)
{
    this->nombre = _nombre;
};

int DtEmpresa::getRUT()
{
    return RUT;
};

void DtEmpresa::setRUT(int _rut)
{
    this->RUT = _rut;
};

void DtEmpresa::addSucursal(std::string _nombre, std::string _direccion, std::string _telefono, int _idSucursal)
{
    Sucursal * _sucursal = new Sucursal(_nombre,_direccion,_telefono,_idSucursal);
    IKey * key = new Integer(_idSucursal);
    this->sucursales->add(key,_sucursal);
    //delete key;
};

void DtEmpresa::deleteSucursal(int _idSuc)
{
    IKey * key = new Integer(_idSuc);
    this->sucursales->remove(key);
    delete key;
};

std::string DtEmpresa::getInfoSuc(int _idSuc)
{
    IKey * key = new Integer (_idSuc);
    Sucursal * suc = dynamic_cast<Sucursal*>(this->sucursales->find(key));
    std::cout<<"Sucursal: "<<suc->getNombre()<<std::endl;
    return suc->getNombre();
};

void DtEmpresa::ListarSucursales(){
    
    IIterator * it = this->sucursales->getIterator();
    while(it->hasCurrent()){
        Sucursal * suc = (Sucursal*)it->getCurrent();
        std::cout<<"    Sucursal: "<<suc->getNombre();
        std::cout<<", ID: "<<suc->getidSucursal()<<std::endl;
        it->next();
    }
    delete it;
};

void DtEmpresa::eliminarSucursales(){
    IIterator * it = this->sucursales->getIterator();
    while(it->hasCurrent()){
        Sucursal * suc = dynamic_cast<Sucursal*>(it->getCurrent());
        //suc->eliminarSecciones();
        IKey * key = new Integer(suc->getidSucursal());
        this->sucursales->remove(key);
        delete key;
        it->next();
    }
    
    delete it;
};


void DtEmpresa::agregarSeccion(int _idSuc, std::string _nombre, std::string _telefono, int _idSeccion){
    IKey * key = new Integer(_idSuc);
    Sucursal * suc = (Sucursal*) this->sucursales->find(key);
    suc->agregarSeccion(_nombre,_telefono,_idSeccion);
    //delete key;
};

Sucursal* DtEmpresa::buscarSucursal(int _idSuc){
    IKey * key = new Integer(_idSuc);
    Sucursal * suc = (Sucursal*) this->sucursales->find(key);
    //delete key;
    return suc;
};