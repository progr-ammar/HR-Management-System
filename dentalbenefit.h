#ifndef DENTALBENEFIT_H
#define DENTALBENEFIT_H

#include "benefits.h"

class DentalBenefit : public Benefits {
public:
    double calculateBenefit() override {
        return 0.15 * amount;
    }
};
#endif