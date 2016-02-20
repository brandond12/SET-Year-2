/*
* FILE : getAge.cpp
* PROJECT : PROG1165 - Assignment 1
* PROGRAMMER : Brandon Davies
* FIRST VERSION : 2014-1-30
* DESCRIPTION : The file cantains the main and function to get a users valid age 
* and log when they enter an invalid input
*/

#include "getAge.h"

int main(void){
	char ageStr[127] = "";
	int ageNum = 0;
	int valid = 0;

	do {
		printf("please enter your age: \n");
		valid = getNum(&ageNum);
		if (valid == kErrorNoInput){
			LogError("not allowed to be empty\n\n");
		}
		else if (valid == kErrorNotNumber){
			LogError("Must be a number\n\n");
		}
		else if (valid == kErrorNotRange){
			LogError("Must be between 1 and 110\n\n");
		}
		else{
			printf("Thank you");
		}
	} while (valid != 0);
	return 0;
}



/*
*FUNCTION		:	getNum
*
*DESCRIPTION	:	This function gets a number from the user and check that it is a valid age
*
*PARAMETERS		:	int *age		:	return value for inputed age
*
*RETURNS		:	int				:	returns a error code
*
*/
int getNum(int *age){
	int valid = 0;
	int strLen = 0;
	char ageStr[127] = "";
	*age = 0;
	fgets(ageStr, 126, stdin);
	strLen = strlen(ageStr);
	if (strLen == 1){
		valid = kErrorNoInput;
	}
	else{
		if (allDigit(ageStr, ageStr+(strLen-1)) == 1){//if all characters are numeric
			sscanf_s(ageStr, "%d", age);//scan char* into a int
			if (*age < 1 || *age > 110 ){
				valid = kErrorNotRange;
			}
		}
		else{
			valid = kErrorNotNumber;
		}
	}
	return valid;
}

/*
*FUNCTION		:	allDigit
*
*DESCRIPTION	:	This function checks if all characters in a given string range are digits
*
*PARAMETERS		:	char *pStart	:	pointer to start of string to check
*				:	char *pStop		:	pointer to the end of the string to check
*
*RETURNS		:	int				:	returns 0 if a character is not valid digits
*												1 if all characters valid digits
*
*/
int allDigit(char *pStart, char *pStop){
	int valid = 1;
	int index = 0;
	while (&pStart[index] <= pStop-1){
		if (isdigit(pStart[index]) == 0){
			valid = 0;
		}
		index++;
	}
	return valid;
}


/*
*FUNCTION		:	LogError
*
*DESCRIPTION	:	This function logs error string given to optional Program Console, Debug Console or a Text File. 
*					The date time and message are logged  
*
*PARAMETERS		:	char *error	:	The error message to be logged
*
*RETURNS		:	void
*
*/
void LogError(char *error){
	time_t tTime = time(NULL);
	char timeStamp[127] = "";
	sprintf(timeStamp, "Timestamp : %s", asctime(localtime(&tTime)));

#ifdef kProgramConsole
	printf("%s", timeStamp);
	printf("%s\n", error);
#endif

#ifdef kDebugConsole
	OutputDebugString(timeStamp);
	OutputDebugString(error);
#endif

#ifdef kTextFile
	{
		FILE *OfilePointer = NULL;
		OfilePointer = fopen(kErrorLogFilePath, "a");//open file
		if (OfilePointer == NULL){
			printf("Could not create/open output file. Exit program\n");
		}
		else{
			fprintf(OfilePointer, "%s ", timeStamp);//save date and error to file
			fprintf(OfilePointer, "%s ", error);
			fclose(OfilePointer);//close file
		}
	}
#endif
}