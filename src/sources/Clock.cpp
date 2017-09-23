#include "./Clock.h"
Clock::Clock(){
	function = NULL;
	timer = 0;
}

Clock::Clock(string function_, int timer_){
	function = function_;
	timer = timer_;
}
 void Clock::carArrivel(Track track){
	 track.pushVehicle();
 }

 void Clock::semaphoreChange(){
	 controller.changeState();
  }

 void Clock::changeTrack(Vehicle Car, Track out, Track in){
	 control.SwitchTrack(Vehicle vehicle, Track out, Track in);
  }

 void Clock::semaphoreArrivel(){

  }

