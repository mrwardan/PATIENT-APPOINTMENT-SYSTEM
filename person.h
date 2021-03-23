#ifndef PERSON_H
#define PERSON_H

#include <iostream>
using namespace std;

class Person
{

public:
    string firstName;
    string lastName;
    string gender;
    string dateOfBirth;
    string phoneNumber;
    string id;
    Person()
    {
        this->firstName = " ";
        this->lastName = " ";
        this->gender = " ";
        this->dateOfBirth = " ";
        this->phoneNumber = " ";
    }
    Person(string firstName, string lastName, string gender, string dateOfBirth, string phoneNumber, string id)
    {
        this->firstName = firstName;
        this->lastName = lastName;
        this->gender = gender;
        this->dateOfBirth = dateOfBirth;
        this->phoneNumber = phoneNumber;
        this->id = id;
    }
    ~Person()
    {
    }
    string getFirstName() const
    {
        return this->firstName;
    }
    string getLastName() const
    {
        return this->lastName;
    }
    string getGender() const
    {
        return this->gender;
    }
    string getDateOfBirth() const
    {
        return this->dateOfBirth;
    }

    string getPhoneNumber() const
    {
        return this->phoneNumber;
    }
    string getId() const
    {
        return this->id;
    }
    void setFirstName(string firstName)
    {
        this->firstName = firstName;
    }
    void setLastName(string lastName)
    {
        this->lastName = lastName;
    }
    void setGender(string gender)
    {
        this->gender = gender;
    }
    void setDateOfBirth(string dateOfBirth)
    {
        this->dateOfBirth = dateOfBirth;
    }

    void setPhoneNumber(string phoneNumber)
    {
        this->phoneNumber = phoneNumber;
    }
    void setId(string id)
    {
        this->id = id;
    }
};
#endif