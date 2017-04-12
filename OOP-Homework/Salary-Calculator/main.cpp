#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstdlib>
#include "core/Deduction.h"
#include "core/Calculator.h"
#include "core/IncomeTax.h"
#include "core/SocialSecurityTax.h"

using namespace std;

vector<Deduction *> loadDeductions(string fileName);

void prepareIniFile() {
    int configLinesCount;
    cin >> configLinesCount;
    string configLine;
    getline(cin, configLine); // trailing end of line
    ofstream fout("config.ini");
    for (int i = 0; i < configLinesCount; i++) {
        getline(cin, configLine);
        fout << configLine << endl;
    }
    fout.close();
}

string trim(const string &str) {
    size_t first = str.find_first_not_of(' ');
    if (string::npos == first) {
        return str;
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

template<typename Out>
void split(const std::string &s, char delim, Out result) {
    std::stringstream ss;
    ss.str(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        *(result++) = item;
    }
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}

vector<Deduction *> loadDeductions(string fileName) {
    vector<Deduction *> deductions;

    std::ifstream infile(fileName);
    std::string line;
    while (std::getline(infile, line)) {
        vector<string> tokens = split(line, ':');

        if (tokens.size() != 3) {
            break;
        }

        string deductionName = tokens[0];

        string rateTokensTrimmed = trim(tokens[1]);
        vector<string> rateTokens = split(rateTokensTrimmed, ' ');
        double rate = atof(rateTokens[0].c_str());

        if (rateTokens.size() == 1) {
            deductions.push_back(new IncomeTax(deductionName, rate));
        } else if (rateTokens.size() == 2) {
            double limit = atof(rateTokens[1].c_str());

            deductions.push_back(new SocialSecurityTax(deductionName, rate, limit));
        }
    }

    return deductions;
}

int main(int argc, char *argv[]) {
    vector<Deduction *> deductions = loadDeductions("config.ini");

    double salary;
    Calculator calc(deductions);
    while (cin >> salary) {
        calc.analyze(salary, cout);
        cout << endl;
    }

    return 0;
}