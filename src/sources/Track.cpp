#include "./Track.h"  //  Track Class

Track::Track() {
	track_name = NULL;
	size = 0;
	velocity = 0;
	out_ways_number = 0;
	semaphore = NULL;
}

Track::Track(int type, std::string track_name, int velocity, int size) {
	this->track_name = track_name;
	this->size = size;
	this->velocity = velocity;
	semaphore = NULL;
	out_ways_number = this->defineOutWaysNumber(type);
}
void Track::pushVehicle() {
	Vehicle vehicle = new Vehicle();
	vehicle.setPosition(size);

}

void Track::pushVehicle(Vehicle Vehicle) {

}

Vehicle Track::popVehicle() {

}

bool Track::fullTrack() {

}

void Track::setSem(Semaphore semaphore) {

}

void Track::setOutWays(structures::ArrayList<Track> out_ways) {

}

structures::ArrayList<Track> Track::getOutWays() {

}

std::string Track::getName() {

}

int Track::defineOutWaysNumber() {

}

