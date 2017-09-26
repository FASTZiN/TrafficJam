
#ifndef TRAFFICJAM_TRACKS_MANAGER_H
#define TRAFFICJAM_TRACKS_MANAGER_H

#include "../headers/model/Vehicle.h"  //  Vehicle Class
#include "../headers/model/Track.h"

class TracksManager {

public:

    /*!
    * Construtor padr�o do gerenciador de tracks (necessario para inicializar no main)
    */
	TracksManager();

    /*!
    * Cria uma track e define seu nome, velocidade padr�o e tamanho
    * Adiciona a track na lista de tracks
    */
	void createTrack(std::string track_name, int velocity, int size);

    /*!
    * Troca veiculos de tracks
    * Utiliza endere�os e ponteiros para simplificar
    * Realiza as fun��es diretamente nos objetos da lista e n�o em copias deles
    * Assim n�o � necessario remover e adicionar objetos
    */
	void switchTrack(Track &track_out, Track &track_in);

    /*!
    * Adiciona um veiculo em uma track especifica
    * Utiliza endere�os e ponteiros para simplificar
    * Realiza a fun��o de adicionar um veiculo diretamente nos objetos da lista
    * Assim n�o � necessario remover e adicionar objetos
    */
	void vehicleIsBorn(Track &track);

    /*!
    * Remove um veiculo PARA SEMPRE de uma track especifica
    * Utiliza endere�os e ponteiros para simplificar
    * Realiza a fun��o de adicionar um veiculo diretamente nos objetos da lista
    * Assim n�o � necessario remover e adicionar objetos
    */
	void vehicleDies(Track &track);

    /*!
    * Adiciona um semaforo em uma track especifica
    * Utiliza endere�os e ponteiros para simplificar
    * Realiza a fun��o de adicionar um semaforo diretamente nos objetos da lista
    * Assim n�o � necessario remover e adicionar objetos
    * Tamb�m � utilizado um endere�o para um semaforo pois:
    * Os semaforos est�o em constante mudan�a de estados no semaphoresmanager.
    * Mais facil ter um pointeiro apontando pra um semaforo
    * Assim n�o � preciso altera-lo na lista all_tracks qnd ele mudar o estado
    */
	void putSemaphoreOnTrack(Track &track, Semaphore &semaphore, int left, int straight, int right);

    /*!
    * Metodo que sera utilizado pelo clock ou main (ainda nao sabemos)
    * Retorna o endere�o de uma track especifica (Caso exista)
    * No fim este metodo serve para:
    * As fun��es que necessitam do endere�o da track nesta mesma classe
    */
	Track& getSpecificTrack(std::string name);

    /*!
     * Retorna o num de pistas
    */
	int numOfTracks();

	void TracksManager::timeToSwitch();

private:

	structures::LinkedList<Track> all_tracks;
};


#endif
