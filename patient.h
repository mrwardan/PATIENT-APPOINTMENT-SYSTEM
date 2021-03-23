#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include "person.h"
using namespace std;

class Patient : public Person
{

public:
    Patient *next;
    Patient() : Person()
    {
    }
    Patient(string patientId, string firstName, string lastName, string gender, string dateOfBirth, string phoneNumber) : Person(firstName, lastName, gender, dateOfBirth, phoneNumber, patientId)
    {
    }
    ~Patient()
    {
    }

    void setPatientInfo()
    {
        cout << "\nEnter First name : ";
        cin >> this->firstName;
        cout << "Enter Last Name. : ";
        cin >> lastName;
        cout << "Enter your gender in small letter (male , female) : ";
        cin >> this->gender;
        cout << "Enter your date of birth  (10-10-1997) : ";
        cin >> this->dateOfBirth;
        cout << "Enter your phone number : ";
        cin >> this->phoneNumber;

        this->setId("P" + firstName.substr(0, 1) + lastName.substr(0, 1) + gender.substr(0, 1) + phoneNumber.substr(0, 2));
        this->update(id, firstName, lastName, gender, dateOfBirth, phoneNumber);
    }
    void update(string patientId, string firstName, string lastName, string gender, string dateOfBirth, string phoneNumber)
    {
        this->id = "P" + firstName.substr(0, 1) + lastName.substr(0, 1) + gender.substr(0, 1) + phoneNumber.substr(0, 2);
        this->firstName = firstName;
        this->lastName = lastName;
        this->gender = gender;
        this->dateOfBirth = dateOfBirth;
        this->phoneNumber = phoneNumber;
    }
    void printPatientList()
    {

        cout << this->id << "\t\t" << this->firstName + " " + this->lastName << "\t\t" << this->gender << "\t\t" << this->dateOfBirth << "\t\t" << this->phoneNumber << "\n";
    }
};
class PatientList
{
private:
    Patient *head;

public:
    PatientList() { head = NULL; }
    ~PatientList(){};
    bool isEmpty() { return head == NULL; }
    void InsertNode(string patientId, string firstName, string lastName, string gender, string dateOfBirth, string phoneNumber)
    {
        int currentIndex = 0;
        Patient *currNode = head;
        Patient *prevNode = NULL;
        while (currNode)
        {
            prevNode = currNode;
            currNode = currNode->next;
        }
        Patient *newNode = new Patient;
        newNode->update(patientId, firstName, lastName, gender, dateOfBirth, phoneNumber);
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
    void *findNode(string id, string phone)
    {
        Patient *currNode = head;
        while (currNode && currNode->getId() != id)
        {
            currNode = currNode->next;
        }
        if (currNode)
        {
            currNode->setPhoneNumber(phone);
            cout << "\nPhone Number is updated successfully\n";
        }
        else
            cout << "Sorry the record is not found";
        
    }
    int deleteNode(string id) // Delete contacts or remove contacts from menu
    {
        Patient *prevNode = NULL;
        Patient *currNode = head;
        int currIndex = 1;

        while (currNode && currNode->getId() != id)
        {
            prevNode = currNode;
            currNode = currNode->next;
            currIndex++;
        }
        if (currNode)
        {
            if (prevNode)
            {
                prevNode->next = currNode->next;
                delete currNode;
                cout << "Record deleted successfully" << endl;
            }
            else
            {
                head = currNode->next;
                delete currNode;
                cout << "Record deleted successfully" << endl;
            }

            return currIndex;
        }
        cout << "Record is not  found" << endl;

        return 0;
    }
    void searchPatientInfoByName(string firstName)
    {
        Patient *currNode = head;
        while (currNode && currNode->getFirstName() != firstName)
        {
            currNode = currNode->next;
        }
        if (currNode)
            currNode->printPatientList();
        else
        {
            cout << "Sorry the record not found " << endl;
        }
    }
    void searchPatientInfoById(string id)
    {
        Patient *currNode = head;
        while (currNode && currNode->getId() != id)
        {
            currNode = currNode->next;
        }
        if (currNode)
            currNode->printPatientList();
        else
        {
            cout << "Sorry the record not found " << endl;
        }
    }
    void insertionSort()
    {
        // Initialize sorted linked list
        Patient *sorted = NULL;

        // Traverse the given linked list and insert every
        // node to sorted
        Patient *current = head;
        while (current != NULL)
        {
            // Store next for next iteration
            Patient *next = current->next;

            // insert current in sorted linked list
            sortedInsert(&sorted, current);

            // Update current
            current = next;
        }

        // Update head_ref to point to sorted linked list
        head = sorted;
    }
    void sortedInsert(Patient **head_ref, Patient *new_node)
    {
        Patient *current;
        /* Special case for the head end */
        if (*head_ref == NULL || (*head_ref)->getFirstName() >= new_node->getFirstName())
        {
            new_node->next = *head_ref;
            *head_ref = new_node;
        }
        else
        {
            /* Locate the node before the point of insertion */
            current = *head_ref;
            while (current->next != NULL &&
                   current->next->getFirstName() < new_node->getFirstName())
            {
                current = current->next;
            }
            new_node->next = current->next;
            current->next = new_node;
        }
    }

    void displayList()
    {

        Patient *currNode = head;
        if (currNode == NULL)
        {
            cout << "Empty \n";
        }

        while (currNode)
        {

            currNode->printPatientList();
            // currNode->Sc
            currNode = currNode->next;
        }
    }
};

#endif