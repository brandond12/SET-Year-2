/*
* FILE			: UnitTestDriver1.cpp
* PROJECT		: PROG1370/PROG1385 - Data Management/Object-oriented Programming  - Project - Winter 2015
* PROGRAMMER	: Nathan Nickel/ Brandon Davies
* FIRST VERSION : 2015-04-11
* DESCRIPTION	: this unit test will focus on testing the AddItem() method
*/
/* -- this is a FILEHEADER COMMENT --
NAME	:	unitTestDriver1
PURPOSE :	this unit test will focus on testing the AddItem() method by checking 3 valid inputs, 3 invalid inputs, and 3 range checks(max/min ranges)
*/
#include "Heister.h"
#include "Inventory.h"
#include "time.h"

#define kNumOfGunAttributes 50

typedef struct weaponInfo
{
	int goodGunAttributes[kNumOfGunAttributes];
	int badGunAttributes[kNumOfGunAttributes];
} weaponInfo;

int createRandomNumber(void);
string createRandomName(void);
string createBadRandomName(void);

int main(void)
{
	srand(time(NULL));//used to randomize rand by telling it where to start
	Inventory* test = new Inventory();
	Heister* values = new Heister();
	weaponInfo* gun = NULL;

	gun = (weaponInfo *)malloc(sizeof(weaponInfo));

	for (int i = 0; i < kNumOfGunAttributes; i++)//fill with random values that should be accepted in add item
	{
		gun->goodGunAttributes[i] = createRandomNumber();
	}
	for (int i = 0; i < kNumOfGunAttributes; i++)//fill with random values that should not ba accepted in addItem
	{
		gun->badGunAttributes[i] = createRandomNumber()+15000000;
	}
	

	string gunName;
	string mod;
	string unlockReq;
	vector<string> avalibleModifications;
	vector<string> extraUnLockReqs;
	int rateOfFire = 0;
	int totalAmmo = 0;
	int magazineAmmo = 0;
	int damage = 0;
	int accuracy = 0;
	int stability = 0;
	int concealment = 0;
	int threat = 0;
	int levelUnLock = 0;
	int cost = 0;



	//normal tests
	//random names and attribes that are within range of what should be accepted will be put in and it is expected that they will be added to the database wihtout throwing an exception
	int next = 0;
	for (int i = 0; i < 3; i++)
	{
		int randomNumber;
		randomNumber = (rand() % 10) + 1;//generates a random number between 10 and 100 not including 100
		int numOfModsOrReq = randomNumber;
		for (int ii = 0; ii < numOfModsOrReq; ii++)
		{
			extraUnLockReqs.push_back(values->createRandomName());
			avalibleModifications.push_back(values->createRandomName());
		}

		gunName = values->createRandomName();
		cout << endl << endl << "Normal test " << i + 1 << endl << "Item to be added : " << gunName << endl << "Expected outcome: no error messages" << endl  << "Actual outcome: " << endl;
		try
		{
			test->AddItem(gunName, avalibleModifications, extraUnLockReqs, gun->goodGunAttributes[i], gun->goodGunAttributes[i], gun->goodGunAttributes[i], gun->goodGunAttributes[i], gun->goodGunAttributes[i], gun->goodGunAttributes[i], gun->goodGunAttributes[i], gun->goodGunAttributes[i], gun->goodGunAttributes[i], gun->goodGunAttributes[i]);
		}
		catch (char* e)
		{
			printf("Error: %s\n", e); //caught an error
			if (strcmp(e, "Invalid Weapon Name") == 0)
			{
				cout << "The Gun name can only use: a-z, A-Z, 0-9, ""."", ""-"", or a space" << endl;
			}
		}
		extraUnLockReqs.clear();
		avalibleModifications.clear();
		test->DisplayDatabase();
		test->DeleteDatabase();
		next = i;
	}
	cout << "Press any key to continue" << endl;
	getchar();
	system("cls");
	cin.clear();
	fflush(stdin);
 	//exception tests

	//exception test 1. this input will have a invalid name but valid values. should throw an exception saying "Invalid Weapon Name"
	gunName = "!@#$%^&*()";
	next++;

	int randomNumber;
	randomNumber = (rand() % 10) + 1;//generates a random number between 10 and 100 not including 100
	int numOfModsOrReq = randomNumber;
	for (int i = 0; i < numOfModsOrReq; i++)
	{
		extraUnLockReqs.push_back(values->createRandomName());
		avalibleModifications.push_back(values->createRandomName());
	}

	cout << endl << "Exception test 1" << endl << "Item to be added : " << gunName << endl << "Expected outcome: error messages" << endl << "Actual outcome: ";
	try
	{
		test->AddItem(gunName, avalibleModifications, extraUnLockReqs, gun->goodGunAttributes[next], gun->goodGunAttributes[next], gun->goodGunAttributes[next], gun->goodGunAttributes[next], gun->goodGunAttributes[next], gun->goodGunAttributes[next], gun->goodGunAttributes[next], gun->goodGunAttributes[next], gun->goodGunAttributes[next], gun->goodGunAttributes[next]);
	}
	catch (char* e)
	{
		printf("Error: %s\n", e); //caught an error
		if (strcmp(e, "Invalid Weapon Name") == 0)
		{
			cout << "The Gun name can only use: a-z, A-Z, 0-9, ""."", ""-"", or a space" << endl;
		}
	}
	extraUnLockReqs.clear();
	avalibleModifications.clear();
	test->DisplayDatabase();
	test->DeleteDatabase();


	//exception test 2. this input will have a valid name but invalid values. 
	gunName = values->createRandomName();

	randomNumber = (rand() % 10) + 1;//generates a random number between 10 and 100 not including 100
	numOfModsOrReq = randomNumber;
	for (int i = 0; i < numOfModsOrReq; i++)
	{
		extraUnLockReqs.push_back(createBadRandomName());
		avalibleModifications.push_back(createBadRandomName());
	}
	next++;
	cout << endl << "Exception test 2" << endl << "Item to be added : " << gunName << endl << "Expected outcome: no error messages but the attributes should default to 1's" << endl << "Actual outcome: ";
	try
	{
		test->AddItem(gunName, avalibleModifications, extraUnLockReqs, gun->badGunAttributes[next], gun->badGunAttributes[next], gun->badGunAttributes[next], gun->badGunAttributes[next], gun->badGunAttributes[next], gun->badGunAttributes[next], gun->badGunAttributes[next], gun->badGunAttributes[next], gun->badGunAttributes[next], gun->badGunAttributes[next]);
	}
	catch (char* e)
	{
		printf("Error: %s\n", e); //caught an error
		if (strcmp(e, "Invalid Weapon Name") == 0)
		{
			cout << "The Gun name can only use: a-z, A-Z, 0-9, ""."", ""-"", or a space" << endl;
		}
	}
	extraUnLockReqs.clear();
	avalibleModifications.clear();
	test->DisplayDatabase();
	test->DeleteDatabase();


	//exception test 3. this input will have a invalid name and invalid values
	gunName = "B@DN@m#!";

	randomNumber = (rand() % 10) + 1;//generates a random number between 10 and 100 not including 100
	numOfModsOrReq = randomNumber;
	for (int i = 0; i < numOfModsOrReq; i++)
	{
		extraUnLockReqs.push_back(createBadRandomName());
		avalibleModifications.push_back(createBadRandomName());
	}
	next++;
	cout << endl << "Exception test 3" << endl << "Item to be added : " << gunName << endl << "Expected outcome: error messages" << endl << "Actual outcome: ";
	try
	{
		test->AddItem(gunName, avalibleModifications, extraUnLockReqs, gun->badGunAttributes[next], gun->badGunAttributes[next], gun->badGunAttributes[next], gun->badGunAttributes[next], gun->badGunAttributes[next], gun->badGunAttributes[next], gun->badGunAttributes[next], gun->badGunAttributes[next], gun->badGunAttributes[next], gun->badGunAttributes[next]);
	}
	catch (char* e)
	{
		printf("Error: %s\n", e); //caught an error
		if (strcmp(e, "Invalid Weapon Name") == 0)
		{
			cout << "The Gun name can only use: a-z, A-Z, 0-9, ""."", ""-"", or a space" << endl;
		}
	}
	extraUnLockReqs.clear();
	avalibleModifications.clear();
	test->DisplayDatabase();
	test->DeleteDatabase();


	cout << "Press any key to continue" << endl;
	getchar();
	system("cls");
	cin.clear();
	fflush(stdin);
	//boundary tests

	//boundary test 1. this input will have a very large number mods and attachments to be added to the gun. should add all the weapon without problem
	gunName = "TEST.MODandUnlcoReq.Limits";
	next++;

	numOfModsOrReq = kMaxMods;
	for (int i = 0; i < numOfModsOrReq; i++)
	{
		extraUnLockReqs.push_back(values->createRandomName());
		avalibleModifications.push_back(values->createRandomName());
	}

	cout << endl << "Boundary test 1" << endl << "Item to be added : " << gunName << endl << "Expected outcome: there should be no error message and mods&unlockReqs should be added properly" << endl << "Actual outcome: " << endl;
	try
	{
		test->AddItem(gunName, avalibleModifications, extraUnLockReqs, gun->goodGunAttributes[next], gun->goodGunAttributes[next], gun->goodGunAttributes[next], gun->goodGunAttributes[next], gun->goodGunAttributes[next], gun->goodGunAttributes[next], gun->goodGunAttributes[next], gun->goodGunAttributes[next], gun->goodGunAttributes[next], gun->goodGunAttributes[next]);
	}
	catch (char* e)
	{
		printf("Error: %s\n", e); //caught an error
		if (strcmp(e, "Invalid Weapon Name") == 0)
		{
			cout << "The Gun name can only use: a-z, A-Z, 0-9, ""."", ""-"", or a space" << endl;
		}
	}
	extraUnLockReqs.clear();
	avalibleModifications.clear();
	test->DisplayDatabase();
	test->DeleteDatabase();

	//boundary test 2. this input will have all the attributes set to their max values. should add weapon
	gunName = "TEST.gunAttributes.Limits";

	randomNumber = (rand() % 10) + 1;//generates a random number between 10 and 100 not including 100
	numOfModsOrReq = randomNumber;
	for (int i = 0; i < numOfModsOrReq; i++)
	{
		extraUnLockReqs.push_back(values->createRandomName());
		avalibleModifications.push_back(values->createRandomName());
	}

	cout << endl << "Boundary test 2" << endl << "Item to be added : " << gunName << endl << "Expected outcome: there should be no error message" << endl << "Actual outcome: "  << endl;
	try
	{
		test->AddItem(gunName, avalibleModifications, extraUnLockReqs, kMaxRateOfFire, kMaxTotalAmmo, kMaxMagazineAmmo, kMaxDamage, kMaxAccuracy, kMaxStability, kMaxConcealment, kMaxThreat, kMaxLevelUnLock, kMaxCost);
	}
	catch (char* e)
	{
		printf("Error: %s\n", e); //caught an error
		if (strcmp(e, "Invalid Weapon Name") == 0)
		{
			cout << "The Gun name can only use: a-z, A-Z, 0-9, ""."", ""-"", or a space" << endl;
		}
	}
	extraUnLockReqs.clear();
	avalibleModifications.clear();
	test->DisplayDatabase();
	test->DeleteDatabase();

	//boundary test 3. will test the limits of the gun name by using all allowable characters. should add all the weapon without problem
	gunName = "-.0123456789 abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	next++;

	randomNumber = (rand() % 10) + 1;//generates a random number between 10 and 100 not including 100
	numOfModsOrReq = randomNumber;
	for (int i = 0; i < numOfModsOrReq; i++)
	{
		extraUnLockReqs.push_back(values->createRandomName());
		avalibleModifications.push_back(values->createRandomName());
	}

	cout << endl << "Boundary test 3" << endl << "Item to be added : " << gunName << endl << "Expected outcome: there should be no error message" << endl << "Actual outcome: " << endl;
	try
	{
		test->AddItem(gunName, avalibleModifications, extraUnLockReqs, gun->goodGunAttributes[next], gun->goodGunAttributes[next], gun->goodGunAttributes[next], gun->goodGunAttributes[next], gun->goodGunAttributes[next], gun->goodGunAttributes[next], gun->goodGunAttributes[next], gun->goodGunAttributes[next], gun->goodGunAttributes[next], gun->goodGunAttributes[next]);
	}
	catch (char* e)
	{
		printf("Error: %s\n", e); //caught an error
		if (strcmp(e, "Invalid Weapon Name") == 0)
		{
			cout << "The Gun name can only use: a-z, A-Z, 0-9, ""."", ""-"", or a space" << endl;
		}
	}
	extraUnLockReqs.clear();
	avalibleModifications.clear();
	test->DisplayDatabase();
	test->DeleteDatabase();




	test->DeleteDatabase();
	free(gun);
	delete values;
	delete test;

	return 0;
}

