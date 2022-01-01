/*
NAME: Talike Bennett
PROJECT: Number Converter
FILE: NC_main.cpp
*/

#include <iostream>
#include <iomanip>
#include <cctype> // isxdigit()
#include "NC_functions.hpp"
using namespace std;

const int windowWidth = 50; //Sets the width of the "window" of the program. Used in FOR loops where "=" is printed.

void PrintSeparator() {

    for(int i = 1; i <= windowWidth; i++) cout << "=";

}

void PrintHeader(int t, int sb = 0) {

	switch(t) {
		case 0: // Choosing source base
			PrintSeparator(); // Prints the top row of the header.
			cout << endl;
			for(int i = 1; i <= 12; i++) cout << "=";
			cout << " Number System Conversion ";
			for(int i = 39; i <= windowWidth; i++) cout << "=";
			cout << endl;
			PrintSeparator(); // Prints the bottom row of the header.
			break;
		case 1: // Choosing target base; needs source base (sb)
			PrintSeparator(); // Prints the top row of the header.
			cout << endl;
			cout << "Source Number System: " << sb << " ";
			cout << setfill('=');
			int tempWidth;
			(sb >= 10) ? tempWidth = 25 : tempWidth = 26;
			cout << setw(tempWidth) << "" << setfill(' ') << endl;
			PrintSeparator(); // Prints the bottom row of the header.
			break;









	}

}

