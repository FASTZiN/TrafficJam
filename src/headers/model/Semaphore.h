#ifndef MODEL_SEMAPHORE_H_
#define MODEL_SEMAPHORE_H_

#include <stdexcept>  // C++ Exceptions
#include "./LinkedQueue.h"
#include "./Track.h"
#include "./ArrayList.h"

class Semaphore {
public:

	Semaphore();
	Semaphore(std::string name, int green_time, int red_time);
	void setPossibilities(int left, int straight, int right);
	void setTrackIn(Track track_in);
	void setTracksOut(Track left,Track straight , Track right);
	void setState(int state);
	void setNextState();
	structures::ArrayList<Track> getTracksOut();
	structures::ArrayList<int> getDirectionsPossibilities();
	int getState();
	int getGreenTime();
	int getYellowTime();
	int getRedTime();
	int getPoiting();
	std::string getName();

private:

	int actual_state, green_time, red_time, poiting;   // Poiting -> 0 = norte, 1 = oeste, 2 = sul, 3 = leste
	Track track_in;
	structures::ArrayList<int> directions_possibilities{3u}, tracks_out{3u};
	std::string name;
};

#endif
