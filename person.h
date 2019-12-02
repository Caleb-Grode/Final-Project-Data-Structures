#ifndef PERSON_H
#define PERSON_H
#include <string>
class person
{
public:
	person();
	bool isSick(); //returns if the person is sick
	bool wasSick(); //returns if the patient was ever sick
	void getSick(int severity); //makes the person sick with a severity of the passed in interger
	void cure(); //removes the state of being sick from the person
	bool operator > (person const &other); //comparing one person to another
	int getSeverity();

private:
	std::string name; //holds the persons name
	int numVisits; //number of times visiting the ER
	bool sick; //the person is sick if this is true
	bool everSick; //the person has been sick if this true
	int severity; //if not sick == 0 if sick it indicates how sick from 1-20
	
};


#endif // !PERSON_H
