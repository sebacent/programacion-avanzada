#include "Persona.h"
#include "Carre.h"
#include "Asignatura.h"
// #include "Inscripcion.h"
// #include "Contrato.h"
class Estudiante : public Persona {
  private:
    std::string telefono;
    int creditos;
    Carrera* carrera;
    // Asignatura* asignaturas;
    // Inscripcion* inscripciones;

  public:
    Estudiante(std::string _nombre, std::string _cedula, std::string _direccion, Date _fechaNacimiento, std::string _telefono, int _creditos);
    ~Estudiante();
    int getCreditos();
    void setCreditos(int _creditos);
    std::string getTelefono();
    void setTelefono();
};