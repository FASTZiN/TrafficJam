#include "../headers/model/Event.h"



	Event::Event(int i) {
		time_of_event = i;
	}

	void Event::vehicleBorns(Track &track, Vehicle &vehicle) {
		std::string vehicle_borns_event= ("Vehicle %d was born in track in time");
	}

	void Event::semaphoreStateChange(Semaphore &semaphore) {
		std::string semaphore_state_event= "";
	}

	void Event::vehicleIsInSemaphore(Track &track, Vehicle &vehicle) {
		std::string vehicle_on_semaphore_event= "";
	}

	void Event::vehicleChangedTrack(Track &track, Vehicle &vehicle) {
		std::string vehicle_change_track= "";
	}

	structures::LinkedList<std::string> Event::getEventList() {
		return this->event_list;
	}

