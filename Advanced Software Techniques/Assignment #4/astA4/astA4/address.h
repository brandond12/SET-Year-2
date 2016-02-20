/*
* FILE			: address.h
* PROJECT		: PROG1165 - Assignment 4
* PROGRAMMER	: Brandon Davies
* FIRST VERSION : 2015-03-10
* DESCRIPTION	: The error codes and class deffinition for the address class. 
*					This class validates inputs and gives success return statments as stated in the method headers 
*/

//General returns
#define kNoEntry 1
#define kNoError 0
#define kerrorFirstChar -1
#define kerrorNotAlowableChar -2
#define kerrorToLong -3
#define kerrorToShort -10
#define kerrorMultipleNonAlpha -13

//setAddress returns
#define kerrorMissingStreetData -4
#define kerrorHouseNum -5
#define kerrorAptNum -6
#define kerrorStreetName -7
#define kerrorStreetType -8
#define kerrorDirection -9

//setTelephone returns
#define kerrorAreaCode -11
#define kerrorFormat -12


class address{
private:
	char name[31];
	char streetAdress[61];
	char city[61];
	char province[3];
	char postalCode[8];
	char telephone[13];

public:
	int setName(char name[]);
	int setAddress(char address[]);
	int setCity(char city[]);
	int setProvince(char province[]);
	int setPostalCode(char postalCode[]);
	int setTelephone(char telephone[]);

	const char* getName();
	const char* getAddress();
	const char* getCity();
	const char* getProvince();
	const char* getPostalCode();
	const char* getTelephone();

	void printAddress();
	address();
};