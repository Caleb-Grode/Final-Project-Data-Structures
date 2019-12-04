
#include "EmergencyRoom.h"
#include "doctor.h"
#include "person.h"
#include "Nurse.h"

int main() {

	EmergencyRoom room;
	person sickMan(20, "Bill");
	Nurse* nurseMan = new Nurse;
	doctor * docMan = new doctor;
		//sick dude arrives
		room.addPatient(&sickMan);

	for (int i = 1; i <= 100; i++) {
		if (nurseMan->canTreat(sickMan.getSeverity())) {
			nurseMan->treat(sickMan);
		}
		else {
			docMan->treat(sickMan);
		}


	}

}