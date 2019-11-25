#include "person.h"

bool person::isSick() {	
	return sick;
}
bool person::wasSick() {
	return everSick;
}
void person::getSick(int severity) {
	this->severity = severity;
	everSick = true;
}
void person::cure() {
	sick = false;
	severity = 0;
}