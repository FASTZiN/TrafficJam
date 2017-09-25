/*
 * ClockManager.cpp
 *
 *  Created on: 22/09/2017
 *      Author: fastzin
 */

#include "../headers/application/ClockManager.h"

ClockManager::ClockManager(SemaphoresManager &semaphores_manager, TracksManager &tracks_manager) {
	eventList = NULL;
	clock = new Clock(SemaphoresManager &semaphores_manager, TracksManager &tracks_manager);
}

void ClockManager::changeSemaphore(int timer){
	if(timer % 5 == 0){
		clock.semaphoreChange();
		Clock clockEvent = new Clock("changeSemaphore", timer);
		eventList.push_back(clockEvent);
	}
}

void ClockManager::vehicleArrival(Track &o1l, Track &n1s, Track &s1n, Track &n2s, Track &s2n, Track &l1o, int timer){
	if(timer == 0){
		clock.vehicleArrivel(o1l);
		clock.vehicleArrivel(n1s);
		clock.vehicleArrivel(s1n);
		clock.vehicleArrivel(s2n);
		clock.vehicleArrivel(n2s);
		clock.vehicleArrivel(l1o);
		Clock clockEvent = new Clock("carArrivel", timer);
		eventList.push_back(clockEvent);
	} else {
	if (timer % 10 == 0) {
		clock.vehicleArrivel(o1l);
		clock.vehicleArrivel(l1o);
		Clock clockEvent = new Clock("carArrivel", timer);
		eventList.push_back(clockEvent);
	} else if (timer % 20 == 0) {
		clock.vehicleArrivel(n1s);
		clock.vehicleArrivel(n2s);
	} else if (timer % 30 == 0) {
		clock.vehicleArrivel(s1n);
	} else if (timer % 60 == 0) {
		clock.vehicleArrivel(s2n);
	}
  }
}

structures::LinkedList ClockManager::eventsList(){
	return eventList;
}


