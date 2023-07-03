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
    if(instancia == NULL){
        instancia = new Sistema();
        instancia->fechaActual = new Date(11,9,2015);
    }
    return instancia;
}

void Sistema::setFecha(Date* _fecha){
    this->fechaActual = _fecha;
}

bool Sistema::esFechaValida(Date *_fecha)
{
    return (this->fechaActual>=_fecha);
}

Date *Sistema::getFecha()
{
    return this->fechaActual;
}

void Sistema::addEmpresa(int rut,std::string nombre){
    IKey* key = new Integer(rut);
    Empresa * empresa = new Empresa(rut, nombre);
    this->empresas->add(key,empresa);
    //delete key; 


    //delete empresa;
}

void Sistema::addEstudiante(std::string ci, std::string nombre, Date *fechaNac, std::string telefono)
{
    IKey* key = new String(ci.c_str());// SE USA ASI c_str()
    Estudiante * estudiante = new Estudiante(nombre, ci, fechaNac, telefono);
    this->estudiantes->add(key,estudiante);
}

void Sistema::deleteOferta(OfertaLaboral *_oferta)
{

    IKey* key = new Integer(_oferta->getIdExpediente());
    IIterator * itEmp = this->empresas->getIterator();
    while(itEmp->hasCurrent()){ //RECORRO TODAS LAS EMPRESAS< SUCURSALES Y SECCIONES PARA ELIMINAR LA OFERTA
        Empresa * emp = (Empresa*) itEmp->getCurrent();
        IIterator * itSuc = emp->getSucursales()->getIterator();

        while(itSuc->hasCurrent()){

            Sucursal * suc = (Sucursal*) itSuc->getCurrent();
            IIterator * itSec = suc->getSecciones()->getIterator();

            while(itSec->hasCurrent()){
                Seccion * sec = (Seccion*) itSec->getCurrent();
                IIterator * itOf = sec->getOfertas()->getIterator();
                sec->getOfertas()->remove(key);
                itSec->next();
            }
            //delete itSec;
            itSuc->next();
        }
        //delete itSuc;
        itEmp->next();
    }
    // delete itOf;
    // delete itSec;
    // delete itSuc;
    delete itEmp;
    IIterator * itEst = this->estudiantes->getIterator();
    OrderedDictionary * inscripciones = NULL;
    while(itEst->hasCurrent()){ //RECORRO TODOS LOS ESTUDIANTES PARA ELIMINAR LA OFERTA
        Estudiante * est = (Estudiante*) itEst->getCurrent();
        inscripciones = est->getInscripciones();
        IIterator * itIns = inscripciones->getIterator();
        while(itIns->hasCurrent()){

            Inscripcion * ins = (Inscripcion*) itIns->getCurrent();
            if(ins->getOferta()->getIdExpediente() == _oferta->getIdExpediente()){

                IKey* keyInsc = new Integer(ins->getId());
                est->getInscripciones()->remove(keyInsc);

                // delete ins;
                // delete key; 
                // delete keyInsc;
                // delete itEmp;
                // delete itIns;
                // delete itEst;
                break;
            }
            itIns->next();
        }
        
        itEst->next();
    }

    this->ofertas->remove(key);

    delete key; 

    
    //delete idOferta;
    _oferta->~OfertaLaboral();

}

void Sistema::deleteAsignatura(int idAsignatura)
{
    //TENGO QUE DESVINCULARLA DE CARRERA TAMBIEN
    IKey* key = new Integer(idAsignatura);
    this->asignaturas->remove(key);
    delete key; 

}

void Sistema::ListarEmpresas()
{

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
    IKey * Ekey = new Integer(_rutEmp);
    Empresa * emp = (Empresa *) this->empresas->find(Ekey);
    if (emp != nullptr){
        std::cout<<"Empresa: "<<emp->getNombre()<<std::endl<<"----------------"<<std::endl;
        emp->ListarSucursales();
    } else{
        std::cout<<"No se encontro empresa"<<std::endl;
    }
    
    delete Ekey;
}

