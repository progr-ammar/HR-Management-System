#ifndef BENEFITS_H
#define BENEFITS_H

#include <iostream>
#include <string>
using namespace std;

class Benefits {
protected:
    string planType;
    double amount;
    string benefitID;
public:
    Benefits() : planType("Unknown"), amount(0), benefitID("Unknown") {}

    virtual void read() {
        cout << "Enter Plan Type (yearly/monthly): ";
        getline(cin >> ws, planType);
        cout << "Enter Benefit ID: ";
        getline(cin, benefitID);
        cout << "Enter Amount: $";
        cin >> amount;
    }

    virtual double calculateBenefit() {
        return 0.1 * amount;
    }

    virtual void print() {
        cout << "Plan: " << planType
            << "\nAmount: $" << amount
            << "\nID: " << benefitID << endl;
    }

    string getBenefitId() { return benefitID; }
    double getAmount() { return amount; }
};
#endif