#ifndef TRAFFICJAM_SEMAPHORES_MANAGER_H_
#define TRAFFICJAM_SEMAPHORES_MANAGER_H_

#include "../headers/model/Track.h"
#include "../headers/model/Semaphore.h"

class SemaphoresManager {
public:

    /*!
    * Construtor padr�o do gerenciador de semaforos (necessario para inicializar no main)
    */
	SemaphoresManager();

    /*!
    * Cria um semaforo e define:
    * Seu nome; Os Tempos das luzes verde e vermelho; Que dire��o controla (N,S,L,O);
    * Adiciona o semaforo na lista de semaforos
    */
	void createSemaphore(std::string name, int green_time, int red_time, int pointing);

    /*!
    * Muda o estado atual de TODOS os semaforos:
    * Estado 0: Todos que controlam as ruas da parte NORTE aberto e o resto fechados
    * Estado 1: Todos que controlam as ruas da parte OESTE aberto e o resto fechados
    * Estado 2: Todos que controlam as ruas da parte SUL aberto e o resto fechados
    * Estado 3: Todos que controlam as ruas da parte LESTE aberto e o resto fechados
    * Estado 4: Todos os semaforos fechados
    */
	void changeStage();

    /*!
    * Incrementa em uma unidade o atributo actual_stage
    * (SERA NECESSARIO UM LISTENER BASEADO NA LISTA DE EVENTOS PARA CHAMAR ESTA FUNCAO)
    * (SER� NECESSARIO TAMBEM UM LISTENER PARA MUDAN�A DE VALOR DO ACTUAL STAGE)
    * (ESTE LISTENER ENTAO CHAMA A FUNCAO QUE MUDA AS LUZES DO SEMAFORO)
    */
	void nextStage();

    /*!
    * Retorna o valor atual do actual_stage
    * Sera necessario na implementa��o do listener
    */
	int getActualStage();

    /*!
    * Retorna o endere�o de um semaforo especifico (Caso exista)
    * � de grande importancia no TracksManager, visto que:
    * Uma track possui um ponteiro pra um semaforo
    * Assim quando ele mudar, n�o � necessario alterar a variavel ponteiro em uma track.
    * Nem alterar a lista de todas as tracks no TracksManager, ou seja, simplifica!
    */
	Semaphore& getSpecificSemaphore(std::string name);

    /*!
     * Mesmo de cima porem com parametro index;
    */
	Semaphore& getSpecificSemaphore(int index);

private:

	structures::LinkedList<Semaphore> all_semaphores;
	int actual_stage;
	void openPointersSem(int pointing);
};

#endif
