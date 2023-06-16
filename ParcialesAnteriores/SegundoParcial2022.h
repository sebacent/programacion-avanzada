class ICollection{};
class ICollectible{};

//ISistemaDeArchivo.h
class ISistemaDeArchivo{
    public:
        virtual void crearArchivo(int idCarpeta,int idArchivo,int tamanio) = 0;
        virtual int calcularTamanioElemento(int id) = 0;
};


//SistemaDeArchivo.h
class SistemaDeArchivo : public ISistemaDeArchivo {
    private:
        static SistemaDeArchivo * instancia;
        SistemaDeArchivo();
        ICollection * elementos;
    public:
        static SistemaDeArchivo* getInstancia();
        
        void crearArchivo(int idCarpeta,int idArchivo,int tamanio);
        int calcularTamanioElemento(int id);
};
//SistemaDeArchivo.cpp
SistemaDeArchivo::SistemaDeArchivo(){

}




//Elemento.h
class Elemento : ICollectible {
    private:
        int id;
    public:
        virtual int calcularTamanio() = 0;

};
//Archivo.h
class Archivo : Elemento {
    private:
        int tamanio;

    public:
        int calcularTamanio();    
};

//Directorio.h
class Directorio : Elemento {
    private:
        ICollection* elementos;
    public:
        int calcularTamanio();
};




