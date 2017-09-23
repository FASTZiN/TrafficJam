#include "./Semaphore.h"

Semaphore::Semaphore() {

}

Semaphore::Semaphore(std::string name, int green_time, int red_time) {

}

void Semaphore::setPossibilities(int left, int straight, int right) {

}

void Semaphore::setTrackIn(Track track_in) {

}
void Semaphore::setTracksOut(Track left,Track straight , Track right) {

}

void Semaphore::setState(int state) {

}

void Semaphore::setNextState() {

}

structures::ArrayList<Track> Semaphore::getTracksOut() {

}

structures::ArrayList<int> Semaphore::getDirectionsPossibilities() {

}

int Semaphore::getState() {

}

int Semaphore::getGreenTime() {

}

int Semaphore::getYellowTime() {

}

int Semaphore::getRedTime() {

}

std::string Semaphore::getName() {

}

int Semaphore::getPoiting() {
	return poiting;
}

