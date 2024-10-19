# ssootarea1


#Sistema 1: 
#Para compilar el archivo carrera3.cpp:
  $ g++ -std=c++11 -pthread -o carrera3 carrera3.cpp   
  $ ./carrera3

#------------------------------------------------------
#Sistema 2:
#Archivo Makefile
  CXX = g++
  CXXFLAGS = -std=c++11 -pthread -Wall
  EXEC = carrera_autos
  $(EXEC): carrera3.cpp
        $(CXX) $(CXXFLAGS) -o $(EXEC) carrera3.cpp

#se presiona archivo nombre: carrera3
#Se abre una terminal bash
