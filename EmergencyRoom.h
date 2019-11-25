#ifndef EMERGENCYROOM_H
#define EMERGENCYROOM_H

#include <vector>
#include "person.h"

class EmergencyRoom

{
public:
	EmergencyRoom();
	~EmergencyRoom();

private:
	std::vector<person> residents; //holds the 2000 persons that are in the town of Simville

};

EmergencyRoom::EmergencyRoom()
{
}

EmergencyRoom::~EmergencyRoom()
{
}

#endif // !EMERGENCYROOM_H
