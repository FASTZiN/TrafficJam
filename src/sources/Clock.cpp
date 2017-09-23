#include "../headers/model/Clock.h"
Clock::Clock(){
	function = NULL;
	timer = 0;
}

Clock::Clock(string function_, int timer_){
	function = function_;
	timer = timer_;
}
 void Clock::vehicleArrivel(Track &track){
	 control.vehicleIsBorn(track);
 }

 void Clock::semaphoreChange(){
	 controller.changeStage();
  }

 void Clock::changeTrack(Track &track_out, Track &track_in){
	 control.switchTrack(track_out, track_in);
  }

 void Clock::semaphoreArrivel(){

  }
