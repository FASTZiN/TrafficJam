#include "./Track.h"  //  Track Class

Track::Track() {
	track_name = NULL;
	size = 0;
	velocity = 0;
	semaphore = NULL;
	out_ways = NULL;
	vehicle_list = NULL;
}

Track::Track(std::string track_name, int velocity, int size) {
	this->track_name = track_name;
	this->size = size;
	this->velocity = velocity;
	semaphore = NULL;
	out_ways = NULL;
	vehicle_list = NULL;

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

void Track::setSemaphore(Semaphore semaphore) {
	this->semaphore = semaphore;
}

void Track::setOutWays(structures::ArrayList<Track> out_ways) {
	this->out_ways = new structures::ArrayList[out_ways.size()];
	this->out_ways = out_ways;
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
		vehicle_pointer->setPosition(position);
	} else {
		throw std::out_of_range ("This vehicle isn't on this track");
	}
}

void Track::changeVehicleDirection(const Vehicle &vehicle) {
	if (vehicle_list.list.contains(vehicle)) {
		Vehicle *vehicle_pointer = vehicle;
		vehicle_pointer->generateDirection(this->semaphore.getDirectionsPossibilities());
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
