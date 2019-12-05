#include "EmergencyRoom.h"

EmergencyRoom::EmergencyRoom(){}
void EmergencyRoom::addPatient(person* p) {
	wait_room.push(p);
	std::cout << "Patient " << p->getName() << " with severity " << p->getSeverity() << " arrives" << std::endl;
}
void EmergencyRoom::addNurse(Nurse* n) {
	nurses.insert(n);
}
void EmergencyRoom::addDoctor(doctor* d) {
	doctors.insert(d);
}