//
// Created by Edi on 12-Apr-17.
//

#ifndef SALARY_CALCULATOR_CALCULATOR_H
#define SALARY_CALCULATOR_CALCULATOR_H


#include <vector>
#include <ostream>

#include "Deduction.h"

using namespace std;

class Calculator {
public:
    Calculator(const vector<Deduction *> &deductions);

    const vector<Deduction *> &getDeductions() const;

    void setDeductions(const vector<Deduction *> &deductions);

    void analyze(double salary, ostream &out);

private:
    vector<Deduction*> deductions;
};


#endif //SALARY_CALCULATOR_CALCULATOR_H
