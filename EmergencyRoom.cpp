#include "EmergencyRoom.h"

EmergencyRoom::EmergencyRoom() {
	numPatientsPerHour = 0;
}

void EmergencyRoom::addPatient(person* p) {
	std::cout << "++Patient " << p->getName() << " with severity " << p->getSeverity() << " arrives" << std::endl;

	if (p->getSeverity() == 0) { //patient is just there for a check up
		std::cout << "--Patient " << p->getName() << " has regular check up" << std::endl;

	}
	if (p->getSeverity() > 10 && p->getSeverity() != 0) { //if the patient is of high severity, add them the the high severity queue (doctor only)

		if (residentsTreated[p->getName()] == NULL) { //if this person has not visited before
			high_sev.push(p); //add them 
			residentsTreated[p->getName()] = p; //map the doctor to them
		}
		else {
			residentsTreated[p->getName()]->getSick(p->getSeverity()); //they have visited before so find them in the map (by their name) make them sick with the severity passed in
			high_sev.push(residentsTreated[p->getName()]); //map the doctor to them
		}
	}
	else if (p->getSeverity() != 0) { //otherwise send them to the low severity queue
		if (residentsTreated[p->getName()] == NULL) { //if this person has not visited before
			low_sev.push(p);//add them 
			residentsTreated[p->getName()] = p; //map them to nurse
		}
		else {
			residentsTreated[p->getName()]->getSick(p->getSeverity()); //they have visited before so find them in the map (by their name) make them sick with the severity passed in
			low_sev.push(residentsTreated[p->getName()]); //map them to the nurse
		}

	}
	std::cout << std::endl;
}
void EmergencyRoom::addNurse(Nurse* n) {
	nurses.insert(n); //add nurse to set of nurses
}
void EmergencyRoom::addDoctor(doctor* d) {
	doctors.insert(d); //add doctor to set of doctors
}
void EmergencyRoom::setPatientsPerHour(int num) {
	numPatientsPerHour = num; //set
}
void EmergencyRoom::takePatients() {
	std::set<doctor* >::iterator iter = doctors.begin(); 
	bool allDoctorsBusy = false;
	while ((*iter)->isBusy()) { //if the doctor at the iterator is busy we do not want to assign them a patient and so we should move to the next

		iter++;
		if (iter == doctors.end()) { //if we have reached the end of the doctor set and have not found a non busy doctor, stop looking so we do not loop for ever
			allDoctorsBusy = true; //all the doctors are busy
			break;
		}
	}

	if (!allDoctorsBusy) { //if there are free doctors (then the doctor at our iter is free)
		if (!high_sev.empty()) { //if there is a person in the high priority queue

			(*iter)->treat(*high_sev.top()); //treat them
			beingTreated[*iter] = high_sev.top(); //map doctor to patient
			high_sev.pop(); //person is now being treated, remove from queue

		}
		else if (!low_sev.empty()) { //if there was no one urgent to treat, treat check if there is a low priority patient to treat

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

	while (iter != doctors.end()) { //find busy doctors
		if ((*iter)->isBusy()) {
			if ((*iter)->treat(*beingTreated[*iter])) { //if the patient is cured/continue treating if not
				beingTreated.erase(*iter); //delete the them from the map
			}
		}
		++iter;
	}
	while (iter2 != nurses.end()) {
		if ((*iter2)->isBusy()) {//find busy nurses
			if ((*iter2)->treat(*beingTreated[*iter2])) { //have them continue to treat their patient
				beingTreated.erase(*iter2); //if the patient is cured, remove them from the map as they are done
			}
		}
		++iter2;
	}

}
EmergencyRoom::~EmergencyRoom() {

}

int EmergencyRoom::getPatientsPerHour() {
	return numPatientsPerHour;
}

void EmergencyRoom::printPatients() {
	std::map <std::string, person*> ::iterator iter = residentsTreated.begin();
	std::cout << "Residents Treated: " << std::endl;
	for (iter; iter != residentsTreated.end(); iter++) {
		std::cout << (*iter).second->getName() << " visits: " << (*iter).second->getNumVisits() << " Average time: " << (*iter).second->getAvgVisitTime() << std::endl;
	}
}

void EmergencyRoom::searchName() {
	std::string names;
	std::cout << "Please Enter a valid name: ";
	std::cin >> names;

	std::map<std::string, person*>::iterator iter;

	iter = residentsTreated.find(names);
	std::cout << (*iter).second->getName() << " visits: " << (*iter).second->getNumVisits() << " Average time: " << (*iter).second->getAvgVisitTime() << std::endl;
}

void EmergencyRoom::displayRecords()
{
	int ans = 0;
	while (ans != 4)
	{

	

	std::cout << "=================== PIRATES HOSPITAL ==================" << std::endl;
	std::cout << "What would you like to do? " << std::endl;
	std::cout << "1. Look at all the residents treated" << std::endl;
	std::cout << "2. Search by name a resident treated" << std::endl;
	std::cout << "3. Calculate average time of treatment" << std::endl;
	std::cout << "4. Exit" << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;
	std::cout << "Option: ";
	std::cin >> ans;

	if (ans < 0 || ans > 4)
	{
		std::cout << "Option not valid!";
	}

	if (ans >= 1 || ans <= 4)
	{
		switch (ans) {
		case 1:
			printPatients();
			break;
		case 2:
			searchName();
			break;
		case 3:
			printAvgVisitTime();
			break;
		case 4:
			break;
		}
	}
	
	}
}
void EmergencyRoom::printAvgVisitTime() { //!!!!
	float numTreated = residentsTreated.size();
	float totalTime = 0;
	std::map <std::string, person*> ::iterator iter = residentsTreated.begin();
	for (iter; iter != residentsTreated.end(); iter++) {
		if (!(*iter).second->isSick())
			totalTime += (*iter).second->getAvgVisitTime();
	}
	std::cout << "Average Visit Time: " << totalTime / numTreated << std::endl;

}