#include <iostream>

#include "Person.h"
#include "Doctor.h"
#include "Patient.h"
#include "Appointment.h"
using namespace std;

static int doctorID = 1000;
static int patientID = 5000;

void addDefaultDoctors(Appointment& appointmentSystem) {
    // Add doctors
    appointmentSystem.addDoctor(Doctor("Dr. Ahmed Ali", "Male", "01/01/1975", doctorID, "Cardiology", 300.0));
    int ahmedID = doctorID++;
    appointmentSystem.addDoctor(Doctor("Dr. Mona Khaled", "Female", "15/05/1980", doctorID, "Dermatology", 200.0));
    int monaID = doctorID++;
    appointmentSystem.addDoctor(Doctor("Dr. Tarek Hassan", "Male", "22/07/1985", doctorID, "Neurology", 400.0));
    int tarekID = doctorID++;
    appointmentSystem.addDoctor(Doctor("Dr. Youssef Adel", "Male", "11/03/1970", doctorID, "Cardiology", 350.0));
    int youssefID = doctorID++;
    appointmentSystem.addDoctor(Doctor("Dr. Laila Samir", "Female", "09/09/1978", doctorID, "Dermatology", 250.0));
    int lailaID = doctorID++;
    appointmentSystem.addDoctor(Doctor("Dr. Ayman Saeed", "Male", "30/10/1982", doctorID, "Neurology", 450.0));
    int aymanID = doctorID++;

    // Add specific slots for Dr. Ahmed Ali (Cardiology)
    appointmentSystem.addAvailableSlotForDoctor("2024-01-15", "09:00 AM", ahmedID);
    appointmentSystem.addAvailableSlotForDoctor("2024-01-15", "11:00 AM", ahmedID);
    appointmentSystem.addAvailableSlotForDoctor("2024-01-16", "10:00 AM", ahmedID);
    appointmentSystem.addAvailableSlotForDoctor("2024-01-17", "02:00 PM", ahmedID);

    // Add specific slots for Dr. Mona Khaled (Dermatology)
    appointmentSystem.addAvailableSlotForDoctor("2024-01-15", "10:00 AM", monaID);
    appointmentSystem.addAvailableSlotForDoctor("2024-01-16", "09:00 AM", monaID);
    appointmentSystem.addAvailableSlotForDoctor("2024-01-16", "03:00 PM", monaID);
    appointmentSystem.addAvailableSlotForDoctor("2024-01-18", "11:00 AM", monaID);

    // Add specific slots for Dr. Tarek Hassan (Neurology)
    appointmentSystem.addAvailableSlotForDoctor("2024-01-15", "01:00 PM", tarekID);
    appointmentSystem.addAvailableSlotForDoctor("2024-01-16", "11:00 AM", tarekID);
    appointmentSystem.addAvailableSlotForDoctor("2024-01-17", "09:00 AM", tarekID);
    appointmentSystem.addAvailableSlotForDoctor("2024-01-19", "02:00 PM", tarekID);

    // Add specific slots for Dr. Youssef Adel (Cardiology)
    appointmentSystem.addAvailableSlotForDoctor("2024-01-16", "08:00 AM", youssefID);
    appointmentSystem.addAvailableSlotForDoctor("2024-01-17", "10:00 AM", youssefID);
    appointmentSystem.addAvailableSlotForDoctor("2024-01-18", "01:00 PM", youssefID);
    appointmentSystem.addAvailableSlotForDoctor("2024-01-19", "09:00 AM", youssefID);

    // Add specific slots for Dr. Laila Samir (Dermatology)
    appointmentSystem.addAvailableSlotForDoctor("2024-01-15", "02:00 PM", lailaID);
    appointmentSystem.addAvailableSlotForDoctor("2024-01-17", "11:00 AM", lailaID);
    appointmentSystem.addAvailableSlotForDoctor("2024-01-18", "09:00 AM", lailaID);
    appointmentSystem.addAvailableSlotForDoctor("2024-01-20", "10:00 AM", lailaID);

    // Add specific slots for Dr. Ayman Saeed (Neurology)
    appointmentSystem.addAvailableSlotForDoctor("2024-01-16", "01:00 PM", aymanID);
    appointmentSystem.addAvailableSlotForDoctor("2024-01-17", "03:00 PM", aymanID);
    appointmentSystem.addAvailableSlotForDoctor("2024-01-18", "10:00 AM", aymanID);
    appointmentSystem.addAvailableSlotForDoctor("2024-01-20", "11:00 AM", aymanID);

    // Default doctors and slots are now created silently
}

