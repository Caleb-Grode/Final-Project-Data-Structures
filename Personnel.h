#ifndef PERSONNEL_H
#define PERSONNEL_H
#include <iostream>
#include <string>
#include "person.h"
class Personnel
{
public:

	

private:
	virtual bool treat(person &patient) = 0; //both doctors and nurses need to be able to treat patients
};


#endif