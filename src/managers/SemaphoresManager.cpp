#include "./SemaphoresManager.h"

SemaphoresManager::SemaphoresManager() {
	all_semaphores = new structures::LinkedList<Track>();
}

void SemaphoresManager::createSemaphore(std::string name, int green_time,int red_time, Track track_in, Track left_track, Track straight_track,Track right_track, int left, int straight, int right) {
	Semaphore semaphore = new Semaphore(name, green_time, red_time);
	semaphore.setTrackIn(track_in);
	semaphore.setTracksOut(left_track, straight_track, right_track);
	semaphore.setPossibilities(left, straight, right);
}

void SemaphoresManager::changeState() {
	switch (actual_state) {
		default:
			this->openPointerSem(4);
			break;
		case 0:
			this->openPointerSem(0);
			break;
		case 1:
			this->openPointerSem(1);
			break;
		case 2:
			this->openPointerSem(2);
			break;
		case 3:
			this->openPointerSem(3);
			break;
	}
}

Semaphore SemaphoresManager::getSpecificSemaphore(std::string name) {

}

void SemaphoresManager::nextState() {
	if(actual_state+1 == 5)
		actual_state = 0;
	else
		actual_state++;
}

int SemaphoresManager::getActualState() {

}

void SemaphoresManager::openPointerSem(int pointing)  {
	for (int i = 0; i < all_semaphores.size(); i++) {
		Semaphore semaphore = all_semaphores.at(i);
		if (semaphore.getPointing() == pointing)
			semaphore.setState(1);
		else
			semaphore.setState(0);
	}
}

