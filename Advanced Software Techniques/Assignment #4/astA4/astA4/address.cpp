/*
* FILE			: address.cpp
* PROJECT		: PROG1165 - Assignment 4
* PROGRAMMER	: Brandon Davies
* FIRST VERSION : 2015-03-10
* DESCRIPTION	: Contains all of the methods defined in address.h for the address class
*/

#include "address.h"
#include <ctype.h>
#include <string.h>
#include <stdio.h>

#pragma warning(disable: 4996)

/*
*FUNCTION		:	address::setName
*
*DESCRIPTION	:	This function takes in a char array to be saved as a name to be saved in the class.
*					If the name is valid it will be saved to name in the class
*					Validation checks for:
*						Only alpha characters and space dashes and periods
*						First character can only be alpha
*						Only one non alpha allowed per word
*
*PARAMETERS		:	char name[]	: The string to be validated and saved to the private name in the class
*					if the input is valid the input will be saved to class variable name
*					
*
*RETURNS		:	int returnValue		: The return value from the function determing if successful of what the error was
*											kNoError				The program was successful
*											kerrorToLong			The user input was greater than 30 characters
*											kNoEntry				The user did not enter any characters
*											kerrorFirstChar			The first character is not alpha
*											kerrorNotAlowableChar	A character was entered that was not valid or in wrong location
*/
int address::setName(char name[]){
	int returnValue = kNoError;
	bool nonAlphaFlag = false;
	int i = 0;

	//check string length
	if (strlen(name) > 30){
		returnValue = kerrorToLong;
	}

	else if (strlen(name) == 0){//if user enters no data
		returnValue = kNoEntry;
	}

	else if (isalpha(name[0]) == false){//can only start with alpha
		returnValue = kerrorFirstChar;
	}

	//check each character is allowable
	while (name[i] != '\0' && returnValue == kNoError){
		//check if character allowable
		if (isalpha(name[i]) == false && name[i] != ' '){//if it is not space or alpha
			if (nonAlphaFlag == false && (name[i] == '-' || name[i] == '\'' || name[i] == '.' || name[i] == '\'')){//check if it is a special character
				nonAlphaFlag = true;//if it is, set flag saying we have used the special character
			}
			else{//if not it is not allowable
				returnValue = kerrorMultipleNonAlpha;
			}
		}
		//if (name[i] == ' '){//if new word, user is allowed another non alpha character
		//	nonAlphaFlag = false;
		//}
		i++;
	}

	//if Valid save
	if (returnValue == kNoError){
		strcpy(this->name, name);
	}

	return returnValue;
}


