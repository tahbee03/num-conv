/*
NAME: Talike Bennett
PROJECT: Number Converter
FILE: NC_functions.hpp
*/

#ifndef NC_FUNC
#define NC_FUNC

#include <cmath> // pow()
#include <string> // string
using namespace std;

string BaseToDec(string source, int baseS) {

    /* 
    BASE(2-9)-TO-DECIMAL CONVERSION
    Based on Demo 4.15
    Modified to work for numbers of base 2 to base 9 
    */

    string target = "";
    int digit;
    int target_int = 0;

    for(int i = 0; i < source.size(); i++) {

        digit = source[i] - '0';
        target_int += digit * pow(baseS, source.size() - (i + 1));

    }

    target = to_string(target_int);
    return target;

}

string HexToDec(string source) {

    /* 
    HEXADECIMAL-TO-DECIMAL CONVERSION
    Based on Demo 4.15
    */

    string target = "";
    const int hexBase = 16; // Base value of hexadecimals
    int digit;
    int target_int = 0;

    for(int i = 0; i < source.size(); i++) {

        if(source.at(i) >= 'a' && source.at(i) <= 'f') digit = source.at(i) - 'a' + 10;
        else if(source.at(i) >= 'A' && source.at(i) <= 'F') digit = source.at(i) - 'A' + 10;
        else digit = source.at(i) - '0';

        target_int += digit * pow(hexBase, source.size() - (i + 1));

    }

    target = to_string(target_int);
    return target;

}

string DecToBase(string source, int baseT) {

    /* 
    DECIMAL-TO-BASE(2-9) CONVERSION
    Based on in-class presentation (Mar 3, 2021) and Demo 4.15
    Modified to work for (1) numbers of base 2 to base 9, and (2) decimals input as strings
    */

    string target = "";
    string target_temp = "";
    const int decimalBase = 10; // Base value of decimals
    int source_int = 0; // Stores the value of source as an integer

    source_int = stoi(source);

    while(source_int > 0) {

        target_temp += to_string(source_int % baseT);
        source_int /= baseT;

    }

    for(int i = target_temp.size() - 1; i >= 0; i--) target += target_temp[i]; // Reverses the string to print the characters in the right order
    return target;

}

string DecToHex(string source) {

    /* 
    DECIMAL-TO-HEXADECIMAL CONVERSION
    Based on in-class presentation (Mar 3) and Demo 4.15
    Modified to convert remainder values greater than 9 to their corresponding hexadecimal letter
    */

    string target = "";
    string target_temp = "";
    const int hexBase = 16; // Base value of hexadecimals
    int source_int = 0; // Stores the value of source as an integer

    source_int = stoi(source);

    while(source_int > 0) {

        int rem = source_int % hexBase;

        if(rem <= 9) target_temp += rem + '0'; // Stores a digit based on the ASCII value derived from rem + '0'
        else target_temp += rem - 10 + 'A'; // Stores a letter based on the ASCII value derived rem - 10 + 'A'
        source_int /= hexBase;

    }

    target_temp += "x0"; // Hexadecimals are usually prepended with '0x'
    for(int i = target_temp.size() - 1; i >= 0; i--) target += target_temp[i]; // Reverses the string to print the characters in the right order

    return target;

}

#endif
