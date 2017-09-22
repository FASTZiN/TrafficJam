#include "./Vehicle.h"

Vehicle::Vehicle() {
size = DEFAULT_SIZE;
velocity = 0;
direction = 1;
position = 0
}

void Vehicle::setSize() {
		  srand(time(0));
	      size = ((rand()%(4)) + 2)+3; // Gera um randomico entre 3 e 6 e adiciona os 3 metros padrao.
}

void Vehicle::setVelocity(int velocity_) {
	velocity = velocity_;
}

/*
 * LEMBRENTE: QUANDO CRIAR A VETOR DE PROBILIDADE:
 *  EX:
 *    PROB[0] = 3 - 30% DE CHANCE
 *    PROB[1] = 7 - 40% DE CHANCE
 *    PROB[2] = 10 - 30% DE CHANCE
 *
 */
void Vehicle::generateDirection(structures::ArrayList<int> directions_possibilities) {
	srand(time(0));
	int direcao = ((rand()%9)+1; // Gera um valor entre 0 e 9 somado a 1(intervalo de 0 a 1)

	if(direcao <= directions_possibilities.at(0)){ //  Verifica se eh menor ao probabilidade de virar a esquerda.
		direction = 0;
	} else {
		if(direcao <= directions_possibilities.at(1)){  //  Verifica se eh menor ao probabilidade de seguir reto
			direction = 1;

		} else {  //  Se nenhuma das anteriores for verdade, ele vira a direita
			direction = 2;
		}
	}

int Vehicle::getDirection() {
	return direction;
}
int Vehicle::getSize() {
return size;
}

int Vehicle::getPosition() {
}


