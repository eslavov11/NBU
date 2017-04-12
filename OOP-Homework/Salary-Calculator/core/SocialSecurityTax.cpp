//
// Created by Edi on 12-Apr-17.
//

#include "SocialSecurityTax.h"

SocialSecurityTax::SocialSecurityTax(const string &deductionName, double rate, double insuranceLimit) : Deduction(deductionName, rate) {
    this->setInsuranceLimit(insuranceLimit);
}

double SocialSecurityTax::calculate(double &salary) {
    double insuranceAmount = salary;
    if (salary > this->getInsuranceLimit()) {
        insuranceAmount = this->getInsuranceLimit();
    }

    double amountToTake = (Deduction::getRate() * (insuranceAmount) / 100);
    salary -= amountToTake;

    return amountToTake;
}

double SocialSecurityTax::getInsuranceLimit() const {
    return insuranceLimit;
}

void SocialSecurityTax::setInsuranceLimit(double insuranceLimit) {
    SocialSecurityTax::insuranceLimit = insuranceLimit;
}

