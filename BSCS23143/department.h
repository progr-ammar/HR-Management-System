#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <iostream>
using namespace std;

class Department
{
private:
    string departID;
    string departName;

public:
    Department()
    {
        departName = "Unknown";
        departID = "Unknown";
    }

    void read()
    {
        cin.ignore();
        cout << "Enter Department Name: ";
        getline(cin, departName);
        cout << "Enter Department ID: ";
        getline(cin, departID);
    }

    void setDepartmentName(string departName)
    {
        this->departName = departName;
    }

    void setDepartmentID(string departID)
    {
        this->departID = departID;
    }

    string getDepartmentID()
    {
        return departID;
    }
    string getDepartmentName()
    {
        return departName;
    }

    void print()
    {
        cout << "Department Name -> " << departName << "\t\t" << "Department ID -> " << departID << endl;
    }
};

#endif