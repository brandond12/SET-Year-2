/*
* FILE			: Heister.h
* PROJECT		: PROG1370/PROG1385 - Data Management/Object-oriented Programming  - Project - Winter 2015
* PROGRAMMER	: Nathan Nickel/ Brandon Davies
* FIRST VERSION : 2015-04-11
* DESCRIPTION	: this is the header for the view layer class that will allow the user to interact with the rest of the program
*/
/// \ class Heister
/// \ brief the perpose of this class is to take input from the user for the weapons and useContainerLayer methods to create and store the weapons
/// <b>Heister</b>
/// \ author <i>Nathan Nickel & Brandon Davies</i>


#ifndef _INCLUDES
#define _INCLUDES
#include "Inventory.h"
#include <string.h>
#include <vector>
using namespace std;

//includes
#include <iostream>
#include <string>
#include "time.h"
#include <sstream>

//defines
#define kNO_INPUT -1
#define kADD_ITEM 1
#define kDELETE_ITEM 2
#define kDELETE_LIST 3
#define kDISPLAY_LIST 4
#define kRANDOM 5
#define kQUIT 0


class Heister
{
	/* ====================================== */
	/*              PRIVATE                   */
	/* ====================================== */
private:
	Inventory* weapon;///< an object for a weapon so container layer functions can be used

	/* ====================================== */
	/*              PUBLIC                    */
	/* ====================================== */
public:
	/* -------------- ATTRIBUTES ------------ */
	/* -------------- METHODS --------------- */
	Heister();///< constructor
	~Heister();///< deconstructor

	void LoadFromFile(void);///< loads the database
	void UpdateFile(void);///< updates the database
	void AddGun(void);///< adds a gun given the right inputs
	void MainMenu(void);///< brings up the menu for the user to interact with
	string CreateRandomName(void);///< creates a random string to be used as a random weapon name or mod
	int CreateRandomNumber(void);///< creates a random number to be used for makeing random weapon attributes
};

#endif