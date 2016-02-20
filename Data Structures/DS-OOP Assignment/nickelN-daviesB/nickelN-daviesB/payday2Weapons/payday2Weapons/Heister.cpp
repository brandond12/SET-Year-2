/*
* FILE			: Heister.cpp
* PROJECT		: PROG1370/PROG1385 - Data Management/Object-oriented Programming  - Project - Winter 2015
* PROGRAMMER	: Nathan Nickel/ Brandon Davies
* FIRST VERSION : 2015-04-11
* DESCRIPTION	: view layer class that will allow the user to interact with the rest of the program aka iteracting with payday 2 weapons
*/


#include "Heister.h"
#include "Inventory.h"


/**
* \breif Class constructor
* \details <b>Details</b>
*
* \param Nothing - No parameters
*
* \return  Nothing is returned
* \see ~Heister()
*/
Heister::Heister()
{
	weapon = new Inventory();
}

/**
* \breif This will be the main menu of the program and will be the only way for the user to interact with the program. 
* \details <b>Details</b>
*
* \param Nothing
*
* \return  Nothing
*/
void Heister::MainMenu(void)
{
	int input = kNO_INPUT;
	string stringInput;
	srand((int)time(NULL));//used to randomize rand by telling it where to start
	
	while (input != kQUIT)//loop until user wants to quit
	{
		cout << "MENU" << endl << "____" << endl;
		cout << "Please enter the number for the corisponding option you would like to select:" << endl;
		cout << " 1: Add a Weapon" << endl;
		cout << " 2: Delete a Weapon" << endl;
		cout << " 3: Delete all Weapons" << endl;
		cout << " 4: Display all Weapons" << endl;
		cout << " 5: Generate Random Weapons" << endl;
		cout << " 0: Save and Quit" << endl;

		cin.clear();
		fflush(stdin);
		cin >> input;
		system("cls");
		if (input == kADD_ITEM)
		{
			AddGun();
		}
		else if (input == kDELETE_ITEM)
		{
			string gunName;

			cin.clear();
			fflush(stdin);

			cout << "Please enter the name of the gun you would like to delete" << endl;
			getline(cin, gunName);
			system("cls");
			try
			{
				weapon->DeleteItem(gunName);
				cout << "Weapon Deleted" << endl;
			}
			catch (char* e)
			{
				printf("Error: %s\n", e); //caught an error
			}
		}
		else if (input == kDISPLAY_LIST)
		{
			weapon->DisplayDatabase();
			system("cls");
		}
		else if (input == kDELETE_LIST)
		{
			cout << "Are you sure you would like to delete the Entire database? y/n" << endl;
			cin >> stringInput;
			if (stricmp(stringInput.c_str(), "y") == 0 || stricmp(stringInput.c_str(), "yes") == 0){
				weapon->DeleteDatabase();
			}
			system("cls");
		}
		else if (input == kRANDOM)
		{
			int num = 0;

			cout << "Please enter how many random inputs you would like created" << endl;
			cin >> num;
			for (int i = 0; i < num; i++)
			{
				string gunName = CreateRandomName();
				vector<string> avalibleModifications;
				vector<string> extraUnLockReqs;
				int rateOfFire = CreateRandomNumber();
				int totalAmmo = CreateRandomNumber();
				int magazineAmmo = CreateRandomNumber();
				int damage = CreateRandomNumber();
				int accuracy = CreateRandomNumber();
				int stability = CreateRandomNumber();
				int concealment = CreateRandomNumber();
				int threat = CreateRandomNumber();
				int levelUnLock = CreateRandomNumber();
				int cost = CreateRandomNumber();

				int randomNumber;
				randomNumber = (rand() % 10) + 1;//generates a random number between 10 and 100 not including 100
				int numOfModsOrReq = randomNumber;
				for (int i = 0; i < numOfModsOrReq; i++)
				{
					extraUnLockReqs.push_back(CreateRandomName());
					avalibleModifications.push_back(CreateRandomName());
				}
				try
				{
					weapon->AddItem(gunName, avalibleModifications, extraUnLockReqs, rateOfFire, totalAmmo, magazineAmmo, damage, accuracy, stability, concealment, threat, levelUnLock, cost);
				}
				catch (char* e)
				{
					printf("Error: %s\n", e); //caught an error
					if (strcmp(e, "Invalid Weapon Name") == 0)
					{
						cout << "The Gun name can only use: a-z, A-Z, 0-9, \".\", \"-\", or a space" << endl;
					}
				}
				extraUnLockReqs.clear();
				avalibleModifications.clear();
			}
			system("cls");
		}
		else
		{
			cout << "Invalid input" << endl << endl;
		}
	}
}

/**
* \breif This method will create a random input to be put into container layer
* \details <b>Details</b>
*
* \param Nothing
*
* \return  randomWord - <b>string</b> - a random gun name 15-20 characters in length and all letters
*/
string Heister::CreateRandomName(void)
{
	string randomWord;
	int randomLength = 0;
	randomLength = (rand() % 15)+5;//generates a random number between 5 and 20 not including 20
	for (int i = 0; i < randomLength; i++)
	{
		randomWord += (rand() % 26)+97;//generates a random number between 97 and 123 not including 123
	}
	return randomWord;

}


