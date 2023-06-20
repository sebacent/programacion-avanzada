    #include "Estudiante.h"

    Estudiante::Estudiante(std::string _nombre, std::string _cedula, std::string _direccion, Date _fechaNacimiento, std::string _telefono, int _creditos, Carrera* _carrera) {
      this->nombre = _nombre;
      this->cedula = _cedula;
      this->telefono = _telefono;
      this->creditos = _creditos;
      this->asignaturas = new OrderedDictionary();
      this->carrera = _carrera;

    }
    Estudiante::~Estudiante() {
    }

    int Estudiante::getCreditos() {
      return creditos;
    }
    void Estudiante::setNombre(std::string _nombre){
        this->nombre = _nombre;
    }
    std::string Estudiante::getTelefono() {
      return telefono;
    }
    void Estudiante::setTelefono(std::string _telefono){
        this->telefono = _telefono;
    }
    void Estudiante::setCreditos(int _creditos) {
      this->creditos = _creditos;
    }
    Carrera* Estudiante::getCarrera(){
        return this->carrera;
    }
    void Estudiante::setCarrera(Carrera* _carrera){
        this->carrera = _carrera;
    }
