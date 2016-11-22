/**
 * Created by Edi on 22-Nov-16.
*/

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


/**
 * HOW TO's
 * strtoul(tokens[i].c_str(), NULL, 10); Convert string to unsigned long long
 *
*/