#include "Empresa.h"

// using the Empresa.h create the getters and setters   for the class Empresa
Empresa::Empresa(int _rut,std::string _nombre) {
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

void Empresa::addSucursal(std::string _nombre, std::string _telefono, std::string _direccion, int _idSucursal)
{
    Sucursal * _sucursal = new Sucursal(_nombre,_telefono,_direccion,_idSucursal);
    IKey * key = new Integer(_idSucursal);
    this->sucursales->add(key,_sucursal);
    //delete key;
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
        Sucursal * suc = (Sucursal*)it->getCurrent();
        std::cout<<"    Sucursal: "<<suc->getNombre();
        std::cout<<", ID: "<<suc->getidSucursal()<<std::endl;
        it->next();
    }
    delete it;
};

void Empresa::eliminarSucursales(){
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


void Empresa::addSeccion(int _idSuc,int _idSeccion, std::string _nombre, std::string _telefono ){
    IKey * key = new Integer(_idSuc);
    Sucursal * suc = (Sucursal*) this->sucursales->find(key);
    if (suc != NULL)
        suc->agregarSeccion(_nombre,_telefono,_idSeccion);
    //delete key;
};

Sucursal* Empresa::buscarSucursal(int _idSuc){
    IKey * key = new Integer(_idSuc);
    Sucursal * suc = (Sucursal*) this->sucursales->find(key);
    //delete key;
    return suc;
};

void Empresa::linkOferta(OfertaLaboral* _Oferta, int _idSuc, int _idSeccion){
    IKey * key = new Integer(_idSuc);
    Sucursal * suc = (Sucursal*) this->sucursales->find(key);
    suc->linkOferta(_idSeccion, _Oferta);
    //delete key;
}
DtEmpresa *Empresa::getDtEmpresa()
{
    DtEmpresa * dte = new DtEmpresa(this->RUT,this->nombre);
    return dte;
}
void Empresa::ListarSecciones(int _idSucursal){
    IKey * key = new Integer(_idSucursal);
    Sucursal * suc = (Sucursal*) this->sucursales->find(key);
    suc->ListarSecciones();
    //delete key;

};

void Empresa::ListarOfertas(int _idSucursal, int _idSeccion){
    IKey * key = new Integer(_idSucursal);
    Sucursal * suc = (Sucursal*) this->sucursales->find(key);
    suc->ListarOfertas(_idSeccion);
    //delete key;
};