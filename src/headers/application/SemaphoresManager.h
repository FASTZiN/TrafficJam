#ifndef HEADERS_SEMAPHORESMANAGER_H_
#define HEADERS_SEMAPHORESMANAGER_H_

#include "./Semaphore.h"

class SemaphoresManager {
public:

	SemaphoresManager();
	void createSemaphore(std::string name, int green_time, int red_time, Track track_in, Track left,Track straight , Track right, int left, int straight, int right);
	void changeState(int pointers);  // Poiters -> Todos {0 = norte, 1 = oeste, 2 = sul, 3 = leste}
	Semaphore getSpecificSemaphore(std::string name);

private:

	structures::LinkedList<Track> all_semaphores;
};

#endif
