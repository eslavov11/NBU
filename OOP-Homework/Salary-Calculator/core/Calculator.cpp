//
// Created by Edi on 12-Apr-17.
//

#include <iomanip>
#include "Calculator.h"

Calculator::Calculator(const vector<Deduction *> &deductions) {
    this->setDeductions(deductions);
}

void Calculator::analyze(double salary, ostream &out) {
    out << std::setw(30) << "Gross salary" << std::setw(10) << salary << " BGN" << std::endl;
    out << "--------------------------------------------" << std::endl;
    for (int i = 0; i < deductions.size(); ++i) {
        double amount = deductions[i]->calculate(salary);
        out << std::setw(30) << deductions[i]->getDeductionName() << std::setw(10) << amount << " BGN" << std::endl;
    }
    out << "============================================" << std::endl;
    out << std::setw(30) << "Net salary" << std::setw(10) << salary << " BGN" << std::endl;

}

const vector<Deduction *> &Calculator::getDeductions() const {
    return deductions;
}

void Calculator::setDeductions(const vector<Deduction *> &deductions) {
    Calculator::deductions = deductions;
}
