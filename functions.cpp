long inline gcd(long a, long b) {
    if (a == 0) return b;
    else if (b == 0) return a;
    return a < b ?
           gcd(a, b % a) :
           gcd(b, a % b);
}

string decimalToFraction(double input, string divideFormatStr) {
    const long precision = 1000000000;
    double integral = floor(input),
            frac = input - integral;
    long gcdRes = gcd(round(frac * precision), precision);
    long denominator = precision / gcdRes;
    long numerator = round(frac * precision) / gcdRes;

    stringstream ss;
    ss << (denominator * integral + numerator) << divideFormatStr << (denominator);

    return ss.str();
}


int powInts(int a, int b) {
    int i, result = 1;
    for (i = 0; i < b; ++i) {
        result *= a;
    }

    return result;
}

int indexOf(const char* arr, int length, char value) {
    for (int i = 0; i < length; ++i) {
        if (arr[i] == value) {
            return i;
        }
    }

    return -1;
}

string toUpper(string input) {
    string upperStr = "";
    for (int i = 0; i < input.length(); ++i) {
        upperStr += ::toupper(input[i]);
    }

    return upperStr;
}

int convertHexadecimalToDecimal(string numberToConvert) {
    int result = 0;
    char hexVals[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    numberToConvert = toUpper(numberToConvert);
    for (int i = 0; i < numberToConvert.length(); ++i) {
        result += indexOf(hexVals, 16, numberToConvert[i]) * powInts(16, numberToConvert.length() - 1 - i);
    }

    return result;
}

int convertOctalToDecimal(string numberToConvert) {
    int result = 0,
            rem,
            i = 0,
            octalNumber = atoi(numberToConvert.c_str());
    while (octalNumber) {
        rem = octalNumber % 10;
        octalNumber /= 10;
        result += rem * powInts(8, i++);
    }

    return result;
}

int convertBinaryToDecimal(string numberToConvert) {
    int result = 0;
    for (int i = 0; i < numberToConvert.length(); ++i) {
        if (numberToConvert[i] == '1') {
            result += powInts(2, numberToConvert.length() - 1 - i);
        }
    }

    return result;
}

int findPrimesCountInRange(int B) {
    srand(B);
    int primesCount = 0;

    for (int i = 0; i < 10000; ++i) {
        if (isPrime(rand() % 10000)) {
            primesCount++;
        }
    }

    return primesCount;
}

bool isPrime(int number) {
    if (number < 2) {
        return false;
    }

    for (int i = 2; i * i <= number; ++i) {
        if (!(number % i)) {
            return false;
        }
    }

    return true;
}

void print(vector<int> numbers) {
    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i] << ", ";
    }
    cout << endl;
}

string toBinary(int n) {
    string r;
    while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
    return r;
}

/** Sieve of Eratosthenes - fast */
int arePrimes[1000];
void genPrimes(int range) {
    for (int i = 0; i < range; ++i) {
        arePrimes[i] = 1;
    }
    arePrimes[0] = 0;
    arePrimes[1] = 0;

    int rangeSqrt = sqrt(range);
    for (int i = 2; i <= rangeSqrt; ++i) {
        if (arePrimes[i]) {
            for (int j = i * i; j < range; j += i) {
                arePrimes[j] = 0;
            }
        }
    }
}

/** Variate(0) -> all variations in array*/
void checkSol() {
    int tempSum = 0;
    for (int i = 0; i < currentSize - 1; i++) {
        tempSum += numbers[i];
    }

    if (tempSum == numbers[currentSize - 1]) {
        for (int i = 0; i < currentSize - 1; i++) {
            if (numbers[i] > 0) {
                if (i > 0) {
                    printf("+%d", numbers[i]);
                } else {
                    printf("%d", numbers[i]);
                }
            } else {
                printf("%d", numbers[i]);
            }
        }

        printf("=%d\n", tempSum);
        foundSolution = 1;
    }
}

void variate(int i) {
    if (i >= currentSize - 1) {
        if (!foundSolution) {
            checkSol();
        }

        return;
    }

    numbers[i] = abs(numbers[i]);
    variate(i + 1);

    numbers[i] = -abs(numbers[i]);
    variate(i + 1);
}
/////////////////////


/**Print all 3 bits binary numbers | variations*/
#include <cstdio>

const int n = 3;
int k = 2;
int arr[n];

void print() {
    for (int i = 0; i < n; ++i) {
        printf("%d ", *(arr+i));
    }

    printf("\n");
}

void variate(int i) {
    if (i == n) {
        print();
        return;
    }

    for (int j = 0; j < k; ++j) {
        arr[i] = j;
        variate(i + 1);
    }
}

int main() {
    variate(0);

    return 0;
}
///////////////////////////////////////

/** permute with repetitions */
void inline swap(int &first, int &second) {
    int temp = first;
    first = second;
    second = temp;
}

void permuteRep(int arr[], int start, int end) {
    print();

    for (int left = end - 1; left >= start; --left) {
        for (int right = left + 1; right <= end; ++right) {
            if (arr[left] != arr[right]) {
                swap(arr[left], arr[right]);
                permuteRep(arr, left + 1, end);
            }
        }

        // rotate left
        int firstElement = arr[left];
        for (int i = left; i <= end - 1; ++i) {
            arr[i] = arr[i + 1];
        }

        arr[end] = firstElement;
    }
}
////////////////////////////////////



/** Measure time.
 *
 * #include <time.h>
 * clock_t tStart = clock();
 * printf("Time taken: %.2fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
 *
 * */
