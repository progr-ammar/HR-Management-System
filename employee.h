#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
#include "benefits.h"
using namespace std;

class Employee {
protected:
    string name;
    string phone;
    string email;
    string employeeID;
    string jobTitle;
    Benefits* benefit;
    int benNum;
public:
    Employee() :
        name("Unknown"),
        phone("Unknown"),
        email("Unknown"),
        employeeID("Unknown"),
        jobTitle("Unknown"),
        benefit(nullptr),
        benNum(0) {}

    ~Employee() {
        delete benefit;
    }

    void setName(string n) { name = n; }
    void setPhone(string p) { phone = p; }
    void setEmail(string e) { email = e; }
    void setEmployeeID(string id) { employeeID = id; }
    void setJobTitle(string title) { jobTitle = title; }
    void setBenefit(Benefits* b) { benefit = b; benNum = 1; }

    string getName() { return name; }
    string getPhone() { return phone; }
    string getEmail() { return email; }
    string getEmployeeID() { return employeeID; }
    string getJobTitle() { return jobTitle; }

    virtual void print() {
        cout << "Name: " << name << "\nPhone: " << phone
            << "\nEmail: " << email << "\nID: " << employeeID
            << "\nJob Title: " << jobTitle << endl;

        if (benNum == 1) {
            cout << "\nBenefits:\n";
            benefit->print();
        }
    }
};
#endif