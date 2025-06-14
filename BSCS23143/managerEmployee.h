#ifndef MANAGEREMPLOYEE_H
#define MANAGEREMPLOYEE_H

#include <iostream>
using namespace std;

class ManagerEmployee : public SalariedEmployee
{
private:
    double bonus;
public:
    ManagerEmployee()
    {
        bonus = 0;
        e_type = 'm';
    }

    void read()
    {
        SalariedEmployee::read();
        cout << "Enter Bonus: ";
        cin >> bonus;
    }

    void setBonus(double bonus)
    {
        this->bonus = bonus;
    }

    double getBonus()
    {
        return bonus;
    }

    double getSalary() {
        double base = salary + bonus;
        double ben = benefit ? benefit->calculateBenefit() : 0.0;
        return base + ben;
    }

    void printMore()
    {
        cout << "Bonus -> " << bonus << endl;
    }

    void print()
    {
        SalariedEmployee::print();
        cout << "Bonus -> " << bonus << endl;
        cout << "Total Cash To Earn -> " << getSalary() << endl;
    }
};

#endif 