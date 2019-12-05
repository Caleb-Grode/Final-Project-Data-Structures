
#include "EmergencyRoom.h"
#include "doctor.h"
#include "person.h"
#include "Nurse.h"
#include <cstdlib>
using std::cout;
using std::cin;
using std::endl;
EmergencyRoom * createER();
	bool lowSevOccur();
	bool medSevOccur();
	bool highSevOccur();
	void updateRoom(EmergencyRoom * r);
int main() {

	EmergencyRoom* ER = createER();
	

	for (int i = 1; i <= 100; i++) {
		updateRoom(ER);
		

	}

	

}

EmergencyRoom * createER() {
	EmergencyRoom ER;
	cout << "Welcome to the Emergency Room Simulator" << endl;
	cout << endl;
	int numDocs;
	cout << "How many doctors? ";
	cin >> numDocs;
	int numNurse;
	cout << "How many nurses? ";
	cin >> numNurse;

	for (int i = 0; i < numNurse; i++) {
		ER.addNurse(new Nurse);
	}
	for (int i = 0; i < numDocs; i++) {
		ER.addDoctor(new doctor);
	}

	return &ER;
}
bool lowSevOccur() {
	srand(0);
	int prob = rand() % 10;

	if (prob > 8) {
		return true;
	}
	else {
		return false;
	}
}
bool medSevOccur() {
	srand(0);
	int prob = rand() % 10;

	if (prob > 3) {
		return true;
	}
	else {
		return false;
	}
}
bool highSevOccur() {
	srand(0);
	int prob = rand() % 10;

	if (prob > 8) {
		return true;
	}
	else {
		return false;
	}
}
void updateRoom(EmergencyRoom * r) {
	srand(0);
	if (lowSevOccur()) {		
		int sev = rand() % 10;
		r->addPatient(new person(sev, ""));
	}
	if (medSevOccur()) {
		int sev = 11 + (std::rand() % (15 - 11 + 1));
		r->addPatient(new person(sev, ""));
	}
	if (highSevOccur()) {
		int sev = 16 + (std::rand() % (20 - 16 + 1));;
		r->addPatient(new person(sev, ""));
	}
}