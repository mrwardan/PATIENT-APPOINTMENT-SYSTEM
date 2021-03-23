#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <iostream>
#include "doctor.h"
#include "patient.h"
using namespace std;

class Appointment
{
private:
    string appointmentid;
    string dateOfAppointment;
    string timeOfAppointment;

    Patient *patient;
    Doctor *doctor;
    Schedule *schedule;

public:
    Appointment *next;
    Appointment()
    {
        // patient = NULL;
        // doctor = NULL;
        // schedule = NULL;
    }
    Appointment(string appointmentid, Patient *patient, Doctor *doctor, Schedule *schedule, string dateOfAppointment, string timeOfAppointment)
    {
        this->appointmentid = appointmentid;
        this->dateOfAppointment = dateOfAppointment;
        this->timeOfAppointment = timeOfAppointment;
        this->patient = patient;
        this->doctor = doctor;
        this->schedule = schedule;
    }

    ~Appointment()
    {
    }
    string getAppointmentid() const
    {
        return this->appointmentid;
    }
    string getDateOfAppointment() const
    {
        return this->dateOfAppointment;
    }
    string getTimeOfAppointment() const
    {
        return this->timeOfAppointment;
    }
    // Patient getPatient() const
    // {
    //     return this->patient;
    // }
    // Doctor getDoctor() const
    // {
    //     return this->doctor;
    // }
    void setDateOfAppointment(string dateOfAppointment)
    {
        this->dateOfAppointment = dateOfAppointment;
    }
    void setTimeOfAppointment(string timeOfAppointment)
    {
        this->timeOfAppointment = timeOfAppointment;
    }
    // void setPatient(Patient patient)
    // {
    //     this->patient = patient;
    // }
    // void setDoctor(Doctor doctor)
    // {
    //     this->doctor = doctor;
    // }
    void setAppointmentid(string appointmentid)
    {
        this->appointmentid = appointmentid;
    }
    void update(Patient *patient, Doctor *doctor, Schedule *schedule)
    {
        this->patient = patient;
        this->doctor = doctor;
        this->schedule = schedule;
        this->dateOfAppointment = this->schedule->getScheduleDay();
        this->timeOfAppointment = this->schedule->getScheduleTimeStart() + " to " + this->schedule->getScheduleTimeEnd();
    }
    void printAppointment()
    {
        if (patient && schedule && doctor != NULL)
            cout << this->patient->getId() << "\t\t" << this->patient->getFirstName() << "\t\t" << this->doctor->getFirstName() << "\t\t" << dateOfAppointment << "\t\t" << timeOfAppointment << endl;
    }
};

class AppointmentList
{
private:
    Appointment *head;

public:
    AppointmentList() { head = NULL; }
    ~AppointmentList(){};
    bool isEmpty() { return head == NULL; }
    void InsertNode(Patient *patient, Doctor *doctor, Schedule *schedule)
    {
        Appointment *currNode=head;
       //  currNode=head;
        Appointment *prevNode = NULL;
        while (currNode && schedule->getScheduleId() > currNode->getAppointmentid())
        {
            prevNode = currNode;
            currNode = currNode->next;
        }
        Appointment *newNode = new Appointment;
        newNode->update(patient, doctor, schedule);
        if (prevNode == NULL)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            newNode->next = prevNode->next;
            prevNode->next = newNode;
        }
    }

    void displayAppointments()
    {

        Appointment *currNode = head;
        if (currNode == NULL)
        {
            cout << "Empty \n";
        }

        while (currNode)
        {

            currNode->printAppointment();
            currNode = currNode->next;
        }
    }
};

#endif