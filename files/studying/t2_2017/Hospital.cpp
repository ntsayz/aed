/*
 * Hospital.cpp
 */

#include "Hospital.h"
//
#include <algorithm>


Hospital::Hospital(unsigned trayC):trayCapacity(trayC)
{ }

void Hospital::addDoctor(const Doctor &d1) {
	doctors.push_back(d1);
}

list<Doctor> Hospital::getDoctors() const {
	return doctors;
}

void Hospital::addTrays(stack<Patient> tray1) {
	letterTray.push_back(tray1);
}

list<stack<Patient> > Hospital::getTrays() const {
	return letterTray;
}



unsigned Hospital::numPatients(string medicalSpecialty) const{
    unsigned res = 0;
    stack<Patient> aux;
    for(auto it = doctors.begin();it != doctors.end() ;it++){
        if(it->getMedicalSpecialty() == medicalSpecialty){
            res+= it->getPatients().size();
        }

    }
	return res;

}

void Hospital::sortDoctors() {
	doctors.sort();
}



bool Hospital::addDoctor(unsigned codM1, string medicalSpecialty1) {
	int count =0 ;
    for(auto it = doctors.begin() ; it != doctors.end(); it++){
        if(it->getMedicalSpecialty() == medicalSpecialty1){
            count++;
        }
    }
    if(count >=3) return false;
    doctors.push_back(Doctor(codM1,medicalSpecialty1));
	return true;

}



queue<Patient> Hospital::removeDoctor(unsigned codM1) {
	// TODO
	queue<Patient> p1;
    auto it = doctors.begin();
    while(it != doctors.end()){
        if(it->getCode() == codM1){
            p1 = it->getPatients();
            it = doctors.erase(it);
            it--;
        }
        it++;
    }
	return p1;

}

//TODO
bool Hospital::putInLessBusyDoctor(unsigned cod1, string medicalSpecialty1) {
    int min = INT32_MIN;
    unsigned doc = 0;
    for(auto it = doctors.begin(); it != doctors.end(); it++){
        if(it->getPatients().size() <= min && it->getMedicalSpecialty() == medicalSpecialty1){
            min = it->getPatients().size();
            doc = it->getCode();
        }
    }
    if(min < 0) return false;

    for(auto it = doctors.begin(); it != doctors.end(); it++){
        if(doc == it->getCode()){
            it->addPatient(Patient(cod1, medicalSpecialty1));
            return true;
        }
    }
	return false;

}



//TODO
void Hospital::processPatient(unsigned codM1) {
    queue<Patient> pq;
    Patient p;
    bool space = false;
    for(auto it = doctors.begin(); it != doctors.end(); it++){
        if(it->getCode() == codM1 && it->getPatients().size() > 0){
            p = it->removeNextPatient();
            for(auto itr = letterTray.begin(); itr != letterTray.end(); itr++){
                if(itr->size() < trayCapacity){
                    itr->push(p);
                    space = true;
                    break;
                }
            }
            if(!space){
                stack<Patient> newStack;
                newStack.push(p);
                letterTray.push_back(newStack);
                break;
            }
        }
    }

}


unsigned Hospital::removePatients(unsigned codP1) {
    int count = 0;
    for(auto itr = letterTray.begin(); itr != letterTray.end(); itr++){
        if(itr->top().getCode() == codP1){
            itr->pop();
            count++;
            if(itr->size() == 0){
                itr-- = letterTray.erase(itr);
            }
        }


    }
	return count;

}




