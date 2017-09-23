
#ifndef HEADERS_TRACKSMANAGER_H_
#define HEADERS_TRACKSMANAGER_H_

#include "./Vehicle.h"  //  Vehicle Class
#include "./SemaphoresManager.h"  //  SemaphoreManager Class

class TracksManager {

public:

    /*!
    * Construtor padrão do gerenciador de tracks (necessario para inicializar no main)
    */
	TracksManager();

    /*!
    * Cria uma track e define seu nome, velocidade padrão e tamanho
    * Adiciona a track na lista de tracks
    */
	void createTrack(std::string track_name, int velocity, int size);

    /*!
    * Troca veiculos de tracks
    * Utiliza endereços e ponteiros para simplificar
    * Realiza as funções diretamente nos objetos da lista e não em copias deles
    * Assim não é necessario remover e adicionar objetos
    */
	void switchTrack(Track &track_out, Track &track_in);

    /*!
    * Adiciona um veiculo em uma track especifica
    * Utiliza endereços e ponteiros para simplificar
    * Realiza a função de adicionar um veiculo diretamente nos objetos da lista
    * Assim não é necessario remover e adicionar objetos
    */
	void vehicleIsBorn(Track &track);

    /*!
    * Remove um veiculo PARA SEMPRE de uma track especifica
    * Utiliza endereços e ponteiros para simplificar
    * Realiza a função de adicionar um veiculo diretamente nos objetos da lista
    * Assim não é necessario remover e adicionar objetos
    */
	void vehicleDies(Track &track);

    /*!
    * Adiciona um semaforo em uma track especifica
    * Utiliza endereços e ponteiros para simplificar
    * Realiza a função de adicionar um veiculo diretamente nos objetos da lista
    * Assim não é necessario remover e adicionar objetos
    * Também é utilizado um endereço para um semaforo pois:
    * Os semaforos estão em constante mudança de estados no semaphoresmanager.
    * Mais facil ter um pointeiro apontando pra um semaforo
    * Assim não é preciso altera-lo na lista all_tracks qnd ele mudar o estado
    */
	void putSemaphoreOnTrack(Track &track, Semaphore &semaphore);

    /*!
    * Metodo que sera utilizado pelo clock ou main (ainda nao sabemos)
    * Retorna o endereço de uma track especifica (Caso exista)
    * No fim este metodo serve para:
    * As funções que necessitam do endereço da track nesta mesma classe
    */
	Track& getSpecificTrack(std::string name);

private:

	structures::LinkedList<Track> all_tracks;
	SemaphoresManager semaphore_manager;
};


#endif
