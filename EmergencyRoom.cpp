#include "EmergencyRoom.h"

EmergencyRoom::EmergencyRoom(){
	numPatientsPerHour = 0;
}
void EmergencyRoom::addPatient(person* p) {
	std::cout << "Patient " << p->getName() << " with severity " << p->getSeverity() << " arrives" << std::endl;
	std::cout << std::endl;
	if (p->getSeverity() > 10) { //if the patient is of high severity, add them the the high severity queue (doctor only)
		high_sev.push(p);
	}
	else { //otherwise send them to the low severity queue
		low_sev.push(p);
	}
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