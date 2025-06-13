#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <iostream>
#include <string>
using namespace std;

class Department {
private:
    string departID;
    string departName;

public:
    Department() : departID("Unknown"), departName("Unknown") {}

    void read() {
        cout << "Enter Department Name: ";
        getline(cin >> ws, departName);
        cout << "Enter Department ID: ";
        getline(cin >> ws, departID);
    }

    void setDepartmentID(string id) { departID = id; }
    void setDepartmentName(string name) { departName = name; }

    string getDepartmentID() { return departID; }
    string getDepartmentName() { return departName; }

    void print() {
        cout << departName << " (ID: " << departID << ")" << endl;
    }
};
#endif