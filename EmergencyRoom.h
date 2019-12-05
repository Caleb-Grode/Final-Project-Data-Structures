#ifndef EMERGENCYROOM_H
#define EMERGENCYROOM_H
#include <queue>
#include <vector>
#include "person.h"
#include <iostream>
#include <set>
#include "Nurse.h"
#include "doctor.h"
//changed
class EmergencyRoom
{
public:
	EmergencyRoom();
	void addPatient(person * p); //probably use with arrival object?
	void addNurse(Nurse* n);
	void addDoctor(doctor* d);

private:
	std::vector<person *> residents; //holds the 2000 persons that are in the town of Simville (maybe change to a map or set etc to meet requirments of project
	std::set<Nurse*> nurses;
	std::set<doctor*> doctors;
	std::priority_queue<person *> wait_room;
	   	   
};





#endif 
