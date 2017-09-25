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
    * Construtor padr�o da track.
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
    * Chama a fun��o PushVehicle com argumentos (reutiliza��o de codigo) e passa o veiculo como argumento
    */
	void pushVehicle();

    /*!
    * Fun��o utilizada p adicionar um veiculo quando este for trocar de pista
    * Verifica se a posi��o do ultimo veiculo + o tamanho do veiculo atual � maior que o tamanho da pista
    * Verifica se a pista esta cheia.
    * Caso os dois sejam falsos:(Seta posicao = tamanho da pista e vel = vel da pista)
    * Adiciona o veiculo na lista de veiculos
    */
	void pushVehicle(Vehicle vehicle);

    /*!
    * Retira o primeiro veiculo da pista
    * S� � usado quando um veiculo for deletado ou quando for trocar de pistas
    */
	Vehicle popVehicle();

    /*!
     * Verifica se a pista esta cheia
    */
	bool fullTrack();

    /*!
    * Seta um semaforo na pista
    * Dentro do metodo tamb�m � setado as possibilidades de dire��o diretamente na lista de semaforos no semaphorosmanager
    * Tamb�m � setado os tracks diretamente na lista de semaforos no semaphorosmanager
    * Isso s� � possivel porque � passado como argumento o endere�o  para um semaforo
    */
	void setSemaphore(Semaphore &semaphore, int left, int straight, int right);

    /*!
    * Define as pistas de saida da presente pista
    * S� � usado para pistas que n�o forem sumidouras
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
    * Muda a posi��o do veiculo diretamente na vehicle_list
    * Por isso precisa do endere�o do veiculo como parametro
    */
	void changeVehiclePosition(const Vehicle &vehicle, int position);

    /*!
    * Muda a direcao do veiculo diretamente na vehicle_list
    * Por isso precisa do endere�o do veiculo como parametro
    */
	void changeVehicleDirection(const Vehicle &vehicle);

    /*!
    * Muda a velocidade do veiculo diretamente na vehicle_list
    * Por isso precisa do endere�o do veiculo como parametro
    */
	void changeVehicleVelocity(const Vehicle &vehicle);

    /*!
    * Informa o endere�o do veiculo no index X da lista de veiculos
    */
	Vehicle& vehicleAt(int index);
	/*
	 * Move todos os vwiculos pela pista
	 */
	void vehicleMoves();
	/*!
	 * Verifica se existem algum veiculo no semaforo.
	 */
	bool vehicleAtSemaphore();

	/*!
	 * Retorna para onde o carro vai se ele estiver n semafaro
	 */
	int whereVehicleGo();
	/*!
	 * Retorna semafaro.
	 */
	Semaphore getSemaphore();

	/*!
	 * Retorna lista de veiculos.
	 */
	structures::LinkedQueue<Vehicle> getVehicleList();

private:

	int size, velocity;
	structures::LinkedQueue<Vehicle> vehicle_list{};
	structures::ArrayList<Track> out_ways{3};
	std::string track_name;
	Semaphore *semaphore;

};
// Fim da classe track.
