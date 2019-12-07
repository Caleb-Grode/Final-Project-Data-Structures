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

}

void person::openFile()
{
	std::string line;
	std::ifstream FirstNamestxt;

	FirstNamestxt.open(".\\\\data\\\\Residents_of_273ville.txt");

	if (FirstNamestxt.fail())
	{
		std::cout << "Couldn't open the file" << std::endl;
	}
	
	if (FirstNamestxt.is_open())
	{
		while (getline(FirstNamestxt, line))
		{
			names.push_back(line);
		}
	}
    FirstNamestxt.close();
	std::cout << names.size() << std::endl;
}

std::string person::getRandName()
{
	srand(time(NULL));
	int randNum = rand() % 2000;
	std::string randomName = names.at(randNum);

	return randomName;
}

std::string person::getName() 
{ 
	name = getRandName();
	return name; 
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
}

void person::cure() {
	sick = false;
	severity = 0;
	std::cout << name << " has been cured! " << std::endl;
}

bool person::operator < (person const &other) {
	return this->severity < other.severity;
}

int person::getSeverity(){
        return severity;
}
std::string person::getName() {
	return name;
}
