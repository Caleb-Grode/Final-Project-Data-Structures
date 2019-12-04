//#include "pch.h"
#include "person.h"
//changed
person::person() {
	sick = false;
	everSick = false;
	severity = 0;
	numVisits = 0;
}
person::person(int sev, std::string name) {
	this->name = name;
	if (sev > 0) {
		this->getSick(sev);
	}
	
	std::cout << "made a person!" << std::endl;
}
bool person::isSick() {	
	return sick;
}
bool person::wasSick() {
	return everSick;
}
void person::getSick(int severity) {
	sick = true;
	this->severity = severity;
	everSick = true;
	std::cout << name << " has an illness of severity " << severity << std::endl;
}
void person::cure() {
	sick = false;
	severity = 0;
	std::cout << name << " has been cured! " << std::endl;
}
bool person::operator > (person const &other) {
	return this->severity > other.severity;
}
int person::getSeverity() {
	return severity;
}
std::string person::getName() {
	return name;
}