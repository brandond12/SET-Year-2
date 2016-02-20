#include "Weapon.h"
#include <string>

/*Overloaded Opreators*/

ofstream& operator<< (ofstream& output, Weapon& obj)
{
	int i = 0;
	output << "Name: " << obj.GetGunName() << endl;
	output << "Modifications: ";
	for (vector<string>::iterator iter = obj.avalibleModifications.begin(); iter != obj.avalibleModifications.end(); iter++){
		output << obj.GetAvalibleModifications().at(i) << " , ";
		i++;
	}
	output << "\nRateOfFire: " << obj.GetRateOfFire() << endl;
	output << "TotalAmmo: " << obj.GetTotalAmmo() << endl;
	output << "MagazineAmmo: " << obj.GetMagazineAmmo() << endl;
	output << "Damage: " << obj.GetDamage() << endl;
	output << "Accuracy: " << obj.GetAccuracy() << endl;
	output << "Stability: " << obj.GetStability() << endl;
	output << "Concealment: " << obj.GetConcealment() << endl;
	output << "Threat: " << obj.GetThreat() << endl;
	output << "LevelUnLock: " << obj.GetLevelUnLock() << endl;
	output << "Cost: " << obj.GetCost() << endl;
	output << "Modifications: ";
	i = 0;
	for (vector<string>::iterator iter = obj.extraUnLockReqs.begin(); iter != obj.extraUnLockReqs.end(); iter++){
		output << obj.GetextraUnLockReqs().at(i) << " , ";
		i++;
	}
	output << endl << "EndOfWeapon";
	output << endl << endl;
	return output;
}

ifstream& operator>> (ifstream& input, Weapon& obj)
{
	string format;
	string stringData;
	input >> format;
	if (!input.eof()){
		input.seekg(1, std::ios::cur);
		getline(input, obj.gunName);

		input >> format >> stringData;
		while (stringData != "RateOfFire:"){
			obj.AddAvalibleModification(stringData);
			input >> format >> stringData;
			if (input.eof()){
				throw "Error: Database Corrupt";
			}
		}
		input >> obj.rateOfFire;
		input >> format >> obj.totalAmmo;
		input >> format >> obj.magazineAmmo;
		input >> format >> obj.damage;
		input >> format >> obj.accuracy;
		input >> format >> obj.stability;
		input >> format >> obj.concealment;
		input >> format >> obj.threat;
		input >> format >> obj.levelUnLock;
		input >> format >> obj.cost;

		input >> format >> stringData;
		while (stringData != "EndOfWeapon"){
			obj.AddExtraUnLockReqs(stringData);
			input >> format >> stringData;
			if (input.eof()){
				throw "Error: Database Corrupt";
			}
		}
	}
	return input;
}


/************************************/
/****Constructors and destructors****/
/************************************/

/**
* \breif Class constructor initilizes variables
* \details <b>Details</b>
*
* \param gunName - <b>string</b> - Name of waepon to be created
*
* \return  Nothing is returned
* \see ~Weapon()
*/
Weapon::Weapon(string gunName){
	int modNumber = 0;
	int charNumber = 0;
	int numValidMods = 0;
	bool correct = true;

	//check valid name
	if ((gunName.c_str()[charNumber] == ' ')){
		throw "Invalid Weapon Name";
	}
	while (gunName.c_str()[charNumber] != '\0'){
		if ((gunName.c_str()[charNumber] < '-' || gunName.c_str()[charNumber] > '.') &&
			(gunName.c_str()[charNumber] < '0' || gunName.c_str()[charNumber] > '9') &&
			(gunName.c_str()[charNumber] < 'A' || gunName.c_str()[charNumber] > 'Z') &&
			(gunName.c_str()[charNumber] < 'a' || gunName.c_str()[charNumber] > 'z') &&
			gunName.c_str()[charNumber] != ' '){
			correct = false;
			break;
		}
		charNumber++;
	}
	if (correct == true){
		this->gunName = gunName;
	}
	else{
		throw "Invalid Weapon Name";
	}
	rateOfFire = 1;
	totalAmmo = 1;
	magazineAmmo = 1;
	damage = 1;
	accuracy = 1;
	stability = 1;
	concealment = 1;
	threat = 1;
	levelUnLock = 0;
	cost = 1000;
}

