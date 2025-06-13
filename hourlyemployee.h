#ifndef HOURLYEMPLOYEE_H
#define HOURLYEMPLOYEE_H

#include "employee.h"

class HourlyEmployee : public Employee {
private:
    double hoursWorked;
    double rate;
public:
    HourlyEmployee() : hoursWorked(0), rate(0) {}

    void setHoursWorked(double h) { hoursWorked = h; }
    void setRate(double r) { rate = r; }
    double getHoursWorked() { return hoursWorked; }
    double getRate() { return rate; }

    double getSalary() override {
        double base = hoursWorked * rate;
        return (benNum == 1) ? base + benefit->calculateBenefit() : base;
    }

    void print() override {
        Employee::print();
        cout << "Type: Hourly\nHours: " << hoursWorked
            << "\nRate: $" << rate << "/hr\nTotal: $" << getSalary() << endl;
    }
};
#endif