/**
* \breif this method will create a random input to be put into container layer
* \details <b>Details</b>
*
* \param Noting
*
* \return  randomNumber - <b>string</b> - generated random number between 10 and 100 not including 100
*/
int Heister::CreateRandomNumber(void)
{
	int randomNumber;
	randomNumber = (rand() % 90) + 10;//generates a random number between 10 and 100 not including 100
	return randomNumber;
}


/**
* \breif this method will allow the user to create a new gun
* \details <b>Details</b>
*
* \param Nothing
*
* \return  Nothing
*/
void Heister::AddGun(void)
{
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

	int myNumber = 0;
	string input = "";

	cin.clear();
	fflush(stdin);

	cout << "Please enter the guns name" << endl;
	getline(cin, gunName);

	cout << "Please enter up to 30 avalible modifactions. Enter \"done\" when finished" << endl;
	while (mod != "done")
	{
		getline(cin, mod);
		if (mod != "done")
		{
			avalibleModifications.push_back(mod);
		}
	} 


	cout << "Please enter up to 30 unlock requirements. Enter \"done\" when finished" << endl;
	while (unlockReq != "done")
	{
		getline(cin, unlockReq);
		if (unlockReq != "done")
		{
			extraUnLockReqs.push_back(unlockReq);
		}
	}


	cout << "Please enter the rate of fire" << endl;
	while (true)
	{
		getline(cin, input);

		// This code converts from string to number safely.
		stringstream myStream(input);
		if (myStream >> myNumber)
		{
			rateOfFire = myNumber;
			break;
		}
		cout << "Invalid number, please try again" << endl;
	}

	cout << "Please enter the total ammo" << endl;
	while (true)
	{
		getline(cin, input);

		// This code converts from string to number safely.
		stringstream myStream(input);
		if (myStream >> myNumber)
		{
			totalAmmo = myNumber;
			break;
		}
		cout << "Invalid number, please try again" << endl;
	}

	cout << "Please enter the magazine capacity" << endl;
	while (true)
	{
		getline(cin, input);

		// This code converts from string to number safely.
		stringstream myStream(input);
		if (myStream >> myNumber)
		{
			magazineAmmo = myNumber;
			break;
		}
		cout << "Invalid number, please try again" << endl;
	}

	cout << "Please enter the damage" << endl;
	while (true)
	{
		getline(cin, input);

		// This code converts from string to number safely.
		stringstream myStream(input);
		if (myStream >> myNumber)
		{
			damage = myNumber;
			break;
		}
		cout << "Invalid number, please try again" << endl;
	}

	cout << "Please enter the accuracy" << endl;
	while (true)
	{
		getline(cin, input);

		// This code converts from string to number safely.
		stringstream myStream(input);
		if (myStream >> myNumber)
		{
			accuracy = myNumber;
			break;
		}
		cout << "Invalid number, please try again" << endl;
	}

	cout << "Please enter the stability" << endl;
	while (true)
	{
		getline(cin, input);

		// This code converts from string to number safely.
		stringstream myStream(input);
		if (myStream >> myNumber)
		{
			stability = myNumber;
			break;
		}
		cout << "Invalid number, please try again" << endl;
	}

	cout << "Please enter the concealment" << endl;
	while (true)
	{
		getline(cin, input);

		// This code converts from string to number safely.
		stringstream myStream(input);
		if (myStream >> myNumber)
		{
			concealment = myNumber;
			break;
		}
		cout << "Invalid number, please try again" << endl;
	}

	cout << "Please enter the threat" << endl;
	while (true)
	{
		getline(cin, input);

		// This code converts from string to number safely.
		stringstream myStream(input);
		if (myStream >> myNumber)
		{
			threat = myNumber;
			break;
		}
		cout << "Invalid number, please try again" << endl;
	}

	cout << "Please enter the level required to unlock" << endl;
	while (true)
	{
		getline(cin, input);

		// This code converts from string to number safely.
		stringstream myStream(input);
		if (myStream >> myNumber)
		{
			levelUnLock = myNumber;
			break;
		}
		cout << "Invalid number, please try again" << endl;
	}

	cout << "Please enter the cost" << endl;
	while (true)
	{
		getline(cin, input);

		// This code converts from string to number safely.
		stringstream myStream(input);
		if (myStream >> myNumber)
		{
			cost = myNumber;
			break;
		}
		cout << "Invalid number, please try again" << endl;
	}
	try
	{
		weapon->AddItem(gunName, avalibleModifications, extraUnLockReqs, rateOfFire, totalAmmo, magazineAmmo, damage, accuracy, stability, concealment, threat, levelUnLock, cost);	
	}
	catch (char* e)
	{
		printf("Error: %s\n", e); //caught an error
		if (strcmp(e, "Invalid Weapon Name") == 0)
		{
			cout << "The Gun name can only use: a-z, A-Z, 0-9, \".\", \"-\", or a space" << endl;
		}
	}
}

/**
* \breif this method simply calls a function from the container class to open the file/database
* \details <b>Details</b>
*
* \param Nothing
*
* \return  Nothing
*/
void Heister::LoadFromFile(void)
{
	weapon->LoadFromFile();
}

/**
* \breif this method simply calls a function from the container class to update the file
* \details <b>Details</b>
*
* \param Nothing
*
* \return  Nothing
*/
void Heister::UpdateFile(void)
{
	weapon->UpdateFile();
}

/**
* \breif Class deconstructor
* \details <b>Details</b>
*
* \param Nothing - No parameters
*
* \return  Nothing is returned
* \see Heister()
*/
Heister::~Heister()
{
	delete weapon;
}