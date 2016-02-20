/*
* FILE : Inventory.cpp
* PROJECT : DS/OOP
* PROGRAMMER : Brandon Davies & Nathan Nickel
* FIRST VERSION : 2015-04-15
* DESCRIPTION : This file is the class header for Inventory
*/

/// \ class Inventory
/// \ brief the perpose of this class is to store all  the weapons. this class is the inventory
/// <b>ContainernLayer</b>
/// \ author <i>Nathan Nickel & Brandon Davies</i>

#ifndef _ContainerLayer_
#define _ContainerLayer_
#include <string.h>
#include "Weapon.h"
#include <vector>
#include <iostream> 
#include <fstream> 
#pragma warning(disable: 4996)
using namespace std;

class Inventory{
	/* ====================================== */
	/*              PRIVATE                   */
	/* ====================================== */
private:
	/* -------------- CONSTANTS ------------- */
	/* -------------- ATTRIBUTES ------------ */
	vector<Weapon*> weapons; ///<a vector of weapons

	/* ====================================== */
	/*              PUBLIC                    */
	/* ====================================== */
public:
	/* -------------- ATTRIBUTES ------------ */
	/* -------------- METHODS --------------- */
	Inventory(); ///<constructor
	~Inventory();///<deconstructor

	//Methods
	void LoadFromFile(void);///<loads the file
	void UpdateFile(void);///<updates teh file
	void AddItem(string gunName, vector<string> avalibleModifications, vector<string> extraUnLockReqs, int rateOfFire, int totalAmmo, int magazineAmmo, int damage, int accuracy, int stability, int concealment, int threat, int levelUnLock, int cost);///<adds an item to the database
	void DeleteItem(string gunName);///<deletes the item that was passed in
	void DeleteDatabase(void);///<deletes the entire database
	void DisplayDatabase(void);///<displays entire database to the screen
};

#endif