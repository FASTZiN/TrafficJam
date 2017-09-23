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

void SemaphoresManager::changeState(int pointers) {
	for (int i = 0; i < all_semaphores.size(); i++) {
		Semaphore semaphore = all_semaphores.at(i);
		if (semaphore.getPoiting() == pointers) {
			semaphore.
		}
	}
}
