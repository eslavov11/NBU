/**
 * Created by Edi on 22-Nov-16.
*/

/**
 * strtoul(tokens[i].c_str(), NULL, 10); Convert string to unsigned long long
 *
*/

/**
 * removes equal consecutive chars ex. aaabb -> ab
 */
char *removeEqualConsecutiveChars(char *input) {
    size_t stringLength = strlen(input);
    char *cpy = malloc(stringLength);
    cpy[0] = input[0];

    int i, index = 0;
    for (i = 0; i < stringLength; i++) {
        if (input[i] != input[i - 1]) {
            cpy[index] = input[i];
            index++;
        }
    }

    cpy[index] = '\0';
    strcpy(input, cpy);

    return input;
}

/**
 * Splits into vector string by delimiter
 * @param theStringVector - the vector in which the tokens will be pushed
 * @param theString
 * @param theDelimiter
 */
void splitString(vector <string> &theStringVector, const string &theString, const string &theDelimiter) {
    size_t start = 0, end = 0;

    while (end != string::npos) {
        end = theString.find(theDelimiter, start);

        theStringVector.push_back(
                theString.substr(start, (end == string::npos) ? string::npos : end - start));

        start = ((end > (string::npos - theDelimiter.size()))
                 ? string::npos : end + theDelimiter.size());
    }
}

/**
 * pad string right with chars
 * example: ("123", '0', '6') -> "123000"
 */
char *padRight(char *input, char paddingChar, int totalStringSize) {
    //doesnt work with big values over 40
    size_t stringLength = strlen(input);

    char *cpy = malloc(totalStringSize + 1);

    if (stringLength < totalStringSize) {
        strcpy(cpy, input);
        int i;
        for (i = stringLength; i < totalStringSize; i++) {
            cpy[i] = paddingChar;
        }
        cpy[totalStringSize] = '\0';
        strcpy(input, cpy);
    }

    return input;
}

/**
 * pad string left with chars
 * example: ("123", '0', '6') -> "000123"
 */
char *padLeft(char *input, char paddingChar, int totalStringSize) {
    //doesnt work with big values over 40
    size_t stringLength = strlen(input);

    char *cpy = malloc(totalStringSize + 1);

    if (stringLength < totalStringSize) {
        strcpy(cpy, input);
        int i, j;
        for (i = 0; i < totalStringSize - stringLength; i++) {
            cpy[i] = paddingChar;
        }
        for (i = totalStringSize - stringLength, j = 0; i < totalStringSize; i++) {
            cpy[i] = input[j++];
        }

        cpy[totalStringSize] = '\0';
        strcpy(input, cpy);
    }

    return input;
}

/**
 * Usage - (00001001, 2) -> 00100100
*/
long long *rotateLeft(long long nums[], long long positions) {
    //not fully tested, rotating bits, works with 64bits signed
    size_t i;
    positions = positions % 64;
    for (i = 0; i < sizeof(nums); i++) {
        long long mask = pow(2, 63 - positions) - 1; // 64 bits mask
        mask = nums[i] & mask;
        nums[i] <<= positions;
        nums[i] |= mask >> (positions);
    }

}

/**
 * Usage - (00001001, 2) -> 01000010
*/
long long *rotateRight(long long nums[], long long positions) {
    //not fully tested, rotating bits, works with 64bits signed
    size_t i;
    positions = positions % 64;
    for (i = 0; i < sizeof(nums); i++) {
        long long mask = pow(2, positions) - 1; //64 bits
        mask = nums[i] & mask;
        nums[i] >>= positions;
        nums[i] |= mask << (63 - positions);
    }
}

void printBinary(long long number) {
    int bit;
    for (bit = 64 - 1; bit >= 0; --bit) {
        if ((number >> bit) & 1) {
            break;
        }

        printf("0");
    }

    while (bit >= 0) {
        printf("%d", ((number >> bit) & 1));
        --bit;
    }

    printf("\n");
}

int findSmallestDigit(unsigned long long number) {
    int smallestDigit = 9;

    while (number > 0) {
        if (number % 10 < smallestDigit) {
            smallestDigit = number % 10;
        }

        number /= 10;
    }

    return smallestDigit;
}

int findLargestDigit(unsigned long long number) {
    int largestDigit = 0;

    while (number > 0) {
        if (number % 10 > largestDigit) {
            smallestDigit = number % 10;
        }

        number /= 10;
    }

    return smallestDigit;
}