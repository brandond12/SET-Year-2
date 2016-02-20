/*
* FILE			: UnitTestDriver2.cpp
* PROJECT		: PROG1370/PROG1385 - Data Management/Object-oriented Programming  - Project - Winter 2015
* PROGRAMMER	: Nathan Nickel/ Brandon Davies
* FIRST VERSION : 2015-04-11
* DESCRIPTION	: this unit test will focus on testing the SetDamage() method
*/
/* -- this is a FILEHEADER COMMENT --
NAME	:	unitTestDriver2
PURPOSE :	this unit test will focus on testing the SetDamage() method by checking 3 valid inputs, 3 invalid inputs, and 3 range checks(max/min ranges)
*/

#include "Weapon.h"
#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	Weapon* test = new Weapon("WeaponToTest.SetDamage");
	//Normal tests_________________________________________________________
	//Normal Test 1. this input is a valid number and should be accpeted by the SetDamage() method and the value should be changed
	int newDamage = 100;
	cout << "Normal test 1" << endl << "Item altered : " << test->GetGunName() << endl << "Expected outcome: The guns Damage to change to " << newDamage << endl << "Current Value: " << test->GetDamage() << endl << "Actual outcome: ";
	test->SetDamage(newDamage);
	cout << test->GetDamage() << endl << endl;

	//Normal Test 2. this input is a valid number and should be accpeted by the SetDamage() method and the value should be changed
	newDamage = 500;
	cout << "Normal test 2" << endl << "Item altered : " << test->GetGunName() << endl << "Expected outcome: The guns Damage to change to " << newDamage << endl << "Current Value: " << test->GetDamage() << endl << "Actual outcome: ";
	test->SetDamage(newDamage);
	cout << test->GetDamage() << endl << endl;

	//Normal Test 3. this input is a valid number and should be accpeted by the SetDamage() method and the value should be changed
	newDamage = 15;
	cout << "Normal test 3" << endl << "Item altered : " << test->GetGunName() << endl << "Expected outcome: The guns Damage to change to " << newDamage << endl << "Current Value: " << test->GetDamage() << endl << "Actual outcome: ";
	test->SetDamage(newDamage);
	cout << test->GetDamage() << endl << endl;

	//Execption Tests______________________________________________________
	//Exception test 1. this input is a not a valid number and should not be accpeted by the SetDamage() method and the value should not be changed
	newDamage = -5;
	cout << "Exception test 1" << endl << "Item altered : " << test->GetGunName() << endl << "Expected outcome: The guns Damage should stay the same and not change to " << newDamage << endl << "Current Value: " << test->GetDamage() << endl << "Actual outcome: ";
	test->SetDamage(newDamage);
	cout << test->GetDamage() << endl << endl;

	//Exception test 2. this input is a not a valid number and should not be accpeted by the SetDamage() method and the value should not be changed
	newDamage = 100000;
	cout << "Exception test 2" << endl << "Item altered : " << test->GetGunName() << endl << "Expected outcome: The guns Damage should stay the same and not change to " << newDamage << endl << "Current Value: " << test->GetDamage() << endl << "Actual outcome: ";
	test->SetDamage(newDamage);
	cout << test->GetDamage() << endl << endl;

	//Exception test 3. this input is a not a valid number and should not be accpeted by the SetDamage() method and the value should not be changed
	newDamage = -100;
	cout << "Exception test 3" << endl << "Item altered : " << test->GetGunName() << endl << "Expected outcome: The guns Damage should stay the same and not change to " << newDamage << endl << "Current Value: " << test->GetDamage() << endl << "Actual outcome: ";
	test->SetDamage(newDamage);
	cout << test->GetDamage() << endl << endl;

	//Boundary tests_______________________________________________________
	//Boundary test 1. this input is a valid number and is the maximum allowable number for the damage. it should be accpeted by the SetDamage() method and the value should be changed
	newDamage = kMaxDamage;
	cout << "Boundary test 1" << endl << "Item altered : " << test->GetGunName() << endl << "Expected outcome: The guns Damage should change to " << newDamage << endl << "Current Value: " << test->GetDamage() << endl << "Actual outcome: ";
	test->SetDamage(newDamage);
	cout << test->GetDamage() << endl << endl;

	//Boundary test 2. this input is a valid number and is the minimum allowable number for the damage. it should be accpeted by the SetDamage() method and the value should be changed
	newDamage = 0;
	cout << "Boundary test 2" << endl << "Item altered : " << test->GetGunName() << endl << "Expected outcome: The guns Damage should change to " << newDamage << endl << "Current Value: " << test->GetDamage() << endl << "Actual outcome: ";
	test->SetDamage(newDamage);
	cout << test->GetDamage() << endl << endl;

	//Boundary test 3.  this input is a not avalid number and is one more than the maximum allowable number for the damage. it should not be accpeted by the SetDamage() method and the value should not be changed
	newDamage = kMaxDamage+1;
	cout << "Boundary test 3" << endl << "Item altered : " << test->GetGunName() << endl << "Expected outcome: The guns Damage should stay the same and not change to " << newDamage << endl << "Current Value: " << test->GetDamage() << endl << "Actual outcome: ";
	test->SetDamage(newDamage);
	cout << test->GetDamage() << endl << endl;

	delete test;
	return 0;
}
