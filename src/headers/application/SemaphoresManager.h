#ifndef HEADERS_SEMAPHORESMANAGER_H_
#define HEADERS_SEMAPHORESMANAGER_H_

#include "./Semaphore.h"

class SemaphoresManager {
public:

	SemaphoresManager();
	void createSemaphore(std::string name, int green_time, int red_time);
	void defineTracks(Track track_in, Track left,Track straight , Track right);
	void defPossibToSpeSem(std::string name, int left, int straight, int right);
	void changeState();
	Semaphore getSpecificSemaphore(std::string name);

private:

	structures::LinkedList<Track> all_semaphores;
};

#endif
