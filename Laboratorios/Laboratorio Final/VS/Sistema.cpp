#include"Sistema.h"

Sistema * Sistema::instancia = NULL;

Sistema::Sistema(){
    this->estudiantes = new OrderedDictionary();
    this->asignaturas = new OrderedDictionary();
    //this->carreras = new OrderedDictionary();
    this->empresas = new OrderedDictionary();

}


Sistema::~Sistema (){}


Sistema * Sistema::getInstancia(){
    if(instancia == NULL)
        instancia = new Sistema();
    return instancia;
}


// int Sistema::comprarPuntos(int idCuenta, int monto){
//     IKey* key = new KeyInteger(idCuenta);
//     ICollectible* cuenta = cuentas->find(key);

// }

void Sistema::addEmpresa(int rut,std::string nombre){
    IKey* key = new Integer(rut);
    Empresa * empresa = new Empresa(rut, nombre);
    this->empresas->add(key,empresa);
    //delete key; //<-- Si borro la key da segmentation fault


    //delete empresa;
}

void Sistema::ListarEmpresas(){

    IIterator * it = this->empresas->getIterator();
    if(it == nullptr)
        std::cout<<"No hay empresas registradas"<<std::endl;
    while(it->hasCurrent()){
        Empresa * emp = dynamic_cast<Empresa*>(it->getCurrent());
        std::cout<<"Empresa: "<<emp->getNombre();
        std::cout<<", RUT: "<<emp->getRUT()<<std::endl;
        it->next();
    }
    delete it;
}


void Sistema::ListarSucursales(int _rutEmp){
    IKey * key = new Integer(_rutEmp);

    Empresa * emp = (Empresa *) this->empresas->find(key);

    emp->ListarSucursales();
    delete key;
}

// DtEmpresa* Sistema::buscarEmpresa(int _rutEmp){
//     IKey * key = new Integer(_rutEmp);
//     Empresa * emp = (Empresa *) this->empresas->find(key);
//     std::cout<<"Empresa: "<<emp->getNombre();
//     std::cout<<", RUT: "<<emp->getRUT()<<std::endl;
//     DtEmpresa * res = emp->getDtEmpresa();
//     return res;

// }

void Sistema::addOferta(int idExpediente, std::string titulo, std::string descripcion, int cantPuestos, int horas, Date* fechaInicio, Date* fechaFin, RangoSueldo* rangoSalarial, int idEmpresa, int idSucursal, int idSeccion, int idAsignatura[50]){
    OfertaLaboral * _oferta = new OfertaLaboral(idExpediente, titulo, descripcion, cantPuestos, horas, fechaInicio, fechaFin, rangoSalarial);

    IKey * key = new Integer(idEmpresa);
    Empresa * emp = (Empresa *) this->empresas->find(key);
    emp->linkOferta(_oferta, idSucursal, idSeccion);

    IKey * Okey = new Integer(idExpediente);
    this->ofertas->add(Okey,_oferta);
    
    int i = 0;
    while (idAsignatura[i] != 0){
        IKey * Akey = new Integer(idAsignatura[i]);
        Asignatura * asig = (Asignatura *) this->asignaturas->find(Akey);
        if (asig != NULL)
            asig->linkOferta(_oferta);
        i++;
    }
}