OrderedDictionary *Sistema::getEstudiantes()
{
    return this->estudiantes;
}

OrderedDictionary *Sistema::getOfertas()
{
    return this->ofertas;
}

OrderedDictionary *Sistema::getAsignaturas()
{
    return this->asignaturas;
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
    IKey * key = new Integer(idEmpresa);
    Empresa * emp = (Empresa *) this->empresas->find(key);
    emp->linkOferta(_oferta, idSucursal, idSeccion);
    IKey * Okey = new Integer(_oferta->getIdExpediente());
    this->ofertas->add(Okey,_oferta);
    
    //LINK DE ASIGNATURAS CON LAS OFERTAS
    int i = 0;
    IKey * Akey;
    Asignatura * asig;
    while (idAsignatura != NULL && idAsignatura[i] != 0){
        Akey = new Integer(idAsignatura[i]);
        asig = (Asignatura *) this->asignaturas->find(Akey);
        if (asig != NULL){
            asig->linkOferta(_oferta);
            _oferta->agregarAsignatura(asig);
        }    

        i++;
    }
        //LINK DE LA OFERTA CON LAS ASIGNATURAS
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
        //HORRIBLE PERO FUNCIONA NO COMO EL ACTIVA()
        if(ofer->activa(this->fechaActual)){
            std::cout<<"    Oferta: "<<ofer->getTitulo();
            std::cout<<", ID: "<<ofer->getIdExpediente()<<std::endl;
        }
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

void Sistema::ListarEstudiantes()
{
    Estudiante * est = NULL;
    Date * fecha = NULL;
    OrderedDictionary * notas = NULL;
    IIterator * it = this->estudiantes->getIterator();
    Nota * nota = NULL;
    Asignatura * asignatura = NULL;
    Inscripcion* inscripcion = NULL;
    while(it->hasCurrent()){
        est = (Estudiante*)it->getCurrent();
        fecha = est->getFechaNacimiento();
        std::cout<<std::endl<<std::endl;
        std::cout<<"    Estudiante: "<<est->getNombre();
        std::cout<<", CI: "<<est->getCedula()<<std::endl;
        std::cout<<"        Fecha de nacimiento: "<<fecha->getDia()<<"/"<< fecha->getMes() <<"/"<<fecha->getAnio()<<std::endl;
        std::cout<<"        Telefono"<<est->getTelefono()<<std::endl;
        std::cout<<"        Creditos: "<<est->getCreditos()<<std::endl;
        std::cout<<"            Asignaturas matriculadas: "<<std::endl;
        notas = est->getAsignaturas();
        IIterator * it2 = notas->getIterator();
        
        if(!it2->hasCurrent())
            std::cout<<"            No hay asignaturas matriculadas"<<std::endl;

        while(it2->hasCurrent()){
            nota = (Nota*)it2->getCurrent();
            asignatura = nota->getAsignatura();
            fecha = nota->getFecha();
            std::cout<<"                Asignatura: "<<asignatura->getNombre();
            std::cout<<", ID: "<<asignatura->getId()<<std::endl;
            std::cout<<"                Nota: "<<nota->getNota()<<std::endl;
            std::cout<<"                Fecha: "<< fecha->getDia()<<"/"<< fecha->getMes() <<"/"<<fecha->getAnio()<<std::endl;
            it2->next();
        }
        delete it2;

        std::cout<<"            Inscripciones: "<<std::endl;
        IIterator * it3 = est->getInscripciones()->getIterator();
        if(!it3->hasCurrent())
            std::cout<<"            No hay inscripciones a Ofertas"<<std::endl;
        while(it3->hasCurrent()){
            inscripcion = (Inscripcion*)it3->getCurrent();
            std::cout<<"                Oferta: "<<inscripcion->getOferta()->getTitulo();
            std::cout<<", ID: "<<inscripcion->getOferta()->getIdExpediente()<<std::endl;
            std::cout<<"                Fecha: "<<inscripcion->getFecha()->getDia()<<"/"<<inscripcion->getFecha()->getMes()<<"/"<<inscripcion->getFecha()->getAnio()<<std::endl;
            it3->next();
        }
        
        delete it3;
        
        it->next();
    }
    //POR QUE SEGMENTATION FAULT SI NO ACCEDO DE NUEVO??

    delete it;
    // delete asignatura;
    // delete nota;
    // delete fecha;
    // delete est;
    // delete notas;


}

void Sistema::ListarEstudiantesSimple()
{
    Estudiante * est = NULL;
    Date * fecha = NULL;
    IIterator * it = this->estudiantes->getIterator();
    std::cout<<std::endl<<std::endl;
    std::cout<<"Ingrese CI del estudiante: "<<std::endl;
    while(it->hasCurrent()){
        est = (Estudiante*)it->getCurrent();
        fecha = est->getFechaNacimiento();
        
        std::cout<<"    "<<est->getNombre();
        std::cout<<", CI: "<<est->getCedula()<<std::endl;
        it->next();
    }
    delete it;
}

void Sistema::ListarCarreras()
{
    IIterator * it = this->carreras->getIterator();
    while(it->hasCurrent()){
        Carrera * car = (Carrera*)it->getCurrent();
        std::cout<<"    Carrera: "<<car->getNombre();
        std::cout<<", ID: "<<car->getId()<<std::endl;
        it->next();
    }
    delete it;
}
//CAMBIO A QUE RECIBA UN DATE Y NO UN *DATE PARA QUE SEA MAS FACIL LA PRECARGA
void Sistema::linkEstudianteAsignatura(std::string ci, int idAsignatura, int nota, Date* fecha, int idNota)
{
    IKey * key = new String(ci.c_str());
    Estudiante * est = (Estudiante *) this->estudiantes->find(key);
    if (est != NULL){
        IKey * Akey = new Integer(idAsignatura);
        ICollectible * asig = this->asignaturas->find(Akey);
        if (asig != NULL){
            est->addAsignatura(idNota,fecha,nota,asig);
            //asig->linkEstudiante(est); NO ES NECESARIO (POR CASOS DE USO)
        }
        delete Akey;
    }
    delete key;
}

void Sistema::linkEstudianteCarrera(std::string ci, int idCarrera)
{
    IKey * key = new String(ci.c_str());
    Estudiante * est = (Estudiante *) this->estudiantes->find(key);
    if (est != NULL){
        // IKey * Ckey = new Integer(idCarrera);
        Carrera * car = this->buscarCarrera(idCarrera);
        if (car != NULL){
            est->addCarrera(car, idCarrera);
           // car->linkEstudiante(est); TAMPOCO VA
        }
    }
    delete key;
}

void Sistema::linkEstudianteOferta(std::string ci, int idOferta, int idInscripcion, Date* fechaInscripcion)
{
    IKey * key = new String(ci.c_str());
    Estudiante * est = (Estudiante *) this->estudiantes->find(key);
    if (est != NULL){
        IKey * Okey = new Integer(idOferta);
        OfertaLaboral * ofer = (OfertaLaboral *) this->ofertas->find(Okey);
        if (ofer != NULL){
            est->addInscripcion(ofer,idOferta, idInscripcion,fechaInscripcion);
            //est->addOferta(ofer, idOferta);
            //ofer->linkEstudiante(est); TAMPOCO VA
        }
        delete Okey;
    }
    delete key;
}

bool Sistema::cumpleRequisitos(OrderedDictionary *_estNotas, OrderedDictionary *_oferAsignaturas)
{
    bool cumple = false, encuentro = false;
    int idAsignatura = 0;
    IIterator * itOf = _oferAsignaturas->getIterator();
    IIterator * itEst = _estNotas->getIterator();
    
    Asignatura * asig = NULL;
    Nota * nota = NULL;
    while(itOf->hasCurrent()){
        asig = (Asignatura*)itOf->getCurrent();
        encuentro = false;
        cumple = false;
        while(itEst->hasCurrent() && !cumple){
            
            nota = (Nota*)itEst->getCurrent();
            if (nota->getAsignatura()->getId() == asig->getId()){ //LA NOTA TIENE UN PUNTERO A LA ASIGNATURA
                encuentro = true;
                if (nota->getNota() >= 6) //DE 6 PARA ARRIBA APRUEBA?
                    cumple = true;
            }
            if (encuentro && !cumple) 
                return false;
            itEst->next();//SIGUIENTE NOTA HASTA ENCONTRAR LA ASIGNATURA
        } 
        itOf->next();
    }
    delete itOf;
    delete itEst;
    //delete asig; <- BAD ALLOC ERA POR ESTO
    //delete nota;

    return cumple;
}

void Sistema::ListarInscriptos(int idOferta)
{
    IKey * key = new Integer(idOferta);
    OfertaLaboral * ofer = (OfertaLaboral *) this->ofertas->find(key);
    if (ofer != NULL){
        std::cout<<"    Oferta: "<<ofer->getTitulo();
        std::cout<<", ID: "<<ofer->getIdExpediente()<<std::endl;
        std::cout<<"        Inscriptos: "<<std::endl;
        IIterator * it = ofer->getInscripciones()->getIterator();
        if(!it->hasCurrent())
            std::cout<<"        No hay inscriptos"<<std::endl;
        while(it->hasCurrent()){
            Inscripcion * ins = (Inscripcion*)it->getCurrent();
            std::cout<<"            Estudiante: "<<ins->getEstudiante()->getNombre();
            std::cout<<", CI: "<<ins->getEstudiante()->getCedula()<<std::endl;
            std::cout<<"            Fecha: "<<ins->getFecha()->getDia()<<"/"<<ins->getFecha()->getMes()<<"/"<<ins->getFecha()->getAnio()<<std::endl;
            it->next();
        }
        delete it;
    }
    delete key;
}

bool Sistema::estaInscripto(int idOferta, std::string ci)
{
    IKey * key = new Integer(idOferta);
    OfertaLaboral * ofer = (OfertaLaboral *) this->ofertas->find(key);
    Estudiante * estudiante = (Estudiante *) this->estudiantes->find(new String(ci.c_str()));
    if (ofer != NULL && estudiante != NULL){
        IIterator * it = ofer->getInscripciones()->getIterator();
        while(it->hasCurrent()){
            Inscripcion * ins = (Inscripcion*)it->getCurrent();
            if (ins->getEstudiante()->getCedula() == ci)
                return true;
            it->next();
        }
        delete it;
    }
    return false;
}

void Sistema::unlinkEstudianteOferta(std::string _ci, int _idOferta)
{
    Inscripcion * ins = NULL;
    IKey * KEstudiante = new String(_ci.c_str());
    Estudiante * est = (Estudiante *) this->estudiantes->find(KEstudiante);
    if (est != NULL){
        IKey * KOferta = new Integer(_idOferta);
        OfertaLaboral * ofer = (OfertaLaboral *) this->ofertas->find(KOferta);
        if (ofer != NULL){
            IIterator * it = est->getInscripciones()->getIterator();
            while(it->hasCurrent()){
                ins = (Inscripcion*)it->getCurrent();
                if (ins->getOferta()->getIdExpediente() == _idOferta){
                    est->getInscripciones()->remove(new Integer(ins->getId()));
                    ofer->getInscripciones()->remove(new Integer(ins->getId()));
                    break;
                }
                it->next();
            }
        }
        delete KOferta;
    }
    delete KEstudiante;

    if (ins!=NULL)
        ins->~Inscripcion();

}