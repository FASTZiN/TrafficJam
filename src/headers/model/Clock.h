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
	Clock(std::string function, int timer);
	Clock(SemaphoresManager &semaphores_manager, TracksManager &tracks_manager);
	void vehicleArrivel(Track &track);
	void vehicleDies(Track &track);
	void semaphoreChange();
	void changeTrack(Track &track_out, Track &track_in);
	bool semaphoreArrivel(std::string track_name);
 private:
  SemaphoresManager *sem_manager_pointer;
  TracksManager *track_manager_pointer;
  string function;
  int timer;
};
#endif
