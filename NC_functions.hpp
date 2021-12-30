/*
NAME: Talike Bennett
PROJECT: Number Converter
FILE: NC_functions.hpp
*/

#ifndef HM2_FUNC
#define HM2_FUNC

#include <cmath>
#include <string> // Library needed to use string operations.
using namespace std;

string BasetoDec(string source, int baseS) {

    /* 
    BASE(2-9)-TO-DECIMAL CONVERSION.
    Based on Demo 4.15.
    Modified to work for numbers of base 2 to base 9. 
    */

    string target = "";
    int digit = 0;
    int temp = 0;

    for(int i = 0; i < source.size(); i++) {

        digit = source[i] - '0'; // Converts each string digit to an integer digit.
        temp += digit * pow(baseS, source.size() - (i + 1));

    }

    target = to_string(temp);
    return target;

}

string DectoBase(string source, int baseT) {

    /* 
    DECIMAL-TO-BASE(2-9) CONVERSION.
    Based on in-class presentation (Mar 3) and Demo 4.15.
    Modified to work for (1) numbers of base 2 to base 9, and (2) decimals input as strings. 
    */

    string target = "";
    string temp = "";
    const int decimalBase = 10; // Base value of decimals.
    int decimalInt = 0; // Stores the value of sourceNum as an integer.

    decimalInt = stoi(source);

    while(decimalInt > 0) {

        temp += to_string(decimalInt % baseT);
        decimalInt /= baseT;

    }

    for(int i = temp.size() - 1; i >= 0; i--) target += temp[i]; // Reverses the string to print the characters in the right order.

    return target;

}

string DectoHex(string source) {

    /* 
    DECIMAL-TO-HEXADECIMAL CONVERSION.
    Based on in-class presentation (Mar 3) and Demo 4.15.
    Modified to convert remainder values greater than 9 to their corresponding hexadecimal letter. 
    */

    string target = "";
    string temp = "";
    const int hexBase = 16;
    int decimalInt = 0;

    decimalInt = stoi(source);

    while(decimalInt > 0) {

        int rem = decimalInt % hexBase; // Holds the result of decimalInt % targetBase.

        if(rem <= 9) temp += rem + '0'; // Stores a digit based on the ASCII value derived from rem + '0'.
        else temp += rem - 10 + 'A'; // Stores a letter based on the ASCII value derived rem - 10 + 'A'. Inverse of letter-to-number conversion from Demo 4.15 (letter - 'A' + 10).
        decimalInt /= hexBase;

    }

    temp += "x0"; // Hexadecimals are usually prepended with '0x'.
    for(int i = temp.size() - 1; i >= 0; i--) target += temp[i]; // Reverses the string to print the characters in the right order.

    return target;

}

string HextoOct(string source); // FIX

string HextoDec(string source); // FIX

#endif