/*
*FUNCTION		:	address::setAddress
*
*DESCRIPTION	:	This function takes in a char array to be saved as a street address number to be saved in the class.
*					If the input is valid it is saved in the class. A valid input is Optional:(uuu-)BuildingNumber StreetName StreetType Optional:(Direction)
*					Validation checks:
*					If streen number prefix uuu exists
*						it contains only numbers and alpha characters
*					Building number is only numbers
*					Street name is only alpha characters
*					Street type is one of the following:
*						Road , RD , Rd. , Street , ST , St. , Avenue , AV , Ave. , Circle , CIR , Circ. Boulevard , BLVD , Blvd. , Lane , Ln. , Court , CT , Ct.
*						check is not case sensitive, saves is in casing shown above
*					Checks Direction (if exists) is one of the following:
*						North , N , N. , South , S , S. , East , E , E. , West , W , W. 
*						check is not case sensitive, saves is in casing shown above
*
*PARAMETERS		:	char address[]	: The string to be validated and saved to the private address in the class
*
*RETURNS		:	int returnValue		: The return value from the function determing if successful of what the error was
*											kNoError				The program was successful
*											kerrorToLong			The user input was greater than 60 characters
*											kNoEntry				The user did not enter any characters
*											kerrorNotAlowableChar	A character was entered that was not valid or in wrong location
*											kerrorMissingStreetData	Not all of the required data was entered
*											kerrorAptNum			The appartment number contains more than number or alpha
*											kerrorHouseNum			House number contains more than alpha
*											kerrorStreetName		Street name contains more than alpha
*											kerrorStreetType		Street type is not of an allowable string
*											kerrorDirection			Direction is not of an allowable string
*/
int address::setAddress(char address[]){
	int returnValue = kNoError;
	bool nonAlphaFlag = false;
	bool hasDash = false;
	int beginingString = 0;
	int i = 0;
	int counter = 0;
	char saveString[61] = "";//used to save the string to be savved to the class; all string changes are applied to the string
	char streetType[10] = "";
	char direction[6] = "";

	//check length
	if (strlen(address) > 60){
		returnValue = kerrorToLong;
	}

	//check skip
	else if (strlen(address) == 0){
		returnValue = kNoEntry;
	}

	//check each character is correct
	//check if dash in first string (befor space)
	while (address[i] != ' ' && returnValue == kNoError){
		if (address[i] == '-'){
			hasDash = true;
			break;
		}
		if (address[i] == '\0'){
			returnValue = kerrorMissingStreetData;
			break;
		}
		i++;
	}

	/****Verify Building Number*****/
	i = 0;
	if (hasDash == true && returnValue == kNoError){//if there is a dash
		while (address[i] != '-' && returnValue == kNoError){//check characters until - are alphanumeric
			if (isalnum(address[i]) == false){
				returnValue = kerrorAptNum;
			}
			i++;
		}
		i++; //move off of '-' character
		//check characters after - are numeric
		while (address[i] != ' ' && returnValue == kNoError){//check caracters after - area numeric
			if (isdigit(address[i]) == false){
				returnValue = kerrorHouseNum;
			}
			i++;
		}
	}
	else if (returnValue == kNoError){//if no dash
		//check characters are numeric
		while (address[i] != ' ' && returnValue == kNoError){//check caracters until - are alphanumeric
			if (isdigit(address[i]) == false){
				returnValue = kerrorHouseNum;
			}
			i++;
		}
	}

	/****check street name****/
	i++;//move off of last space
	while (address[i] != ' ' && returnValue == kNoError){
		//check all letters
		if (isalpha(address[i]) == false){
			returnValue = kerrorStreetName;
		}
		if (address[i] == '\0'){
			returnValue = kerrorMissingStreetData;
			break;
		}
		i++;
	}

	/*****check street type*****/
	beginingString = i;    
	if (address[i] == '\0' && returnValue == kNoError){//check if anything left in input
		returnValue = kerrorMissingStreetData;//if not street type missing
	}

	//save street type in its own string to check valid
	i++;//move off of last space
	while (address[i] != ' ' && address[i] != '\0' && returnValue == kNoError){
		if ((i - beginingString) > 9){//more than 9 characters to be coppied in
			returnValue = kerrorStreetType;
			break;
		}
		streetType[counter++] = address[i];
		i++;
	}

	//compare the string containing street type to valid types
	if (returnValue == kNoError){
		i = beginingString+1;//move past last space
		strcpy(saveString, address);
		returnValue = kerrorStreetType;
		if (stricmp(streetType, "road") == 0 ||
			stricmp(streetType, "street") == 0 ||
			stricmp(streetType, "avenue") == 0 ||
			stricmp(streetType, "circle") == 0 ||
			stricmp(streetType, "boulevard") == 0 ||
			stricmp(streetType, "lane") == 0 ||
			stricmp(streetType, "court") == 0 ||
			stricmp(streetType, "rd.") == 0 ||
			stricmp(streetType, "st.") == 0 ||
			stricmp(streetType, "ave.") == 0 ||
			stricmp(streetType, "circ.") == 0 ||
			stricmp(streetType, "blvd.") == 0 ||
			stricmp(streetType, "ln.") == 0 ||
			stricmp(streetType, "ct.") == 0){//If it is type from the list above format it
			int counter = 1;
			saveString[i++] = toupper(streetType[0]);//change the user input to correct capitolization
			while (streetType[counter] != '\0'){
				saveString[i++] = tolower(streetType[counter++]);
			}
			returnValue = kNoError;
		}

		else if (stricmp(streetType, "rd") == 0 ||
			stricmp(streetType, "st") == 0 ||
			stricmp(streetType, "av") == 0 ||
			stricmp(streetType, "cir") == 0 ||
			stricmp(streetType, "blvd") == 0 ||
			stricmp(streetType, "ct") == 0){//If it is type from the list above format it
			int counter = 0;
			while (streetType[counter] != '\0'){
				saveString[i++] = toupper(streetType[counter++]);//change the user input to correct capitolization
			}
			returnValue = kNoError;
		}
	}
	i++;
	/****check street direction*****/
	counter = 0;
	beginingString = i;
	//save direction into its own string to check
	while (address[i] != '\0' && returnValue == kNoError){
		direction[counter++] = address[i];
		i++;
		if ((i - beginingString) > 5){
			returnValue = kerrorDirection;
		}
	}

	//compare the given direction to valid directions
	if (returnValue == kNoError && strlen(direction) != 0){
		i = beginingString;
		returnValue = kerrorDirection;
			if (stricmp(direction, "north") == 0 ||
				stricmp(direction, "south") == 0 ||
				stricmp(direction, "east") == 0 ||
				stricmp(direction, "west") == 0){//if given direction matches one from list above
			int counter = 1;
			saveString[i++] = toupper(direction[0]);//change user input to proper capitolizeation
			while (direction[counter] != '\0'){
				saveString[i++] = tolower(direction[counter++]);
			}
			returnValue = kNoError;
		}

		else if (stricmp(direction, "n") == 0 ||
			stricmp(direction, "s") == 0 ||
			stricmp(direction, "e") == 0 ||
			stricmp(direction, "w") == 0 ||
			stricmp(direction, "n.") == 0 ||
			stricmp(direction, "s.") == 0 ||
			stricmp(direction, "e.") == 0 ||
			stricmp(direction, "w.") == 0){//if given direction matches one from list above
			saveString[i++] = toupper(direction[0]);//change user input to proper capitolizeation
			returnValue = kNoError;
		}
	}
	if (returnValue == kNoError){//if entire address is valid
		strcpy(this->streetAdress, saveString);//save it in the class
	}
	
	return returnValue;
}



