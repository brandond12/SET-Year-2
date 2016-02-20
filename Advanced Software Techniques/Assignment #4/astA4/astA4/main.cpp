/*
* FILE			: main.cpp
* PROJECT		: PROG1165 - Assignment 4
* PROGRAMMER	: Nathan Nickel
* FIRST VERSION : 2015-03-10
* DESCRIPTION	: Gets user input for a address book. Up to 10 address book entrys can be made. 
*					If no name is entered it will stop taking in addresses if any other feilds are left empty that input is skipped
*					At the end of the programm all addresses are printed
*/

#include "address.h"
#include <iostream>
#include <stdio.h>
#pragma warning(disable: 4996)

void clearCRLF(char *str);

using namespace std;

int main(void)
{
	address addressBook[10];
	char input[1024] = "";
	int retVal = 0;
	bool endProg = false;

	cout << "Ada" << endl << endl;

	for (int addressSet = 0; addressSet < 10; addressSet++)
	{

		cout << "Entering address number " << addressSet + 1 << " into address book" << endl << endl;

		cout << "Please enter your full name:" << endl;//get user input
		fgets(input, 1024, stdin);//get Name
		clearCRLF(input);
		retVal = addressBook[addressSet].setName(input);//Validate Name
		while (retVal != 0)
		{
			if (retVal == kNoEntry)
			{
				endProg = true;
				break;
			}

			else if (retVal < 0)
			{
				if (retVal == kerrorFirstChar)
				{
					cout << "Error: Name cannot begin with spaces, dash(-), apostope('), or period(.)" << endl;
					cout << "Please try again or press Enter to exit" << endl << endl;
					cout << "Please enter your full name:" << endl;//get user input
					fgets(input, 1024, stdin);//get Name
					clearCRLF(input);
					retVal = addressBook[addressSet].setName(input);//Validate Name
				}
				else if (retVal == kerrorNotAlowableChar)
				{
					cout << "Error: Name cannot contain any other characters other than Canadain English letters or spaces, dash(-), apostope('), and period(.)" << endl;
					cout << "Please try again or press Enter to exit" << endl << endl;
					cout << "Please enter your full name:" << endl;//get user input
					fgets(input, 1024, stdin);//get Name
					clearCRLF(input);
					retVal = addressBook[addressSet].setName(input);//Validate Name
				}
				else if (retVal == kerrorToLong)
				{
					cout << "Error: Name cannot be more than 30 characters in length" << endl;
					cout << "Please try again or press Enter to exit" << endl << endl;
					cout << "Please enter your full name:" << endl;//get user input
					fgets(input, 1024, stdin);//get Name
					clearCRLF(input);
					retVal = addressBook[addressSet].setName(input);//Validate Name
				}
				else if (retVal == kerrorMultipleNonAlpha)
				{
					cout << "Error: Name cannot have more than one non alphabetic character" << endl;
					cout << "Please try again or press Enter to exit" << endl << endl;
					cout << "Please enter your full name:" << endl;//get user input
					fgets(input, 1024, stdin);//get Name
					clearCRLF(input);
					retVal = addressBook[addressSet].setName(input);//Validate Name
				}
				
				else
				{
					cout << "unexpected error" << endl;
					endProg = true;
					break;

				}
			}
		}
		if (endProg == true)//break out of for loop
		{
			break;
		}

		cout << "Please enter your address including: House number, Street name and Street type:" << endl;
		fgets(input, 1024, stdin);//get street address
		clearCRLF(input);
		retVal = addressBook[addressSet].setAddress(input);//validate street address
		while (retVal < 0)
		{
			if (retVal == kerrorFirstChar)
			{
				cout << "Error: Street address cannot begin with spaces, dash(-), apostope('), or period(.)" << endl;
				cout << "Please try again or press Enter to skip" << endl << endl;
				cout << "Please enter your street address including: House number, Street name and Street type:" << endl;//get user input
				fgets(input, 1024, stdin);//get Name
				clearCRLF(input);
				retVal = addressBook[addressSet].setAddress(input);//Validate Name
			}
			else if (retVal == kerrorNotAlowableChar)
			{
				cout << "Error: Street address can only contain Canadian English letters, numbers, spaces, dash (-), apostrophe (') and period (.)" << endl;
				cout << "Please try again or press Enter to skip" << endl << endl;
				cout << "Please enter your street address including: House number, Street name and Street type:" << endl;//get user input
				fgets(input, 1024, stdin);//get Name
				clearCRLF(input);
				retVal = addressBook[addressSet].setAddress(input);//Validate Name
			}
			else if (retVal == kerrorToLong)
			{
				cout << "Error: Street address cannot be more than 30 characters in length" << endl;
				cout << "Please try again or press Enter to skip" << endl << endl;
				cout << "Please enter your street address including: House number, Street name and Street type:" << endl;//get user input
				fgets(input, 1024, stdin);//get Name
				clearCRLF(input);
				retVal = addressBook[addressSet].setAddress(input);//Validate Name
			}
			else if (retVal == kerrorMissingStreetData)
			{
				cout << "Error: Missing part of street address." << endl;
				cout << "Street address must be in format:" <<endl << " optional apartment number, must contain street number, street name, street type, and optional contain direction" << endl;
				cout << "Slease try again or press Enter to skip" << endl << endl;
				cout << "Please enter your street address including: House number, Street name and Street type:" << endl;//get user input
				fgets(input, 1024, stdin);//get Name
				clearCRLF(input);
				retVal = addressBook[addressSet].setAddress(input);//Validate Name
			}
			else if (retVal == kerrorHouseNum)
			{
				cout << "Error: The house number must only contain numbers" << endl;
				cout << "Please try again or press Enter to skip" << endl << endl;
				cout << "Please enter your street address including: House number, Street name and Street type:" << endl;//get user input
				fgets(input, 1024, stdin);//get Name
				clearCRLF(input);
				retVal = addressBook[addressSet].setAddress(input);//Validate Name
			}
			else if (retVal == kerrorStreetName)
			{
				cout << "Error: The street name must contain only letters" << endl;
				cout << "Please try again or press Enter to skip" << endl << endl;
				cout << "Please enter your street address including: House number, Street name and Street type:" << endl;//get user input
				fgets(input, 1024, stdin);//get Name
				clearCRLF(input);
				retVal = addressBook[addressSet].setAddress(input);//Validate Name
			}
			else if (retVal == kerrorStreetType)
			{
				cout << "Error: Street type can only be Road(RD), Street(ST), Avenue(AV), Circle(CIR), Boulevard(BLVD), Lane, or Court(CT)" << endl;
				cout << "Please try again or press Enter to skip" << endl << endl;
				cout << "Please enter your street address including: House number, Street name and Street type:" << endl;//get user input
				fgets(input, 1024, stdin);//get Name
				clearCRLF(input);
				retVal = addressBook[addressSet].setAddress(input);//Validate Name
			}
			else if (retVal == kerrorDirection)
			{
				cout << "Error: Street direction must be North(N), South(S), East(E), West(W)" << endl;
				cout << "Please try again or press Enter to skip" << endl << endl;
				cout << "Please enter your street address including: House number, Street name and Street type:" << endl;//get user input
				fgets(input, 1024, stdin);//get Name
				clearCRLF(input);
				retVal = addressBook[addressSet].setAddress(input);//Validate Name
			}
			else if (retVal == kerrorAptNum)
			{
				cout << "Error: Appartment number must only contain numbers and letters" << endl;
				cout << "Please try again or press Enter to skip" << endl << endl;
				cout << "Please enter your street address including: House number, Street name and Street type:" << endl;//get user input
				fgets(input, 1024, stdin);//get Name
				clearCRLF(input);
				retVal = addressBook[addressSet].setAddress(input);//Validate Name
			}
			else
			{
				cout << "unexpected error" << endl;
				endProg = true;
				break;
			}
		}
		if (endProg == true)//break out of for loop
		{
			break;
		}

		cout << "Please enter your city:" << endl;
		fgets(input, 1024, stdin);//Get City
		clearCRLF(input);
		retVal = addressBook[addressSet].setCity(input);//Validate City
		while (retVal < 0)
		{
			if (retVal == kerrorFirstChar)
			{
				cout << "Error: City can not begin with spaces, dash(-), apostope('), or period(.)" << endl;
				cout << "Please try again or press Enter to skip" << endl << endl;
				cout << "Please enter your city:" << endl;//get user input
				fgets(input, 1024, stdin);//get Name
				clearCRLF(input);
				retVal = addressBook[addressSet].setCity(input);//Validate Name
			}
			else if (retVal == kerrorNotAlowableChar)
			{
				cout << "Error: City can only contain Canadian english letters and connot contain multiple spaces in a row" << endl;
				cout << "Please try again or press Enter to skip" << endl << endl;
				cout << "Please enter your city:" << endl;//get user input
				fgets(input, 1024, stdin);//get Name
				clearCRLF(input);
				retVal = addressBook[addressSet].setCity(input);//Validate Name
			}
			else if (retVal == kerrorToLong)
			{
				cout << "Error: City name cannot be more than 60 characters in length" << endl;
				cout << "Please try again or press Enter to skip" << endl << endl;
				cout << "Please enter your city:" << endl;//get user input
				fgets(input, 1024, stdin);//get Name
				clearCRLF(input);
				retVal = addressBook[addressSet].setCity(input);//Validate Name
			}
			else
			{
				cout << "unexpected error" << endl;
				endProg = true;
				break;
			}
		}
		if (endProg == true)//break out of for loop
		{
			break;
		}


		cout << "Please input your province two letter code:" << endl;
		fgets(input, 1024, stdin);//Get Provence
		clearCRLF(input);
		retVal = addressBook[addressSet].setProvince(input);//Validate Provence
		while (retVal < 0)
		{
			if (retVal == kerrorNotAlowableChar)
			{
				cout << "Error: incorrect input. The allowable inputs are:" << endl << "ON, BC, QC, AB, MB, NB, NL, NS, NT, NU, PE, SK, YT" << endl;
				cout << "Please try again or press Enter to skip" << endl << endl;
				cout << "Please input your province two letter code:" << endl;//get user input
				fgets(input, 1024, stdin);//get Name
				clearCRLF(input);
				retVal = addressBook[addressSet].setProvince(input);//Validate Name
			}
			else if (retVal == kerrorToLong)
			{
				cout << "Error: Province name cannot be more than 2 characters long. The allowable inputs are:" << endl << "ON, BC, QC, AB, MB, NB, NL, NS, NT, NU, PE, SK, YT" << endl;
				cout << "Please try again or press Enter to skip" << endl << endl;
				cout << "Please input your province two letter code:" << endl;//get user input
				fgets(input, 1024, stdin);//get Name
				clearCRLF(input);
				retVal = addressBook[addressSet].setProvince(input);//Validate Name

			}
			else if (retVal == kerrorToShort)
			{
				cout << "Error: The province name cannot be less than 2 characters in length. The allowable inputs are:" << endl << "ON, BC, QC, AB, MB, NB, NL, NS, NT, NU, PE, SK, YT" << endl;
				cout << "Please try again or press Enter to skip" << endl << endl;
				cout << "Please input your province two letter code:" << endl;//get user input
				fgets(input, 1024, stdin);//get Name
				clearCRLF(input);
				retVal = addressBook[addressSet].setProvince(input);//Validate Name
			}
			else
			{
				cout << "unexpected error" << endl;
				endProg = true;
				break;
			}
		}
		if (endProg == true)//break out of for loop
		{
			break;
		}

		cout << "Please input your postal code:" << endl;
		fgets(input, 1024, stdin);//Get Postal Code
		clearCRLF(input);
		retVal = addressBook[addressSet].setPostalCode(input);//Validate Postal Code
		while (retVal < 0)
		{
			if (retVal == kerrorNotAlowableChar)
			{
				cout << "Error: Postal code invalid. Valid example: N2Y G7L" << endl;
				cout << "Please try again or press Enter to skip" << endl << endl;
				cout << "Please input your postal code:" << endl;//get user input
				fgets(input, 1024, stdin);//get Name
				clearCRLF(input);
				retVal = addressBook[addressSet].setPostalCode(input);//Validate Name
			}
			else if (retVal == kerrorToLong)
			{
				cout << "Error: Postal code cannot be more than seven characters in length" << endl;
				cout << "Please try again or press Enter to skip" << endl << endl;
				cout << "Please input your postal code:" << endl;//get user input
				fgets(input, 1024, stdin);//get Name
				clearCRLF(input);
				retVal = addressBook[addressSet].setPostalCode(input);//Validate Name
			}
			else if (retVal == kerrorToShort)
			{
				cout << "Error: Postal code cannot be less than 6 characters in length" << endl;
				cout << "Please try again or press Enter to skip" << endl << endl;
				cout << "Please input your postal code:" << endl;//get user input
				fgets(input, 1024, stdin);//get Name
				clearCRLF(input);
				retVal = addressBook[addressSet].setPostalCode(input);//Validate Name
			}
			else
			{
				cout << "unexpected error" << endl;
				endProg = true;
				break;
			}
		}
		if (endProg == true)//break out of for loop
		{
			break;
		}

		cout << "Please enter your ten digit telephone number:" << endl;
		fgets(input, 1024, stdin);//Get Telephone
		clearCRLF(input);
		retVal = addressBook[addressSet].setTelephone(input);//Validate Telephone
		while (retVal < 0)
		{
			if (retVal == kerrorNotAlowableChar)
			{
				cout << "Error: Telephone number can only contain  numbers, dashes(-), periods(.), and brackets" << endl;
				cout << "Please try again or press Enter to skip" << endl << endl;
				cout << "Please enter your ten digit telephone number:" << endl;//get user input
				fgets(input, 1024, stdin);//get Name
				clearCRLF(input);
				retVal = addressBook[addressSet].setTelephone(input);//Validate Name
			}
			else if (retVal == kerrorToLong)
			{
				cout << "Error: Telephone number input cannot be more than 14 characters" << endl;
				cout << "Please try again or press Enter to skip" << endl << endl;
				cout << "Please enter your ten digit telephone number:" << endl;//get user input
				fgets(input, 1024, stdin);//get Name
				clearCRLF(input);
				retVal = addressBook[addressSet].setTelephone(input);//Validate Name
			}
			else if (retVal == kerrorToShort)
			{
				cout << "Error: elephone number cannot be less than 10 characters in length" << endl;
				cout << "Please try again or press Enter to skip" << endl << endl;
				cout << "Please enter your ten digit telephone number:" << endl;//get user input
				fgets(input, 1024, stdin);//get Name
				clearCRLF(input);
				retVal = addressBook[addressSet].setTelephone(input);//Validate Name
			}
			else if (retVal == kerrorFormat)
			{
				cout << "Error: Phone number in wrong format. Please enter in format XXX-XXX-XXXX" << endl;
				cout << "Please try again or press Enter to skip" << endl << endl;
				cout << "Please enter your ten digit telephone number:" << endl;//get user input
				fgets(input, 1024, stdin);//get Name
				clearCRLF(input);
				retVal = addressBook[addressSet].setTelephone(input);//Validate Name
			}
			else if (retVal == kerrorAreaCode)
			{
				cout << "Error: Area code does not match selected province" << endl;
				cout << "Please try again or press Enter to skip" << endl << endl;
				cout << "Please enter your ten digit telephone number:" << endl;//get user input
				fgets(input, 1024, stdin);//get Name
				clearCRLF(input);
				retVal = addressBook[addressSet].setTelephone(input);//Validate Name
			}
			else
			{
				cout << "unexpected error" << endl;
				endProg = true;
				break;
			}
		}
		cout << endl << endl;
		if (endProg == true)//break out of for loop
		{
			break;
		}

		system("cls");
	}


	cout << endl << "Printing address book:" << endl << endl;

	for (int i = 0; i < 10; i++)
	{
		addressBook[i].printAddress();
		if (strcmp(addressBook[i + 1].getName(), "") != 0 && (i == 2 || i == 5 || i == 8)){
			//wait for user input to advance
			cout << endl << endl << "Press any key to scroll" << endl;
			getchar();
			system("cls");
		}
	}

	return 0;
}

// FUNCTION		: void clearCRLF(char *str)
// DESCRIPTION  : This function will get rid of a \n at the end of a string. If there isn't one, it doesn't change the string.
// PARAMETERS   : <char><*str><start of the string> 
// RETURNS      : void
void clearCRLF(char *str)
{
	char *whereIsCRLF = strchr(str, '\n');
	if (whereIsCRLF != NULL)
	{
		*whereIsCRLF = '\0';
	}
}