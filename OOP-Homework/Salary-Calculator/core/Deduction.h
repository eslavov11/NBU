//
// Created by Edi on 12-Apr-17.
//

#ifndef SALARY_CALCULATOR_DEDUCTION_H
#define SALARY_CALCULATOR_DEDUCTION_H

#include <iostream>

using namespace std;

class Deduction {
public:
    Deduction(const string &deductionName, double rate);

    const string &getDeductionName() const;

    void setDeductionName(const string &deductionName);

    double getRate() const;

    void setRate(double rate);

    virtual double calculate(double& salary) = 0;

private:
    string deductionName;
    double rate;
};


#endif //SALARY_CALCULATOR_DEDUCTION_H
