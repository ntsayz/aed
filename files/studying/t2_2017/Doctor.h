/*
 * Doctor.h
 */

#ifndef SRC_DOCTOR_H_
#define SRC_DOCTOR_H_

#include <string>
#include <queue>


using namespace std;

class Patient {
    unsigned codeP;
  string medicalSpecialty;
public:
  Patient(unsigned cod, string mS);
  string getMedicalSpecialty() const;
  unsigned getCode() const;

    Patient();
};


class Doctor {
    unsigned codeM;
  string medicalSpecialty;
  queue<Patient> patients;
public:
  Doctor(unsigned codM, string mS);
  Doctor(unsigned codM, string mS, queue<Patient> patients1);
  unsigned getCode() const;
  string getMedicalSpecialty() const;
  queue<Patient> getPatients() const;
  void addPatient(const Patient &p1);
  Patient removeNextPatient();
  bool operator<(Doctor d1){
      if(this->getPatients().size() < d1.getPatients().size()){
          return true;
      }else if(this->getPatients().size() == d1.getPatients().size() && this->medicalSpecialty != d1.medicalSpecialty){
          return this->medicalSpecialty < d1.medicalSpecialty;
      }else if(this->medicalSpecialty == d1.medicalSpecialty){
          return this->getCode() < d1.getCode();
      }
  }

  void moveToFront(unsigned codP1);

  class PatientInexistent {};

    Doctor();
};


#endif /* SRC_DOCTOR_H_ */
