#include "./TracksManager.h"

TracksManager::TracksManager() {
	all_tracks = new structures::LinkedList<Track>();
	semaphore_manager = NULL;
}

void TracksManager::createTrack(std::string track_name, int velocity, int size) {
	Track track = new Track(track_name, velocity, size);
	all_tracks.push_back(track);

}

void TracksManager::switchTrack(Track &track_out, Track &track_in) {
	if (all_tracks.contains(track_out) && all_tracks.contains(track_in)) {
		Track *track_out_pointer = track_out, *track_in_pointer = track_in;
		track_in_pointer->pushVehicle(track_out_pointer->popVehicle());
	} else {
		throw std::out_of_range ("Those tracks aren't on the tracks list");
	}
}

void TracksManager::vehicleIsBorn(Track &track) {
	if (all_tracks.contains(track)) {
		Track *track_pointer = track;
		*track_pointer->pushVehicle();
	} else {
		throw std::out_of_range ("This track isn't on your list");
	}
}

void TracksManager::vehicleDies(Track &track) {
	if (all_tracks.contains(track)) {
		Track *track_pointer = track;
		*track_pointer->popVehicle();
	} else {
		throw std::out_of_range ("This track isn't on your list");
	}
}

void TracksManager::putSemaphoreOnTrack(Track &track, Semaphore &semaphore) {
	if (all_tracks.contains(track)) {
		Track *track_pointer = track;
		*track_pointer->setSemaphore(semaphore);
	} else {
		throw std::out_of_range ("This track isn't on your list");
	}
}

Track& TracksManager::getSpecificTrack(std::string name) {
	for (int i = 0; i < all_tracks.size(); i++) {
		if (all_tracks.at(i).getName() == name) {
			return all_tracks.at(i);
			break;
		}
	}
	throw std::out_of_range ("There's no track with this name");
}