/*
*FUNCTION		:	address::setCity
*
*DESCRIPTION	:	This function takes in a char array to be saved as a city to be saved in the class.
*					If the City is valid it is saved to the class variable city
*					Validation checks:
*						input length not greater than 60 charaters
*						did not enter anything
*						each character is alpha character or poeiod, dash or apostraphy
*						first character is alpha
*						no two spaces in a row
*
*PARAMETERS		:	char city[]	: The string to be validated and saved to the private city in the class
*					if the input is valid the input will be saved to class variable city
*					Validation checks:
*						first character is a alpha character
*						all characters are alpha, period, space, single quote or dash
*						no 2 spaces in a row
*
*RETURNS		:	int returnValue		: The return value from the function determing if successful of what the error was
*											kNoError				The program was successful
*											kerrorToLong			The user input was greater than 60 characters
*											kNoEntry				The user did not enter any characters
*											kerrorFirstChar			The first character is not alpha
*											kerrorNotAlowableChar	A character was entered that was not valid or in wrong location
*/
int address::setCity(char city[]){
	int returnValue = kNoError;
	int i = 0;

	//check length
	if (strlen(city) > 60){
		returnValue = kerrorToLong;
	}

	//check skip
	else if (strlen(city) == 0){
		returnValue = kNoEntry;
	}

	//check first character value
	else if (isalpha(city[0]) == false){//first character must be alpha
		returnValue = kerrorFirstChar;
	}

	//check each character is valid
	while (returnValue == kNoError && city[i] != '\0'){
		if (isalpha(city[i]) == false && city[i] != '-' && city[i] != '\'' && city[i] != '.' && city[i] != ' '){//if the character is not a valid character
			returnValue = kerrorNotAlowableChar;
		}
		if (city[i] == ' ' && city[i - 1] == ' '){//not allowed 2 consecutive spaces
			returnValue = kerrorNotAlowableChar;
		}
		i++;
	}

	if (returnValue == kNoError){//is the city is valid
		strcpy(this->city, city);//save the city to the class
	}
	return returnValue;
}



