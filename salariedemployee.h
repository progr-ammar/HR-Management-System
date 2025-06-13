#ifndef SALARIEDEMPLOYEE_H
#define SALARIEDEMPLOYEE_H

#include "employee.h"

class SalariedEmployee : public Employee {
private:
    double salary;
public:
    SalariedEmployee() : salary(0) {}

    void setSalary(double s) { salary = s; }
    double getSalary() { return salary; }

    double getSalary() override {
        return (benNum == 1) ? salary + benefit->calculateBenefit() : salary;
    }

    void print() override {
        Employee::print();
        cout << "Type: Salaried\nSalary: $" << salary
            << "\nTotal: $" << getSalary() << endl;
    }
};
#endif