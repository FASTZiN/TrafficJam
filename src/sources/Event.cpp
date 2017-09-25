#include "../headers/model/Event.h"



	Event::Event() {
		time_of_event = 0;
	}

	void Event::vehicleBorns(Track &track, Vehicle &vehicle) {
		std::string vehicle_borns_event= "";
	}

	void Event::semaphoreStateChange(Semaphore &semaphore) {
		std::string semaphore_state_event= "";
	}

	void Event::vehicleIsInSemaphore(Track &track, Vehicle &vehicle, Semaphore &semaphore) {
		std::string vehicle_on_semaphore_event= "";
	}

	void Event::vehicleChangedTrack(Track &track, Vehicle &vehicle) {
		std::string vehicle_change_track= "";
	}

