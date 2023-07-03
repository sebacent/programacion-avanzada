    #include "Estudiante.h"

    Estudiante::Estudiante(std::string _nombre, std::string _cedula, Date* _fechaNacimiento, std::string _telefono) 
    {
      this->nombre = _nombre;
      this->cedula = _cedula;
      this->telefono = _telefono;
      this->fechaNacimiento = _fechaNacimiento;
      this->creditos = 0;
      this->inscripciones = new OrderedDictionary();
      this->asignaturas = new OrderedDictionary();
      this->carreras = new OrderedDictionary();

    }
    Estudiante::~Estudiante() {
    }

    int Estudiante::getCreditos() {
      IIterator * it = this->asignaturas->getIterator();
      while(it->hasCurrent())
      {
        if (((Nota*)it->getCurrent())->getNota() >= 6)
          this->creditos += ((Nota*)it->getCurrent())->getCreditos();
        it->next();
      }
      return creditos;
    }

    std::string Estudiante::getCedula() {
      return this->cedula;
    }

    void Estudiante::setNombre(std::string _nombre){
        this->nombre = _nombre;
    }

    std::string Estudiante::getNombre(){
        return this->nombre;
    }
    void Estudiante::ListarEstudiante()
    {
        std::cout << "Cedula: " << this->cedula << std::endl;
        std::cout << "Nombre: " << this->nombre << std::endl;
        std::cout << "Fecha de Nacimiento: " << this->fechaNacimiento->getDia() << "/" << this->fechaNacimiento->getMes() << "/" << this->fechaNacimiento->getAnio() << std::endl;
        std::cout << "Telefono: " << this->telefono << std::endl;
        std::cout << "Creditos: " << this->creditos << std::endl;
        std::cout << "Carreras: " << std::endl;
        // IIterator * it = this->carreras->getIterator();
        
        // while(it->hasCurrent())
        // {
        //     it->getCurrent()->print();
        //     //std::cout <<  << std::endl;
        //     it->next();
        // }
        
        // std::cout << "Asignaturas: " << std::endl;
        // it = this->asignaturas->getIterator();
        // while(it->hasCurrent())
        // {
        //     std::cout << it->getCurrent() << std::endl;
        //     it->next();
        // }
        
        // std::cout << "Inscripciones: " << std::endl;
        // it = this->inscripciones->getIterator();
        // while(it->hasCurrent())
        // {
        //     std::cout << it->getCurrent() << std::endl;
        //     it->next();
        // }

    }

    void Estudiante::addAsignatura(int _id, Date* _fecha, int _nota, ICollectible* _asignatura)
    {
        Asignatura* asignatura = (Asignatura*)_asignatura;      
        Nota* nota = new Nota(this,asignatura,_fecha, _nota,_id);
        IKey * key = new Integer(_id);
        this->asignaturas->add(key, nota);

    }

    std::string Estudiante::getTelefono()
    {
        return telefono;
    }

    void Estudiante::setTelefono(std::string _telefono){
        this->telefono = _telefono;
    }

    void Estudiante::setCreditos(int _creditos) {
      this->creditos = _creditos;
    }


    void Estudiante::removeAsignatura(int idAsign) {
      IKey * key = new Integer(idAsign);
      this->asignaturas->remove(key);
      delete key;
    }
    
    void Estudiante::addInscripcion(OfertaLaboral* _Oferta, int _idOferta, int _idInscripcion, Date * _fecha ) 
    {
      Inscripcion * inscripcion = new Inscripcion(_idInscripcion, _fecha, this, _Oferta);  

      IKey * key = new Integer(_idInscripcion);
      this->inscripciones->add(key, inscripcion);
      _Oferta->agregarInscripcion(inscripcion);
    }

    void Estudiante::removeInscripcion(int idInscripcion) {
      IKey * key = new Integer(idInscripcion);
      this->inscripciones->remove(key);
      delete key;
    }

    void Estudiante::addCarrera(ICollectible* _carrera, int idCarrera) {
      IKey * key = new Integer(idCarrera);
      this->carreras->add(key, _carrera);
    }

    void Estudiante::removeCarrera(int idCarrera) {
      IKey * key = new Integer(idCarrera);
      this->carreras->remove(key);
      delete key;
    }

    OrderedDictionary* Estudiante::getCarreras() {
      return this->carreras;
    }

    OrderedDictionary* Estudiante::getAsignaturas() {
      return this->asignaturas;
    }

    OrderedDictionary* Estudiante::getInscripciones() {
      return this->inscripciones;
    }




    // OrderedDictionary* Estudiante::getCarrera(){
    //     return this->carrera;
    // }
    // void Estudiante::setCarrera(OrderedDictionary* _carrera){
    //     this->carrera = _carrera;
    // }
