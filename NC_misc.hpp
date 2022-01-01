/*
NAME: Talike Bennett
PROJECT: Number Converter
FILE: NC_misc.hpp
*/

#ifndef NC_MISC
#define NC_MISC

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int windowWidth = 50; // Sets the width of the "window" of the program. Used in FOR loops where "=" is printed
const string wordList[] = {"", "", "Binary", "Ternary", "Quaternary", "Quinary", "Senary", "Septenary", "Octal", "Nonary", "Decimal",
		                           "", "", "", "", "", "Hexadecimal"};

void PrintSeparator() {

    for(int i = 1; i <= windowWidth; i++) cout << "=";

}

void PrintHeader(int t, int sb = 0, int tb = 0) {

	switch(t) {
		case 0: // Choosing source base
			PrintSeparator();
			cout << endl;
			for(int i = 1; i <= 12; i++) cout << "=";
			cout << " Number System Conversion ";
			for(int i = 39; i <= windowWidth; i++) cout << "=";
			cout << endl;
			PrintSeparator();
			break;
		case 1: // Choosing target base; needs source base (sb)
			PrintSeparator();
			cout << endl;
			cout << "Source Number System: " << sb << " ";
			cout << setfill('=');
			int tempWidth;
			(sb >= 10) ? tempWidth = 25 : tempWidth = 26;
			cout << setw(tempWidth) << "" << setfill(' ') << endl;
			PrintSeparator();
			break;
		case 2: // Conversion window; needs source base (sb) and target base (tb)
			PrintSeparator();
			cout << endl;
			cout << "Source Number System: " << sb << ", Target Number System: " << tb << endl;
			PrintSeparator();
			break;
		case 3: // Confirm close window
			PrintSeparator();
			cout << endl;
			for(int i = 1; i <= 17; i++) cout << "=";
			cout << " Confirm  Close ";
			for(int i = 34; i <= windowWidth; i++) cout << "=";
			cout << endl;
			PrintSeparator();
	}

}

#endif