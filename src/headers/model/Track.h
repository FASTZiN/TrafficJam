// Copyright David Grunheidt 2017
#ifndef MODEL_TRACK_H
#define MODEL_TRACK_H

#include "./Vehicle.h"  //  Vehicle Class
#include "./LinkedQueue.h"  //  LinkedQueue structure
#include "./ArrayList.h"  //  ArrayList structure
#include "./Semaphore.h"  //  Semaphore Class

class Track {
public:

	Track();
	Track(int type, std::string track_name, int velocity, int size);
	void pushVehicle();
	void pushVehicle(Vehicle Vehicle);
	Vehicle popVehicle();
	bool fullTrack();
	void setSem(Semaphore semaphore);
	void setOutWays(structures::ArrayList<Track> out_ways);
	structures::ArrayList<Track> getOutWays();
	std::string getName();

private:

	int size, velocity, out_ways_number;
	structures::LinkedQueue<Vehicle> Vehicle_list { };
	structures::ArrayList<Track> out_ways { out_ways_number };
	std::string track_name;
	Semaphore semaphore;
	int defineOutWaysNumber(int type);

};
// Fim da classe track.

#endif
