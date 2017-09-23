/*
 * ClockManager.h
 *
 *  Created on: 22/09/2017
 *      Author: fastzin
 */

#ifndef HEADERS_APPLICATION_CLOCKMANAGER_H_
#define HEADERS_APPLICATION_CLOCKMANAGER_H_
#include "./Clock.h"
#include "./LinkedList.h"

class ClockManager{
 public:
void changeSemaphore(int timer);

void carArrival(Track o1l, Track n1s, Track s1n, Track n2s, Track s2n, Track l1o, int timer);

structures::LinkedList eventsList();
private:
 Clock clock;
 structures::LinkedList<Clock> eventList;
}
#endif /* HEADERS_APPLICATION_CLOCKMANAGER_H_ */
