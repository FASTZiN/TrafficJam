#include "../headers/model/Track.h"  //  Track Class
#include "../headers/model/Semaphore.h"  //  Track Class

Track::Track() {
	track_name = NULL;
	size = 0;
	velocity = 0;
	semaphore = NULL;
	born_frequency = 0;
}

Track::Track(std::string track_name, int velocity, int size, int born_freq) {
	this->track_name = track_name;
	this->size = size;
	this->velocity = velocity;
	this->born_frequency = born_freq;
	semaphore = NULL;
}

void Track::pushVehicle() {
	Vehicle vehicle = new Vehicle();
	this->pushVehicle(vehicle);
}

void Track::pushVehicle(Vehicle vehicle) {
	Vehicle vehicle1 = vehicle;
	if (!(fullTrack()) || !(vehicle_list.back().position + vehicle.size > size)) {
		vehicle1.setPosition(size);
		vehicle1.setVelocity(velocity);
		vehicle_list.enqueue(vehicle);
	} else {
		throw std::out_of_range("This track is full, can't add a new vehicle");
	}
}

Vehicle Track::popVehicle() {
	if (!vehicle_list.empty()) {
		return vehicle_list.dequeue();
	} else {
		throw std::out_of_range("This track is empty, no vehicle to remove");
	}
}

bool Track::fullTrack() {
	return vehicle_list.size() == size;
}

void Track::setSemaphore(Semaphore &semaphore, int left, int straight, int right) {
	this->semaphore = semaphore;
	this->semaphore->setTracks(this->, this->out_ways);
	this->semaphore->setPossibilities(left, straight, right);
}

void Track::setOutWays(Track left,Track straight , Track right) {
	out_ways[0] = left;
	out_ways[1] = straight;
	out_ways[2] = right;
}

structures::ArrayList<Track> Track::getOutWays() {
	if (!out_ways == NULL) {
		return out_ways;
	} else {
		throw std::out_of_range("This track is END-LINE");
	}
}

std::string Track::getName() {
	return track_name;
}

void Track::changeVehiclePosition(const Vehicle &vehicle, int position) {
	if (vehicle_list.list.contains(vehicle)) {
		Vehicle *vehicle_pointer = vehicle;
		vehicle_pointer->CarMoves();
	} else {
		throw std::out_of_range ("This vehicle isn't on this track");
	}
}

void Track::changeVehicleDirection(const Vehicle &vehicle) {
	if (vehicle_list.list.contains(vehicle)) {
		Vehicle *vehicle_pointer = vehicle;

	} else {
		throw std::out_of_range ("This vehicle isn't on this track");
	}
}

void Track::changeVehicleVelocity(const Vehicle &vehicle) {
	if (vehicle_list.list.contains(vehicle)) {
		Vehicle *vehicle_pointer = vehicle;
		vehicle_pointer->setVelocity(this->velocity);
	} else {
		throw std::out_of_range ("This vehicle isn't on this track");
	}
}

Vehicle& Track::vehicleAt(int index) {
	return vehicle_list.list.at(index);
}

void Track::vehicleMoves(){
	for(auto i=0; i<vehicle_list.size(); i++){
		Vehicle *toMove = this->vehicleAt(i);
		if(toMove->getPosition() < size){
			toMove->CarMoves();
		}
	}
}

bool Track::vehicleAtSemaphore(){
	Vehicle *firstOnQueue = vehicle_list.front();

	if(firstOnQueue->getPosition() == firstOnQueue->getSize()){
		return true;
	} else {
		return false;
	}
}

int Track::whereVehicleGo(){
	if(vehicleAtSemaphore()){
		Vehicle *firstOnQueue = vehicle_list.front();
		firstOnQueue ->generateDirection(semaphore->getDirectionsPossibilities());
		return firstOnQueue->getDirection();
	}
	return -1;
}

Semaphore Track::getSemaphore(){
	return *semaphore;
}

structures::LinkedQueue<Vehicle> Track::getVehicleList() {
	return vehicle_list;
}

int Track::getBornFrequency() {
	return born_frequency;
}
