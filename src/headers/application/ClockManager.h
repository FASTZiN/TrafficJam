#ifndef TRAFFICJAM_CLOCK_MANAGER_H
#define TRAFFICJAM_CLOCKMANAGER_H

#include "../headers/model/Clock.h"
#include "../headers/library/LinkedList.h"
#include "../headers/model/Track.h"

class ClockManager {
public:

	ClockManager();
	void changeSemaphore(int timer);
	void vehicleArrival(Track &o1l, Track &n1s, Track &s1n, Track &n2s, Track &s2n, Track &l1o, int timer);
	structures::LinkedList eventsList();

private:
	Clock clock;
	structures::LinkedList<Clock> eventList;
}
#endif /* HEADERS_APPLICATION_CLOCKMANAGER_H_ */

