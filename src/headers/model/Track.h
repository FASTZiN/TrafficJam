// Copyright David Grunheidt 2017
#ifndef TRAFFICJAM_TRACK_H
#define TRAFFICJAM_TRACK_H

#include <stdexcept>  // C++ Exceptions
#include "../headers/model/Vehicle.h"  //  Vehicle Class
#include "../library/LinkedQueue.h"  //  LinkedQueue structure
#include "../library/ArrayList.h"  //  ArrayList structure
#include "../headers/model/Semaphore.h"  //  Semaphore Class

class Track {
public:

    /*!
    * Construtor padrão da track.
    * Seta size, velocity = 0 e o resto = NULL
    */
	Track();

    /*!
    * Construtor com parametros da track
    * Define o nome, a velocidade padrao e o tamanho da pista
    * Seta o resto para NULL
    */
	Track(std::string track_name, int velocity, int size);

    /*!
    * Cria um veiculo em pistas fontes (tamanho randomico)
    * Chama a função PushVehicle com argumentos (reutilização de codigo) e passa o veiculo como argumento
    */
	void pushVehicle();

    /*!
    * Função utilizada p adicionar um veiculo quando este for trocar de pista
    * Verifica se a posição do ultimo veiculo + o tamanho do veiculo atual é maior que o tamanho da pista
    * Verifica se a pista esta cheia.
    * Caso os dois sejam falsos:(Seta posicao = tamanho da pista e vel = vel da pista)
    * Adiciona o veiculo na lista de veiculos
    */
	void pushVehicle(Vehicle vehicle);

    /*!
    * Retira o primeiro veiculo da pista
    * Só é usado quando um veiculo for deletado ou quando for trocar de pistas
    */
	Vehicle popVehicle();

    /*!
     * Verifica se a pista esta cheia
    */
	bool fullTrack();

    /*!
    * Seta um semaforo na pista
    * Dentro do metodo também é setado as possibilidades de direção diretamente na lista de semaforos no semaphorosmanager
    * Também é setado os tracks diretamente na lista de semaforos no semaphorosmanager
    * Isso só é possivel porque é passado como argumento o endereço  para um semaforo
    */
	void setSemaphore(Semaphore &semaphore, int left, int straight, int right);

    /*!
    * Define as pistas de saida da presente pista
    * Só é usado para pistas que não forem sumidouras
    */
	void setOutWays(Track left,Track straight , Track right);

    /*!
    * Retorna as pistas de saida da presente pista
    * Indice 1 = left, indice 2 = straight, indice 3 = right
    */
	structures::ArrayList<Track> getOutWays();

    /*!
    * Retorna o nome da presente pista (Usado no TracksManager para achar determinada pista)
    */
	std::string getName();

    /*!
    * Muda a posição do veiculo diretamente na vehicle_list
    * Por isso precisa do endereço do veiculo como parametro
    */
	void changeVehiclePosition(const Vehicle &vehicle, int position);

    /*!
    * Muda a direcao do veiculo diretamente na vehicle_list
    * Por isso precisa do endereço do veiculo como parametro
    */
	void changeVehicleDirection(const Vehicle &vehicle);

    /*!
    * Muda a velocidade do veiculo diretamente na vehicle_list
    * Por isso precisa do endereço do veiculo como parametro
    */
	void changeVehicleVelocity(const Vehicle &vehicle);

    /*!
    * Informa o endereço do veiculo no index X da lista de veiculos
    */
	Vehicle& vehicleAt(int index);

private:

	int size, velocity;
	structures::LinkedQueue<Vehicle> vehicle_list{};
	structures::ArrayList<Track> out_ways{3};
	std::string track_name;
	Semaphore *semaphore;

};
// Fim da classe track.
