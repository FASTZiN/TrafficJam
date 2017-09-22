#ifndef HEADERS_CLOCK_H_
#define HEADERS_CLOCK_H_

#include "./Clock.h"
#include <cstdint>
#include <stdexcept>
#include <chrono>

class Clock{
 public:
	Clock();
	~Clock();
	void carArrivel();
	void semaphoreChange();
	void changeTrack();
	void semaphoreArrivel();
 private:
	auto time;

};
#endif
