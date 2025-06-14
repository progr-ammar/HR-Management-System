#ifndef HOURLYEMPLOYEE_H
#define HOURLYEMPLOYEE_H

#include <iostream>
using namespace std;

class HourlyEmployee : public Employee
{
private:
    double hoursWorked;
    double rate;

public:
    HourlyEmployee()
    {
        hoursWorked = 0;
        rate = 0;
        e_type = 'h';
    }

    void read()
    {
        Employee::read();
        cout << "Enter Hours Worked: ";
        cin >> hoursWorked;
        cout << "Enter Rate: ";
        cin >> rate;
    }

    void setHoursWorked(double hoursWorked)
    {
        this->hoursWorked = hoursWorked;
    }

    void setRate(double rate)
    {
        this->rate = rate;
    }

    double getHoursWorked()
    {
        return hoursWorked;
    }

    double getRate()
    {
        return rate;
    }

    double getSalary() {
        double base = hoursWorked * rate;
        double ben = benefit ? benefit->calculateBenefit() : 0.0;
        return base + ben;
    }

    void printMore()
    {
        cout << "Hours Worked -> " << hoursWorked << "\tRate -> " << rate << endl;
    }

    void print()
    {
        Employee::print();
        cout << "Hours Worked -> " << hoursWorked << endl;
        cout << "Rate -> " << rate << endl;
        cout << "Total Cash To Earn -> " << getSalary() << endl;
    }
};

#endif