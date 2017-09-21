// Copyright David Grunheidt 2017
#ifndef CARROS_H
#define CARROS_H

#include <cstdint>  // std::size_t
#include <stdexcept>  // C++ Exceptions

class Carros {
 public:
   Carros();
   void setTamanho();
   int getTamanho();
   void setVelocidade(int velocidade);
   int getDirection();
 private:
   int tamanho;
   int velocidade;

}  // Fim do namespace structures.

#endif