//
// Created by Edi on 12-Apr-17.
//

#include "IncomeTax.h"

IncomeTax::IncomeTax(const string &deductionName, double rate) : Deduction(deductionName, rate) {}

double IncomeTax::calculate(double &salary) {
    double amountToTake = (Deduction::getRate() * (salary) / 100);
    salary -= amountToTake;

    return amountToTake;
}

