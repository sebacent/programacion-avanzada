#include <iostream>
#include <string>
#include "Empresa.h"
#include "Paga.h"
#include "Empleado.h"
#include <cstdlib>
#include <cstring>


using namespace std;


int main() {

    static Empresa empresa;
    empresa = Empresa();
    int opcion = 0;
    if(1==1){
        // ------------- EJERCICIO 2 -----------------
        do {
            std::cout << "Menu" << std::endl;
            std::cout << "1. Dar de alta una empresa" << std::endl;
            std::cout << "2. Agregar empleado a la empresa" << std::endl;
            std::cout << "3. Calcular total de sueldos en pesos" << std::endl;
            std::cout << "4. Calcular total de sueldos en dolares" << std::endl;
            std::cout << "5. Listar empleados de la empresa" << std::endl;
            std::cout << "6. Salir" << std::endl;
            std::cout << "Ingrese una opcion: ";
            std::cin >> opcion;
            switch (opcion) {
                case 1: {
                    char nombre[50], nombre_legal[50];
                    int rut;
                    try
                    {
                        printf("Ingrese nombre de la empresa: ");
                        scanf("%s", nombre);
                        if (strlen(nombre) > 20){
                            throw std::invalid_argument("Nombre con formato incorrecto.\n");
                        }

                        printf("Ingrese nombre legal de la empresa: ");
                        scanf("%s", nombre_legal);
                        if (strlen(nombre_legal) > 20){
                            throw std::invalid_argument("Nombre Legal con formato incorrecto.\n");
                        }
                        printf("Ingrese RUT de la empresa: ");
                        scanf("%d", &rut);

                        if ( rut < 1 || rut > 99999999) {
                            throw std::invalid_argument("Formato de RUT incorrecto.\n"); 
                        }
                    }
                    catch (std::exception& e) {
                        std::cout << "Ocurrio un error al intentar dar de alta una Empresa: " << e.what() << std::endl;
                    }
                   

                    empresa = Empresa(nombre, nombre_legal, rut);
                    //empresa = Empresa();
                    //PRECARGA que no anda porque se muere en el 2do new :)
                    if(1==1){
                        Jornalero * jorna = new (std::nothrow) Jornalero("JORGE MARTINEZ","50151411",22,Paga(250.8,Moneda::US) ,75,&empresa);
                        jorna->imprimirEmpleado();
                        if(jorna != nullptr){
                            empresa.AddEmpleado(jorna);
                            
                        }
                        Jornalero * jorna1 = new (std::nothrow) Jornalero("PEDRO PIRIZ","4015141",35,Paga(180.8,Moneda::US) ,50,&empresa);
                        
                        if(jorna1 != nullptr)  {
                            jorna1->imprimirEmpleado();
                            empresa.AddEmpleado(jorna1);
                        }
                        Jornalero * jorna2 = new (std::nothrow) Jornalero("MARTIN DIAZ","4587495",40,Paga(300.8,Moneda::US) ,60,&empresa);
                        
                        if(jorna2 != nullptr)    {
                            jorna2->imprimirEmpleado();
                            empresa.AddEmpleado(jorna2);
                        }
                        Fijo* fij = new (std::nothrow) Fijo("MARIO BROS","1111222",35,Paga(185.8,Moneda::US),&empresa);
                        Fijo* fij1 = new (std::nothrow) Fijo("LUIS ENRIQUE","2221114",29,Paga(162.8,Moneda::US),&empresa);
                        Fijo* fij2 = new (std::nothrow) Fijo("LUCAS VIATRI","6665554",38,Paga(200.8,Moneda::US),&empresa);
                        if(fij != nullptr)
                            empresa.AddEmpleado(fij);
                        if(fij1 != nullptr)    
                            empresa.AddEmpleado(fij1);
                        if(fij2 != nullptr)    
                            empresa.AddEmpleado(fij2);
                    }    
                    empresa.listarEmpleados();
                    break;

                }
                case 2: {
                    char nombre[50], ci[8];
                    int edad, tipo, horas,moneda;
                    double valorHora;
                    Moneda empMoneda;
                    Paga empPaga;
                    try
                    {
                        printf("Ingrese nombre del empleado: ");
                        scanf("%s", nombre);
                        if (strlen(nombre) > 20){
                            throw std::invalid_argument("Formato de nombre incorrecto. (DEMASIADO LARGO)\n");
                        }

                        printf("Ingrese CI del empleado: ");
                        scanf("%s", ci);

                        // Verificación de entrada
                        if (strlen(ci) > 8 || strlen(ci) < 7) {
                            throw std::invalid_argument("El largo de la CI no es correcto.(La CI debe contener 7 u 8 digitos)\n");
                        }

                        // Verificación de entrada
                        for (int i = 0; ci[i] != '\0'; i++) {
                            if (!isdigit(ci[i])) {
                                throw std::invalid_argument("Formato de CI incorrecto. La cedula debe contener solo digitos.\n");
                            }
                        }

                        printf("Ingrese edad del empleado: ");
                        scanf("%d", &edad);     
                        if(edad < 18){ 
                             throw std::invalid_argument("Ingrese una edad valida (Mayor o igual a 18).\n");
                        }
                        printf("Ingrese valor hora del empleado: ");
                        scanf("%lf", &valorHora);
                        
                        // Verificación de entrada
                        if (valorHora <= 0 ) {
                            throw std::invalid_argument("Valor de hora incorrecto, debe ser mayor a 0.\n");
                        }


                        printf("Ingrese moneda de paga (0 = USD, 1 = US): ");
                        scanf("%d", &moneda);

                        // Verificación de entrada
                        if (moneda != 0 && moneda != 1 ) {
                             throw std::invalid_argument("No existe la moneda indicada.\n");
                        }

                        if (moneda == 0)
                            empMoneda = Moneda::USD;
                        else 
                            empMoneda = Moneda::US;

                        empPaga = Paga(valorHora, empMoneda);

                        printf("Ingrese tipo de empleado (1. Jornalero, 2. Fijo): ");
                        scanf("%d", &tipo);

                        if (tipo == 1) {
                            printf("Ingrese horas trabajadas del empleado: ");
                            scanf("%d", &horas);
                            if(horas < 0)
                                throw std::invalid_argument("Las horas trabajadas no pueden ser menores que 0.\n");
                        

                            Jornalero* empJorna = new Jornalero(nombre, ci, edad, Paga(valorHora,empMoneda), horas, &empresa);
                            if(empJorna != nullptr){
                                empJorna->imprimirEmpleado();
                                empresa.AddEmpleado(empJorna);                       
                            } else {
                                throw std::invalid_argument("No se pudo crear el nuevo empleado.\n");
                            }    
                        } else if (tipo == 2) {
                            Fijo* empFijo = new Fijo(nombre, ci, edad, Paga(valorHora,empMoneda), &empresa);
                            if(empFijo != nullptr) {
                                empFijo->imprimirEmpleado();
                                empresa.AddEmpleado(empFijo);                       
                            } else {
                                throw std::invalid_argument("No se pudo crear el nuevo empleado.\n");

                            }
                        } else {
                             throw std::invalid_argument("Tipo de empleado no valido. (Tipos validos: 1;2)\n");
                        }

                    }catch (std::exception& e) {
                        std::cout << "Ocurrio un error al intentar dar de alta un Empleado: " << e.what() << std::endl;
                    }
                    break;
                }
                case 3: {
                    Paga totalSueldoPeso = empresa.totalSueldoPeso();
                    std::cout << "Total de sueldos en pesos: " << totalSueldoPeso.getMonto() << std::endl;
                    break;
                }
                case 4: {
                    Paga totalSueldoDolar = empresa.totalSueldoDolar();
                    std::cout << "Total de sueldos en dolares: " << totalSueldoDolar.getMonto() << std::endl;
                    break;
                }
                case 5: {
                // empresa.empresaImprimir();
                    empresa.listarEmpleados();
                    break;
                }
                case 6:
                    return 0;
                default:
                    std::cout << "Opcion invalida." << std::endl;
                    break;
            }
        } while (opcion != 6);
    } else {
      //  empresa.empresaImprimir();
// ------------- EJERCICIO 1 -----------------


// 1. El enumerado Moneda, representado con los valores: “us” y “usd” para peso y dólar
//  respectivamente.
        cout<< "Enumerado moneda"<<endl;
        
    Moneda m = USD;
    std::cout << "  Nombre del enumerado: "<< "USD"<<endl;
    std::cout << "  Valor del enumerado: " << m << std::endl;
    

    m = US;
    std::cout << "  Nombre del enumerado: "<< "US"<<endl;
    std::cout << "  Valor del enumerado: " << m << std::endl;
    


// 2. La clase estática Cambio, con las siguientes operaciones:

    /*a) a_pesos(float importe) : que dado un importe lo convierte a pesos utilizando
    una cotización fija1*/

    cout<<"CAMBIO A PESO: ";
    cout<<Cambio::cPeso(100)<<endl;

    /*b) a_dolar(float importe) : que dado un importe lo convierte a dólares utilizando
    una cotización fija.*/

    cout<<"CAMBIO A DOLAR: ";
    cout<<Cambio::cDolar(4015)<<endl;
        
//3) El datatype Paga, que representará la paga realizada a los empleados.
    //a) El constructor por defecto deberá crear una Paga con monto 0 y moneda us.
    Paga pDefautl = Paga();
    cout<<"PAGA DEFAULT: "<<endl;
    cout<<pDefautl<<endl;



    /*b) Deberá contar con dos operaciones que utilizarán la clase estática Cambio:
    i) a_dolar() : Retorna una Paga donde si la moneda es “us” realiza la conversión
    utilizando Cambio.*/
    cout<<"CAMBIO 1500 US A DOLAR: "<<endl;
    cout<<Cambio::cDolar(1500)<<endl;
    

    /*ii) a_peso() : Retorna una Paga donde si la moneda es “usd” realiza la conversión
    utilizando Cambio. */
    cout<<"CAMBIO 1500 USD A PESO: "<<endl;
    cout<<Cambio::cPeso(1500)<<endl;
//c) Agregar la sobrecarga de las siguientes operaciones:
    Paga pPaga = Paga(3200,Moneda::US);
    cout<<"VALORES PAGA INICIAL: "<<endl;
    cout<<pPaga<<endl;


    //i) Asignación (operador =)
        Paga pPaga1 = Paga(100,Moneda::US);
        cout<<"VALORES PAGA1 INICIAL: "<<endl;
        cout<<pPaga1<<endl;


        pPaga1 = pPaga;
        cout<<"SOBRECARGA PAGA ASIGNACION: "<<endl;
        cout<<pPaga1<<endl;


    //ii) Multiplicación (operador *)
        //(1) Si realizamos: Paga(120, Moneda::us) * 30 el resultado debe ser
       
    //iii) Suma (operador +)
        /*(1) Si realizamos: Paga(3200, Moneda::us) + Paga(1200,
        Moneda::us) el resultado debe ser Paga(4400, Moneda::us).*/
        Paga pPaga3 = Paga(1200,Moneda::USD)+ Paga(3200,Moneda::USD);
        cout<<"SOBRECARGA PAGA SUMA "<<endl;
        cout<<pPaga3<<endl;
        


        /*(2) Si realizamos: Paga(3200, Moneda::us) + Paga(500,
        Moneda::usd) o en el orden inverso de moneda se debe lanzar una
excepción correspondiente*/
        cout<<"Paga(3200, Moneda::us) + Paga(500,Moneda::usd)"<<endl;
        Paga pPaga2 = pPaga + Paga(500,Moneda::USD);
        cout<<"Paga(500,Moneda::usd) + Paga(3200, Moneda::us)"<<endl;
        pPaga2 = Paga(3200,Moneda::USD) + pPaga ;
/*d) Agregar la sobrecarga del operador de inserción de flujo (ej. <<) en un objeto de tipo
std::ostream. El mismo debe imprimir en el flujo de salida el datatype Paga con el
siguiente formato: Monto Moneda
Por ejemplo la sentencia cout << Paga(15400, Moneda::usd) << “\n” debe
imprimir “15.400 usd” y un salto de línea en la salida estándar (observar la
inclusión del carácter separador “.”).*/
        cout<< "pPaga3"<<endl<<pPaga3<< "\n";


        Fijo* emple = new Fijo("PRUEBAS EXCEPC","7777777",35,Paga(185.8,Moneda::US),&empresa);


//EXCEPCIONES 
        emple->setEdad(-10);
        //emple->setValorHora(Paga(150,Moneda::SOL)); <- NO SE PUEDE
        emple->setValorHora(Paga(-1500,Moneda::US));


    }

    return 0;
}
//INICIO PRECARGA
    /*
    Empresa pruebaEmpresa = Empresa();
    pruebaEmpresa.empresaImprimir();
    
    Jornalero * jorna = new Jornalero("JORGE MARTINEZ","50151411",22,Paga(350.8,Moneda::US) ,50,&pruebaEmpresa);
    jorna->imprimirEmpleado();
    pruebaEmpresa.AddEmpleado(jorna);
    pruebaEmpresa.listarEmpleados();
    
    Fijo* fij = new (std::nothrow) Fijo("JORGE MARTINEZ","50151411",22,Paga(185.8,Moneda::US),&pruebaEmpresa);
    cout<<"LLEGO ACAAA"<<endl;
    if (fij != nullptr) {
        fij->imprimirEmpleado();
        pruebaEmpresa.AddEmpleado(fij);
    
    } else {
        cout << "FIJO :: NO TENGO MEMORIAAA: "<<endl;

    }
    

    Jornalero * jorna2 = new (std::nothrow) Jornalero("PEDRO MARTINEZ","1515151",24,Paga(350.8,Moneda::US) ,55,&pruebaEmpresa);
    if (jorna2 != nullptr) {
        jorna2->imprimirEmpleado();
        pruebaEmpresa.AddEmpleado(jorna2);
    
    } else {
        cout << "NO TENGO MEMORIAAA: "<<endl;

    }
    pruebaEmpresa.listarEmpleados();
    cout << "FIJO:: GETSUELDOPESOS"<<fij->getSueldoPeso()<<endl;
    */
    //FIN PRECARGA