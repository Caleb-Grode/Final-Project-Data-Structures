
#include "EmergencyRoom.h"
#include "doctor.h"
#include "person.h"
#include "Nurse.h"
#include <cstdlib>
#include <ctime>
using std::cout;
using std::cin;
using std::endl;
void setUpER(EmergencyRoom * room);
	bool lowSevOccur();
	bool medSevOccur();
	bool highSevOccur();
	void updateRoomQueue(EmergencyRoom * r);
	void takePatients(EmergencyRoom* r);
int main() {
	EmergencyRoom room;
	EmergencyRoom* ER = &room;
	setUpER(ER);


	for (int i = 1; i <= 100; i++) {
		updateRoomQueue(ER);
		

	}

	

}

void setUpER(EmergencyRoom * room) {
	
	cout << "Welcome to the Emergency Room Simulator" << endl;
	cout << endl;
	int numDocs;
	cout << "How many doctors? ";
	cin >> numDocs;
	int numNurse;
	cout << "How many nurses? ";
	cin >> numNurse;

	for (int i = 0; i < numNurse; i++) {
		room->addNurse(new Nurse);
	}
	for (int i = 0; i < numDocs; i++) {
		room->addDoctor(new doctor);
	}

}
bool lowSevOccur() {
	srand(time(NULL));
	int prob = rand() % 10;

	if (prob < 8) {
		return true;
	}
	else {
		return false;
	}
}
bool medSevOccur() {
	srand(time(NULL));
	int prob = rand() % 10;

	if (prob < 3) {
		return true;
	}
	else {
		return false;
	}
}
bool highSevOccur() {
	srand(time(NULL));
	int prob = rand() % 10;

	if (prob < 2) {
		return true;
	}
	else {
		return false;
	}
}
void updateRoomQueue(EmergencyRoom * r) {
	srand(time(NULL));
	if (lowSevOccur()) {		
		int sev = rand() % 10;
		r->addPatient(new person(sev, "low")); //name is assigned randomly from in person class (Xavi) so these constructors need to change once this file is paired with the updated one
		//TODO: change add patient function to put the high severity patients into the high priority queue and low priority into low priority queue
	}
	if (medSevOccur()) {
		int sev = 11 + (std::rand() % (15 - 11 + 1)); //sev should be a number between 11 and 15
		r->addPatient(new person(sev, "med"));
	}
	if (highSevOccur()) {
		int sev = 16 + (std::rand() % (20 - 16 + 1)); //sev should be a number between 16 and 20
		r->addPatient(new person(sev, "high"));
	}
}
void takePatients(EmergencyRoom* r) {
	//TODO make second queue for severitys < 11 and change names to reflect it (for high severities make it priority and low just a normal queue)
	//THIS SHOULD BE A PART OF EMERGENCY ROOM

	//find not busy doctor
		//assign the not busy doctor and make them begin treating the highest priority patient
			//check if the high priority queue is empty
			//if not take and 
				//treat from there
			//if true take 
					//from low priority queue (if it is not empty)
	//iterate through the set of doctors and repeat this process
	
	//now that the doctors are treating the highest priority patients:

	//find not busy nurse
		//if the low priority queue has person(s) in it
		//take and treat them

}