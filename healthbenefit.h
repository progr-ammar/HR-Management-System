#ifndef HEALTHBENEFIT_H
#define HEALTHBENEFIT_H

#include "benefits.h"

class HealthBenefit : public Benefits {
private:
    string coverage;
public:
    double calculateBenefit() override {
        return 0.2 * amount;
    }

    void read() override {
        Benefits::read();
        cout << "Enter Coverage: ";
        getline(cin >> ws, coverage);
    }

    void print() override {
        Benefits::print();
        cout << "Coverage: " << coverage << endl;
    }
};
#endif