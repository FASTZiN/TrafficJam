#ifndef HEADERS_SEMAPHORESMANAGER_H_
#define HEADERS_SEMAPHORESMANAGER_H_

#include "./Semaphore.h"

class SemaphoresManager {
public:

	SemaphoresManager();
	void createSemaphore(std::string name, int green_time, int red_time, Track track_in, Track left,Track straight , Track right, int left, int straight, int right);
	void changeState();
	Semaphore getSpecificSemaphore(std::string name);
	void nextStage();
	int getActualState();

private:

	structures::LinkedList<Track> all_semaphores;
	int actual_state;  //  All { 0 = North Open, 1 = East Open, 2 == South Open, 3 == Least Open } Rest = Close, Others ==  All Close;
	void openPointerSem(int pointing);
};

#endif
