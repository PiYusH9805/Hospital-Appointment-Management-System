#include<bits/stdc++.h>
using namespace std;
int pid;
int did;

class Patient {
    public:
    string name;
    string gender;
    int age;
    int ID;
    Patient(string n, string g, int a) {
        ID = pid;
        pid++;
        name = n;
        gender = g;
        age = a;
    }
};

class Doctor {
    public:
    string name;
    string gender;
    int age;
    int ID;
    Doctor(string n, string g, int a) {
        ID = did;
        did++;
        name = n;
        gender = g;
        age = a;
    }
};

class Appointment {
    public:
    int patientID;
    int doctorID;
    string Date;

    Appointment(int p, int d, string date) {
        patientID = p;
        doctorID = d;
        Date = date;
    }
};

vector<Patient> allPatients;
vector<Doctor> allDoctors;
vector<Appointment> allAppointments;

bool isPatientpersent(int id) {
    bool ans  = false;
    for(int i = 0; i < allPatients.size(); i++) {
        if(allPatients[i].ID == id) {
            ans = true;
        }
    }
    return ans;
}

bool isDoctorpersent(int id) {
    bool ans  = false;
    for(int i = 0; i < allDoctors.size(); i++) {
        if(allDoctors[i].ID == id) {
            ans = true;
        }
    }
    return ans;
}

void addPatient() {
    string n, g;
    int a;
    cout << "Enter patient name: " << endl;
    cin >> n;
    cout << "Enter Patient age: " << endl;
    cin >> a;
    cout << "Enter patient gender: " << endl;
    cin >> g;
    Patient temp(n, g, a);
    allPatients.push_back(temp);
}

void addDoctor() {
    string n, g;
    int a;
    cout << "Enter Doctor name: " << endl;
    cin >> n;
    cout << "Enter Doctor age: " << endl;
    cin >> a;
    cout << "Enter Doctor gender: " << endl;
    cin >> g;
    Doctor temp(n, g, a);
    allDoctors.push_back(temp);
}

void ScheduleAppointments() {
    int patientID;
    int doctorID;
    string Date;

    cout << "Enter the Patient ID: " << endl;
    cin >> patientID;
    cout << "Enter the Doctor ID: " << endl;
    cin >> doctorID;
    cout << "Enter the Date in DD-MM-YYYY: " << endl;
    cin >> Date;

    if(isPatientpersent(patientID) == false || isDoctorpersent(doctorID) == false) {
        cout << "Invalid Patient or Doctor ID" << endl;
        cout << "Appointment Schedule Unsuccessfully" << endl;
        cout << endl;
        return;
    }
    Appointment temp(patientID, doctorID, Date);
    allAppointments.push_back(temp);
}

void viewpatient() {
    for(int i = 0; i < allPatients.size(); i++) {
        cout << "Patient name : " << allPatients[i].name << endl;
    }
    cout << endl;
}

void viewDoctor() {
    for(int i = 0; i < allDoctors.size(); i++) {
        cout << "Doctor name : " << allDoctors[i].name << endl;
    }
    cout << endl;
}

void viewAppointment() {
    for(int i = 0; i < allAppointments.size(); i++) {
        cout << "Patient ID : " << allAppointments[i].patientID
             << " has Appointment with Doctor ID " << allAppointments[i].doctorID
             << " on Date " << allAppointments[i].Date << endl;
    }
    cout << endl;
}

int main() {
    pid = 1;
    did = 1;

    int choice;
    do {
        cout << "1. Add Patient" << endl;
        cout << "2. Add Doctor" << endl;
        cout << "3. Schedule Appointment" << endl;
        cout << "4. View Patient" << endl;
        cout << "5. View Doctor" << endl;
        cout << "6. View Appointment" << endl;
        cout << "0. Exit" << endl;
        cout << endl;
        cout << "Give your choice : " << endl;
        cin >> choice;

        switch(choice) {
            case 1:
                addPatient();
                break;
            case 2:
                addDoctor();
                break;
            case 3:
                ScheduleAppointments();
                break;
            case 4:
                viewpatient();
                break;
            case 5:
                viewDoctor();
                break;
            case 6:
                viewAppointment();
                break;
            default:
                cout << "Invalid choice" << endl;
                cout << endl;
        }
    } while(choice != 0);

    return 0;
}
