/*
* FILE			: UnitTestDriver3.cpp
* PROJECT		: PROG1370/PROG1385 - Data Management/Object-oriented Programming  - Project - Winter 2015
* PROGRAMMER	: Nathan Nickel/ Brandon Davies
* FIRST VERSION : 2015-04-11
* DESCRIPTION	: this unit test will focus on testing the DeleteItem() method but will also use addItem so there will be something to actually delete
*/
/* -- this is a FILEHEADER COMMENT --
NAME	:	unitTestDriver3
PURPOSE :	this unit test will focus on testing the DeleteItem() method by checking 3 valid inputs, 3 invalid inputs, and 3 range checks(max/min ranges)
*/

#include "Inventory.h"
#include <string>

int main(void)
{
	Inventory* test = new Inventory();

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

	gunName = "Golden AK.762";
	mod = "sight";
	unlockReq = "Achivement";
	avalibleModifications.push_back(mod);
	extraUnLockReqs.push_back(unlockReq);
	rateOfFire = 50;
	totalAmmo = 120;
	magazineAmmo = 30;
	damage = 54;
	accuracy = 25;
	stability = 15;
	concealment = 30;
	threat = 15;
	levelUnLock = 30;
	cost = 120000;

	test->AddItem(gunName, avalibleModifications, extraUnLockReqs, rateOfFire, totalAmmo, magazineAmmo, damage, accuracy, stability, concealment, threat, levelUnLock, cost);//call main menu

	avalibleModifications.pop_back();
	extraUnLockReqs.pop_back();

	//trying to delete a gun that was just created. should delete the gun along with all of it properties
	try
	{
		//test->displayDatabase();
		cout << "Normal test 1" << endl << "Item being deleted : " << gunName << endl << "Expected outcome: Gun has blown up!" << endl << "Actual outcome: ";
		test->DeleteItem(gunName);
		cout << endl << endl;
		//test->displayDatabase();
	}
	catch (char* e)
	{
		cout << "Error: " << e << endl; //caught an error
	}


	gunName = "Thanatos .50 cal";
	mod = "silencer";
	unlockReq = "DLC";
	avalibleModifications.push_back(mod);
	extraUnLockReqs.push_back(unlockReq);
	rateOfFire = 100;
	totalAmmo = 50;
	magazineAmmo = 600;
	damage = 15;
	accuracy = 10;
	stability = 25;
	concealment = 10;
	threat = 10;
	levelUnLock = 100;
	cost = 20000;

	test->AddItem(gunName, avalibleModifications, extraUnLockReqs, rateOfFire, totalAmmo, magazineAmmo, damage, accuracy, stability, concealment, threat, levelUnLock, cost);//call main menu

	avalibleModifications.pop_back();
	extraUnLockReqs.pop_back();

	//trying to delete a gun that was just created. should delete the gun along with all of it properties
	try
	{
		//test->displayDatabase();
		cout << "Normal test 2" << endl << "Item being deleted : " << gunName << endl << "Expected outcome: Gun has blown up!" << endl << "Actual outcome: ";
		test->DeleteItem(gunName);
		cout << endl << endl;
	}
	catch (char* e)
	{
		cout << "Error: " << e << endl; //caught an error
	}


	gunName = "OVE9000";
	mod = "stock";
	unlockReq = "DLC";
	avalibleModifications.push_back(mod);
	extraUnLockReqs.push_back(unlockReq);
	rateOfFire = 1500;
	totalAmmo = 600;
	magazineAmmo = 100;
	damage = 80;
	accuracy = 30;
	stability = 40;
	concealment = 5;
	threat = 15;
	levelUnLock = 60;
	cost = 350000;

	test->AddItem(gunName, avalibleModifications, extraUnLockReqs, rateOfFire, totalAmmo, magazineAmmo, damage, accuracy, stability, concealment, threat, levelUnLock, cost);//call main menu

	avalibleModifications.pop_back();
	extraUnLockReqs.pop_back();

	//trying to delete a gun that was just created. should delete the gun along with all of it properties
	try
	{
		//test->displayDatabase();
		cout << "Normal test 3" << endl << "Item being deleted : " << gunName << endl << "Expected outcome: Gun has blown up!" << endl << "Actual outcome: ";
		test->DeleteItem(gunName);
		cout << endl << endl;
	}
	catch (char* e)
	{
		cout << "Error: " << e << endl; //caught an error
	}


	//exception tests:
	//testing to see what happens if you try to delete a gun that never existed. should return an error: "Gun Not Found"
	try
	{
		test->DeleteItem("nonExistentGun 1");
	}
	catch (char* e)
	{
		cout << "Error: " << e << endl; //caught an error
	}
	//testing to see what happens if you try to delete another gun that never existed. should return an error: "Gun Not Found"
	try
	{
		test->DeleteItem("Pistol 2");
	}
	catch (char* e)
	{
		cout << "Error: " << e << endl; //caught an error
	}
	//testing to see what happens if you try to delete something that has already been deleted. since Rifle 3 has already been deleted this should return an error: "Gun Not Found"
	try
	{
		test->DeleteItem("OVE9000");
	}
	catch (char* e)
	{
		cout << "Error: " << e << endl; //caught an error
	}

	delete test;
	return 0;
}