/**
* \breif Class constructor initilizes variables
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
* \see ~Weapon()
*/
Weapon::Weapon(string gunName, vector<string> avalibleModifications, vector<string> extraUnLockReqs, int rateOfFire = 1, int totalAmmo = 1, int magazineAmmo = 1, int damage = 1,
	int accuracy = 1, int stability = 1, int concealment = 1, int threat = 1, int levelUnLock = 0, int cost = 1){
	vector<string> modsToAdd;
	vector<string> reqsToAdd;
	int modNumber = 0;
	int charNumber = 0;
	int numValidMods = 0;
	bool correct = true;

	//check valid name
	if ((gunName.c_str()[charNumber] == ' ')){
		throw "Invalid Weapon Name";
	}
	while (gunName.c_str()[charNumber] != '\0'){
		if ((gunName.c_str()[charNumber] < '-' || gunName.c_str()[charNumber] > '.') &&
			(gunName.c_str()[charNumber] < '0' || gunName.c_str()[charNumber] > '9') &&
			(gunName.c_str()[charNumber] < 'A' || gunName.c_str()[charNumber] > 'Z') &&
			(gunName.c_str()[charNumber] < 'a' || gunName.c_str()[charNumber] > 'z') &&
			gunName.c_str()[charNumber] != ' '){
			correct = false;
			break;
		}
		charNumber++;
	}
	if (correct == true){
		this->gunName = gunName;
	}
	else{
		throw "Invalid Weapon Name";
	}


	//check all mods valid
	for (vector<string>::iterator iter = avalibleModifications.begin(); iter != avalibleModifications.end(); iter++){
		correct = true;
		charNumber = 0;
		if ((iter->c_str()[charNumber] == ' ')){
			correct = false;
		}
		while (iter->c_str()[charNumber] != '\0'){
			if ((gunName.c_str()[charNumber] < '-' || gunName.c_str()[charNumber] > '.') &&
				(iter->c_str()[charNumber] < '0' || iter->c_str()[charNumber] > '9') &&
				(iter->c_str()[charNumber] < 'A' || iter->c_str()[charNumber] > 'Z') &&
				(iter->c_str()[charNumber] < 'a' || iter->c_str()[charNumber] > 'z') &&
				iter->c_str()[charNumber] != ' '){
				correct = false;
				break;
			}
			charNumber++;
		}
		if (correct == true){
			modsToAdd.push_back(*iter);
		}
		if (modsToAdd.size() >= kMaxMods){
			break;
		}
	}
	this->avalibleModifications = modsToAdd;

	modNumber = 0;
	//check all unlock reqs valid
	for (vector<string>::iterator iter = extraUnLockReqs.begin(); iter != extraUnLockReqs.end(); iter++){
		correct = true;
		charNumber = 0;
		if ((iter->c_str()[charNumber] == ' ')){
			correct = false;
		}
		while (iter->c_str()[charNumber] != '\0'){
		if ((gunName.c_str()[charNumber] < '-' || gunName.c_str()[charNumber] > '.') &&
				(iter->c_str()[charNumber] < '0' || iter->c_str()[charNumber] > '9') &&
				(iter->c_str()[charNumber] < 'A' || iter->c_str()[charNumber] > 'Z') &&
				(iter->c_str()[charNumber] < 'a' || iter->c_str()[charNumber] > 'z') &&
				iter->c_str()[charNumber] != ' '){
				correct = false;
				break;
			}
			charNumber++;
		}
		if (correct == true){
			reqsToAdd.push_back(*iter);
		}
		if (reqsToAdd.size() >= kMaxReqs){
			break;
		}
	}
	this->extraUnLockReqs = reqsToAdd;

	if (rateOfFire >= 0 && rateOfFire <= kMaxRateOfFire){
		this->rateOfFire = rateOfFire;
	}
	else{
		this->rateOfFire = 1;
	}

	if (totalAmmo >= 0 && totalAmmo <= kMaxTotalAmmo){
		this->totalAmmo = totalAmmo;
	}
	else{
		this->totalAmmo = 1;
	}

	if (magazineAmmo >= 0 && magazineAmmo <= kMaxMagazineAmmo){
		this->magazineAmmo = magazineAmmo;
	}
	else{
		this->magazineAmmo = 1;
	}

	if (damage >= 0 && damage <= kMaxDamage){
		this->damage = damage;
	}
	else{
		this->damage = 1;
	}

	if (accuracy >= 0 && accuracy <= kMaxAccuracy){
		this->accuracy = accuracy;
	}
	else{
		this->accuracy = 1;
	}

	if (stability >= 0 && stability <= kMaxStability){
		this->stability = stability;
	}
	else{
		this->stability = 1;
	}

	if (concealment >= 0 && concealment <= kMaxConcealment){
		this->concealment = concealment;
	}
	else{
		this->concealment = 1;
	}

	if (threat >= 0 && threat <= kMaxThreat){
		this->threat = threat;
	}
	else{
		this->threat = 1;
	}

	if (levelUnLock >= 0 && levelUnLock <= kMaxLevelUnLock){
		this->levelUnLock = levelUnLock;
	}
	else{
		this->levelUnLock = 1;
	}

	if (cost >= 0 && cost <= kMaxCost){
		this->cost = cost;
	}
	else{
		this->cost = 1;
	}
}

