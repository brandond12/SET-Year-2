/*
* FILE : Inventory.cpp
* PROJECT : DS/OOP
* PROGRAMMER : Brandon Davies
* FIRST VERSION : 2015-00-08
* DESCRIPTION : This file includes all of the methods for the Inventory Class
*/

#include "Inventory.h"
#include <new>

/**
* \breif Class constructor 
* \details <b>Details</b>
*
* \param gunName - <b>string</b> - Name of waepon to be created
*
* \return  Nothing is returned
* \see ~Inventory()
*/
Inventory::Inventory(){

}

/**
* \breif Class destructor
* \details <b>Details</b>
*
* \param Nothing - No parameters
*
* \return  Nothing is returned
* \see Inventory()
*/
Inventory::~Inventory(){
	
}


/**
* \breif creates a weapon and adds it to the list of weapons
*
* \details <b>Details</b>
*
* \param gunName - <b>string</b> - Name of waepon to be created
* \param avalibleModifications - <b>vector<string></b> - vector of allowable modification to the weapon
* \param extraUnLockReqs - <b>vector<string></b> - vector of all requiered requierments to unlock the weapon
* \param rateOfFire - <b>int</b> - the rate of fire of the weapon
* \param totalAmmo - <b>int</b> - the total ammo the can be carried for the weapon
* \param magazineAmmo - <b>int</b> - the ammout of ammo held in one clip of the weapon
* \param damage - <b>int</b> - the amount of damage created by the weapon
* \param accuracy - <b>int</b> - the accuracy of the weapon
* \param stability - <b>int</b> - the firing stability of fire of the weapon
* \param concealment - <b>int</b> - the concealment of the weapon
* \param threat - <b>int</b> - the theat level of the weapon
* \param levelUnLock - <b>int</b> - the requient user level to unlock the weapon
* \param cost - <b>int</b> - the unlock cost of the weapon
*
* \return  Nothing is returned
*/
void Inventory::AddItem(string gunName, vector<string> avalibleModifications, vector<string> extraUnLockReqs, int rateOfFire, int totalAmmo, int magazineAmmo, int damage, int accuracy, int stability, int concealment, int threat, int levelUnLock, int cost){
	vector<Weapon*>::iterator iter;
	Weapon* pWeapon = NULL;
	int weaponNumber = 0;
	try{
		pWeapon = new Weapon(gunName, avalibleModifications, extraUnLockReqs, rateOfFire, totalAmmo, magazineAmmo, damage, accuracy, stability, concealment, threat, levelUnLock, cost);
	}
	catch (std::bad_alloc&){
		throw "Out of Memory";
	}

	//fine alphabetic location
	for (iter = weapons.begin(); iter != weapons.end(); iter++){
		if (stricmp((*iter)->GetGunName().c_str(), pWeapon->GetGunName().c_str()) > 0){
			break;
		}
	}
	//add to vector
	weapons.insert(iter, pWeapon);
}


/**
* \breif Class meathod to delete a weapon from the list of weapons. Will throw exception is weapon does not exist
* \details <b>Details</b>
*
* \param gunName - <b>string</b> - name of weapon to be removed from list
*
* \return  Nothing
*/
void Inventory::DeleteItem(string gunName){
	vector<Weapon*>::const_iterator iter = weapons.begin();
	bool foundIt = false;

	while (iter != weapons.end()){
		if ((*iter)->GetGunName() == gunName){
			delete *iter;
			weapons.erase(iter);
			foundIt = true;
			break;
		}
		iter++;
	}

	if(foundIt == false){
		throw "Gun Not Found";
	}
}


/**
* \breif Class meathod to delete all weapons from the database
* \details <b>Details</b>
*
* \param Nothing
*
* \return  Nothing
*/
void Inventory::DeleteDatabase(void){
	int weaponNumber = 0;

	for (; weapons.begin() != weapons.end();){
		delete weapons.at(weaponNumber);
		weapons.erase(weapons.begin());
	}
}