/*
*FUNCTION		:	address::setProvince
*
*DESCRIPTION	:	This function takes in a char array to be saved as a province to be saved in the class.
*					if the province is valid it is saved to the class variable will all capitol letters
*					validation checks that the input is one of the following:
*					ON, BC, QC, AB, MB, NB, NL, NS, NT, NU, PE, SK, YT
*						The check is not case sensitive
*
*PARAMETERS		:	char province[]	: The string to be validated and saved to the private province in the class
*
*RETURNS		:	int returnValue		: The return value from the function determing if successful of what the error was
*											kNoError				The program was successful
*											kNoEntry				The user did not enter any characters
*											kErrorToShort			The user entered less than 2 characters
*											kerrorToLong			The user input was greater than 2 characters
*											kerrorNotAlowableChar	The entry contains a invalid character, this is an invalid provence
*/
int address::setProvince(char province[]){
	int returnValue = kNoError;
	char saveString[3] = "";

	//check skip
	if (strlen(province) == 0){
		returnValue = kNoEntry;
	}

	//check length
	else if (strlen(province) > 2){
		returnValue = kerrorToLong;
	}
	
	else if (strlen(province) < 2){
		returnValue = kerrorToShort;
	}

	//check input matches one of the 12 allowable inputs
	else if (stricmp(province, "ON") != 0 &&
		stricmp(province, "BC") != 0 &&
		stricmp(province, "QC") != 0 &&
		stricmp(province, "AB") != 0 &&
		stricmp(province, "MB") != 0 &&
		stricmp(province, "NB") != 0 &&
		stricmp(province, "NL") != 0 &&
		stricmp(province, "NS") != 0 &&
		stricmp(province, "NT") != 0 &&
		stricmp(province, "NU") != 0 &&
		stricmp(province, "PE") != 0 &&
		stricmp(province, "SK") != 0 &&
		stricmp(province, "YT") != 0){//if it does not match any allowable inputs
		returnValue = kerrorNotAlowableChar;//set error
	}

	else{//if it is valid change the capitolization to all capitols
		strcpy(saveString, province);
		saveString[0] = toupper(province[0]);
		saveString[1] = toupper(province[1]);
	}

	if (returnValue == kNoError){//if the province is valid
		strcpy(this->province, saveString);//save it to the class
	}
	return returnValue;
}

/*
*FUNCTION		:	address::setPostalCode
*
*DESCRIPTION	:	This function takes in a char array to be saved as a postal code to be saved in the class.
*					The entered postal code may have a space or not. letters may be capitol or not
*					must be in format: letter, digit, letter, digit, letter, digit or letter, digit, letter, space, digit, letter, digit
*					If code is valid, postal code will be with capitol letters and with space
*
*PARAMETERS		:	char postalCode[]	: The string to be validated and saved to the private postalCode in the class
*
*RETURNS		:	int returnValue		: The return value from the function determing if successful of what the error was
*											kNoError				The program was successful
*											kNoEntry				The user did not enter any characters
*											kErrorToShort			The user entered less than 6 characters
*											kerrorToLong			The user input was greater than 7 characters
*											kerrorNotAlowableChar	The user enterd a character not allowable at that time
*/
int address::setPostalCode(char postalCode[]){
	int returnValue = kNoError;
	int i = 0;
	int codeNum = 3;
	bool correctFlag = false;
	char firstCharSet[37] = "ABCEGHJKLMNPRSTVXYabceghjklmnprstvxy";
	char secondCharSet[42] = "ABCEGHJKLMNPRSTVWXYZabceghjklmnprstvwxyz";
	char saveString[8] = "";

	//check skip
	if (strlen(postalCode) == 0){
		returnValue = kNoEntry;
	}

	//check length
	else if (strlen(postalCode) > 7){
		returnValue = kerrorToLong;
	}

	else if (strlen(postalCode) < 6){
		returnValue = kerrorToShort;
	}

	else if (strlen(postalCode) == 7){
		if (postalCode[3] != ' '){
			returnValue = kerrorNotAlowableChar;
		}
	}
	/****Check code is valid****/
	/**check first character**/
	while (i <= 37 && returnValue == kNoError){//loop through array of allowable characters until run out of valid characters or character is found to be valid
		if (postalCode[0] == firstCharSet[i]){
			correctFlag = true;
			saveString[0] = toupper(postalCode[0]);//save the valid character capitalized is the string to be saved
			break;
		}
		i++;
	}
	if (correctFlag == false && returnValue == kNoError){//if no other error, but character is invalid
		returnValue = kerrorNotAlowableChar;//set return error
	}

	/**check second number**/
	if (isdigit(postalCode[1]) == false && returnValue == kNoError){//if not a number and no other errors
		returnValue = kerrorNotAlowableChar;//set error code
	}
	else if (returnValue == kNoError){//digit is valid and no other errors
		saveString[1] = postalCode[1];//save the digit to the string to be saved
	}

	/**check third character**/
	//reset variables
	i = 0;
	correctFlag = false;

	while (i <= 42 && returnValue == kNoError){//loop through array of allowable characters until run out of valid characters or character is found to be valid
		if (postalCode[2] == secondCharSet[i]){
			correctFlag = true;
			saveString[2] = toupper(postalCode[2]);//save the valid character capitalized is the string to be saved
			break;
		}
		i++;
	}
	if (correctFlag == false && returnValue == kNoError){//if no other error, but character is invalid
		returnValue = kerrorNotAlowableChar;
	}

	//check fourth character is space
	if (postalCode[3] == ' '){
		codeNum = 4;
	}
	saveString[3] = ' ';

	/**check fouth number**/
	if (isdigit(postalCode[codeNum]) == false && returnValue == kNoError){//if not a number and no other errors
		returnValue = kerrorNotAlowableChar;//set error code
	}
	else if (returnValue == kNoError){//digit is valid and no other errors
		saveString[4] = postalCode[codeNum];//save the digit to the string to be saved
		codeNum++;
	}

	/**check fifth character**/
	//reset variables
	i = 0;
	correctFlag = false;

	while (i <= 42 && returnValue == kNoError){//loop through array of allowable characters until run out of valid characters or character is found to be valid
		if (postalCode[codeNum] == secondCharSet[i]){
			correctFlag = true;
			saveString[5] = toupper(postalCode[codeNum]);//save the valid character capitalized is the string to be saved
			codeNum++;
			break;
		}
		i++;
	}
	if (correctFlag == false && returnValue == kNoError){//if no other error, but character is invalid
		returnValue = kerrorNotAlowableChar;
	}

	/**check sixth number**/
	if (isdigit(postalCode[codeNum]) == false && returnValue == kNoError){//if not a number and no other errors
		returnValue = kerrorNotAlowableChar;//set error code
	}
	else if(returnValue == kNoError){//digit is valid and no other errors
		saveString[6] = postalCode[codeNum];//save the digit to the string to be saved
		saveString[7] = '\0';//end the string in a string terminator
	}

	if (returnValue == kNoError){
		strcpy(this->postalCode, saveString);
	}
return returnValue;
}