/**
* \breif Class destructor destroyes the object
* \details <b>Details</b>
*
* \param Nothing - No parameters
*
* \return  Nothing is returned
* \see Weapon()
*/
Weapon::~Weapon(){

}

/*Public Methods*/
/**
* \breif Class meathod to add a avalible modification to a weapon
* \details <b>Details</b>
*
* \param modification - <b>string</b> - the modification to be added
*
* \return  correct -  <b>bool</b> - if the modification was added
*/
bool Weapon::AddAvalibleModification(string modification){
	int modNumber = 0;
	int charNumber = 0;
	bool correct = true;

	if (avalibleModifications.size() >= kMaxMods){
		correct = false;
	}

	if ((modification.c_str()[charNumber] == ' ')){
		correct = false;
	}
	while (modification.c_str()[charNumber] != '\0'){
		if ((modification.c_str()[charNumber] < '-' || modification.c_str()[charNumber] > '.') &&
			(modification.c_str()[charNumber] < '0' || modification.c_str()[charNumber] > '9') &&
			(modification.c_str()[charNumber] < 'A' || modification.c_str()[charNumber] > 'Z') &&
			(modification.c_str()[charNumber] < 'a' || modification.c_str()[charNumber] > 'z') &&
			modification.c_str()[charNumber] != ' '){
			correct = false;
			break;
		}
		charNumber++;
	}
	if (correct == true){
		avalibleModifications.push_back(modification);
	}
	return correct;
}

/**
* \breif Class meathod to add a unlock requierment to a weapon
* \details <b>Details</b>
*
* \param UnLockReq - <b>string</b> - the unlock requierment to be added
*
* \return  correct -  <b>bool</b> - if the unlock requierment was added
*/
bool Weapon::AddExtraUnLockReqs(string UnLockReq){
	int unLockNumber = 0;
	int charNumber = 0;
	bool correct = true;

	if (extraUnLockReqs.size() >= kMaxReqs){
		correct = false;
	}
	if ((UnLockReq.c_str()[charNumber] == ' ')){
		correct = false;
	}
	while (UnLockReq.c_str()[charNumber] != '\0'){
		if ((UnLockReq.c_str()[charNumber] < '-' || UnLockReq.c_str()[charNumber] > '.') &&
			(UnLockReq.c_str()[charNumber] < '0' || UnLockReq.c_str()[charNumber] > '9') &&
			(UnLockReq.c_str()[charNumber] < 'A' || UnLockReq.c_str()[charNumber] > 'Z') &&
			(UnLockReq.c_str()[charNumber] < 'a' || UnLockReq.c_str()[charNumber] > 'z') &&
			UnLockReq.c_str()[charNumber] != ' '){
			correct = false;
			break;
		}
		charNumber++;
	}
	if (correct == true){
		extraUnLockReqs.push_back(UnLockReq);
	}
	return correct;
}

/**
* \breif Class meathod to delete a avalible modification from a weapon
* \details <b>Details</b>
*
* \param modification - <b>string</b> - the modification to be deleted
*
* \return  returnValue -  <b>bool</b> - if the modification was deleted
*/
bool Weapon::DeleteAvalibleModification(string modification){
	int modNumber = 0;
	bool returnValue = false;
	for (vector<string>::iterator iter = avalibleModifications.begin(); iter != avalibleModifications.end(); iter++){
		if (*iter == modification){
			avalibleModifications.erase(iter);
			returnValue = true;
		}
	}
	return returnValue;
}

/**
* \breif Class meathod to delete a unlock requierment from a weapon
* \details <b>Details</b>
*
* \param UnLockReq - <b>string</b> - the unlock requierment to be deleted
*
* \return  returnValue -  <b>bool</b> - if the unlock requierment was deleted
*/
bool Weapon::DeleteExtraUnLockReqs(string UnLockReq){
	int extraRequNum = 0;
	bool returnValue = false;
	for (vector<string>::iterator iter = extraUnLockReqs.begin(); iter != extraUnLockReqs.end(); iter++){
		if (*iter == UnLockReq){
			avalibleModifications.erase(iter);
			returnValue = true;
		}
	}
	return returnValue;
}

