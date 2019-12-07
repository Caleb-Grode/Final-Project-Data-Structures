#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

class person
{
private:
	std::string name; //holds the persons name
	std::vector<std::string> names; //holds the 2000 persons that are in the town of Simville
	int numVisits; //number of times visiting the ER
	bool sick; //the person is sick if this is true
	bool everSick; //the person has been sick if this true
	int severity; //if not sick == 0 if sick it indicates how sick from 1-20

public:
	person();
	person(int sev, std::string name);
	void openFile();
	std::string getRandName();
	std::string getName();
	bool isSick();
	bool wasSick();
	void getSick(int severity);
	void cure();
	bool operator < (person const& other);
	int getSeverity();
	void setName();
};

#endif // PERSON_