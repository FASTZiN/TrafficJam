#ifndef HEADERS_CLOCK_H_
#define HEADERS_CLOCK_H_


#include <cstdint>
#include <stdexcept>
#include <chrono>
#include "./SemaphoresManager.h"
#include "./TracksManager.h"

class Clock{
 public:
	Clock();
	~Clock();
	void vehicleArrivel();
	void semaphoreChange();
	void changeTrack();
	void semaphoreArrivel();
 private:
	auto time;

};
#endif
