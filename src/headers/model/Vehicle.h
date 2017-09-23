// Copyright David Grunheidt 2017
#ifndef MODEL_VEHICLE_H
#define MODEL_VEHICLE_H

#include <stdexcept>  // C++ Exceptions
#include "./ArrayList.h"  // ArrayList structure
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>// necessário p/ as funções rand() e srand()
#include <time.h>//necessário p/ função time()

class Vehicle {
public:

	Vehicle();
	void setSize();
	void setVelocity(int velocity);
	void generateDirection(structures::ArrayList<int> directions_possibilities);
	int getDirection(); // Direction -> { 0 = left, 1 = straight, 2 = right}
	int getSize();
	void setPosition(int position);
	int getPosition();

private:

	static const auto DEFAULT_SIZE = 3u;
	int size, velocity, position, direction = 1;

};
// Fim da classe Carro.
#endif
