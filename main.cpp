#include "windows.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <cstdio>
#include "person.h"
#include "schedule.h"
#include "doctor.h"
#include "patient.h"
#include "appointment.h"
#include "receptionist.h"
#include "menusAndHeaders.h"
using namespace std;

int main()
{
    List schudele;
    DoctorList doctor;
    PatientList patient;
    Patient p;
    AppointmentList *appointment = new AppointmentList();

    fstream file, file2, file3;
    file.open("patiten.txt");
    file2.open("doctor_list.txt");
    file3.open("doctor_schedule.txt");

    string id, firstName, lastName, gender, dateOfBirth, phoneNumber;
    string day, startTime, endTime, status;
    int choice, user;
    int isPatient = 1;
    int isDoctor = 2;
    int isReceptionist = 3;
    int i = 6;

    // // reading patient data from file

    while (getline(file, id, '\n'))
    {
        file >> id >> firstName >> lastName >> gender >> dateOfBirth >> phoneNumber;
        patient.InsertNode(id, firstName, lastName, gender, dateOfBirth, phoneNumber);
    }

    while (getline(file3, id, '\n'))
    {

        file3 >> id >> day >> startTime >> endTime >> status;
        schudele.InsertNode(id, day, startTime, endTime, status);
    }

    // reading doctor data from file

    while (getline(file2, id, '\n'))
    {

        file2 >> id >> firstName >> lastName >> gender >> dateOfBirth >> phoneNumber;
        doctor.InsertNode(schudele, i, id, firstName, lastName, gender, dateOfBirth, phoneNumber);
    }

    do
    {
        mainManu();
        cin >> user;
        do
        {
            if (user == isPatient)
            {

                patientMenu();
                cin >> choice;
            }
            else if (user == isDoctor)
            {
                doctorMenu();

                cin >> choice;
            }
            else if (user == isReceptionist)
            {
                recMenu();
                cin >> choice;
            }
            else if (user == 4)
            {
                Sleep(1000);
                cout << "\n\t\t\tThank you for using the program :) \n\n";
                Sleep(2000);

                return 0;
            }
            else
                cout << "\nsorry this option is not avilable\n";

            //         // cout << "12) Exit\n\n";

            switch (choice)
            {
            case 1: //New Record
                if (user == isPatient)
                {
                    doctorTableHeaders();
                    doctor.displaySchedul();
                    cout << "-----------------------------------------------------------------------------------\n";
                    cout << "\nPlease write the appointment id : ";
                    cin >> id;
                    int index;
                    Doctor *d = doctor.findNode(id, index);
                    Schedule *s;
                    if (d != NULL)
                    {
                        s = d->schedule[index];

                        p.setPatientInfo();
                        patient.InsertNode(p.getId(), p.getFirstName(), p.getLastName(), p.getGender(), p.getDateOfBirth(), p.getPhoneNumber());
                        appointment->InsertNode(&p, d, s);
                        cout << "\n";
                        // Sleep(2000);
                        Sleep(500);
                        cout << "\nBooked Successfully\n";
                        cout << "\nYour booking information\n\n\n";
                        // sleep(1000);
                        patientBookingTableHeaders();

                        appointment->displayAppointments();

                        Sleep(2000);
                    }
                    else
                        cout << "\nSorry the appointment you choose is booked or not avaliable" << endl;

                    break;
                }
                //}

                else if (user == isDoctor)
                {
                    patientBookingTableHeaders();
                    if (appointment != NULL)
                    {
                        appointment->displayAppointments();
                    }

                    cout << "--------------------------------------------------------------------------------------------\n\n";
                    Sleep(2000);
                }

                if (user == isReceptionist) // add else
                {

                    patient.displayList();
                    cout << "--------------------------------------------------------------------------------------------\n\n";
                    Sleep(2000);
                }
                break;

            case 2: //Display All Records
                if (user == isPatient)
                {
                    int pos;
                    Sleep(500);
                    doctorTableHeaders();
                    doctor.displaySchedul();
                    cout << "--------------------------------------------------------------------------------------------------------\n";

                    Sleep(2000);
                }
                if (user == isDoctor)
                {
                    cout << "\n\n"
                         << "Enter Patient First Name : ";
                    cin >> firstName;
                    cout << "\n\n";
                    Sleep(500);
                    patientInfoTableHeaders();
                    patient.searchPatientInfoByName(firstName);

                    cout << "--------------------------------------------------------------------------------------------\n\n";
                    Sleep(2000);
                }
                if (user == isReceptionist)
                {

                    cout << "\n\n--------------------------------------------------------------------------------------------\n";
                    doctorInfoTableHeaders();

                    doctor.displayList();

                    cout << "--------------------------------------------------------------------------------------------\n\n";
                    Sleep(2000);
                }

                break;

            case 3:
                if (user == isPatient)
                {
                    int pos1;
                    int pos2;
                    cout << "\n"
                         << "Please enter the doctor first name : ";
                    cin >> firstName;
                    Sleep(500);
                    doctorTableHeaders();
                    doctor.findByFirstName(firstName);

                    cout << "------------------------------------------------------------------------------------------------------------\n";
                    Sleep(2000);
                }
                if (user == isDoctor)
                {
                    cout << "\n\n"
                         << "Enter Patient ID : ";
                    cin >> id;

                    Sleep(500);
                    patientInfoTableHeaders();
                    patient.searchPatientInfoById(id);

                    cout << "------------------------------------------------------------------------------------------------------------\n\n";
                    Sleep(2000);
                }
                if (user == isReceptionist)
                {
                    cout << "\nPlesae enter the doctor first name : ";
                    cin >> firstName;
                    Sleep(500);
                    doctorTableHeaders();

                    doctor.searchDoctorInfoByName(firstName);

                    cout << "------------------------------------------------------------------------------------------------------------\n\n";
                    Sleep(2000);
                }

                break;

            case 4:
                if (user == isPatient || user == isReceptionist)
                {
                    Sleep(500);
                    doctorTableHeaders();
                    doctor.findAvialableDoctor();

                    cout << "------------------------------------------------------------------------------------------------------------\n\n";
                    Sleep(2000);
                }
                if (user == isDoctor)
                {
                    Sleep(500);
                    cout << "\nFill in your schdeule information\n";

                    cout << "\nEnter your first name : ";
                    cin >> firstName;
                    Doctor *d = doctor.getDoctor(firstName);
                    Schedule s;
                    if (d)
                    {
                        s.getdata();
                        doctor.getDoctor(firstName)->updateSchduel(&s);
                        doctorTableHeaders();

                        doctor.findByFirstName(firstName);
                        cout << "\n----------------------------------------------------------------------------------\n";
                    }

                    Sleep(2000);
                }

                break;

            case 5:
                // char tempChar1;
                // char tempChar2;
                if (user == isReceptionist)
                {
                    cout << "\n//////////////////////// BEFORE SORTING//////////////////////////\n";
                    cout << "\nThe Patient list after sorting in asending order\n\n";
                    Sleep(500);
                    patientInfoTableHeaders();
                    patient.displayList();
                    Sleep(3000);

                    patient.insertionSort();

                    cout << "\n//////////////////////// BEFORE SORTING//////////////////////////\n";

                    cout << "\nThe Patient list after sorting in asending order\n\n";
                    Sleep(500);
                    patientInfoTableHeaders();
                    patient.displayList();
                    Sleep(3000);
                }

                break;
            case 6:
                if (user == isReceptionist)
                {
                    Sleep(500);
                    patientInfoTableHeaders();

                    patient.displayList();
                    cout << "------------------------------------------------------------------------------------------------------------\n\n";

                    cout << "\nPlease enter the patiten Id : ";
                    cin >> id;
                    cout << "\nPlease enter the new phone number (0113205080) : ";
                    cin >> phoneNumber;

                    patient.findNode(id, phoneNumber);
                    Sleep(500);
                    patientInfoTableHeaders();

                    patient.displayList();

                    cout << "------------------------------------------------------------------------------------------------------------\n\n";
                    Sleep(2000);
                }
                break;

            case 7:
                if (user == isReceptionist)
                {
                    Sleep(500);
                    patientInfoTableHeaders();

                    patient.displayList();
                    cout << "------------------------------------------------------------------------------------------------------------\n";

                    cout << "------------------------------------------------------------------------------------------------------------\n\n";
                    cout << "\nPlease enter the patiten Id : ";
                    cin >> id;

                    patient.deleteNode(id);
                    patientInfoTableHeaders();

                    patient.displayList();
                    cout << "------------------------------------------------------------------------------------------------------------\n\n";
                    Sleep(2000);
                }

                break;

            case 8:
                cout << "\nReturning to the main interface\n";
                Sleep(1000);
                break;

            case 9: //exit
                system("cls");
                cout << "\n\t\t\tThank you for using the program :) \n\n";
                Sleep(2000);
                return 0;

                break;
            }
        } while (choice != 8);

    } while (choice != 9);
}