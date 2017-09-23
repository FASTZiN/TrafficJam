#ifndef TRAFFICJAM_CLOCK_H
#define TRAFFICJAM_CLOCK_H

#include <cstdint>
#include <stdexcept>
#include <string>
#include "../headers/application/SemaphoresManager.h"
#include "../headers/application/TracksManager.h"

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
