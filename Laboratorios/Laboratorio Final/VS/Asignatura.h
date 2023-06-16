// #include <iostream>
// #include "ICollection/interfaces/ICollectible.h"
// #include "ICollection/interfaces/ICollection.h"
// #include "ICollection/interfaces/IDictionary.h"
// #include "ICollection/collections/List.h"
// #include "Carrera.h"
#include <string>
#include "ICollectible.h"



class Asignatura : public  ICollectible {
  private:
    std::string nombre;
    std::string id;
    int creditos;
  public:
    Asignatura(std::string nombre, std::string id, int creditos);
    ~Asignatura();
    std::string getNombre();
    std::string getid();
    int getcreditos();
};