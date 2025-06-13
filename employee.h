#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    string phone;
    string email;
    string employeeID;
    string jobTitle;
public:
    Employee() {
        name = phone = email = employeeID = jobTitle = "Unknown";
    }

    // Basic setters/getters
    void setName(string n) { name = n; }
    string getName() { return name; }
    void setPhone(string p) { phone = p; }
    string getPhone() { return phone; }
    void setEmail(string e) { email = e; }
    string getEmail() { return email; }
    void setEmployeeID(string id) { employeeID = id; }
    string getEmployeeID() { return employeeID; }
    void setJobTitle(string title) { jobTitle = title; }
    string getJobTitle() { return jobTitle; }

    virtual void print() {
        cout << "Name: " << name << "\nID: " << employeeID
            << "\nJob Title: " << jobTitle << endl;
    }
};
#endif