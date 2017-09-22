
#ifndef HEADERS_TRACKSMANAGER_H_
#define HEADERS_TRACKSMANAGER_H_

#include "./Vehicle.h"  //  Vehicle Class
#include "./SemaphoresManager.h"  //  SemaphoreManager Class

class TracksManager {

public:

	TracksManager();
	void createTrack(int type, std::string track_name, int velocity, int size);
	void SwitchTrack(std::string track_out, std::string track_in);
	void VehicleIsBorn(std::string name);
	void VehicleDies(std::string name);
	void putSemaphoreOnTrack(std::string name, Semaphore semaphore);
	Track getSpecificTrack(std::string name);

private:

	structures::LinkedList<Track> all_tracks;
	SemaphoresManager semaphore_manager;
};


#endif