/*Getters*/
/**
* \breif Class meathod to return the weapon name
* \details <b>Details</b>
*
* \param No Parameter
*
* \return  this->gunName -  <b>const string</b> - the objects weapons name
*/
const string Weapon::GetGunName(void){
	return this->gunName;
}
/**
* \breif Class meathod to return the weapon avalible modifications
* \details <b>Details</b>
*
* \param No Parameter
*
* \return  this->avalibleModifications -  <b>const vector<string></b> - the objects weapons avalible modifications
*/
const vector<string> Weapon::GetAvalibleModifications(void){
	return this->avalibleModifications;
}
/**
* \breif Class meathod to return the weapon Rate of Fire
* \details <b>Details</b>
*
* \param No Parameter
*
* \return  this->rateOfFire -  <b>int</b> - the objects weapons Rate of Fire
*/
int Weapon::GetRateOfFire(void){
	return this->rateOfFire;
}
/**
* \breif Class meathod to return the weapon Total Ammo
* \details <b>Details</b>
*
* \param No Parameter
*
* \return  this->totalAmmo -  <b>int</b> - the objects weapons Total Ammo
*/
int Weapon::GetTotalAmmo(void){
	return this->totalAmmo;
}
/**
* \breif Class meathod to return the weapon Magazene Ammo
* \details <b>Details</b>
*
* \param No Parameter
*
* \return  this->magazineAmmo -  <b>int</b> - the objects weapons Magazine Ammo
*/
int Weapon::GetMagazineAmmo(void){
	return this->magazineAmmo;
}
/**
* \breif Class meathod to return the weapon Damage
* \details <b>Details</b>
*
* \param No Parameter
*
* \return  this->damage -  <b>int</b> - the objects weapons Damage
*/
int Weapon::GetDamage(void){
	return this->damage;
}
/**
* \breif Class meathod to return the weapon Accuracy
* \details <b>Details</b>
*
* \param No Parameter
*
* \return  this->accuracy -  <b>int</b> - the objects weapons Accuracy
*/
int Weapon::GetAccuracy(void){
	return this->accuracy;
}
/**
* \breif Class meathod to return the weapon Stability
* \details <b>Details</b>
*
* \param No Parameter
*
* \return  this->stability -  <b>int</b> - the objects weapons Stability
*/
int Weapon::GetStability(void){
	return this->stability;
}
/**
* \breif Class meathod to return the weapon Concealment
* \details <b>Details</b>
*
* \param No Parameter
*
* \return  this->concealment -  <b>int</b> - the objects weapons Concealment
*/
int Weapon::GetConcealment(void){
	return this->concealment;
}
/**
* \breif Class meathod to return the weapon Threat
* \details <b>Details</b>
*
* \param No Parameter
*
* \return  this->threat -  <b>int</b> - the objects weapons Threat
*/
int Weapon::GetThreat(void){
	return this->threat;
}
/**
* \breif Class meathod to return the level the waepon is unlocked at
* \details <b>Details</b>
*
* \param No Parameter
*
* \return  this->levelUnLock -  <b>int</b> - the objects the level the waepon is unlocked at
*/
int Weapon::GetLevelUnLock(void){
	return this->levelUnLock;
}
/**
* \breif Class meathod to return the weapon unlock cost
* \details <b>Details</b>
*
* \param No Parameter
*
* \return  this->cost -  <b>int</b> - the objects weapons unlock cost
*/
int Weapon::GetCost(void){
	return this->cost;
}
/**
* \breif Class meathod to return the weapon
* \details <b>Details</b>
*
* \param No Parameter
*
* \return  this->extraUnLockReqs -  <b>const vector<string></b> - the objects weapons
*/
const vector<string> Weapon::GetextraUnLockReqs(void){
	return this->extraUnLockReqs;
}

