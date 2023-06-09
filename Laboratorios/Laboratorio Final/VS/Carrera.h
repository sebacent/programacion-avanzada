#include <iosrteam>
#include ""
class Carrera : public  ICollectible {
  private:
    std::string nombre;
    std::string direccion;
    std::string telefono;
    int numero;
    //ICollection* asignaturas;

  public:
    Carrera(std::string nombre, std::string direccion, std::string telefono, int numero) {
      this->nombre = nombre;
      this->direccion = direccion;
      this->telefono = telefono;
      this->numero = numero;
    }
    std::string getNombre() {
      return nombre;
    }
    std::string getDireccion() {
      return direccion;
    }
    std::string getTelefono() {
      return telefono;
    }
    int getNumero() {
      return numero;
    }
};