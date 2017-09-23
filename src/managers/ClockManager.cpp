/*
 * ClockManager.cpp
 *
 *  Created on: 22/09/2017
 *      Author: fastzin
 */

#include "./ClockManager.h"
ClockManager::ClockManager(){
	eventList = NULL;
}

void ClockManager::changeSemaphore(int timer){
	if(timer % 5 == 0){
		clock.semaphoreChange();
		Clock clockEvent = new Clock("changeSemaphore", timer);
		eventList.push_back(clockEvent);
	}
}

void ClockManager::carArrival(Track o1l, Track n1s, Track s1n, Track n2s, Track s2n, Track l1o, int timer){
	if(timer == 0){
		clock.carArrivel(o1l);
		clock.carArrivel(n1s);
		clock.carArrivel(s1n);
		clock.carArrivel(s2n);
		clock.carArrivel(n2s);
		clock.carArrivel(l1o);
		Clock clockEvent = new Clock("carArrivel", timer);
		eventList.push_back(clockEvent);
	} else {
	if (timer % 10 == 0) {
		clock.carArrivel(o1l);
		clock.carArrivel(l1o);
		Clock clockEvent = new Clock("carArrivel", timer);
		eventList.push_back(clockEvent);
	} else if (timer % 20 == 0) {
		clock.carArrivel(n1s);
		clock.carArrivel(n2s);
	} else if (timer % 30 == 0) {
		clock.carArrivel(s1n);
	} else if (timer % 60 == 0) {
		clock.carArrivel(s2n);
	}
  }
}

structures::LinkedList ClockManager::eventsList(){
	return eventList;
}