/*Setters*/
/**
* \breif Class meathod to set the weapons
* \details <b>Details</b>
*
* \param gunName - <b>string</b> - the value the weapon name will be set to
*
* \return  returnValue -  <b>bool</b> - if the assignment succeeded
*/
bool Weapon::SetGunName(string gunName){
	bool returnValue = true;
	int charNumber = 0;
	//check valid name
	if ((gunName.c_str()[charNumber] == ' ')){
		returnValue = false;
	}
	while (gunName.c_str()[charNumber] != '\0'){
		if ((gunName.c_str()[charNumber] < '-' || gunName.c_str()[charNumber] > '.') &&
			(gunName.c_str()[charNumber] < '0' || gunName.c_str()[charNumber] > '9') &&
			(gunName.c_str()[charNumber] < 'A' || gunName.c_str()[charNumber] > 'Z') &&
			(gunName.c_str()[charNumber] < 'a' || gunName.c_str()[charNumber] > 'z') &&
			gunName.c_str()[charNumber] != ' '){
			returnValue = false;
			break;
		}
		charNumber++;
	}
	if (returnValue == true){
		this->gunName = gunName;
	}
	return returnValue;
}

/**
* \breif Class meathod to set the weapons avalible modifications
* \details <b>Details</b>
*
* \param avalibleModifications - <b>vector<string></b> - the value the avalible weapon modifications will be set to
*
* \return  modNumber -  <b>int</b> - number  of modifications set
*/
int Weapon::SetAvalibleModifications(vector<string> avalibleModifications){
	bool correct = true;
	int modNumber = 0;
	int charNumber = 0;

	this->avalibleModifications.clear();

	for (vector<string>::iterator iter = avalibleModifications.begin(); iter != avalibleModifications.end(); iter++){
		correct = true;
		charNumber = 0;

		if ((iter->c_str()[charNumber] == ' ')){
			correct = false;
		}
		while (iter->c_str()[charNumber] != '\0'){
			if ((iter->c_str()[charNumber] < '-' || iter->c_str()[charNumber] > '.') &&
				(iter->c_str()[charNumber] < '0' || iter->c_str()[charNumber] > '9') &&
				(iter->c_str()[charNumber] < 'A' || iter->c_str()[charNumber] > 'Z') &&
				(iter->c_str()[charNumber] < 'a' || iter->c_str()[charNumber] > 'z') &&
				iter->c_str()[charNumber] != ' '){
				correct = false;
				break;
			}
			charNumber++;
		}
		if (correct == true){
			this->avalibleModifications.push_back(iter->c_str());
			modNumber++;
		}
		if (avalibleModifications.size() >= kMaxMods){
			break;
		}
	}
	return modNumber;
}

/**
* \breif Class meathod to set the weapons rate of fire
* \details <b>Details</b>
*
* \param rateOfFire - <b>int</b> - the value the weapon rate of fire will be set to
*
* \return  returnValue -  <b>bool</b> - if the assignment succeeded
*/
bool Weapon::SetRateOfFire(int rateOfFire){
	bool returnValue = false;

	if (rateOfFire >= 0 && rateOfFire <= kMaxRateOfFire){
		returnValue = true;
		this->rateOfFire = rateOfFire;
	}
	return returnValue;
}

/**
* \breif Class meathod to set the weapons total ammo
* \details <b>Details</b>
*
* \param totalAmmo - <b>int</b> - the value the weapon total ammo will be set to
*
* \return  returnValue -  <b>bool</b> - if the assignment succeeded
*/
bool Weapon::SetTotalAmmo(int totalAmmo){
	bool returnValue = false;

	if (totalAmmo >= 0 && totalAmmo <= kMaxTotalAmmo){
		returnValue = true;
		this->totalAmmo = totalAmmo;
	}
	return returnValue;
}

/**
* \breif Class meathod to set the weapons magazine ammo
* \details <b>Details</b>
*
* \param magazineAmmo - <b>int</b> - the value the weapon magazine ammo will be set to
*
* \return  returnValue -  <b>bool</b> - if the assignment succeeded
*/
bool Weapon::SetMagazineAmmo(int magazineAmmo){
	bool returnValue = false;

	if (magazineAmmo >= 0 && magazineAmmo <= kMaxMagazineAmmo){
		returnValue = true;
		this->magazineAmmo = magazineAmmo;
	}
	return returnValue;
}

/**
* \breif Class meathod to set the weapons damaga
* \details <b>Details</b>
*
* \param damage - <b>int</b> - the value the weapon damage will be set to
*
* \return  returnValue -  <b>bool</b> - if the assignment succeeded
*/
bool Weapon::SetDamage(int damage){
	bool returnValue = false;

	if (damage >= 0 && damage <= kMaxDamage){
		returnValue = true;
		this->damage = damage;
	}
	return returnValue;
}

