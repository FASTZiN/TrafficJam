#ifndef TRAFFICJAM_SEMAPHORE_H
#define TRAFFICJAM_SEMAPHORE_H

#include <stdexcept>  // C++ Exceptions
#include "../headers/model/Track.h"
#include "../library/ArrayList.h"

class Semaphore {
public:

    /*!
    * Construtor padr�o do semaforo
    * Seta name para NULL, Pointing para -1 e o resto = 0
    */
	Semaphore();

    /*!
    * Construtor com argumentos do semaforo
    * Define o nome, o tempo de luz verde e vermelha e para onde aponta (N,O,S,L)
    */
	Semaphore(std::string name, int green_time, int red_time, int pointing);

    /*!
    * Seta as possibilidades de virada do semaforo
    * Ser� utilizado posteriormente nos veiculos para definir onde ir�o virar
    */
	void setPossibilities(int left, int straight, int right);

    /*!
    * Abre/Fecha o semaforo
    * 0 = fechado 1 = aberto
    */
	void setState(int state);

    /*!
    * Define a track que o semaforo est� e as de saida
    * N�o � necessario informar um endere�o para a track que ele pertence:
    * Pois n�o iremos verificar informa��es sobre a track dentro do semaforo
    * E sim dentro das tracks
    */
	void Semaphore::setTracks(Track track_in, structures::ArrayList<Track> tracks_out);

    /*!
    * Retorna as possibilidades de saida
    * Indice 0 = esquerda, indice 1 = reto, indice 2 = direita
    */
	structures::ArrayList<int> getDirectionsPossibilities();
	int getState();

    /*!
    * Retorna o tempo da luz verde
    */
	int getGreenTime();

    /*!
    * Retorna o tempo da luz vermelha
    */
	int getRedTime();

    /*!
    * Retorna a dire��o que o sinal controla (N = 0, 1 = O, 2 = S, 3 = L);
    */
	int getPointing();

    /*!
    * Retorna o nome do semaforo (Mesmo nome da track que ele pertence)
    */
	std::string getName();

private:

	int actual_state, green_time, red_time, pointing;   // Poiting -> 0 = norte, 1 = oeste, 2 = sul, 3 = leste
	structures::ArrayList<int> directions_possibilities{3};  //
	structures::ArrayList<Track> tracks{4};  // (Indice 1 = Track in, resto = Out);
	std::string name;
};

#endif
