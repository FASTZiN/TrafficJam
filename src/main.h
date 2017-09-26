#ifndef MAIN_H_
#define MAIN_H_

#include "../library/LinkedList.h"
#include "../headers/model/Event.h"
#include "../headers/application/SemaphoresManager.h"
#include "../headers/application/TracksManager.h"
#include "../library/LinkedList.h"

class main {
	SemaphoresManager semaphores_manager;
	TracksManager tracks_manager;
	structures::LinkedList<Event> clock { };

	int main(int argc, char *argv[]) {
		tracks_manager = new TracksManager();
		semaphores_manager = new SemaphoresManager();

		tracks_manager.createTrack("N1sul", 60, 500);
		tracks_manager.createTrack("N1norte", 60, 500);
		tracks_manager.createTrack("N2sul", 40, 500);
		tracks_manager.createTrack("N1sul", 60, 500);
		tracks_manager.createTrack("S1sul", 60, 500);
		tracks_manager.createTrack("S1norte", 60, 500);
		tracks_manager.createTrack("S2sul", 40, 500);
		tracks_manager.createTrack("S2norte", 40, 500);
		tracks_manager.createTrack("O1oeste", 80, 2000);
		tracks_manager.createTrack("O1leste", 80, 2000);
		tracks_manager.createTrack("C1oeste", 60, 300);
		tracks_manager.createTrack("C1leste", 60, 300);
		tracks_manager.createTrack("L1oeste", 80, 400);
		tracks_manager.createTrack("L1leste", 80, 400);

		semaphores_manager.createSemaphore("N1sul", 5, 5, 0);
		semaphores_manager.createSemaphore("N2sul", 5, 5, 0);
		semaphores_manager.createSemaphore("S1norte", 5, 5, 2);
		semaphores_manager.createSemaphore("S2norte", 5, 5, 2);
		semaphores_manager.createSemaphore("C1oeste", 5, 5, 3);
		semaphores_manager.createSemaphore("L1oeste", 5, 5, 3);
		semaphores_manager.createSemaphore("O1leste", 5, 5, 1);
		semaphores_manager.createSemaphore("C1leste", 5, 5, 1);

		tracks_manager.putSemaphoreOnTrack(
				tracks_manager.getSpecificTrack("N1sul"),
				semaphores_manager.getSpecificSemaphore("N1sul"), 80, 10, 10);
		tracks_manager.putSemaphoreOnTrack(
				tracks_manager.getSpecificTrack("N2sul"),
				semaphores_manager.getSpecificSemaphore("N2sul"), 40, 30, 30);
		tracks_manager.putSemaphoreOnTrack(
				tracks_manager.getSpecificTrack("S1norte"),
				semaphores_manager.getSpecificSemaphore("S1norte"), 10, 10, 80);
		tracks_manager.putSemaphoreOnTrack(
				tracks_manager.getSpecificTrack("S2norte"),
				semaphores_manager.getSpecificSemaphore("S2norte"), 30, 30, 40);
		tracks_manager.putSemaphoreOnTrack(
				tracks_manager.getSpecificTrack("C1oeste"),
				semaphores_manager.getSpecificSemaphore("C1oeste"), 30, 40, 30);
		tracks_manager.putSemaphoreOnTrack(
				tracks_manager.getSpecificTrack("L1oeste"),
				semaphores_manager.getSpecificSemaphore("L1oeste"), 30, 30, 40);
		tracks_manager.putSemaphoreOnTrack(
				tracks_manager.getSpecificTrack("O1leste"),
				semaphores_manager.getSpecificSemaphore("O1leste"), 10, 80, 10);
		tracks_manager.putSemaphoreOnTrack(
				tracks_manager.getSpecificTrack("C1leste"),
				semaphores_manager.getSpecificSemaphore("C1leste"), 30, 40, 30);

		for (int i = 0; i < 60; i++) {
			if (i == 59) {
				i = 0;
				clock.~LinkedList();
				structures::LinkedList<Event> new_clock { };
				clock = new_clock;
			}

			tryAddCarInAllTracks();
		}

	}
	void tryAddCarInAllTracks () {
		for (int i = 0; i < tracks_manager.numOfTracks(); i++) {
			tracks_manager.vehicleIsBorn(tracks_manager.getSpecificTrack(i)))
		}
	}
};

#endif /* MAIN_H_ */