int main() {

	bool runProgram = true; //Controls whether or not the main program will continue running.
	bool confirmQuit = false; //Controls whether or not the user prompts to exit the program.
	char yesOrNo; //Holds the user's 'Y' and 'N' inputs.

	/* The following WHILE loop controls the processes of the entire program. If the user chooses to exit the program,
	runProgram will be false, the computer will break out of the WHILE loop, and the program will be terminated. */
	while(runProgram) {

		int sourceBase = 0; // Holds the value of the source number system base. Used as the base in the conversion FOR loops.
		int targetBase = 0; // Holds the value of the target number system base.
		const string wordList[] = {"", "", "binary", "ternary", "quaternary", "quinary", "senary", "septenary", "octal", "nonary", "decimal",
		                     "", "", "", "", "", "hexadecimal"};

		/* The following DO-WHILE loop prints out the main menu and executes the main program as long as the user inputs valid values. */
		do {

			string sourceNum = " "; //Holds the value of the source number.
			long long targetNum = 0; //Holds the value of the target number.
			string targetNumStr; //Holds the value of the target number (for decimal-to-hexadecimal conversion only).

			/* MAIN MENU */
			PrintHeader(0);
			cout << endl;
			cout << "Choose your source number system:" << endl;

			for(int i = 2; i <= 16; i++) { // Prints out the options for the main menu.

				if(i >= 11 && i <= 15) continue; // Bases 11-15 are not used in this program, so they are not printed.
				cout << "(" << i << ") " << wordList[i] << endl;

			}

			cout << endl;
			cout << "(Input any other value to exit the program.)" << endl;
			cout << "Enter number: ";
			cin >> sourceBase;
			PrintSeparator(); // Prints the bottom row of the window.
			cout << endl << endl;

			PrintHeader(1, sourceBase);
			cout << endl;

			if(sourceBase >= 2 && sourceBase <= 9) { // For source number systems 2-9 (base 2-9).

				/* CHOOSE TARGET NUMBER SYSTEM MENU */
				cout << "Choose your target number system: " << endl;
				cout << "(10) decimal" << endl;
				cout << endl;
				cout << "(Input any other value to exit the program.)" << endl;
				cout << "Enter number: ";
				cin >> targetBase;
				PrintSeparator(); // Prints the bottom row of the window.
				cout << endl << endl;

				if (targetBase != 10) { // If user inputs an invalid number, they will be prompted to exit the program.

					confirmQuit = true;
					break;

				} else {

					/* CONVERSION WINDOW */
					PrintSeparator(); //Prints the top row of the header.

					cout << endl;
					cout << "Source Number System: " << sourceBase << ", Target Number System: " << targetBase << endl;

					PrintSeparator(); //Prints the bottom row of the header.

					cout << endl;
					cout << "Input your number in source number system:" << endl;

					switch (sourceBase) {

						case 2:
							cout << "Binary: ";
							break;
						case 3:
							cout << "Ternary: ";
							break;
						case 4:
							cout << "Quaternary: ";
							break;
						case 5:
							cout << "Quinary: ";
							break;
						case 6:
							cout << "Senary: ";
							break;
						case 7:
							cout << "Septenary: ";
							break;
						case 8:
							cout << "Octal: ";
							break;
						case 9:
							cout << "Nonary: ";
							break;

					}

					cin >> sourceNum;
					targetNum = stoi(BasetoDec(sourceNum, sourceBase));
					cout << "Decimal: " << targetNum << endl;
					cout << "You will be returned to the main menu." << endl;

					PrintSeparator(); //Prints the bottom row of the window.

					cout << endl << endl;

				}

				continue;
				/* End of base(2-9) to decimal conversion. Next iteration of
				DO-WHILE loop starts; main menu is printed. */

			} else if(sourceBase == 10) { // For source number system 10 (decimal).

				/* CHOOSE TARGET NUMBER SYSTEM MENU */
				cout << "Choose your target number system: " << endl;

				for(int i = 2; i <= 16; i++) { // Prints out the options for the target number system selection menu.

					if (i >= 10 && i <= 15) continue; // Bases 10-15 are not used here, so they are not printed.
					cout << "(" << i << ") " << wordList[i] << endl;

				}

				cout << endl;
				cout << "(Input any other value to exit the program.)" << endl;
				cout << "Enter number: ";
				cin >> targetBase;
				PrintSeparator(); //Prints the bottom row of the window.
				cout << endl << endl;

				if ((targetBase < 2) || ((targetBase > 9) && (targetBase != 16))) { //If user inputs an invalid number, they will be prompted to exit the program.

					confirmQuit = true;
					break;

				} else {

					/* CONVERSION WINDOW */
					PrintSeparator(); //Prints the top row of the header.
					
					cout << endl;
					cout << "Source Number System: " << sourceBase << ", Target Number System: " << targetBase;
					cout << endl;

					PrintSeparator(); //Prints the bottom row of the header.

					cout << endl;
					cout << "Input your number in source number system:" << endl;
					cout << "Decimal: ";
					cin >> sourceNum;

					if ((targetBase >= 2) && (targetBase <= 9)) { //Decimal-to-base(2-9) conversion.

						targetNum = stoi(DectoBase(sourceNum, targetBase));

					    switch (targetBase) {

							case 2:
								cout << "Binary: ";
								break;
							case 3:
								cout << "Ternary: ";
								break;
							case 4:
								cout << "Quaternary: ";
								break;
							case 5:
								cout << "Quinary: ";
								break;
							case 6:
								cout << "Senary: ";
								break;
							case 7:
								cout << "Septenary: ";
								break;
							case 8:
								cout << "Octal: ";
								break;
							case 9:
								cout << "Nonary: ";
								break;

						}

						cout << targetNum << endl;

					}

					if (targetBase == 16) { //Decimal-to-hexadecimal conversion.

						targetNumStr = DectoHex(sourceNum);
					    cout << "Hexadecimal: " << targetNumStr << endl;

					}

					cout << "You will be returned to the main menu." << endl;

					PrintSeparator(); //Prints the bottom row of the window.

					cout << endl << endl;

				}

				continue;

				/* End of decimal to base (2-9)/decimal to hexadecimal conversion. Next iteration of
				DO-WHILE loop starts; main menu is printed. */

			} else if (sourceBase == 16) { //For source number system 16 (hexadecimal).

				/* CHOOSE TARGET NUMBER SYSTEM MENU */
				/*
				PrintSeparator(); //Prints the top row of the header.

				cout << endl;
				cout << "Source Number System: " << sourceBase << " ";

				for (int i = 26; i <= windowWidth; i++) {

					cout << "=";

				}

				cout << endl;

				PrintSeparator(); //Prints the bottom row of the header.

				cout << endl;
				*/
				cout << "Choose your target number system: " << endl;
				cout << "(8) octal" << endl;
				cout << "(10) decimal" << endl;
				cout << "Input any other value to exit the program." << endl;
				cin >> targetBase;

				PrintSeparator(); //Prints the bottom row of the window.

				cout << endl << endl;

				if ((targetBase != 8) && (targetBase != 10)) { //If user inputs an invalid number, they will be prompted to exit the program.

					confirmQuit = true;
					break;

				} else {

					/* CONVERSION WINDOW */
					PrintSeparator(); //Prints the top row of the header.

					cout << endl;
					cout << "Source Number System: " << sourceBase << ", Target Number System: " << targetBase << endl;

					PrintSeparator(); //Prints the bottom row of the header.

					cout << endl;
					cout << "Input your number in source number system:" << endl;
					cout << "Hexadecimal: ";

					/* HEXADECIMAL INPUT VALIDATION LOOP */
					int chances = 5; //Limits the amount of times the user can input an invalid hexadecimal number.
					bool validHex; //Controls wheteher or not the conversion will happen.

					while (chances > 0) {

						cin >> sourceNum;
						validHex = true;

						for (int i = 0; i < sourceNum.size(); i++) {

							if (!isxdigit(sourceNum[i])) {

								validHex = false;
								break;

							}

						}

						if (!validHex) { //If the user enters an invalid hexadecimal number, they will get a warning and the loop will reiterate.

							chances--;
							if (chances == 0) {

								cout << "Not a valid number!" << endl;
								break;

							} else {

								cout << "Not a valid number! Try again:" << endl;
								cout << "Hexadecimal: ";
								continue;

							}

						} else { //Otherwise, their number will undergo conversion.

							break;

						}

					}

					if ((targetBase == 8) && (validHex)) { //Hexadecimal-to-octal conversion.

						/* HEXADECIMAL-TO-OCTAL CONVERSION.
						Based on Demo 4.15, in-class presentation (Mar 3), and outside source.

						OUTSIDE SOURCE: https://youtu.be/ML_AkW97Axk ("Hexadecimal to Octal Conversion", The Organic Chemistry Tutor, May 23 2018)

						CONVERSION PROCESS (according to video):
						(1) Convert each digit of the hexadecimal number to their corresponding decimal values. (ex. A = 10)
						(2) Convert each decimal number to their corresponding binary values. (ex. 10 = 1010)
						(3) Group binary numbers into groups of three. Add 0s in the beginning if necessary. (ex. 1010 -> 001 010)
						(4) Convert each group of 3 to their corresponding decimal values. Each resulting value is a digit of the octal number. (ex. 001 010 = 12) */

					    string tempLongBin; //Holds the binary value of all the characters as one long string.

					    for (int i = 0; i < sourceNum.size(); i++) { //Performs the following operations on each character of sourceNum.

					        int tempDec = 0; //Holds the decimal value of the character at index i.
					        int tempBin = 0; //Holds the binary value of the character at index i as an integer.
					        string tempBinStr; //Holds the binary value of the character at index i as a string.
					        long long placeValue = 1; //Needed to put the digits in the right place.

					        if (sourceNum[i] >= 'a' && sourceNum[i] <= 'f') { //Operation 1A: If the character at index i is a lowercase hex letter, then it will get converted to it's decimal value.

					            tempDec = sourceNum[i] - 'a' + 10;

					        } else if (sourceNum[i] >= 'A' && sourceNum[i] <= 'F') { //Operation 1B: If the character at index i is a uppercase hex letter, then it will get converted to it's decimal value.

					            tempDec = sourceNum[i] - 'A' + 10;

					        } else { //Operation 1C: If the character at index i is a hex digit (number), then it will get converted to it's decimal value.

					            tempDec = sourceNum[i] - '0';

					        }

					        while (tempDec > 0) { //Operation 2: Decimal-to-binary conversion from in-class presentation.

					            tempBin += (tempDec % 2) * placeValue;
					            tempDec /= 2;
					            placeValue *= 10;

					        }

					        while (tempBin > 0) { //Operation 3: Converts the int binary to a string binary. Needed to combine all binary numbers later.

					            char temp = (tempBin % 10) + '0'; //tempBin % 10 is the last digit of the binary number; add '0' to get the ASCII code of the number. (ex. converts 1 into '1')
					            tempBinStr.push_back(temp);
					            tempBin /= 10;

					        }

					        for (int i = 0; i < tempBinStr.size() / 2; i++) { //Operation 4: Reverses tempBinStr so the numbers are in the right order.

					            char temp = tempBinStr[i];
					            tempBinStr[i] = tempBinStr[tempBinStr.size() - (i + 1)];
					            tempBinStr[tempBinStr.size() - (i + 1)] = temp;

					        }

					        /* OPERATION 5 EXPLANATION: Since we're converting from a hexadecimal,
					        the greatest "digit" is 'f'/'F', whose binary value is 1111 (15).
					        That said, all of the binary numbers need to have 4 digits.
					        Using any more or less than that will cause a debugging error with the rest of the conversion. */
					        if (tempBinStr.size() == 1) { //Operation 5A: Adds three 0s to a one-digit binary number.

					            tempBinStr.insert(0, "0");
					            tempBinStr.insert(0, "0");
					            tempBinStr.insert(0, "0");

					        } else if (tempBinStr.size() == 2) { //Operation 5B: Adds two 0s to a two-digit binary number.

					            tempBinStr.insert(0, "0");
					            tempBinStr.insert(0, "0");

					        } else if (tempBinStr.size() == 3) { //Operation 5C: Adds one 0 to a three-digit binary number.

					            tempBinStr.insert(0, "0");

					        }

					        tempLongBin.append(tempBinStr); //Operation 6: Accumulates the binary value of every character as one value.

					    }

					    /* In order to split the long binary number into groups of three,
					    we need to make sure it is divisible by 3 first.
					    That said, 0s need to be inserted at the beginning of tempLongBin accordingly. */
					    if (tempLongBin.size() % 3 == 1) { //If tempLongBin has a remainder of one, append two more 0s.

					        tempLongBin.insert(0, "0");
					        tempLongBin.insert(0, "0");

					    } else if (tempLongBin.size() % 3 == 2) { //If tempLongBin has a remainder of two, append one more 0.

					        tempLongBin.insert(0, "0");

					    }

					    int bin3 = tempLongBin.size() / 3; //Number of groups of 3 binary numbers.
					    for (int i = 0; i <= tempLongBin.size() - 3; i += 3) { //Iterates through every 3 digits in tempLongBin.

					        int tempDec = 0; //Holds the digit that is derived from each 3 binary numbers.

					        for (int j = i; j < i + 3; j++) { //Binary-to-decimal conversion from Demo 4.15. Modified so that the range of the exponent is [0, 2]. Each "decimal" digit represents a digit of the octal number.

					            tempDec += (tempLongBin[j] - '0') * pow(2, 3 - ((j % 3) + 1));

					        }

					        targetNum += tempDec * pow(10, bin3 - 1); //Appends tempDec to the resulting octal number. It's placement is based on the group it comes from.
					        bin3--;

					    }

						cout << "Octal: " << targetNum << endl;

					}

					if ((targetBase == 10) && (validHex)) { //Hexadecimal-to-decimal conversion.

						/* HEXADECIMAL TO DECIMAL CONVERSION.
						Based on Demo 4.15. */

						const int hexBase = 16;
					    int digit;

					    for (int i = 0; i < sourceNum.size(); i++) {

					        if (sourceNum.at(i) >= 'a' && sourceNum.at(i) <= 'f') {

					            digit = sourceNum.at(i) - 'a' + 10;

					        } else if (sourceNum.at(i) >= 'A' && sourceNum.at(i) <= 'F') {

					            digit = sourceNum.at(i) - 'A' + 10;

					        } else {

					            digit = sourceNum.at(i) - '0';

					        }

					        targetNum += digit * pow(hexBase, sourceNum.size() - (i + 1));

					    }

					    cout << "Decimal: " << targetNum << endl;

					}

					cout << "You will be returned to the main menu." << endl;

					PrintSeparator(); //Prints the bottom row of the window.

					cout << endl << endl;

				}

				continue;

				/* End of hexadecimal to octal/hexadecimal to decimal conversion. Next iteration of
				DO-WHILE loop starts; main menu is printed. */

			} else { //If user inputs an invalid number, they will be prompted to exit the program.

				confirmQuit = true;

			}

		} while (!confirmQuit);

		/* CONFIRM CLOSE WINDOW */
		if (confirmQuit) {

			PrintSeparator(); //Prints the top row of the header.

			cout << endl;

			for (int i = 1; i <= 17; i++) {

				cout << "=";

			}

			cout << " Confirm  Close ";

			for (int i = 34; i <= windowWidth; i++) {

				cout << "=";

			}

			cout << endl;

			PrintSeparator(); //Prints the bottom row of the header.

			cout << endl;
			cout << "Are you sure you want to quit the program? (Y/N)" << endl;
			cin >> yesOrNo;

			if (yesOrNo == 'Y') {

				cout << "Bye!" << endl;
				PrintSeparator(); //Prints the bottom row of the window.
				
				cout << endl;

				runProgram = false;

				/* The program ends at this point. */


			} else {

				cout << "You will be returned to the main menu." << endl;
				PrintSeparator(); //Prints the bottom row of the window.
				
				cout << endl << endl;

				confirmQuit = false;

				/* The program returns to the main DO-WHILE loop
				and prints out the main menu. */

			}

		}

	}

	return 0;

}
