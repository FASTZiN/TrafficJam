#include "../headers/application/SemaphoresManager.h"

SemaphoresManager::SemaphoresManager() {
	all_semaphores = new structures::LinkedList<Track>();
	actual_stage = -1;
}

void SemaphoresManager::createSemaphore(std::string name, int green_time,int red_time, int pointing) {
	Semaphore semaphore = new Semaphore(name, green_time, red_time, pointing);
	all_semaphores.push_back(semaphore);
}

void SemaphoresManager::changeStage() {
	switch (actual_stage) {
		default:
			this->openPointersSem(4);
			break;
		case 0:
			this->openPointersSem(0);
			break;
		case 1:
			this->openPointersSem(1);
			break;
		case 2:
			this->openPointersSem(2);
			break;
		case 3:
			this->openPointersSem(3);
			break;
	}
}

Semaphore& SemaphoresManager::getSpecificSemaphore(std::string name) {
	for (int i = 0; i < all_semaphores.size(); i++) {
		if (all_semaphores.at(i).getName() == name) {
			return all_semaphores.at(i);
			break;
		}
	}
	throw std::out_of_range ("There's no semaphore with this name");  // Caso percorra todo o for significa que não achou nenhum com o nome
}

void SemaphoresManager::nextStage() {
	actual_stage++;
	if (actual_stage == 5)
		actual_stage = 0;
}

int SemaphoresManager::getActualStage() {
	return actual_stage;
}

void SemaphoresManager::openPointersSem(int pointing)  {
	for (int i = 0; i < all_semaphores.size(); i++) {
		Semaphore *semaphore = all_semaphores.at(i);
		if (semaphore->getPointing() == pointing)
			semaphore->setState(1);
		else
			semaphore->setState(0);
	}
}