/**
* \breif Class meathod to set the weapons accuracy
* \details <b>Details</b>
*
* \param accuracy - <b>int</b> - the value the weapon accuracy will be set to
*
* \return  returnValue -  <b>bool</b> - if the assignment succeeded
*/
bool Weapon::SetAccuracy(int accuracy){
	bool returnValue = false;

	if (accuracy >= 0 && accuracy <= kMaxAccuracy){
		returnValue = true;
		this->accuracy = accuracy;
	}
	return returnValue;
}

/**
* \breif Class meathod to set the weapons stability
* \details <b>Details</b>
*
* \param stability - <b>int</b> - the value the weapon stability will be set to
*
* \return  returnValue -  <b>bool</b> - if the assignment succeeded
*/
bool Weapon::SetStability(int stability){
	bool returnValue = false;

	if (stability >= 0 && stability <= kMaxStability){
		returnValue = true;
		this->stability = stability;
	}
	return returnValue;
}

/**
* \breif Class meathod to set the weapons concealment
* \details <b>Details</b>
*
* \param concealment - <b>int</b> - the value the weapon concealment will be set to
*
* \return  returnValue -  <b>bool</b> - if the assignment succeeded
*/
bool Weapon::SetConcealment(int concealment){
	bool returnValue = false;

	if (concealment >= 0 && concealment <= kMaxConcealment){
		returnValue = true;
		this->concealment = concealment;
	}
	return returnValue;
}

/**
* \breif Class meathod to set the weapons threat
* \details <b>Details</b>
*
* \param threat - <b>int</b> - the value the weapon threat will be set to
*
* \return  returnValue -  <b>bool</b> - if the assignment succeeded
*/
bool Weapon::SetThreat(int threat){
	bool returnValue = false;

	if (threat >= 0 && threat <= kMaxThreat){
		returnValue = true;
		this->threat = threat;
	}
	return returnValue;
}

/**
* \breif Class meathod to set the weapons unlock level
* \details <b>Details</b>
*
* \param levelUnLock - <b>int</b> - the value the weapon unlock level will be set to
*
* \return  returnValue -  <b>bool</b> - if the assignment succeeded
*/
bool Weapon::SetLevelUnLock(int levelUnLock){
	bool returnValue = false;

	if (levelUnLock >= 0 && levelUnLock <= kMaxLevelUnLock){
		returnValue = true;
		this->levelUnLock = levelUnLock;
	}
	return returnValue;
}

/**
* \breif Class meathod to set the weapons cost
* \details <b>Details</b>
*
* \param cost - <b>int</b> - the value the weapon cost will be set to
*
* \return  returnValue -  <b>bool</b> - if the assignment succeeded
*/
bool Weapon::SetCost(int cost){
	bool returnValue = false;

	if (cost >= 0 && cost <= kMaxCost){
		returnValue = true;
		this->cost = cost;
	}
	return returnValue;
}

/**
* \breif Class meathod to set the weapons required unlocks
* \details <b>Details</b>
*
* \param gunName - <b>vector<string></b> - the values to set to the required unlocks for the weapon
*
* \return  extrasNumber -  <b>int</b> - the number of unlock requierments set
*/
int Weapon::SetextraUnLockReqs(vector<string> extraUnLockReqs){
	int extrasNumber = 0;
	int charNumber = 0;
	bool correct = true;

	extraUnLockReqs.clear();

	for (vector<string>::iterator iter = extraUnLockReqs.begin(); iter != extraUnLockReqs.end(); iter++){
		correct = true;
		charNumber = 0;

		if ((iter->c_str()[charNumber] == ' ')){
			correct = false;
		}
		while (iter->c_str()[charNumber] != '\0'){
			if ((iter->c_str()[charNumber] < '-' || iter->c_str()[charNumber] > '.') &&
				(iter->c_str()[charNumber] < '0' || iter->c_str()[charNumber] > '9') &&
				(iter->c_str()[charNumber] < 'A' || iter->c_str()[charNumber] > 'Z') &&
				(iter->c_str()[charNumber] < 'a' || iter->c_str()[charNumber] > 'z') &&
				iter->c_str()[charNumber] != ' '){
				correct = false;
				break;
			}
			charNumber++;
		}
		if (correct == false){
			extraUnLockReqs.erase(iter);
			extrasNumber++;
		}
		if (correct == true){
			this->extraUnLockReqs.push_back(iter->c_str());
			charNumber++;
		}
		if (extraUnLockReqs.size() >= kMaxReqs){
			break;
		}
	}
	return extrasNumber;
}
