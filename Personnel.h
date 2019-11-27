#ifndef PERSONNEL_H
#define PERSONNEL_H

#include <string>
#include "person.h"
class Personnel
{
public:
	Personnel();
	

private:
	virtual bool treat(int severity, person &patient) = 0; //both doctors and nurses need to be able to treat patients
};


#endif