/**
* \breif Class meathod to display all weapons in list to the screen. It lists 3 weapons at a time
* \details <b>Details</b>
*
* \param Nothing
*
* \return  Nothing
*/
void Inventory::DisplayDatabase(void){
	string placeHolder;
	int displayCounter = 0;
	for (vector<Weapon*>::const_iterator iter = weapons.begin(); iter != weapons.end(); iter++){
		printf("%s\nRate of Fire:\t%d\nTotal Ammo: \t%d\nMagazine Ammo: \t%d\nDamage: \t%d\nAccuracy: \t%d\nStability: \t%d\nConcealment: \t%d\nThreat: \t%d\nLevel Un-Lock: \t%d\nCost: \t\t$%d\n", 
			(*iter)->GetGunName().c_str(), (*iter)->GetRateOfFire(), (*iter)->GetTotalAmmo(), (*iter)->GetMagazineAmmo(), (*iter)->GetDamage(), (*iter)->GetAccuracy(), (*iter)->GetStability(), (*iter)->GetConcealment(), (*iter)->GetThreat(), (*iter)->GetLevelUnLock(), (*iter)->GetCost());
		
		printf("Modifications:\t\t");
		{
			vector<string> modifications = (*iter)->GetAvalibleModifications();
			vector<string>::const_iterator iter2 = modifications.begin();
			while (iter2 != modifications.end()){
				placeHolder = *iter2;
				printf("\n\t%s", placeHolder.c_str());
				iter2++;
			}
		}
		
		printf("\nExtra Unlock Requirments:");
			{
			vector<string> unlockReqs = (*iter)->GetextraUnLockReqs();
			vector<string>::const_iterator iter2 = unlockReqs.begin();
			while (iter2 != unlockReqs.end()){
				placeHolder = *iter2;
				printf("\n\t%s", placeHolder.c_str());
				iter2++;
			}
		}
		printf("\n\n");
		if (displayCounter > 3 && iter != weapons.end()){
			printf("Press any key to show next weapons\n");
			cin.clear();
			fflush(stdin);
			getchar();
			displayCounter = 0;
		}
		else{
			displayCounter++;
		}
	}
	printf("Press any key to go back to main menu\n");
	cin.clear();
	fflush(stdin);
	getchar();
}

/**
* \breif Class meathod to load all data from a file, if file is not found the program exits quietly
* \details <b>Details</b>
*
* \param Nothing
*
* \return  Nothing
*/
void Inventory::LoadFromFile(void){
	ifstream	infile;
	Weapon *temp = NULL;
	//Open file
	infile.open("BrandonDav.txt", ios::in);
	if (!infile.fail()){
		while (!infile.eof()){
			//Get input
			temp = new Weapon("");
			infile >> *temp;
			if (!infile.eof()){
				AddItem(temp->GetGunName(), temp->GetAvalibleModifications(), temp->GetextraUnLockReqs(), temp->GetRateOfFire(), temp->GetTotalAmmo(), temp->GetMagazineAmmo(), temp->GetDamage(), temp->GetAccuracy(), temp->GetStability(), temp->GetConcealment(), temp->GetThreat(), temp->GetLevelUnLock(), temp->GetCost());
			}
			delete(temp);
		}
		infile.close();
	}
}

/**
* \breif Class meathod to save all data to a file, with throw exception if file can not be opened
* \details <b>Details</b>
*
* \param Nothing
*
* \return  Nothing
*/
void Inventory::UpdateFile(void){
	ofstream	outfile;
	Weapon temp("Test");
	vector<Weapon*>::const_iterator iter = weapons.begin();
	//Open file
	outfile.open("BrandonDav.txt", ios::out);
	if (outfile.fail()){
		throw "Could not open File";
	}
	while (iter != weapons.end()){
		outfile << **iter;
		iter++;
	}
	outfile.close();
}