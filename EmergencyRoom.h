#ifndef EMERGENCYROOM_H
#define EMERGENCYROOM_H
#include <queue>
#include "Personnel.h"
#include <vector>
#include "person.h"
#include <iostream>
#include <set>
#include "Nurse.h"
#include "doctor.h"
#include <iterator>
#include <map>
//changed
class EmergencyRoom
{
public:
	EmergencyRoom();
	void addPatient(person* p); //probably use with arrival object?
	void addNurse(Nurse* n);
	void addDoctor(doctor* d);
	void setPatientsPerHour(int num);
	void takePatients();
	void treatPatients();
	~EmergencyRoom();
	int getPatientsPerHour();
	// Records from Patients
	void printPatients(); 
	void searchName();
	void displayRecords(); // Menu of options
	void printAvgVisitTime();


private:
	std::vector<person*> residents; //holds the 2000 persons that are in the town of Simville (maybe change to a map or set etc to meet requirments of project
	std::set<Nurse*> nurses;
	std::set<doctor*> doctors;
	std::priority_queue<person*> high_sev; //can only be treated by doctors (severity 11-20)
	std::priority_queue<person*> low_sev; //can be treated by both (severity 1-10)
	int numPatientsPerHour;
	std::map<Personnel*, person*> beingTreated;
	std::map<std::string, person*> residentsTreated;
};

#endif
