#include "../headers/model/Vehicle.h"

Vehicle::Vehicle() {
	size = 0;
	this->setSize();
	velocity = 0;
	position = 0;
}

void Vehicle::setSize() {
	srand(time(0));
	size = ((rand() % (4)) + 2) + 3; // Gera um randomico entre 3 e 6 e adiciona os 3 metros padrao.
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
	int direcao = 1 + (rand() % 10); // Gera um valor entre 0 e 9 somado a 1(intervalo de 0 a 1).
	if (direcao <= directions_possibilities.at(0)) { //  Verifica se eh menor ao probabilidade de virar a esquerda.
		direction = 0;
	} else {
		if (direcao <= directions_possibilities.at(1)) { //  Verifica se eh menor ao probabilidade de seguir reto
			direction = 1;
		} else {  //  Se nenhuma das anteriores for verdade, ele vira a direita
			direction = 2;
		}
	}
}

void Vehicle::CarMoves(){
	int move = round(velocity/3.6);

	position = position + move;
}

void Vehicle::setPosition(int position) {
	this->position = position;
}

int Vehicle::getDirection() {
	return direction;
}
int Vehicle::getSize() {
	return size;
}

int Vehicle::getPosition() {
	return position;
}


