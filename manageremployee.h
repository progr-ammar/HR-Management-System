#ifndef MANAGEREMPLOYEE_H
#define MANAGEREMPLOYEE_H

#include "salariedemployee.h"

class ManagerEmployee : public SalariedEmployee {
private:
    double bonus;
public:
    ManagerEmployee() : bonus(0) {}

    void setBonus(double b) { bonus = b; }
    double getBonus() { return bonus; }

    double getSalary() override {
        double base = salary + bonus;
        return (benNum == 1) ? base + benefit->calculateBenefit() : base;
    }

    void print() override {
        SalariedEmployee::print();
        cout << "Bonus: $" << bonus << "\nAdjusted Total: $" << getSalary() << endl;
    }
};
#endif