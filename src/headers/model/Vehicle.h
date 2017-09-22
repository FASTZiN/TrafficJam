// Copyright David Grunheidt 2017
#ifndef MODEL_VEHICLE_H
#define MODEL_VEHICLE_H

#include "./ArrayList.h"  // ArrayList structure

class Vehicle {
public:

	Vehicle();
	int getTamanho();
	void setVelocidade(int velocity);
	void generateDirection(structures::ArrayList<Vehicle> out_ways,
			structures::ArrayList<int> directions_possibilities);
	int getDirection(); // Direction -> { 0 = left, 1 = straight, 2 = right, 3 = stop}

private:

	static const auto DEFAULT_SIZE = 3u;
	int size, velocity, position, direction = 1;

};
// Fim da classe Carro.
#endif
