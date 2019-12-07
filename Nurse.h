#include "Personnel.h"
#include <string>

#ifndef NURSE_H
#define NURSE_H
//changed
class Nurse: public Personnel {
public:
	Nurse();
	~Nurse();
	bool treat(person &patient); //returns when/if patient is treated, uses the cure function on the patient that is passed in.
	bool canTreat(int sev); //returns if the nurse can treat the illness (sev < 11)
	bool isBusy();
private:
	bool busy;
	int workingTime;

};
#endif