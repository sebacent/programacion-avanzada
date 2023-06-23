#include"Sistema.h"

Sistema * Sistema::instancia = NULL;

Sistema::Sistema(){
    this->estudiantes = new OrderedDictionary();
    this->asignaturas = new OrderedDictionary();
    this->carreras = new OrderedDictionary();
    this->empresas = new OrderedDictionary();
    this->ofertas = new OrderedDictionary();
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

void Sistema::ListarSucursales(int _rutEmp)
{   
    std::cout<<"RECIBO: "<<_rutEmp<<std::endl;
    std::cout<<"DEBUG----------->ListarSucursales"<<std::endl;
    IKey * Ekey = new Integer(_rutEmp);
    std::cout<<"DEBUG----------->Creo key"<<std::endl;
    Empresa * emp = (Empresa *) this->empresas->find(Ekey);
    if (emp != nullptr){
        std::cout<<"Empresa: "<<emp->getNombre()<<std::endl<<"----------------"<<std::endl;
        emp->ListarSucursales();
    } else{
        std::cout<<"DEBUG----------->No se encontro empresa"<<std::endl;
    }
    
    //delete key;
}


Empresa* Sistema::buscarEmpresa(int _rutEmp){
    IKey * key = new Integer(_rutEmp);
    Empresa * emp = (Empresa *) this->empresas->find(key);
    std::cout<<"Empresa: "<<emp->getNombre();
    std::cout<<", RUT: "<<emp->getRUT()<<std::endl;
    //DtEmpresa * res = emp->getDtEmpresa();
    return emp;

}

Carrera *Sistema::buscarCarrera(int _id)
{
    IKey * key = new Integer(_id);
    Carrera * car = (Carrera *) this->carreras->find(key);
    std::cout<<"Carrera: "<<car->getNombre();
    std::cout<<", ID: "<<car->getId()<<std::endl;
    return car;

}

void Sistema::addOferta(int idExpediente, std::string titulo, std::string descripcion, int cantPuestos, int horas, Date* fechaInicio, Date* fechaFin, RangoSueldo* rangoSalarial, int idEmpresa, int idSucursal, int idSeccion, int idAsignatura[50]){
    OfertaLaboral * _oferta = new OfertaLaboral(idExpediente, titulo, descripcion, cantPuestos, horas, fechaInicio, fechaFin, rangoSalarial);
    std::cout<<"DEBUG----------->Oferta creada"<<std::endl;
    IKey * key = new Integer(idEmpresa);
    Empresa * emp = (Empresa *) this->empresas->find(key);
    std::cout<<"DEBUG----------->Busco empresa"<<std::endl;
    emp->linkOferta(_oferta, idSucursal, idSeccion);
    std::cout<<"DEBUG----------->Enlazo empresa"<<std::endl;
    IKey * Okey = new Integer(_oferta->getIdExpediente());
    this->ofertas->add(Okey,_oferta);
    std::cout<<"DEBUG----------->Agrego Oferta al Sistema"<<std::endl;
    
    //LINK DE ASIGNATURAS CON LAS OFERTAS
    int i = 0;
    IKey * Akey;
    Asignatura * asig;
    std::cout<<"DEBUG----------->Link de Asignaturas con las Ofertas "<<std::endl;
    while (idAsignatura != NULL && idAsignatura[i] != 0){
        std::cout<<"DEBUG----------->1"<<std::endl;
        Akey = new Integer(idAsignatura[i]);
        std::cout<<"DEBUG----------->2"<<std::endl;
        asig = (Asignatura *) this->asignaturas->find(Akey);
        std::cout<<"DEBUG----------->3"<<std::endl;
        if (asig != NULL){
            std::cout<<"DEBUG----------->3.5"<<std::endl;
            asig->linkOferta(_oferta);
            std::cout<<"DEBUG----------->4"<<std::endl;
            _oferta->agregarAsignatura(asig);
        }    
        std::cout<<"DEBUG----------->5"<<std::endl;

        i++;
    }
        //LINK DE LA OFERTA CON LAS ASIGNATURAS
    std::cout<<"DEBUG-----------> FIN Link de Asignaturas con las Ofertas "<<std::endl;
}


void Sistema::addAsignatura(std::string nombre,int idAsignatura, int creditos, int idCarrera)
{
    IKey * key = new Integer(idAsignatura);
    Asignatura * asig = (Asignatura *) this->asignaturas->find(key);
    if(asig == NULL){
        asig = new Asignatura(nombre,idAsignatura, creditos);
    }
    this->asignaturas->add(key,asig);
    Carrera * car = this->buscarCarrera(idCarrera);
    if (car != NULL)
        car->linkAsignatura(asig);
    //delete key;
    //delete car;
}

void Sistema::ListarAsignaturas()
{
    IIterator * it = this->asignaturas->getIterator();
    while(it->hasCurrent()){
        Asignatura * asig = (Asignatura*)it->getCurrent();
        std::cout<<"    Asignatura: "<<asig->getNombre();
        std::cout<<", ID: "<<asig->getId()<<std::endl;
        it->next();
    }
    delete it;
}

void Sistema::addCarrera(std::string nombre, int idCarrera)
{
    Carrera * car = new Carrera(nombre,idCarrera);
    IKey * key = new Integer(idCarrera);
    this->carreras->add(key,car);
}

void Sistema::addSucursal(int idSucursal, std::string sucNombre, std::string telefono, std::string direccion, int idEmpresa)
{
    IKey * key = new Integer(idEmpresa);
    Empresa * emp = (Empresa *) this->empresas->find(key);
    if (emp != NULL)
        emp->addSucursal(sucNombre, telefono, direccion , idSucursal);
    delete key;
}

void Sistema::ListarSecciones(int idEmpresa, int idSucursal)
{
    IKey * key = new Integer(idEmpresa);
    Empresa * emp = (Empresa *) this->empresas->find(key);
    emp->ListarSecciones(idSucursal);
    delete key;

}

void Sistema::addSeccion(int _idSuc, int _idSecc, std::string _nombre, std::string _telefono, int _idEmp)
{
    IKey * key = new Integer(_idEmp);
    Empresa * emp = (Empresa *) this->empresas->find(key);
    if (emp != NULL)
        emp->addSeccion(_idSuc, _idSecc, _nombre, _telefono);
    delete key;
}

void Sistema::ListarOfertas(){
    IIterator * it = this->ofertas->getIterator();
    while(it->hasCurrent()){
        OfertaLaboral * ofer = (OfertaLaboral*)it->getCurrent();
        std::cout<<"    Oferta: "<<ofer->getTitulo();
        std::cout<<", ID: "<<ofer->getIdExpediente()<<std::endl;
        it->next();
    }
    delete it;
}

void Sistema::ListarOfertas(int idEmpresa, int idSuc, int idSecc){

    IKey * key = new Integer(idEmpresa);
    Empresa * emp = (Empresa *) this->empresas->find(key);
    if (emp != NULL)
        emp->ListarOfertas(idSuc, idSecc);
    delete key;


}

// void deleteEmpresa(int _id){
//     IKey * key = new Integer(_id);
//     Empresa * emp = (Empresa *) this->empresas->find(key);
//     if (emp != NULL)
//         this->empresas->remove(key);
//     delete key;
// }