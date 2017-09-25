#ifndef TRAFFICJAM_CLOCK_H
#define TRAFFICJAM_CLOCK_H

#include <cstdint>
#include <stdexcept>
#include <stdio.h>
#include <time.h>
#include "../library/LinkedList.h";
#include "../headers/model/Track.h"
#include "../headers/model/Vehicle.h"
#include "../headers/model/Semaphore.h"

using namespace std;
class Event{
 public:
	Event();
	void vehicleBorns(Track &track, Vehicle &vehicle);
	void semaphoreStateChange(Semaphore &semaphore);
	void vehicleIsInSemaphore(Track &track, Vehicle &vehicle);
	void vehicleChangedTrack(Track &track, Vehicle &vehicle);

 private:
	structures::LinkedList<std::string> event_list {};
	int time_of_event;
};
#endif
