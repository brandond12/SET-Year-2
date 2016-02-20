/*
* FILE			: project.cpp
* PROJECT		: PROG1370/PROG1385 - Data Management/Object-oriented Programming  - Project - Winter 2015
* PROGRAMMER	: Nathan Nickel/ Brandon Davies
* FIRST VERSION : 2015-04-11
* DESCRIPTION	: create an object for the Heister and call its menu
*/
/* -- this is a FILEHEADER COMMENT --
NAME	:	project
PURPOSE :	this file simply calls a the menu function in the Heister class which will get input from the user for them to choose what they want to do and 
then depending on the users choice the program will add a gun manually with user input, create a specified number of random weapons, 
display the database, delete the entire database, or delete one weapon from the database
*/

#include "Heister.h"

int main(void)
{
	Heister* UI = new Heister();
	UI->LoadFromFile();
	UI->MainMenu();//call main menu
	UI->UpdateFile();
	delete UI;

	return 0;
}