void addSampleAppointments(Appointment& appointmentSystem) {
    // Create sample patients (silently)
    Patient patient1("Sarah Ahmed", "Female", "15/03/1990", patientID++, "Chest pain: yes\nShortness of breath: no\n");
    Patient patient2("Kareem Ashraf", "Male", "22/07/1985", patientID++, "Skin rashes: yes\nItching: yes\n");
    Patient patient3("Emma Medhat", "Female", "10/12/1992", patientID++, "Frequent headaches: yes\nDizziness: no\n");
    Patient patient4("John Smith", "Male", "05/09/1988", patientID++, "Chest pain: no\nShortness of breath: yes\n");
    Patient patient5("Lili anwar", "Female", "18/06/1995", patientID++, "Skin rashes: no\nItching: yes\n");
    Patient patient6("Salma Ahmed", "Male", "30/11/1987", patientID++, "Frequent headaches: yes\nDizziness: yes\n");

    // Get doctors by specialty to find specific doctors
    vector<Doctor> cardiologyDoctors = appointmentSystem.getDoctorsBySpecialty("Cardiology");
    vector<Doctor> dermatologyDoctors = appointmentSystem.getDoctorsBySpecialty("Dermatology");
    vector<Doctor> neurologyDoctors = appointmentSystem.getDoctorsBySpecialty("Neurology");

    // Find Dr. Ahmed Ali (first cardiology doctor, ID: 1000)
    Doctor* drAhmed = nullptr;
    for (size_t i = 0; i < cardiologyDoctors.size(); i++) {
        if (cardiologyDoctors[i].getID() == 1000) {
            drAhmed = &cardiologyDoctors[i];
            break;
        }
    }

    // Find Dr. Mona Khaled (first dermatology doctor, ID: 1001)
    Doctor* drMona = nullptr;
    for (size_t i = 0; i < dermatologyDoctors.size(); i++) {
        if (dermatologyDoctors[i].getID() == 1001) {
            drMona = &dermatologyDoctors[i];
            break;
        }
    }

    // Find Dr. Tarek Hassan (first neurology doctor, ID: 1002)
    Doctor* drTarek = nullptr;
    for (size_t i = 0; i < neurologyDoctors.size(); i++) {
        if (neurologyDoctors[i].getID() == 1002) {
            drTarek = &neurologyDoctors[i];
            break;
        }
    }

    // Book appointments silently (no console output)
    if (drAhmed) {
        appointmentSystem.bookAppointmentSilent(&patient1, drAhmed, "2024-01-15", "11:00 AM");
        appointmentSystem.bookAppointmentSilent(&patient4, drAhmed, "2024-01-17", "02:00 PM");
    }

    if (drMona) {
        appointmentSystem.bookAppointmentSilent(&patient2, drMona, "2024-01-15", "10:00 AM");
        appointmentSystem.bookAppointmentSilent(&patient5, drMona, "2024-01-16", "09:00 AM");
    }

    if (drTarek) {
        appointmentSystem.bookAppointmentSilent(&patient3, drTarek, "2024-01-15", "01:00 PM");
        appointmentSystem.bookAppointmentSilent(&patient6, drTarek, "2024-01-16", "11:00 AM");
    }

    // Sample appointments are now created silently in the background
}

