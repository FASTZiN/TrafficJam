#include "./TracksManager.h"

TracksManager::TracksManager() {
	all_tracks = new structures::LinkedList<Track>();
	semaphore_manager = NULL;
}

void TracksManager::createTrack(int type, std::string track_name, int velocity, int size) {
	Track track = new Track(type, track_name, velocity, size);
	all_tracks.push_back(track);

}

void TracksManager::SwitchTrack(std::string track_out, std::string track_in) {
	this->getSpecificTrack(track_out).pushVehicle(this->getSpecificTrack(track_in).popVehicle());
}

void TracksManager::VehicleIsBorn(std::string name) {
	this->getSpecificTrack(name).pushVehicle();

}

void TracksManager::VehicleDies(std::string name) {
	this->getSpecificTrack(name).popVehicle();
}

void TracksManager::putSemaphoreOnTrack(std::string name, Semaphore semaphore) {
	this->getSpecificTrack(name).setSem(semaphore);
}

Track TracksManager::getSpecificTrack(std::string name) {
	for (int i = 0; i < all_tracks.size(); i++) {
		Track trackaux = all_tracks.at(i);
		if (trackaux.getName() == name) {
			return trackaux;
			break;
		}
	}
	throw std::out_of_range ("There's no track with this name");
}

