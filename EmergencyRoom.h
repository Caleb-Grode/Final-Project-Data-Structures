#ifndef EMERGENCYROOM_H
#define EMERGENCYROOM_H
#include <queue>
#include <vector>
#include "person.h"
#include <iostream>
//changed
class EmergencyRoom

{
public:
	EmergencyRoom();
	void addPatient(person * p); //probably use with arrival object?

private:
	std::vector<person *> residents; //holds the 2000 persons that are in the town of Simville (maybe change to a map or set etc to meet requirments of project
	//vector of doctors
	//vector of nurses
	std::priority_queue<person *> wait_room;
	   	   
};





#endif 
