#include "Personnel.h"
#include <string>
#ifndef NURSE_H
#define NURSE_H

class Nurse: public Personnel {
public:
	Nurse();
	bool treat(int severity, person &patient); //returns when/if patient is treated, uses the cure function on the patient that is passed in.

private:
	

};

#endif