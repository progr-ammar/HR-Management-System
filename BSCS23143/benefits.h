#ifndef BENEFITS_H
#define BENEFITS_H

#include <iostream>
using namespace std;

class Benefits
{
protected:
    string planType;
    double amount;
    string benefitID;

public:
    Benefits()
    {
        planType = "Unknown";
        amount = 0;
        benefitID = "Unknown";
    }
    virtual ~Benefits() {}
    //virtual void read() {
    //    cin.ignore();
    //    cout << "Enter Benefit ID: ";
    //    getline(cin, benefitID);

    //    do {
    //        cout << "Enter Plan Type (monthly/yearly): ";
    //        getline(cin, planType);
    //        if (planType != "monthly" && planType != "yearly") {
    //            cout << "Invalid input. Please enter either 'monthly' or 'yearly'.\n";
    //        }
    //    } while (planType != "monthly" && planType != "yearly");

    //    cout << "Enter Benefit Amount: ";
    //    while (!(cin >> amount) || amount < 0) {
    //        cout << "Invalid input. Enter a positive number: ";
    //        cin.clear();
    //        cin.ignore(1000, '\n');
    //    }
    //}

    virtual void read() {
        cout << "Enter Benefit ID: ";
        getline(cin, benefitID);
        cout << "Enter Plan Type (monthly/yearly): ";
        getline(cin, planType);
        cout << "Enter Amount: ";
        cin >> amount;
        cin.ignore();
    }

    virtual void setBenefitID(string benefitID)
    {
        this->benefitID = benefitID;
    }

    //virtual string getBenefitId()
    //{
    //    return benefitID;
    //}
    virtual string getBenefitId() const 
    { 
        return benefitID; 
    }


    virtual void setPlanType(string planType)
    {
        this->planType = planType;
    }

    virtual void setAmount(double amount)
    {
        this->amount = amount;
    }

    virtual string getPlanType()
    {
        return planType;
    }

    virtual double getAmount()
    {
        return amount;
    }

    virtual double calculateBenefit() const {
        if (planType == "yearly") return amount / 12.0;
        else                       return amount;
    }

    //virtual void print() {
    //    cout << "ID: " << benefitID
    //        << " | Plan Type: " << planType
    //        << " | Amount: " << fixed << setprecision(2) << amount;
    //}
    virtual void print() const {
        cout << "Benefit ID: " << benefitID
            << " | Plan Type: " << planType
            << " | Amount: " << fixed << setprecision(2) << amount
            << " | Payout: " << calculateBenefit()
            << "\n";
    }
};

#endif