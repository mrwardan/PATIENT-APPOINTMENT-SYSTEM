#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <iostream>
using namespace std;

class Schedule
{
private:
    string scheduleId;
    string scheduleDay;
    string scheduleTimeStart;
    string scheduleTimeEnd;
    string status;

public:
    Schedule *next;

    Schedule(){};
    Schedule(string scheduleId, string scheduleDay, string scheduleTimeStart, string scheduleTimeEnd, string status)
    {
        this->scheduleId = scheduleId;
        this->scheduleDay = scheduleDay;
        this->scheduleTimeStart = scheduleTimeStart;
        this->scheduleTimeEnd = scheduleTimeEnd;
        this->status = status;
    };
    ~Schedule(){};

    string getScheduleId() const
    {
        return this->scheduleId;
    }
    string getScheduleDay() const
    {
        return this->scheduleDay;
    }
    string getScheduleTimeStart() const
    {
        return this->scheduleTimeStart;
    }
    string getScheduleTimeEnd() const
    {
        return this->scheduleTimeEnd;
    }
    string getStatus() const
    {
        return this->status;
    }
    void setScheduleId(string scheduleId)
    {
        this->scheduleId = scheduleId;
    }
    void setScheduleDay(string scheduleDay)
    {
        this->scheduleDay = scheduleDay;
    }
    void setScheduleTimeStart(string scheduleTimeStart)
    {
        this->scheduleTimeStart = scheduleTimeStart;
    }
    void setScheduleTimeEnd(string scheduleTimeEnd)
    {
        this->scheduleTimeEnd = scheduleTimeEnd;
    }
    void setStatus(string status)
    {
        this->status = status;
    }
    void getdata()
    {
        cout << "\nEnter your free day : ";
        cin >> this->scheduleDay;
        cout << "\nEnter the appointment start time (8:am) : ";
        cin >> this->scheduleTimeStart;
        cout << "\nEnter the appointment end time (2:pm) : ";
        cin >> this->scheduleTimeEnd;
        this->status = "available";
    }
    void update(string scheduleId,
                string scheduleDay,
                string scheduleTimeStart,
                string scheduleTimeEnd,
                string status)
    {
        this->scheduleId = scheduleId;
        this->scheduleDay = scheduleDay;
        this->scheduleTimeStart = scheduleTimeStart;
        this->scheduleTimeEnd = scheduleTimeEnd;
        this->status = status;
    }

    void printScheduleDetail()
    {
        cout << this->scheduleId << "\t\t" << this->scheduleDay << "\t\t" << this->scheduleTimeStart << "\t\t" << this->scheduleTimeEnd << "        " << this->status << "\n";
    }
};

class List
{
private:
    Schedule *head;
    Schedule *node;

public:
    List()
    {
        head = NULL;
        node = NULL;
    }
    ~List(){};
    bool isEmpty() { return head == NULL; }
    void InsertNode(string scheduleId,
                    string scheduleDay,
                    string scheduleTimeStart,
                    string scheduleTimeEnd,
                    string status)
    {
        int currentIndex = 0;
        Schedule *currNode = head;
        Schedule *prevNode = NULL;
        while (currNode && scheduleId > currNode->getScheduleId())
        {
            prevNode = currNode;
            currNode = currNode->next;
        }
        Schedule *newNode = new Schedule;
        newNode->update(scheduleId, scheduleDay, scheduleTimeStart, scheduleTimeEnd, status);
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

        //  return newNode;
    }

    Schedule *findNode(string id)
    {
        Schedule *currNode = head;
        while (currNode)
        {
            if (currNode->getScheduleId() != id)
                currNode = currNode->next;
            else
                return currNode;
        }

        return 0;
    }
    Schedule *getId()
    {

        Schedule *temp;

        if (node)
        {
            temp = node;
            node = node->next;

            return temp;
        }
        else
            node = head;
        return NULL;
    }

    void displayList()
    {

        Schedule *currNode = head;
        if (currNode == NULL)
        {
            cout << "Empty \n";
        }

        while (currNode)
        {

            currNode->printScheduleDetail();
            currNode = currNode->next;
        }
    }
};

#endif