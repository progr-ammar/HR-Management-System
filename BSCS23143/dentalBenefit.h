#ifndef DENTALBENEFIT_H
#define DENTALBENEFIT_H

#include <iostream>
using namespace std;

class DentalBenefit : public Benefits
{
public:

    void read()
    {
        Benefits::read();
    }

    double calculateBenefit()
    {
        return 0.1 * amount;
    }

    void print() {
        Benefits::print();
        cout << endl;
    }

};

#endif