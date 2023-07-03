INTERFACES = ICollection/interfaces/
COLECCIONES = ICollection/collections/
OBJETOS = Date.o RangoSueldo.o Carrera.o Inscripcion.o Asignatura.o Persona.o Encargado.o Estudiante.o Nota.o Seccion.o Sucursal.o DtEmpresa.o Empresa.o DtOferta.o Oferta.o main.o ISistema.o Sistema.o Factory.o ICollectible.o IIterator.o IKey.o OrderedKey.o OrderedDictionaryEntry.o String.o Integer.o ListNode.o ListIterator.o IDictionary.o OrderedDictionary.o


#List.o

all: $(OBJETOS)
	g++ $(OBJETOS) -o programa

ICollection.o: $(INTERFACES)ICollection.h
	g++ -Wall -g -c $(INTERFACES)ICollection.cpp

ICollectible.o: $(INTERFACES)ICollectible.h
	g++ -Wall -g -c $(INTERFACES)ICollectible.cpp 

IIterator.o: $(INTERFACES)IIterator.h $(INTERFACES)ICollectible.o
	g++ -Wall -g -c $(INTERFACES)IIterator.cpp 

IKey.o: $(INTERFACES)IKey.h
	g++ -Wall -g -c $(INTERFACES)IKey.cpp

OrderedKey.o: $(INTERFACES)OrderedKey.h $(INTERFACES)IKey.o 
	g++ -Wall -g -c $(INTERFACES)OrderedKey.cpp

Integer.o: ICollection/Integer.h ICollectible.o OrderedKey.o
	g++ -Wall -g -c ICollection/Integer.cpp

String.o: ICollection/String.h ICollectible.o OrderedKey.o
	g++ -Wall -g -c ICollection/String.cpp

OrderedDictionaryEntry.o: $(COLECCIONES)OrderedDictionaryEntry.h ICollectible.o OrderedKey.o
	g++ -Wall -g -c $(COLECCIONES)OrderedDictionaryEntry.cpp

ListNode.o: $(COLECCIONES)ListNode.h ICollectible.o
	g++ -Wall -g -c $(COLECCIONES)ListNode.cpp

ListIterator.o: $(COLECCIONES)ListIterator.h ListNode.o 
	g++ -Wall -g -c $(COLECCIONES)ListIterator.cpp

IDictionary.o: $(INTERFACES)IDictionary.h IIterator.o ICollectible.o IKey.o
	g++ -Wall -g -c $(INTERFACES)IDictionary.cpp

OrderedDictionary.o: $(COLECCIONES)OrderedDictionary.h IDictionary.o OrderedDictionaryEntry.o ListIterator.o
	g++ -Wall -g -c $(COLECCIONES)OrderedDictionary.cpp

#List.o : $(COLECCIONES)List.h ICollection.o ListNode.o ListIterator.o
#	g++ -Wall -g -c $(COLECCIONES)List.cpp	

RangoSueldo.o: ICollectible.o 
	g++ -Wall -g -c RangoSueldo.cpp

Date.o: ICollectible.o 
	g++ -Wall -g -c Date.cpp

Inscripcion.o: Estudiante.o Oferta.o ICollectible.o  Date.o  OrderedDictionary.o#List.o
	g++ -Wall -g -c Inscripcion.cpp

Asignatura.o: Oferta.o ICollectible.o OrderedDictionary.o
	g++ -Wall -g -c Asignatura.cpp	

Carrera.o: ICollectible.o OrderedDictionary.o Asignatura.o
	g++ -Wall -g -c Carrera.cpp

Nota.o : Asignatura.o Estudiante.o ICollectible.o 
	g++ -Wall -g -c Nota.cpp	

Persona.o: Carrera.o ICollectible.o 
	g++ -Wall -g -c Persona.cpp

Encargado.o: Persona.o 
	g++ -Wall -g -c Encargado.cpp

Estudiante.o: Oferta.o Nota.o Inscripcion.o Persona.o  OrderedDictionary.o
	g++ -Wall -g -c Estudiante.cpp

Seccion.o: Encargado.o ICollectible.o 
	g++ -Wall -g -c Seccion.cpp

Sucursal.o: Seccion.o OrderedDictionary.o
	g++ -Wall -g -c Sucursal.cpp	

DtEmpresa.o: Sucursal.o ICollectible.o OrderedDictionary.o
	g++ -Wall -g -c DtEmpresa.cpp

