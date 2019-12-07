
#include "EmergencyRoom.h"
#include "doctor.h"
#include "person.h"
#include "Nurse.h"
#include <cstdlib>
#include <ctime>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
void setUpER(EmergencyRoom * room); //takes in pointer to Emergency Room, lets user define the number of nurses, doctors and number of patients arriving per hour
	bool lowSevOccur(int seed); //returns whether a low Severity patient arrives this clock tick, takes in a seed for the random number generator
	bool medSevOccur(int seed); //returns whether a medium Severity patient arrives this clock tick, takes in a seed for the random number generator
	bool highSevOccur(int seed); //returns whether a high Severity patient arrives this clock tick, takes in a seed for the random number generator
	void updateRoomQueue(EmergencyRoom * r, int seed, std::vector<std::string>* names); //takes in a pointer to the emergency room and a seed time for the random number generator. Adds arriving person(s) to the priority queues
	void takePatients(EmergencyRoom* r); //REMOVE
	void openFile(std::vector<std::string> * names); //opens the file of names and puts them in the vector
	std::string getRandName(std::vector<std::string> * names, int seed); //finds a random name from the vector of names

int main() {
	std::vector<std::string> names;
	EmergencyRoom room;
	EmergencyRoom* ER = &room;
	setUpER(ER);
	openFile(&names);
	
	int runTime = 7 * 24 * 60;

	for (int i = 0; i < runTime; i++) {
		updateRoomQueue(ER, i, &names);
		

	}

	

}

void setUpER(EmergencyRoom * room) {
	
	cout << "Welcome to the Emergency Room Simulator" << endl;
	cout << endl;
	int numDocs;
	cout << "How many doctors? ";
	cin >> numDocs;
	int numNurse;
	cout << "How many nurses? ";
	cin >> numNurse;

	for (int i = 0; i < numNurse; i++) {
		room->addNurse(new Nurse);
	}
	for (int i = 0; i < numDocs; i++) {
		room->addDoctor(new doctor);
	}

}
bool lowSevOccur(int seed) {
	srand(seed);
	int prob = rand() % 10;

	if (prob < 8) {
		return true;
	}
	else {
		return false;
	}
}
bool medSevOccur(int seed) {
	srand(seed);
	int prob = rand() % 10;

	if (prob < 3) {
		return true;
	}
	else {
		return false;
	}
}
bool highSevOccur(int seed) {
	srand(seed);
	int prob = rand() % 10;

	if (prob < 2) {
		return true;
	}
	else {
		return false;
	}
}
void updateRoomQueue(EmergencyRoom * r, int seed, std::vector<std::string>* names) {
	//TODO: Limit number of patients created per hour using Emergency room setNumPatientsPerHour method
	srand(time(NULL));
	if (lowSevOccur(seed)) {		
		int sev = rand() % 10;
		r->addPatient(new person(sev, getRandName(names, seed))); //name is assigned randomly from in person class (Xavi) so these constructors need to change once this file is paired with the updated one
		//TODO: change add patient function to put the high severity patients into the high priority queue and low priority into low priority queue
		seed++; //change the seed in case another person arrives
	}
	if (medSevOccur(seed)) {
		int sev = 11 + (std::rand() % (15 - 11 + 1)); //sev should be a number between 11 and 15
		r->addPatient(new person(sev, getRandName(names, seed)));
		seed++;
	}
	if (highSevOccur(seed)) {
		int sev = 16 + (std::rand() % (20 - 16 + 1)); //sev should be a number between 16 and 20
		r->addPatient(new person(sev, getRandName(names, seed)));
	}
}
void takePatients(EmergencyRoom* r) {
	//TODO make second queue for severitys < 11 and change names to reflect it (for high severities make it priority and low just a normal queue)
	//THIS SHOULD BE A PART OF EMERGENCY ROOM

	//find not busy doctor
		//assign the not busy doctor and make them begin treating the highest priority patient
			//check if the high priority queue is empty
			//if not take and 
				//treat from there
			//if true take 
					//from low priority queue (if it is not empty)
	//iterate through the set of doctors and repeat this process
	
	//now that the doctors are treating the highest priority patients:

	//find not busy nurse
		//if the low priority queue has person(s) in it
		//take and treat them

}
void openFile(std::vector<std::string>* names)
{
	std::string line;
	std::ifstream FirstNamestxt;

	//FirstNamestxt.open(".\\\\data\\\\Residents_of_273ville.txt"); //visual studio code
	FirstNamestxt.open(".\\Residents_of_273ville.txt"); //visual studio 2019

	if (FirstNamestxt.fail())
	{
		std::cout << "Couldn't open the file" << std::endl;
	}

	if (FirstNamestxt.is_open())
	{
		while (getline(FirstNamestxt, line))
		{
			names->push_back(line);
		}
	}
	FirstNamestxt.close();
	
}
std::string getRandName(std::vector<std::string>* names, int seed)
{
	srand(seed);
	int randNum = rand() % 2000;
	std::string randomName = names->at(randNum);

	return randomName;
}