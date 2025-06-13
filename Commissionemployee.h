#ifndef COMMISSIONEMPLOYEE_H
#define COMMISSIONEMPLOYEE_H

#include "employee.h"

class CommissionEmployee : public Employee {
private:
    double target;
    double rate;
public:
    CommissionEmployee() : target(0), rate(0) {}

    void setTarget(double t) { target = t; }
    void setRate(double r) { rate = r; }
    double getTarget() { return target; }
    double getRate() { return rate; }

    double getSalary() override {
        double base = target * rate;
        return (benNum == 1) ? base + benefit->calculateBenefit() : base;
    }

    void print() override {
        Employee::print();
        cout << "Type: Commission\nTarget: $" << target
            << "\nRate: " << rate << "\nTotal: $" << getSalary() << endl;
    }
};
#endif