/*
*FUNCTION		:	address::setTelephone
*
*DESCRIPTION	:	This function takes in a char array to be saved as a telephone number to be saved in the class. 
*					If the number if valid it is saved in the class in format XXX-XXX-XXXX
*					It validates: 
*						it is in a valid format (XXX) XXX-XXXX , XXX-XXX-XXXX , XXX.XXX.XXXX , XXXXXXXXXX
*						all phone number digits are valid numbers
*						area code matches area codes from previously envered province
*							If no province was entered then it checks the area code is valid in any province
*
*PARAMETERS		:	char telephone[]	: The string to be validated and saved to the private telephone in the class
*
*RETURNS		:	int returnValue		: The return value from the function determing if successful of what the error was
*											kNoError				The program was successful
*											kerrorToLong			The user input was greater than 14 characters
*											kerrorToShort			The user input was less than 10 characters
*											kNoEntry				The user did not enter any characters
*											kerrorNotAlowableChar	A character was entered that was not valid or in wrong location
*											kerrorAreaCode			The entered area code does not match province
*											kerrorFormat			The number format was not consistant
*/
int address::setTelephone(char telephone[]){
	int returnValue = kNoError;
	int charNum = 0;
	int provinceIndex = 0;
	int index = 0;
	char userDelimiter = 'x';
	char areaCode[4] = "";
	char saveString[13] = "";//used to build the phone number into a standard format XXX-XXX-XXXX
	char possibleAreaCodes[13][14][4]{//list of allowable area codes by province
			{//Alberta
				"403", "587", "780",
			},
			{//British Columbia
				"236", "250", "604", "778",
			},
			{//Manitoba
				"204", "431",
			},
			{//New Brunswik
				"506",
			},
			{//Newfoundland
				"709",
			},
			{//Northwest Territories
				"867",
			},
			{//Nove Socia
				"902",
			},
			{//Nunavut
				"867",
			},
			{//Ontario
				"226", "249", "289", "343", "365", "416", "437", "519", "613", "647", "705", "807", "905",
			},
			{//Prince Edward Island
				"902", "782",
			},
			{//Quebec
				"418", "438", "450", "514", "579", "581", "819", "873",
			},
			{//Saaskatchewan
				"306", "639",
			},
			{//Yukon
				"867"
			}
	};

	//check skip
	if (strlen(telephone) == 0){
		returnValue = kNoEntry;
	}

	//check length
	else if (strlen(telephone) > 14){
		returnValue = kerrorToLong;
	}

	else if (strlen(telephone) < 10){
		returnValue = kerrorToShort;
	}

	/**get area code**/
	else if (isdigit(telephone[0]) == false){//if first character not a number
		if (telephone[0] != '('){//check if it is an oopen bracket
			returnValue = kerrorNotAlowableChar;
		}
		else{
			charNum = 1;//if so start at second character
		}
	}
	if (isdigit(telephone[charNum]) == false && returnValue == kNoError){//if current to error and first digit is not valid
		returnValue = kerrorNotAlowableChar;
	}
	else if(returnValue == kNoError){//first digit is valid, run if no errors
		saveString[0] = telephone[charNum];//add first number to build phone number
		areaCode[0] = telephone[charNum];
		charNum++;
		if (isdigit(telephone[charNum]) == false){//is second digit is not valid
			returnValue = kerrorNotAlowableChar;
		}
		else{//second character is valid
			saveString[1] = telephone[charNum];//add second number to build phone number
			areaCode[1] = telephone[charNum];
			charNum++;
			if (isdigit(telephone[charNum]) == false){//third charater is not valid
				returnValue = kerrorNotAlowableChar;
			}
			else{//third character is valid
				saveString[2] = telephone[charNum];//add third number to build phone number
				saveString[3] = '-';//add delimiter to build phone number
				areaCode[2] = telephone[charNum];
				areaCode[3] = '\0';
			}
		}
	}
	/**check area code is valid**/
	//find what province user inputed 
	if (strlen(this->province) == 0){//if no province set selection to -1
		provinceIndex = -1;
	}
	else if (stricmp(this->province, "AB") == 0){
		provinceIndex = 0;
	}
	else if (stricmp(this->province, "BC") == 0){
		provinceIndex = 1;
	}
	else if (stricmp(this->province, "MB") == 0){
		provinceIndex = 2;
	}
	else if (stricmp(this->province, "NB") == 0){
		provinceIndex = 3;
	}
	else if (stricmp(this->province, "NL") == 0){
		provinceIndex = 4;
	}
	else if (stricmp(this->province, "NT") == 0){
		provinceIndex = 5;
	}
	else if (stricmp(this->province, "NS") == 0){
		provinceIndex = 6;
	}
	else if (stricmp(this->province, "NU") == 0){
		provinceIndex = 7;
	}
	else if (stricmp(this->province, "ON") == 0){
		provinceIndex = 8;
	}
	else if (stricmp(this->province, "PE") == 0){
		provinceIndex = 9;
	}
	else if (stricmp(this->province, "QC") == 0){
		provinceIndex = 10;
	}
	else if (strcmp(this->province, "SK") == 0){
		provinceIndex = 11;
	}
	else if (strcmp(this->province, "YT") == 0){
		provinceIndex = 12;
	}

	if (returnValue == kNoError){
		returnValue = kerrorAreaCode;//set area code error by default and if it is valid change it back to no error
		if (provinceIndex != -1){//if there is a listed province, check that provences area codes
			while (possibleAreaCodes[provinceIndex][index][0] != '\0'){
				if (strcmp(possibleAreaCodes[provinceIndex][index], areaCode) == 0){
					returnValue = kNoError;
				}
				index++;
			}
		}
		else{//id there is no listed province check all area codes
			provinceIndex = 0;
			while (provinceIndex <= 12){
				while (possibleAreaCodes[provinceIndex][index][0] != '\0'){
					if (strcmp(possibleAreaCodes[provinceIndex][index], areaCode) == 0){
						returnValue = kNoError;
					}
					index++;
				}
				provinceIndex++;
			}
		}
	}

	/**Done checking area code**/
	//if opening brace check closing brace
	if (telephone[0] == '(' && telephone[4] != ')' && returnValue == kNoError){
		returnValue = kerrorFormat;
	}

	charNum++;
	//check for delimitors
	if (telephone[charNum] == ' ' || telephone[charNum] == '.' || telephone[charNum] == ')' || telephone[charNum] == '-' && returnValue == kNoError){//if next character is a delimiter, and no errors, move forward
		//if (telephone[charNum] != ')'){
			userDelimiter = telephone[charNum];
		//}
		if (isdigit(telephone[charNum + 1]) == false){
			userDelimiter = telephone[charNum+1];
		}
		charNum++;
		if (telephone[charNum - 1] == ')' && telephone[charNum] == ' '){//if delimiter was a colse brace, a space is allowed
			charNum++;
		}
	}
	else if (isdigit(telephone[charNum]) == false && returnValue == kNoError){
		returnValue = kerrorFormat;
	}

	/**check the next 3 digits**/
	if (returnValue == kNoError){
		if (isdigit(telephone[charNum]) == false){
			returnValue = kerrorNotAlowableChar;
		}
		saveString[4] = telephone[charNum];//add fourth number to build phone number
		charNum++;
		if (isdigit(telephone[charNum]) == false){
			returnValue = kerrorNotAlowableChar;
		}
		saveString[5] = telephone[charNum];//add fifth number to build phone number
		charNum++;
		if (isdigit(telephone[charNum]) == false){
			returnValue = kerrorNotAlowableChar;
		}
		saveString[6] = telephone[charNum];//add sixth number to build phone number
		saveString[7] = '-';//add delimiter to build phone number
		charNum++;
	}

		//check second delimiter matches
	if (telephone[charNum] != userDelimiter && returnValue == kNoError){
		//check if delimiter not existant
		if (userDelimiter == 'x'){
			//dont increment
		}
		else if (userDelimiter == ')' && isdigit(telephone[charNum])==false){
			charNum++;
		}
		else if (userDelimiter == ')'){
			//do nothing
		}
		else{
			returnValue = kerrorFormat;
		}
	}
	else if (returnValue == kNoError){
		charNum++;
	}

	//check last 4 digits
	if (returnValue == kNoError){
		if (isdigit(telephone[charNum]) == false){
			returnValue = kerrorNotAlowableChar;
		}
		saveString[8] = telephone[charNum];//add seventh number to build phone number
		charNum++;
		if (isdigit(telephone[charNum]) == false){
			returnValue = kerrorNotAlowableChar;
		}
		saveString[9] = telephone[charNum];//add eigth number to build phone number
		charNum++;
		if (isdigit(telephone[charNum]) == false){
			returnValue = kerrorNotAlowableChar;
		}
		saveString[10] = telephone[charNum];//add ninth number to build phone number
		charNum++;
		if (isdigit(telephone[charNum]) == false){
			returnValue = kerrorNotAlowableChar;
		}
		saveString[11] = telephone[charNum];//add tenth number to build phone number
		saveString[12] = '\0';//add string terminator to build phone number
	}

	if (returnValue == kNoError){//if no error save the build phone number
		strcpy(this->telephone, saveString);
	}

	return returnValue;
}

/**********************************************************************/
/*********************Getters******************************************/
/**********************************************************************/

const char* address::getName(void){
	return this->name;
}
const char* address::getAddress(void){
	return this->streetAdress;
}
const char* address::getCity(void){
	return this->city;
}
const char* address::getProvince(void){
	return this->province;
}
const char* address::getPostalCode(void){
	return this->postalCode;
}
const char* address::getTelephone(void){
	return this->telephone;
}


/*
*FUNCTION		:	address::printAddress
*
*DESCRIPTION	:	This function takes prints out all of the address data in a defined format
*
*PARAMETERS		:	void
*
*RETURNS		:	void
*/
void address::printAddress(void){
	if (strlen(this->name) != 0){
		printf("%s\n%s\n%s, %s, %s\n%s\n++++++++++++\n", this->name, this->streetAdress, this->city, this->province, this->postalCode, this->telephone);
	}
}

address::address(){
	strcpy(name, "");
	strcpy(streetAdress, "");
	strcpy(city, "");
	strcpy(province, "");
	strcpy(postalCode, "");
	strcpy(telephone, "");
}
