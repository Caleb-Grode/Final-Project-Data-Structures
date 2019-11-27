#ifndef EMERGENCYROOM_H
#define EMERGENCYROOM_H
#include <queue>
#include <vector>
#include "person.h"

class EmergencyRoom

{
public:
	EmergencyRoom();

private:
	std::vector<person *> residents; //holds the 2000 persons that are in the town of Simville
	//vector of doctors
	//vector of nurses
	std::priority_queue<person *> wait_room;
	   	   
};





#endif // !EMERGENCYROOM_H
