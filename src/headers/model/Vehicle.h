// Copyright David Grunheidt 2017
#ifndef MODEL_VEHICLE_H
#define MODEL_VEHICLE_H

#include <stdexcept>  // C++ Exceptions
#include "./ArrayList.h"  // ArrayList structure
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>// necessÃ¡rio p/ as funÃ§Ãµes rand() e srand()
#include <time.h>//necessÃ¡rio p/ funÃ§Ã£o time()

class Vehicle {
public:

    /*!
    * Construtor padrão do veiculo, Seta um tamanho randomico, e os outros atributos = 0;
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
    * Gerar a direção que o veiculo vai virar (Obs: só usar quando o mesmo estiver no semaforo)
    * Direction -> { 0 = left, 1 = straight, 2 = right}
    * Enquanto ele nao estiver no semaforo sua direção padrão = 1 (reto)
    * Em outras classes será verificado se ele está no semaforo:
    * Se a posicao do veiculo for igual ao seu tamanho significa que está.
    */
	void generateDirection(structures::ArrayList<int> directions_possibilities);

    /*!
    * Retorna a direção do veiculo
    */
	int getDirection();

    /*!
    * Retorna o tamanho do veiculo
    */
	int getSize();

    /*!
    * Seta a posição do veiculo
    */
	void setPosition(int position);

    /*!
    * Retorna a posição do veiculo em relação ao tamanho da pista
    */
	int getPosition();

private:

	int size, velocity, position, direction = 1;

};
// Fim da classe Carro.
#endif
