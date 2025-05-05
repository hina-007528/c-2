#include <iostream>
#include <string>
using namespace std;
const int MAX_PATIENTS = 100; 


struct Patient {
   string name;
    int age;
  string medicalCondition;
    int patientID;
};

Patient patientRecords[MAX_PATIENTS];
int numPatients = 0; 

void addPatient(const string& name, int age, const string& condition, int id) {
    if (numPatients >= MAX_PATIENTS) {
        cout << "Error: Patient records are full." << endl;
        return;
    }
    
    patientRecords[numPatients] = {name, age, condition, id};
    ++numPatients;
}

void updateMedicalCondition(int id, const string& newCondition) {
    for (int i = 0; i < numPatients; ++i) {
        if (patientRecords[i].patientID == id) {
            patientRecords[i].medicalCondition = newCondition;
            return;
        }
    }
    cout << "Error: Patient ID not found." << endl;
}


void dischargePatient(int id) {
    for (int i = 0; i < numPatients; ++i) {
        if (patientRecords[i].patientID == id) {
            
            for (int j = i; j < numPatients - 1; ++j) {
                patientRecords[j] = patientRecords[j + 1];
            }
            --numPatients;
            return;
        }
    }
   cout << "Error: Patient ID not found." << endl;
}

void displayPatientRecords() {
    if (numPatients == 0) {
       cout << "No patient records available." << endl;
        return;
    }

    for (int i = 0; i < numPatients; ++i) {
        cout << "Patient ID: " << patientRecords[i].patientID << endl;
       cout << "Name: " << patientRecords[i].name << endl;
        cout << "Age: " << patientRecords[i].age << endl;
       cout << "Medical Condition: " << patientRecords[i].medicalCondition << endl;
        cout << "-----------------------------" << endl;
    }
}

int main() {
   
    addPatient("John Doe", 45, "Flu", 101);
    addPatient("Jane Smith", 30, "Cold", 102);

    
    cout << "Patient Records:" << endl;
    displayPatientRecords();

   
    updateMedicalCondition(101, "Recovered from Flu");

   
    cout << "\nPatient Records After Update:" << endl;
    displayPatientRecords();

    dischargePatient(102);

  
    cout << "\nPatient Records After Discharge:" << endl;
    displayPatientRecords();

    return 0;
}