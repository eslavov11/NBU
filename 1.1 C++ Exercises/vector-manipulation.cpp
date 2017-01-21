/**
 * Vector manipulation
 */

#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int numberOfDigits(const unsigned int &i);

double findAvgOfSpecialNumbers(const vector<unsigned int> &vector);

int main() {
    vector<unsigned int> numbers;
    unsigned int number;

    while (cin >> number) {
        numbers.push_back(number);
    }

    double avg = findAvgOfSpecialNumbers(numbers);

    printf("%.3f", avg);
}

double findAvgOfSpecialNumbers(const vector<unsigned int> &vector){
    double sum = 0.0, count = 0.0;

    for (int i = 0; i < vector.size(); ++i) {
        if (vector[i] == 0 || (vector[i] % 2 == 0 && numberOfDigits(vector[i]) % 2 != 0)) {
            ++count;
            sum += vector[i];
        }
    }

    return count == 0 ? 0.0 : (sum / count);
}

int numberOfDigits(const unsigned int &i) {
    int number = i, count = 0;
    while (number > 0) {
        ++count;
        number/=10;
    }

    return count;
}
