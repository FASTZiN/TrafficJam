#include "./Clock.h"

 Clock::Clock(){

}

 Clock::~Clock(){

 }

 void Clock::carArrivel(Track track){
	 track.pushCar()
 }

 void Clock::semaphoreChange(SemaphoresManager controller){
	 controller.changeState();
  }

 void Clock::changeTrack(TracksManager controller, Vehicle Car, Track out, Track in){
	 controller.SwitchTrack(Vehicle Car, Track out, Track in);
  }

 void Clock::semaphoreArrivel(){

  }

