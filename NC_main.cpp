/*
NAME: Talike Bennett
PROJECT: Number Converter
FILE: NC_main.cpp
*/

#include <iostream>
#include <cctype> // isxdigit()
#include "NC_functions.hpp" // BaseToDec(), DecToBase(), HexToDec(), DecToHex()
#include "NC_misc.hpp" // windowWidth, wordList, PrintSeparator(), PrintHeader()
using namespace std;

int main() {

	while(true) {

		do {

			int sourceBase; // Holds the value of the source number system base
			int targetBase; // Holds the value of the target number system base
			string sourceNum; // Holds the value of the source number
			string targetNum; // Holds the value of the target number

			/* SOURCE NUMBER SYSTEM SELECTION */
			PrintHeader(0);
			cout << endl;
			cout << "Choose your source number system:" << endl;

			for(int i = 2; i <= 16; i++) { // Prints out the options for the main menu

				if(i >= 11 && i <= 15) continue; // Bases 11-15 are not used in this program, so they are not printed
				cout << "(" << i << ") " << wordList[i] << endl;

			}

			cout << endl;
			cout << "(Input any other value to exit the program.)" << endl;
			cout << "Enter number: ";
			cin >> sourceBase;
			PrintSeparator(); // Prints the bottom row of the window
			cout << endl << endl;

			if(sourceBase >= 2 && sourceBase <= 9) { // For source number systems 2-9 (base 2-9)

				/* TARGET NUMBER SYSTEM SELECTION */
				PrintHeader(1, sourceBase);
				cout << endl;
				cout << "Choose your target number system: " << endl;
				cout << "(10) decimal" << endl;
				cout << endl;
				cout << "(Input any other value to exit the program.)" << endl;
				cout << "Enter number: ";
				cin >> targetBase;
				PrintSeparator(); // Prints the bottom row of the window
				cout << endl << endl;

				if(targetBase == 10) {

					/* CONVERSION WINDOW */
					PrintHeader(2, sourceBase, targetBase);
					cout << endl;
					cout << "Input your number in source number system:" << endl;
					cout << wordList[sourceBase] << ": ";
					cin >> sourceNum;
					targetNum = BasetoDec(sourceNum, sourceBase);
					cout << "Decimal: " << targetNum << endl;
					cout << "You will be returned to the main menu." << endl;
					PrintSeparator(); // Prints the bottom row of the window
					cout << endl << endl;

					// End of base(2-9) to decimal conversion

				} else { // If user inputs an invalid number, they will be prompted to exit the program

					break;

				}

			} else if(sourceBase == 10) { // For source number system 10 (decimal)

				/* TARGET NUMBER SYSTEM SELECTION */
				PrintHeader(1, sourceBase);
				cout << endl;
				cout << "Choose your target number system: " << endl;

				for(int i = 2; i <= 16; i++) { // Prints out the options for the target number system selection menu

					if (i >= 10 && i <= 15) continue; // Bases 10-15 are not used here, so they are not printed
					cout << "(" << i << ") " << wordList[i] << endl;

				}

				cout << endl;
				cout << "(Input any other value to exit the program.)" << endl;
				cout << "Enter number: ";
				cin >> targetBase;
				PrintSeparator(); // Prints the bottom row of the window
				cout << endl << endl;

			
				if(targetBase >= 2 && targetBase <= 9) { // Decimal-to-base(2-9) conversion
					
					/* CONVERSION WINDOW */
					PrintHeader(2, sourceBase, targetBase);
					cout << endl;
					cout << "Input your number in source number system:" << endl;
					cout << "Decimal: ";
					cin >> sourceNum;
					targetNum = DectoBase(sourceNum, targetBase);
					cout << wordList[targetBase] << ": " << targetNum << endl;
					cout << "You will be returned to the main menu." << endl;
					PrintSeparator(); // Prints the bottom row of the window
					cout << endl << endl;

					// End of decimal to base(2-9) conversion
					
				} else if(targetBase == 16) { // Decimal-to-hexadecimal conversion

					/* CONVERSION WINDOW */
					PrintHeader(2, sourceBase, targetBase);
					cout << endl;
					cout << "Input your number in source number system:" << endl;
					cout << "Decimal: ";
					cin >> sourceNum;
					targetNum = DectoHex(sourceNum);
					cout << "Hexadecimal: " << targetNum << endl;
					cout << "You will be returned to the main menu." << endl;
					PrintSeparator(); // Prints the bottom row of the window
					cout << endl << endl;

					// End of decimal to hexadecimal conversion

				} else { // If user inputs an invalid number, they will be prompted to exit the program

					break;

				}

			} else if(sourceBase == 16) { // For source number system 16 (hexadecimal)

				/* TARGET NUMBER SYSTEM SELECTION */
				PrintHeader(1, sourceBase);
				cout << endl;
				cout << "Choose your target number system: " << endl;
				// cout << "(8) octal" << endl;
				cout << "(10) decimal" << endl;
				cout << endl;
				cout << "(Input any other value to exit the program.)" << endl;
				cout << "Enter number: ";
				cin >> targetBase;
				PrintSeparator(); // Prints the bottom row of the window
				cout << endl << endl;

				if(targetBase == 10) { // Hexadecimal-to-decimal conversion

					/* CONVERSION WINDOW */
					PrintHeader(2, sourceBase, targetBase);
					cout << endl;
					cout << "Input your number in source number system:" << endl;
					cout << "Hexadecimal: 0x";
					cin >> sourceNum;
					targetNum = HextoDec(sourceNum);
					cout << "Decimal: " << targetNum << endl;
					cout << "You will be returned to the main menu." << endl;
					PrintSeparator(); // Prints the bottom row of the window
					cout << endl << endl;

					// End of hexadecimal to decimal conversion

				} else { // If user inputs an invalid number, they will be prompted to exit the program

					break;

				}

			} else { // If user inputs an invalid number, they will be prompted to exit the program

				break;

			}

		} while(true);

		/* CONFIRM CLOSE WINDOW */
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