string askQuestions(const string& specialty) {
    string answers = "";
    string response;

    cout << "Answer the following questions for " << specialty << ":" << endl;

    if (specialty == "Cardiology") {
        cout << "1. Do you experience chest pain? (yes/no): ";
        cin >> response;
        answers += "Chest pain: " + response + "\n";

        cout << "2. Do you have shortness of breath? (yes/no): ";
        cin >> response;
        answers += "Shortness of breath: " + response + "\n";
    }
    else if (specialty == "Dermatology") {
        cout << "1. Do you have any skin rashes? (yes/no): ";
        cin >> response;
        answers += "Skin rashes: " + response + "\n";

        cout << "2. Do you have itching? (yes/no): ";
        cin >> response;
        answers += "Itching: " + response + "\n";
    }
    else if (specialty == "Neurology") {
        cout << "1. Do you experience frequent headaches? (yes/no): ";
        cin >> response;
        answers += "Frequent headaches: " + response + "\n";

        cout << "2. Do you feel dizzy? (yes/no): ";
        cin >> response;
        answers += "Dizziness: " + response + "\n";
    }

    cout << "Your answers: \n" << answers << endl;
    return answers;
}

int main() {
    Appointment appointmentSystem;
    addDefaultDoctors(appointmentSystem);
    addSampleAppointments(appointmentSystem);

    int choice;
    cout << "Welcome to the Clinic Booking System" << endl;
    cout << "Are you a:" << endl;
    cout << "1) New Doctor (Register)" << endl;
    cout << "2) Existing Doctor (View Schedule)" << endl;
    cout << "3) Patient" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        // New Doctor Registration
        string name, gender, dob, specialty;
        double fee;
        int slotCount;
        string date, time;

        cout << "Enter Doctor Details:" << endl;
        cout << "Name: "; cin.ignore(); getline(cin, name);
        cout << "Gender: "; getline(cin, gender);
        cout << "Date of Birth: "; getline(cin, dob);

        cout << "Specialty (Cardiology/Dermatology/Neurology): ";
        getline(cin, specialty);
        cout << "Consultation Fee: "; cin >> fee;

        Doctor newDoctor(name, gender, dob, doctorID++, specialty, fee);
        appointmentSystem.addDoctor(newDoctor);

        cout << "Enter number of available slots: ";
        cin >> slotCount;
        cin.ignore();

        for (int i = 0; i < slotCount; ++i) {
            cout << "Enter date (YYYY-MM-DD): "; getline(cin, date);
            cout << "Enter time (e.g., 10:00 AM): "; getline(cin, time);
            appointmentSystem.addAvailableSlotForDoctor(date, time, newDoctor.getID());
        }

        cout << "Doctor added successfully.\n";
        cout << "--- Doctor Information ---\n";
        cout << "ID: " << newDoctor.getID() << "\nName: " << newDoctor.getName()
             << "\nSpecialty: " << newDoctor.getSpecialty()
             << "\nFee: " << newDoctor.getConsultationFee() << endl;

        cout << "\nAvailable slots added:\n";
        vector<AppointmentSlot*> slots = appointmentSystem.getAvailableSlotsForDoctor(newDoctor.getID());
        for (AppointmentSlot* slot : slots) {
            if (!slot->isBooked) {
                cout << "- " << slot->date << " at " << slot->time << endl;
            }
        }
    }
    else if (choice == 2) {
        // Existing Doctor View Schedule
        cout << "Enter your name to view your schedule:" << endl;
        cout << "Available doctors in the system:" << endl;
        
        // Show all doctors first
        cout << "1. Dr. Ahmed Ali" << endl;
        cout << "2. Dr. Mona Khaled" << endl;
        cout << "3. Dr. Tarek Hassan" << endl;
        cout << "4. Dr. Youssef Adel" << endl;
        cout << "5. Dr. Laila Samir" << endl;
        cout << "6. Dr. Ayman Saeed" << endl;
        
        cout << "\nSelect your number (1-6): ";
        int doctorChoice;
        cin >> doctorChoice;
        
        int selectedDoctorID = -1;
        switch (doctorChoice) {
            case 1: selectedDoctorID = 1000; break;  // Dr. Ahmed Ali
            case 2: selectedDoctorID = 1001; break;  // Dr. Mona Khaled
            case 3: selectedDoctorID = 1002; break;  // Dr. Tarek Hassan
            case 4: selectedDoctorID = 1003; break;  // Dr. Youssef Adel
            case 5: selectedDoctorID = 1004; break;  // Dr. Laila Samir
            case 6: selectedDoctorID = 1005; break;  // Dr. Ayman Saeed
            default: 
                cout << "Invalid choice." << endl;
                return 0;
        }
        
        appointmentSystem.displayDoctorSchedule(selectedDoctorID);
    }
    else if (choice == 3) {
        string name, gender, dob, specialtyChoice;

        cout << "Enter Patient Details:" << endl;
        cout << "Name: "; cin.ignore(); getline(cin, name);
        cout << "Gender: "; getline(cin, gender);
        cout << "Date of Birth: "; getline(cin, dob);

        Patient newPatient(name, gender, dob, patientID++, "");

        cout << "Choose a specialty:" << endl;
        cout << "1) Cardiology\n2) Dermatology\n3) Neurology" << endl;
        cout << "Enter choice: ";
        int specChoice;
        cin >> specChoice;

        switch (specChoice) {
            case 1: specialtyChoice = "Cardiology"; break;
            case 2: specialtyChoice = "Dermatology"; break;
            case 3: specialtyChoice = "Neurology"; break;
            default: cout << "Invalid choice." << endl; return 0;
        }

        string medicalHistory = askQuestions(specialtyChoice);
        newPatient.setMedicalHistory(medicalHistory);

        cout << "Your Medical History is recorded as:\n" << medicalHistory << endl;

        cout << "\nAvailable doctors for " << specialtyChoice << ":" << endl;
        vector<Doctor> doctorsForSpecialty = appointmentSystem.getDoctorsBySpecialty(specialtyChoice);

        for (size_t i = 0; i < doctorsForSpecialty.size(); ++i) {
            cout << i + 1 << ") " << doctorsForSpecialty[i].getName()
                 << " - Price: " << doctorsForSpecialty[i].getConsultationFee() << endl;
        }

        cout << "\nSelect a doctor by number: ";
        int doctorChoice;
        cin >> doctorChoice;

        if (doctorChoice > 0 && doctorChoice <= doctorsForSpecialty.size()) {
            Doctor selectedDoctor = doctorsForSpecialty[doctorChoice - 1];

            cout << "\nAvailable slots for Dr. " << selectedDoctor.getName() << ":" << endl;
            vector<AppointmentSlot*> slots = appointmentSystem.getAvailableSlotsForDoctor(selectedDoctor.getID());
            vector<AppointmentSlot*> unbookedSlots;

            for (AppointmentSlot* slot : slots) {
                if (!slot->isBooked) {
                    cout << unbookedSlots.size() + 1 << ") " << slot->date << " - " << slot->time << endl;
                    unbookedSlots.push_back(slot);
                }
            }

            if (unbookedSlots.empty()) {
                cout << "No available slots found." << endl;
                return 0;
            }

            cout << "\nChoose a time slot by number: ";
            int slotChoice;
            cin >> slotChoice;

            if (slotChoice > 0 && slotChoice <= unbookedSlots.size()) {
                AppointmentSlot* chosenSlot = unbookedSlots[slotChoice - 1];

                cout << "\n--- Appointment Summary ---" << endl;
                cout << "Specialty: " << specialtyChoice << endl;
                cout << "Doctor: " << selectedDoctor.getName() << endl;
                cout << "Time: " << chosenSlot->date << " " << chosenSlot->time << endl;
                cout << "Consultation Fee: " << selectedDoctor.getConsultationFee() << endl;

                cout << "\nConfirm your appointment? (yes/no): ";
                string confirmation;
                cin >> confirmation;

                if (confirmation == "yes") {
                    appointmentSystem.bookAppointment(&newPatient, &selectedDoctor, chosenSlot->date, chosenSlot->time);
                    cout << "Appointment confirmed! You will receive a reminder 24 hours before the appointment." << endl;
                } else {
                    cout << "Appointment not confirmed." << endl;
                }
            } else {
                cout << "Invalid slot selection." << endl;
            }
        }
    }

    return 0;
}
