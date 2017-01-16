/** 
 * Coded numbers
 */

#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0, codedNumber = 0, code; i < n; ++i, codedNumber = 0) {
        cin >> code;
        codedNumber += code;

        cin >> code;
        codedNumber += code * 10;

        cin >> code;
        codedNumber += code * 100;

        cin >> code;
        codedNumber += code * 1000;

        *(arr + i) = codedNumber;
    }

    int numberToDecodeIndex,
        numberToDecode;
    string numberSpecs, delimiter = ", ";
    while (cin >> numberToDecodeIndex) {
        numberToDecode = *(arr + numberToDecodeIndex);

        numberSpecs = "The number is ";
        numberSpecs += ((numberToDecode % 10) ? "odd" : "even") + delimiter;

        numberSpecs += "prime: ";
        switch (numberToDecode / 10 % 10) {
            case 1:
                numberSpecs += "1";
                break;
            case 2:
                numberSpecs += "composite";
                break;
            case 0:
                numberSpecs += "yes";
                break;
            case -1:
                numberSpecs += "0 or negative";
                break;
            default:
                break;
        }

        numberSpecs += delimiter + "good: ";
        switch (numberToDecode / 10 % 10) {
            case 1:
                numberSpecs += "no";
                break;
            case 2:
                numberSpecs += "0, 1 or negative";
                break;
            case 0:
                numberSpecs += "yes";
                break;
            default:
                break;
        }

        numberSpecs += delimiter + "power of two: ";
        switch (numberToDecode / 10 % 10) {
            case 1:
                numberSpecs += "no";
                break;
            case 2:
                numberSpecs += "yes";
                break;
            case 0:
                numberSpecs += "0 or negative";
                break;
            default:
                break;
        }

        cout << numberSpecs << endl;
    }
}

/**
 * Потребителят въвежда брой на числата, които иска да бъдат обработени. След това въвежда стойности за всяко едно число.

 Числата се кодират вътрешно както следва:
 * числото на единиците показва четност (0 - четно, 1 - нечетно)
 * числото на десетиците показва дали е просто (0 - просто, 1 - 1, 2 - съставно, -1 - ако е 0 или отрицателно)
 * числото на стотиците показва дали е хубаво (0 - хубаво, 1- не, 2 - 0, 1 или отрицателно)
 * числото на хилядите - дали е степен на двойката (0 - 0 или орицателно, 1 - ако не е, 2 - ако е степен на двойката)

 Програмата да пази кодовете в масив и да ги отпечатва.
 Потребителят да задава номер на число, а програмата да отпечатва неговите характеристики (декодирайки кода).
 */
