#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
#include "benefits.h"
#include "department.h"
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
    Department* department;
    char e_type;

public:
    Employee() :
        name("Unknown"), phone("Unknown"), email("Unknown"),
        employeeID("Unknown"), jobTitle("Unknown"),
        benefit(new Benefits), benNum(0),
        department(new Department), e_type('N') {}

    virtual ~Employee() {
        delete benefit;
        delete department;
    }

    void setName(string n) { name = n; }
    void setPhone(string p) { phone = p; }
    void setEmail(string e) { email = e; }
    void setEmployeeID(string id) { employeeID = id; }
    void setJobTitle(string title) { jobTitle = title; }
    void setBenefit(Benefits* b) { benefit = b; benNum = 1; }
    void setDepart(Department* d) { department = d; }
    void setType(char t) { e_type = t; }

    string getName() { return name; }
    string getPhone() { return phone; }
    string getEmail() { return email; }
    string getEmployeeID() { return employeeID; }
    string getJobTitle() { return jobTitle; }
    char getType() { return e_type; }
    string getDepartName() { return department->getDepartmentName(); }

    virtual void print() {
        cout << "Employee Name: " << name << endl;
        cout << "Phone: " << phone << endl;
        cout << "Email: " << email << endl;
        cout << "ID: " << employeeID << endl;
        cout << "Job Title: " << jobTitle << endl;

        cout << "Department: ";
        department->print();

        if (benNum == 1) {
            cout << "Benefits: ";
            benefit->print();
        }
    }

    virtual double getSalary() { return 0; }
};
#endif