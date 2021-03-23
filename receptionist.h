#ifndef Doctor_H
#define DOCTOR_H

#include <iostream>
#include "person.h"
#include "appointment.h"

class Receptionist : public Person
{
private:
    Appointment appointment;

public:
    Receptionist() : Person()
    {
    }
    Receptionist(Appointment appointment, string firstName, string lastName, string gender, string dateOfBirth, string phoneNumber, string receptionistId) : Person(firstName, lastName, gender, dateOfBirth, phoneNumber, receptionistId)
    {
        this->appointment = appointment;
    }
    ~Receptionist()
    {
    }
    Appointment getAppointment() const
    {
        return this->appointment;
    }
    string getReceptionistId() const
    {
        return this->getId();
    }
    void setAppointment(Appointment appointment)
    {
        this->appointment = appointment;
    }
    void printAppointmentInfo()
    {
        this->appointment.printAppointment();
    }
    void setReceptionistId(string receptionistId)
    {
        this->setId(receptionistId);
    }
};
#endif