Empresa.o: Sucursal.o ICollectible.o OrderedDictionary.o
	g++ -Wall -g -c Empresa.cpp

DtOferta.o: ICollectible.o 
	g++ -Wall -g -c DtOferta.cpp

Oferta.o : DtOferta.o Inscripcion.o Seccion.o ICollectible.o ICollection.o OrderedDictionary.o 
	g++ -Wall -g -c Oferta.cpp

ISistema.o: DtEmpresa.o ISistema.h
	g++ -c ISistema.cpp

Sistema.o: ISistema.o Empresa.o Oferta.o Carrera.o Sistema.h  String.o Integer.o OrderedDictionary.o
	g++ -Wall -g -c Sistema.cpp


Factory.o: Factory.h ISistema.o Sistema.o
	g++ -c Factory.cpp	

main.o: ISistema.o Factory.o
	g++ -Wall -g -c main.cpp

clean:
	rm -f programa *.o $(INTERFACES)*.o $(COLECCIONES)*.o

clean2:
	rm -f *.o $(INTERFACES)*.o $(COLECCIONES)*.o

run:
	make clean
	make
	clear
	make clean2
	./programa






# main: main.o
# 	g++ -Wall -g main.o -o main

# main.o: main.cpp Empresa.o
# 	g++ -Wall -g -c main.cpp -o main.o

# Empresa.o: Empresa.cpp 
# 	g++ -Wall -g -c Empresa.o -o Empresa.o

# Empresa.cpp: Empresa.h ICollection/collections/List.h ICollection/interfaces/ICollectible.h
# 	g++ -Wall -g -c Empresa.cpp -o Empresa.o

# all: main

# main: main.o Empresa.o
# 	g++ -Wall -g main.o Empresa.o -o main

# main.o: main.cpp Empresa.h
# 	g++ -Wall -g -c main.cpp -o main.o

# Empresa.o: Empresa.cpp Empresa.h ICollection/collections/List.cpp ICollection/interfaces/ICollectible.cpp
# 	g++ -Wall -g -c Empresa.cpp -o Empresa.o

# ICollectible.cpp : ICollection/interfaces/ICollectible.h
# 	g++ -Wall -g -c ICollection/interfaces/ICollectible.o ICollection/interfaces/ICollectible.cpp  

# List.cpp : ICollection/collections/List.h ICollection/interfaces/ICollectible.h
# 	g++ -Wall -g -c ICollection/collections/List.o ICollection/collections/List.cpp 

# clean:
# 	rm -f *.o main

	
# #help me making this makefile

# Path: makefile
# -g option enables debugging mode
# -Wall flag turns on most, but not all, compiler warnings
# -c flag generates object code for separate files
# -std=c++11 flag is for C++11 version

# # Compiler
# CXX = g++
# CXXFLAGS = -Wall -g #-std=c++11

# # Linker
# LD = g++
# LDFLAGS = -g

# # Sources
# SRCS = main.cpp Empresa.cpp ICollection/collections/List.cpp ICollection/interfaces/ICollectible.cpp #ICollectible.cpp List.cpp 

# # Headers
# HEADERS = $(wildcard *.h)

# # Objects
# OBJS = $(SRCS:.cpp=.o)

# # Binary
# BIN = main #ICollectible List

# # Compile
# all: $(BIN)
# # RECIPE para generar el archivo binario a partir de los archivos objeto generados durante la compilación.
# $(BIN): $(OBJS)
# 	$(LD) $(LDFLAGS) $(OBJS) -o $(BIN)

# #Define una regla para generar un archivo objeto a partir de un archivo fuente 
# #y los archivos de encabezado necesarios.
# #Esta línea es la receta para generar un archivo objeto a partir de un archivo fuente y
# #los archivos de encabezado necesarios.

# %.o: %.cpp $(HEADERS)
# 	$(CXX) $(CXXFLAGS) -c $< -o $@ 



# # Clean
# # Define una regla llamada clean que elimina todos los archivos OBJS y BIN
# # generados durante la compilación.
# clean:
# 	rm -f $(OBJS) $(BIN)

# # Path: makefile



# # ICollection/collection/List.o: ICollection/collection/List.cpp
# #     g++ -Wall -g -c ICollection/collection/List.cpp -o ICollection/collection/List.o

# */