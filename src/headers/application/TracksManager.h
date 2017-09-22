
#ifndef HEADERS_TRACKSMANAGER_H_
#define HEADERS_TRACKSMANAGER_H_

#include "./Vehicle.h"  //  Vehicle Class
#include "./SemaphoresManager.h"  //  SemaphoreManager Class

class TracksManager {

public:

	TracksManager();
	void createTrack(int type, std::string track_name, int velocity, int size);
	void SwitchTrack(Vehicle vehicle,Track track_out, Track track_in);
	void VehicleIsBorn(Vehicle vehicle, Track track_in);
	void VehicleDies(Vehicle vehicle, Track actual_track);
	void putSemaphoreOnTrack(Track track, Semaphore semaphore);
	Track getSpecificTrack(std::string name);

private:

	structures::LinkedList<Track> all_tracks;
	SemaphoresManager semaphore_manager;
};


#endif
