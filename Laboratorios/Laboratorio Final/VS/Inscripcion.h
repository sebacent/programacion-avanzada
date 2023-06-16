#include "Date.h"
#include "ICollectible.h"

class Inscripcion : public ICollectible {
    private:
        Date fecha;
        Date ** entrevistas;
    public:
        Inscripcion(Date _fecha, Date** _entrevistas);
        ~Inscripcion();
        Date getFecha();
        void setFecha(Date _fecha);
        Date** getEntrevistas();
        void setEntrevistas(Date** _entrevistas);    
        void agregarEntrevista(Date _fecha);
        void eliminarEntrevista(Date _fecha);
        
}