/**
* \breif this method will create a random input to be put into container layer
* \details <b>Details</b>
*
* \param Noting
*
* \return  randomNumber - <b>string</b> - generated random number between 10 and 100 not including 100
*/
int createRandomNumber(void)
{
	int randomNumber;
	randomNumber = (rand() % 90) + 10;//generates a random number between 10 and 100 not including 100
	return randomNumber;
}

/**
* \breif This method will create a random input to be put into container layer
* \details <b>Details</b>
*
* \param Nothing
*
* \return  randomWord - <b>string</b> - a random gun name 15-20 characters in length and all letters
*/
string createRandomName(void)
{
	string randomWord;
	int randomLength = 0;
	randomLength = (rand() % 15) + 5;//generates a random number between 5 and 20 not including 20
	for (int i = 0; i < randomLength; i++)
	{
		randomWord += (rand() % 26) + 97;//generates a random number between 97 and 123 not including 123
	}
	return randomWord;

}

/**
* \breif This method will create a random input to be put into container layer
* \details <b>Details</b>
*
* \param Nothing
*
* \return  randomWord - <b>string</b> - a random gun name 15-20 characters in length but with no acceptible letters
*/
string createBadRandomName(void)
{
	string randomWord;
	int randomLength = 0;
	randomLength = (rand() % 15) + 5;//generates a random number between 5 and 20 not including 20
	for (int i = 0; i < randomLength; i++)
	{
		randomWord += (rand() % 47)+1;//generates a random number between 1 and 47 not including 47
	}
	return randomWord;

}

