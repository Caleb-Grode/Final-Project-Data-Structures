#include "Personnel.h"
#include <string>
#ifndef DOCTOR_H
#define DOCTOR_H

class doctor : public Personnel {
public:
	doctor();
	bool treat(person& patient); //returns when/if patient is treated, uses the cure function on the patient that is passed in.

private:
	bool busy;
	int workingTime;

};
#endif