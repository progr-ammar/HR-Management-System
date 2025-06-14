#ifndef HEALTHBENEFIT_H
#define HEALTHBENEFIT_H

#include <iostream>
using namespace std;

class HealthBenefit : public Benefits
{
private:
    string coverage;

public:
    HealthBenefit()
    {
        coverage = "Unknown";
    }

    void read() override {
        Benefits::read();
        cin.ignore();
        cout << "Enter Coverage Details (e.g., Full_Coverage, Basic, etc.): ";
        getline(cin, coverage);
        if (coverage.empty()) coverage = "N/A";
    }

    void setCoverage(string coverage)
    {
        this->coverage = coverage;
    }

    string getCoverage()
    {
        return coverage;
    }

    double calculateBenefit()
    {
        return 0.2 * amount;
    }

    void print()
    {
        Benefits::print();
        cout << "\t\tCoverage -> " << coverage << endl;
    }
};

#endif