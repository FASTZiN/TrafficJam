#ifndef HEADERS_CLOCK_H_
#define HEADERS_CLOCK_H_

#include <cstdint>
#include <stdexcept>
#include <string>

using namespace std;
class Clock{
 public:
	Clock();
	Clock(string function, int timer);
	void vehicleArrivel(Track track);
	void semaphoreChange();
	void changeTrack(Vehicle vehicle, Track out, Track in);
	void semaphoreArrivel();
 private:
  SemaphoresManager controller;
  TracksManager control;
  string function;
  int timer;
};
#endif
