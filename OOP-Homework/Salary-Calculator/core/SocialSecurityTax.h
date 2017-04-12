//
// Created by Edi on 12-Apr-17.
//

#ifndef SALARY_CALCULATOR_SOCIALSECURITYTAX_H
#define SALARY_CALCULATOR_SOCIALSECURITYTAX_H


#include "Deduction.h"

class SocialSecurityTax : public Deduction {
public:
    SocialSecurityTax(const string &deductionName, double rate, double insuranceLimit);

    double getInsuranceLimit() const;

    void setInsuranceLimit(double insuranceLimit);

    double calculate(double& salary) override;
private:
    double insuranceLimit;
};


#endif //SALARY_CALCULATOR_SOCIALSECURITYTAX_H
