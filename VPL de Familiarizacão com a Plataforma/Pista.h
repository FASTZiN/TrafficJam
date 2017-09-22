// Copyright David Grunheidt 2017
#ifndef TRAFFICJAM_PISTA_H
#define TRAFFICJAM_PISTA_H

#include <cstdint>  // std::size_t
#include <stdexcept>  // C++ Exceptions
#include "./Carro.h"  // Class Carro
#include "./LinkedQueue.h"  // LinkedQueue structure
#include "./ArrayList.h"  // ArrayList structure

class Pista {
 public:

	Pista();
	Pista(std::string trackName, int velocidade, int tamanho);
    void pushCar();
    void pushCar(Carro car);
    Carro popCar();
    bool fullTrack();
    void setOutWays(Pista left,Pista straight , Pista right );
    structures::ArrayList<Pista> getOutWays();

 private:

    structures::LinkedQueue<Carro> CarList{};
    structures::ArrayList<Pista> OutWays{3u};
    int tamanho;
    int velocidade;
    std::string trackName;

};  // Fim da classe pista.

#endif
