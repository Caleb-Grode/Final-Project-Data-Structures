//#include "pch.h"
#include "doctor.h"

doctor::doctor() {
	busy = false;
	workingTime = 0;
}
bool doctor::treat(person& patient) {
	if (!busy) { //if the nurse is just starting to treat the patient
		busy = true; //the nurse is now busy
		workingTime = 0;
	}
	if (workingTime == patient.getSeverity()) { //a severity of n takes n minutes to cure so if the working time == the severity the patient can be cured
		patient.cure(); //cure the patient
		busy = false; //the nurse is now not busy
		return true; //the patient is cured. return true
	}
	else {
		workingTime++; //the patient is not cured. Credit one minute to the working time
		return false; //the patient is not cured return false
	}
}
