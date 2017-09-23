#ifndef HEADERS_CLOCK_H_
#define HEADERS_CLOCK_H_

#include <cstdint>
#include <stdexcept>
#include <string>
#include "./SemaphoresManager.h"
#include "./TracksManager.h"

using namespace std;
class Clock{
 public:
	Clock();
	Clock(string function, int timer);
	void vehicleArrivel(Track &track);
	void semaphoreChange();
	void changeTrack(Track &track_out, Track &track_in);
	void semaphoreArrivel();
 private:
  SemaphoresManager controller;
  TracksManager control;
  string function;
  int timer;
};
#endif
