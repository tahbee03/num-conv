/*
NAME: Talike Bennett
PROJECT: Number Converter
FILE: NC_main.cpp
*/

#include <iostream>
#include <ios> // streamsize
#include <limits> // numeric_limits
#include "NC_functions.hpp" // BaseToDec(), DecToBase(), HexToDec(), DecToHex()
#include "NC_misc.hpp" // windowWidth, wordList, PrintSeparator(), PrintHeader(), ValidInput()
using namespace std;

/*
Input Stream Error Handling Sources:
https://www.cplusplus.com/reference/istream/istream/ignore/
https://www.tutorialspoint.com/what-is-the-use-of-cin-ignore-in-cplusplus
*/

int main() {

	while(true) {

		do {

			int sourceBase; // Holds the value of the source number system base
			int targetBase; // Holds the value of the target number system base
			string sourceNum; // Holds the value of the source number
			string targetNum; // Holds the value of the target number

			// SOURCE NUMBER SYSTEM SELECTION
			PrintHeader(0);
			cout << endl;
			cout << "Choose your source number system:" << endl;

			for(int i = 2; i <= 16; i++) { // Prints out the options for the main menu

				if(i >= 11 && i <= 15) continue; // Bases 11-15 are not used in this program, so they are not printed
				cout << "(" << i << ") " << wordList[i] << endl;

			}

			cout << endl;
			cout << "(Input any other number to exit the program.)" << endl;
			cout << "Enter number: ";
			cin >> sourceBase;

            while(cin.fail()) { // Handles the case where the user enters invalid input for sourceBase

                cout << "Invalid input!" << endl;
                cin.clear(); // Removes stream error
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clears stream buffer
                cout << "Enter number: ";
                cin >> sourceBase;

            }

			PrintSeparator(); // Prints the bottom row of the window
			cout << endl << endl;

            if(!(sourceBase >= 2 && sourceBase <= 10) && !(sourceBase == 16)) break;

            // TARGET NUMBER SYSTEM SELECTION
            PrintHeader(1, sourceBase);
            cout << endl;
            cout << "Choose your target number system: " << endl;

            for(int i = 2; i <= 16; i++) { // Prints out the options for the target number system selection menu

                if(i == sourceBase) continue; // You cannot convert to the same number system
                if(i >= 11 && i <= 15) continue; // Bases 11-15 are not used here, so they are not printed
                cout << "(" << i << ") " << wordList[i] << endl;

            }

            cout << endl;
            cout << "(Input any other number to exit the program.)" << endl;
            cout << "Enter number: ";
            cin >> targetBase;

            while(cin.fail() || sourceBase == targetBase) { // Handles the case where the user enters invalid input for targetBase

                cout << "Invalid input!" << endl;
                cin.clear(); // Removes stream error
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clears stream buffer
                cout << "Enter number: ";
                cin >> targetBase;

            }

            PrintSeparator(); // Prints the bottom row of the window
            cout << endl << endl;

            if(!(targetBase >= 2 && targetBase <= 10) && !(targetBase == 16)) break;

            // CONVERSION WINDOW
            PrintHeader(2, sourceBase, targetBase);
            cout << endl;
            cout << "Input your number in source number system:" << endl;
            cout << wordList[sourceBase] << ": ";
            if(sourceBase == 16) cout << "0x";
            cin >> sourceNum;

            while(!ValidInput(sourceNum, sourceBase)) { // Handles the case where the user enters invalid input for sourceNum

                cout << "Invalid input!" << endl;
                cout << wordList[sourceBase] << ": ";
                if(sourceBase == 16) cout << "0x";
                cin >> sourceNum;

            }

            if(sourceBase < 10) {

                if(targetBase < 10) targetNum = DecToBase(BaseToDec(sourceNum, sourceBase), targetBase); // base 2-9 to base 2-9
                else if(targetBase == 10) targetNum = BaseToDec(sourceNum, sourceBase); // base 2-9 to decimal
                else if(targetBase == 16) targetNum = DecToHex(BaseToDec(sourceNum, sourceBase)); // base 2-9 to hexadecimal

            } else if(sourceBase == 10) {

                if(targetBase < 10) targetNum = DecToBase(sourceNum, targetBase); // decimal to base 2-9
                else if(targetBase == 16) targetNum = DecToHex(sourceNum); // decimal to hexadecimal

            } else if(sourceBase == 16) {

                if(targetBase < 10) targetNum = DecToBase(HexToDec(sourceNum), targetBase); // hexadecimal to base 2-9
                else if(targetBase == 10) targetNum = HexToDec(sourceNum); // hexadecimal to decimal

            }

            cout << wordList[targetBase] << ": " << targetNum << endl;
            cout << "You will be returned to the main menu." << endl;
            PrintSeparator(); // Prints the bottom row of the window
            cout << endl << endl;		

		} while(true);

		// CONFIRM CLOSE WINDOW
		char yesOrNo; // Holds the user's 'Y' and 'N' inputs

		PrintHeader(3);
		cout << endl;
		cout << "Are you sure you want to quit the program? (Y/N)" << endl;
		cin >> yesOrNo;

		if(yesOrNo == 'Y' || yesOrNo == 'y') {

			cout << "Bye!" << endl;
			PrintSeparator(); // Prints the bottom row of the window
			cout << endl << endl;
			break; 
			
			// The program ends at this point

		} else {

			cout << "You will be returned to the main menu." << endl;
			PrintSeparator(); // Prints the bottom row of the window
			cout << endl << endl;

			// The program returns to the DO-WHILE loop

		}

	}

	return 0;

}
