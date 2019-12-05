#include "person.h"

person::person() {
	sick = false;
	everSick = false;
	severity = 0;
	numVisits = 0;
}

person::person(int sev, std::string name) {
	this->name = name;
	if (sev>0){
		this ->getSick(sev);
	}
	std::cout << "made a person!" << std::endl;
}

std::string person::getRandName()
{
	std::string line;
	std::fstream firstName;

	firstName.open(".\\\\data\\\\Residents_of_273ville.txt");

	if(firstName.fail())
	{
		std::cout << "Couldn't open the file" << std::endl;
	} else if(firstName.is_open()) {	
		while(!firstName.eof())
		{
			firstName >> line;
			residents.push_back(line);
		}
			firstName.close();
		}

		int person = rand() % 1999;
		std::string chosenPerson = residents.at(person);

		return chosenPerson;
}

void person::setName(){
	name = getRandName();
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
	std:: cout << name << " has an illness of severity" << severity << std::endl;
}

void person::cure() {
	sick = false;
	severity = 0;
	std::cout << name << " has been cured! " << std::endl;
}

bool person::operator > (person const &other) {
	return this->severity > other.severity;
}

int person::getSeverity(){
        return severity;
}
