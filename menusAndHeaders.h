#ifndef MENUSANDHEADERS_H
#define MENUSANDHEADERS_H

#include <iostream>
using namespace std;

void mainManu()
{
    cout << "\t\t****************************************************************\n";
    cout << "\n\t\t\t\t**Patient Appointment System**\n\n";
    cout << "\t\t****************************************************************\n";
    cout << "\n\t\t\t\t (1) Patitent\n\t\t\t\t (2) Doctor\n\t\t\t\t (3) Reciptionist\n\t\t\t\t (4) Exit";
    cout << "\n\n\t\t****************************************************************\n\n";
    cout << " Enter your choise : ";
}
void patientMenu()
{
    cout << "\n\n\t\t****************************************************************\n";

    cout << "\n\t\t\t\t1) Make an appointment\n";    //done
    cout << "\t\t\t\t2) Display Doctors Schdule\n";  //done
    cout << "\t\t\t\t3) Search doctor Name.\n";      //done
    cout << "\t\t\t\t4) serach available doctors\n"; //done
    cout << "\t\t\t\t8) return to user interface\n"; // done
    cout << "\t\t\t\t9) Exit\n\n";                   //done
    cout << "\t\t****************************************************************\n\n";

    cout << "What would you like to do? : ";
}
void doctorMenu()
{
    cout << "\n\n\t\t****************************************************************\n";

    cout << "\n\t\t\t\t1) Display All patient appointments\n"; //done
    cout << "\t\t\t\t2) Search patient Name\n";                // done
    cout << "\t\t\t\t3) Search patient by id\n";               // done
    cout << "\t\t\t\t4) Update schdule.\n";                    //done
    cout << "\t\t\t\t8) return to user interface\n";           // done
    cout << "\t\t\t\t9) Exit\n\n";                             //done
    cout << "\t\t****************************************************************\n\n";

    cout << "What would you like to do? : ";
}
void recMenu()
{
    cout << "\n\n\t\t****************************************************************\n";

    cout << "\n\t\t\t\t1) Display All patient list\n"; //done
    cout << "\t\t\t\t2) Display Doctors list\n";       //done
    cout << "\t\t\t\t3) Search doctor Name.\n";        //done
    cout << "\t\t\t\t4) serach available doctors\n";   //done
    cout << "\t\t\t\t5) Sort patients list by first name\n";
    cout << "\t\t\t\t6) Update patient phone number.\n"; //done
    cout << "\t\t\t\t7) Delete patient record\n";        //done
    cout << "\t\t\t\t8) return to user interface\n";     // done
    cout << "\t\t\t\t9) Exit\n\n";                       // done
    cout << "\t\t****************************************************************\n\n";

    cout << "What would you like to do? : ";
}
void doctorTableHeaders()
{
    cout << "\nThese are the avilable date and dcotors\n\n";
    cout << "----------------------------------------------------------------------------------\n";

    cout << "\nDoctor Name\t\t Schduel ID\t\t Day\t\tStart Time\tEnd Time\tStatus\n";
    cout << "-----------------------------------------------------------------------------------\n";
}
void doctorInfoTableHeaders()
{
    cout << "Doctor ID"
         << "\t"
         << "Doctor Name"
         << "\t\t"
         << "Gender"
         << "\t\t"
         << "Day Of Birth"
         << "\t\t"
         << "Phone Number"
         << "\n";
    cout << "--------------------------------------------------------------------------------------------\n";
}
void patientBookingTableHeaders()
{
    cout << "-----------------------------------------------------------------------------------------\n";
    cout << "Patient ID\t"
         << "Patient Name\t"
         << "Doctor Name\t"
         << "Appointment Day\t"
         << "Appointment Time\n";
    cout << "-----------------------------------------------------------------------------------------\n";
}
void patientInfoTableHeaders()
{
    // patientInfoTableHeaders();
    cout << "\n\n--------------------------------------------------------------------------------------------\n";
    cout << "Patient ID"
         << "\t"
         << "Patient Name"
         << "\t\t"
         << "Gender"
         << "\t\t"
         << "Day Of Birth"
         << "\t\t"
         << "Phone Number"
         << "\n";
    cout << "--------------------------------------------------------------------------------------------\n";
}
#endif