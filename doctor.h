#ifndef DOCTOR_H
#define DOCTOR_H

#include "person.h"
#include "schedule.h"
#include <iostream>

using namespace std;

class Doctor : public Person
{
public:
    Doctor *next;
    Schedule *schedule[10];
    int i = 0;

    Doctor() : Person()
    {
        for (int k = 0; k < 10; k++)
        {
            schedule[k] = NULL;
        }
    }
    Doctor(string doctorId, Schedule schedule, string firstName, string lastName, string gender, string dateOfBirth, string phoneNumber) : Person(firstName, lastName, gender, dateOfBirth, phoneNumber, doctorId)
    {
    }
    ~Doctor()
    {
    }

    void update(string doctorId, string firstName, string lastName, string gender, string dateOfBirth, string phoneNumber)
    {
        this->id = doctorId;
        this->firstName = firstName;
        this->lastName = lastName;
        this->gender = gender;
        this->dateOfBirth = dateOfBirth;
        this->phoneNumber = phoneNumber;
    }
    void printDoctorInfo()
    {
        cout << this->id << "\t\t" << this->firstName + " " + this->lastName << "\t\t" << this->gender << "\t\t" << this->dateOfBirth << "\t" << this->phoneNumber << "\n";
    }
    void printDoctorSchduel()
    {
        // cout << endl;

        int size = sizeof(schedule) / sizeof(schedule[0]);
        for (int k = 0; k < size; k++)
        {
            if (schedule[k] != NULL)
            {
                cout << " " << firstName << " " << lastName << "\t\t";

                schedule[k]->printScheduleDetail();
                cout << endl;
            }
        }
    }
    void updateSchduel(Schedule *schedule)
    {

        // schedule->printScheduleDetail();
        int pos1, pos2;
        pos1 = schedule->getScheduleTimeStart().find(":");
        pos2 = schedule->getScheduleTimeEnd().find(":");
        schedule->setScheduleId(this->id + "_" + schedule->getScheduleDay().substr(0, 1) + schedule->getScheduleTimeStart().substr(0, pos1) + schedule->getScheduleTimeEnd().substr(0, pos2));
        this->schedule[i] = schedule;

        i++;
        // = schedule;
    }
};
class DoctorList
{
private:
    Doctor *head;

public:
    DoctorList() { head = NULL; }
    ~DoctorList(){};
    bool isEmpty() { return head == NULL; }
    void InsertNode(List schduel, int i, string doctorId, string firstName, string lastName, string gender, string dateOfBirth, string phoneNumber)
    {
        int currentIndex = 0;
        Doctor *currNode = head;
        Doctor *prevNode = NULL;
        while (currNode && doctorId > currNode->getId())
        {
            prevNode = currNode;
            currNode = currNode->next;
        }
        Doctor *newNode = new Doctor;
        newNode->update(doctorId, firstName, lastName, gender, dateOfBirth, phoneNumber);
        string scId;
        int index;
        Schedule *temp;

        while (i != 0)
        {
            temp = schduel.getId();
            if (temp != NULL)
            {
                scId = temp->getScheduleId();
                index = scId.find("_");
                scId = scId.substr(0, index);

                if (newNode)
                {
                    if (newNode->getId() == scId)
                    {
                        newNode->updateSchduel(temp);
                    }
                }
            }
            i--;
        }
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
    Doctor *getDoctor(string firstName)
    {
        Doctor *currNode = head;
        while (currNode && currNode->getFirstName() != firstName)
        {
            currNode = currNode->next;
        }
        if (currNode)
            return currNode;
        else
        {
            return NULL;
        }
    }

    Doctor *findNode(string id, int &index)
    {
        Doctor *currNode = head;
        int size = 0;
        while (currNode && size < 10)
        {
            if (currNode->schedule[size] != NULL)
            {
                if (currNode->schedule[size]->getScheduleId() == id)
                {
                    if (currNode->schedule[size]->getStatus() == "available")
                    {
                        index = size;
                        currNode->schedule[size]->setStatus("Booked");
                        return currNode;
                        // currNode->printDoctorSchduel();
                    }
                }
                size++;

                // currNode = currNode->next;
            }
            else
            {
                size = 0;
                currNode = currNode->next;
            }
        }
        return NULL;
    }
    void findByFirstName(string firstName)
    {
        Doctor *currNode = head;
        while (currNode && currNode->getFirstName() != firstName)
        {
            currNode = currNode->next;
        }
        if (currNode)
            currNode->printDoctorSchduel();
        else
        {
            cout << "Sorry the record not found " << endl;
        }
    }
    void findAvialableDoctor()
    {
        Doctor *currNode = head;
        int size = 0;
        while (currNode && size < 10)
        {
            if (currNode->schedule[size] != NULL)
            {

                if (currNode->schedule[size]->getStatus() == "available")
                {
                    size++;

                    currNode->printDoctorSchduel();
                }
                currNode = currNode->next;
            }
            else
                size = 0;
        }
    }
    void searchDoctorInfoByName(string firstName)
    {
        Doctor *currNode = head;
        while (currNode && currNode->getFirstName() != firstName)
        {
            currNode = currNode->next;
        }
        if (currNode)
            currNode->printDoctorInfo();
        else
        {
            cout << "Sorry the record not found " << endl;
        }
    }
    void displayList()
    {

        Doctor *currNode = head;
        if (currNode == NULL)
        {
            cout << "Empty \n";
        }

        while (currNode)
        {

            currNode->printDoctorInfo();
            currNode = currNode->next;
        }
    }
    void displaySchedul()
    {

        Doctor *currNode = head;
        if (currNode == NULL)
        {
            cout << "Empty \n";
        }

        while (currNode)
        {

            currNode->printDoctorSchduel();
            currNode = currNode->next;
        }
    }
};
#endif