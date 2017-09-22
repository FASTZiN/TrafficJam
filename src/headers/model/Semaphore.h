#ifndef MODEL_SEMAPHORE_H_
#define MODEL_SEMAPHORE_H_

#include "./LinkedQueue.h"
#include "./Track.h"
#include "./ArrayList.h"

class Semaphore {
public:

	Semaphore();
	Semaphore(std::string name, int green_time, int yellow_time, int red_time);
	void setPossibilities(int left, int straight, int right);
	void setTrackIn(Track track_in);
	void setTracksOut(Track left,Track straight , Track right);
	void setState(int state);
	void setNextState();
	structures::ArrayList<Track> getTracksOut();
	structures::ArrayList<Track> getDirectionsPossibilities();
	int getState();
	int getGreenTime();
	int getYellowTime();
	int getRedTime();
	std::string getName();

private:

	int actual_state, green_time, yellow_time, red_time;
	Track track_in;
	structures::ArrayList<int> directions_possibilities{3u}, tracks_out{3u};
	std::string name;
};

#endif
