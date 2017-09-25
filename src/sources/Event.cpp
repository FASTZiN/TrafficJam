#include "../headers/model/Event.h"



	Event::Event(int i) {
		time_of_event = i;
	}

	void Event::vehicleBorns(Track &track, Vehicle &vehicle) {
		std::string vehicle_borns_event= ("Vehicle %p was born in track %s in time %d", vehicle, track.getName(), time_of_event);
	}

	void Event::semaphoreStateChange(Semaphore &semaphore) {
		std::string semaphore_state_event= ("Semaphore %p has change state to %d in time %d", semaphore, semaphore.getState(), time_of_event);
	}

	void Event::vehicleIsInSemaphore(Track &track, Vehicle &vehicle) {
		std::string vehicle_on_semaphore_event= ("Vehicle %p was in semaphore on track %s in time %d", vehicle, track.getName(), time_of_event);
	}

	void Event::vehicleChangedTrack(Track &track, Vehicle &vehicle) {
		std::string vehicle_change_track= ("Vehicle %p change track to &s in time %d", vehicle, track.getName(), time_of_event);
	}

	structures::LinkedList<std::string> Event::getEventList() {
		return this->event_list;
	}

