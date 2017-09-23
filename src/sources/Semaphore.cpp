#include "../headers/model/Semaphore.h"

Semaphore::Semaphore() {
	actual_state = 0;
	green_time = 0;
	red_time = 0;
	pointing = -1;
	name = NULL;
}

Semaphore::Semaphore(std::string name, int green_time, int red_time, int pointing) {
	this->name = name;
	this->green_time = green_time;
	this->red_time = red_time;
	this->pointing = pointing;
	actual_state = 0;
}


void Semaphore::setPossibilities(int left, int straight, int right) {
		directions_possibilities[0] = left;
		directions_possibilities[1] = straight;
		directions_possibilities[2] = right;
}


void Semaphore::setState(int state) {
	this->actual_state = state;
}

void Semaphore::setTracks(Track track_in, structures::ArrayList<Track> tracks_out) {
	tracks[0] = track_in;
	tracks[1] = tracks_out[0];
	tracks[2] = tracks_out[1];
	tracks[3] = tracks_out[2];
}

structures::ArrayList<int> Semaphore::getDirectionsPossibilities() {
	return directions_possibilities;
}

int Semaphore::getState() {
	return actual_state;
}

int Semaphore::getGreenTime() {
	return green_time;
}


int Semaphore::getRedTime() {
	return red_time;
}

std::string Semaphore::getName() {
	return name;
}

int Semaphore::getPointing() {
	return pointing;
}

