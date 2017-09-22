// Copyright David Grunheidt 2017
#ifndef MODEL_TRACK_H
#define MODEL_TRACK_H

#include <stdexcept>  // C++ Exceptions
#include "./Vehicle.h"  //  Vehicle Class
#include "./LinkedQueue.h"  //  LinkedQueue structure
#include "./ArrayList.h"  //  ArrayList structure
#include "./Semaphore.h"  //  Semaphore Class

class Track {
public:

	Track();
	Track(int type, std::string track_name, int velocity, int size);
	void pushVehicle();
	void pushVehicle(Vehicle vehicle);
	Vehicle popVehicle();
	bool fullTrack();
	void setSem(Semaphore semaphore);
	void setOutWays(structures::ArrayList<Track> out_ways);
	structures::ArrayList<Track> getOutWays();
	std::string getName();

private:

	int size, velocity;
	structures::LinkedQueue<Vehicle> vehicle_list { };
	structures::ArrayList<Track> out_ways;
	std::string track_name;
	Semaphore semaphore;

};
// Fim da classe track.
