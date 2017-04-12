//
// Created by Edi on 12-Apr-17.
//

#include "Deduction.h"

Deduction::Deduction(const string &deductionName, double rate) : deductionName(deductionName), rate(rate) {}

const string &Deduction::getDeductionName() const {
    return deductionName;
}

void Deduction::setDeductionName(const string &deductionName) {
    Deduction::deductionName = deductionName;
}

double Deduction::getRate() const {
    return rate;
}

void Deduction::setRate(double rate) {
    Deduction::rate = rate;
}

