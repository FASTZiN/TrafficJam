#include "./Clock.h"

 Clock::Clock(){

}

 Clock::~Clock(){

 }

 void Clock::vehicleArrivel(Track track){
	 track.pushVehicle();
 }

 void Clock::semaphoreChange(SemaphoresManager controller){
	 controller.changeState();
  }

 void Clock::changeTrack(TracksManager controller, Vehicle car, Track out, Track in){
	 controller.SwitchTrack(car, out, in);
  }

 void Clock::semaphoreArrivel(){

  }

