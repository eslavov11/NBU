//
// Created by Edi on 12-Apr-17.
//

#ifndef SALARY_CALCULATOR_INCOMETAX_H
#define SALARY_CALCULATOR_INCOMETAX_H


#include "Deduction.h"

class IncomeTax : public Deduction {
public:
    IncomeTax(const string &deductionName, double rate);

    double calculate(double& price) override;

private:
};


#endif //SALARY_CALCULATOR_INCOMETAX_H
