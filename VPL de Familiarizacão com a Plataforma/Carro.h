// Copyright David Grunheidt 2017
#ifndef TRAFFICJAM_CARRO_H
#define TRAFFICJAM_CARRO_H

#include <cstdint>  // std::size_t
#include <stdexcept>  // C++ Exceptions
#include "./ArrayList.h"  // ArrayList structure

class Carro {
 public:

   Carro();
   int getTamanho();
   void setVelocidade(int velocidade);
   void generateDirection(structures::ArrayList<Pista> outWays);
   int getDirection();  // Direction -> { 0 = left, 1 = straight, 2 = right }

 private:

   int size, velocity, position, direction = 1;

};  // Fim da classe Carro.
#endif
