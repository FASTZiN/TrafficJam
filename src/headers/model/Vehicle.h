// Copyright David Grunheidt 2017
#ifndef TRAFFICJAM_VEHICLE_H
#define TRAFFICJAM_VEHICLE_H

#include <stdexcept>  // C++ Exceptions
#include "../library/ArrayList.h"  // ArrayList structure
#include <stdio.h>
#include <math.h>
#include <stdlib.h>// necessário p/ as funções rand() e srand()
#include <time.h>//necessário p/ função time()

class Vehicle {
public:

    /*!
    * Construtor padr�o do veiculo, Seta um tamanho randomico, e os outros atributos = 0;
    */
	Vehicle();

    /*!
    * Metodo para setar um valor randomico para o tamanho do veiculo
    */
	void setSize();

    /*!
    * Setar a velocidade do veiculo (Na hora que o mesmo nascer ou for trocar de pista)
    */
	void setVelocity(int velocity);

    /*!
    * Gerar a dire��o que o veiculo vai virar (Obs: s� usar quando o mesmo estiver no semaforo)
    * Direction -> { 0 = left, 1 = straight, 2 = right}
    * Enquanto ele nao estiver no semaforo sua dire��o padr�o = 1 (reto)
    * Em outras classes ser� verificado se ele est� no semaforo:
    * Se a posicao do veiculo for igual ao seu tamanho significa que est�.
    */
	void generateDirection(structures::ArrayList<int> directions_possibilities);

    /*!
    * Retorna a dire��o do veiculo
    */
	int getDirection();

    /*!
    * Retorna o tamanho do veiculo
    */
	int getSize();

    /*!
    * Seta a posi��o do veiculo
    */
	void setPosition(int position);

    /*!
    * Retorna a posi��o do veiculo em rela��o ao tamanho da pista
    */
	int getPosition();
	/*!
	 * Move o veiculo pela pista.
	 */
	void Vehicle::CarMoves();

private:

	int size, velocity, position, direction = 1;

};
// Fim da classe Carro.
#endif
