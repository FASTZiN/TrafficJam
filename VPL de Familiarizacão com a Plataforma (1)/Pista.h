// Copyright David Grunheidt 2017
#ifndef PISTA_H
#define PISTA_H

#include <cstdint>  // std::size_t
#include <stdexcept>  // C++ Exceptions
#include "./LinkedQueue.h"
#include "./ArrayList.h"
class Pista {
 public:
    void pushCar();
    void pushCar(Carros car);
    Carros popCar();
    bool fullTrack();
    void setOutWays(Pista left,Pista straight , Pista right );
    ArrayList getOutWays();
 private:
    LinkedQueue<Carros> CarList = new LinkedQueue();
    ArrayList<Pista> OutWays = new ArrayList(3);
    int tamanho;
    int velocidade;
}  // Fim do namespace structures.

#endif