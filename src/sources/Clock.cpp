#include "../headers/model/Clock.h"

Clock::Clock(SemaphoresManager &semaphores_manager, TracksManager &tracks_manager) {
	function = NULL;
	timer = 0;
	track_manager_pointer = tracks_manager;
	sem_manager_pointer = semaphores_manager;
}

Clock::Clock(string function_, int timer_){
	function = function_;
	timer = timer_;
	track_manager_pointer = NULL;
	sem_manager_pointer = NULL;
}
 void Clock::vehicleArrivel(Track &track){
	 track_manager_pointer->vehicleIsBorn(track);
 }

 void Clock::vehicleDies(Track &track) {
	 track_manager_pointer->vehicleDies(track);
 }

 void Clock::semaphoreChange(){
	 sem_manager_pointer->changeStage();
  }

 void Clock::changeTrack(Track &track_out, Track &track_in){
	 track_manager_pointer->switchTrack(track_out, track_in);
  }

bool Clock::semaphoreArrivel(std::string track_name){
	 Track *track_pointer = track_manager_pointer->getSpecificTrack(track_name);
	 if (track_pointer->vehicleAtSemaphore())
		 return true;
	 else
		 return false;
  }
