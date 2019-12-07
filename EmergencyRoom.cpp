#include "EmergencyRoom.h"

EmergencyRoom::EmergencyRoom(){
	numPatientsPerHour = 0;
}
void EmergencyRoom::addPatient(person* p) {
	std::cout << "++Patient " << p->getName() << " with severity " << p->getSeverity() << " arrives" << std::endl;
	
	if (p->getSeverity() == 0) {
		std::cout << "--Patient " << p->getName() << " has regular check up" << std::endl;
	}
	if (p->getSeverity() > 10 && p->getSeverity() != 0) { //if the patient is of high severity, add them the the high severity queue (doctor only)
		high_sev.push(p);
	}
	else if (p->getSeverity() != 0) { //otherwise send them to the low severity queue
		low_sev.push(p);
	}
	std::cout << std::endl;
}
void EmergencyRoom::addNurse(Nurse* n) {
	nurses.insert(n);
}
void EmergencyRoom::addDoctor(doctor* d) {
	doctors.insert(d);
}
void EmergencyRoom::setPatientsPerHour(int num) {
	numPatientsPerHour = num;
}
void EmergencyRoom::takePatients() {
	std::set<doctor* >::iterator iter = doctors.begin();
	bool allDoctorsBusy = false;
	while ((*iter)->isBusy()) { //if the doctor at the iterator is busy we do not want to assign them a patient and so we should move to the next
		
		iter++;
		if (iter == doctors.end()) { //if we have reached the end of the doctor set and have not found a non busy doctor, stop looking so we do not loop for ever
			allDoctorsBusy = true;
			break;
		}
	}

	if (!allDoctorsBusy) { //if there are free doctors (then the doctor at our iter is free)
		if (!high_sev.empty()) { //if there is a person in the high priority queue
			(*iter)->treat(*high_sev.top()); //treat them
			beingTreated[*iter] = low_sev.top(); //map doctor to patient
			high_sev.pop(); //person is now being treated, remove from queue
		}
		else if (!low_sev.empty()){ //if there was no one urgent to treat, treat check if there is a low priority patient to treat
			(*iter)->treat(*low_sev.top()); //treat them
			beingTreated[*iter] = low_sev.top(); //map doctor to patient
			low_sev.pop(); //person is now being treated, remove from queue
		}

	}
	
	//now do the same process for nurses
	std::set<Nurse* >::iterator iter2 = nurses.begin();
	bool allNursesBusy = false;
	while ((*iter2)->isBusy()) { //if the Nurse at the iterator is busy we do not want to assign them a patient and so we should move to the next
		iter2++;
		if (iter2 == nurses.end()) { //if we have reached the end of the Nurse set and have not found a non busy Nurse, stop looking so we do not loop for ever
			allNursesBusy = true;
			break;
		}
	}

	if (!allNursesBusy) { //if there are free Nurses (then the Nurse at our iter2 is free)
		if (!low_sev.empty()) { //if there is a person in the low priority queue
			(*iter2)->treat(*low_sev.top()); //treat them
			beingTreated[*iter2] = low_sev.top(); //map nurse to patient
			low_sev.pop(); //person is now being treated, remove from queue
		}

	}

}

void EmergencyRoom::treatPatients() {
	//now that doctors and nurses have patients they need to continue to treat them until they are cured
	std::set<doctor* >::iterator iter = doctors.begin();
	std::set<Nurse* >::iterator iter2 = nurses.begin();

	while (iter != doctors.end()) { //find not busy doctors
		if ((*iter)->isBusy()) { 
			if ((*iter)->treat(*beingTreated[*iter])) { //if the patient is cured
				beingTreated.erase(*iter); //delete the them from the map
			}
		}
		++iter;
	}
	while (iter2 != nurses.end()) { //find not busy doctors
		if ((*iter2)->isBusy()) {
			if ((*iter2)->treat(*beingTreated[*iter2])) {
				beingTreated.erase(*iter2);
			}
		}
		++iter2;
	}

}