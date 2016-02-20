#ifndef _domainLayer_
#define _domainLayer_
#include <string.h>
#include <vector>
#include <fstream> 
using namespace std;

/// \ class Weapon
/// \ brief the perpose of this class is to validate all the weapon enteries. this class is the weapon
/// <b>Weapon</b>
/// \ author <i>Nathan Nickel & Brandon Davies</i>

#define kMaxCost 10000000
#define kMaxLevelUnLock 100
#define kMaxThreat 500
#define kMaxConcealment 100
#define kMaxStability 100
#define kMaxAccuracy 100
#define kMaxDamage 10000
#define kMaxMagazineAmmo 1000
#define kMaxTotalAmmo 1000
#define kMaxRateOfFire 10000
#define kMaxReqs 50
#define kMaxMods 50

class Weapon{
	/* ====================================== */
	/*              PRIVATE                   */
	/* ====================================== */
private:
	/* -------------- ATTRIBUTES ------------ */
	string gunName;///<the name of the gun
	vector<string> avalibleModifications;///<all the modifications on the weapon
	int rateOfFire;///<rate of tire of the weapon
	int totalAmmo;///<total ammo of the weapon
	int magazineAmmo;///<magazine size of the weapon
	int damage;///<damage of the weapon
	int accuracy;///<accuracy of the weapon
	int stability;///<stability of the weapon
	int concealment;///< the weapons concealablility
	int threat;///< the weapons threat
	int levelUnLock;///<the level needed tp unlock the weapon
	int cost;///<the cost of the weapon
	vector<string> extraUnLockReqs;///<any extra unlock requirements such as DLC

	/* ====================================== */
	/*              PUBLIC                    */
	/* ====================================== */
public:
	/* -------------- CONSTANTS ------------- */
	/* -------------- ATTRIBUTES ------------ */
	/*Constructor and Destructors*/
	Weapon(string gunName);///<constructor
	Weapon(string gunName, vector<string> avalibleModifications, vector<string> extraUnLockReqs, int rateOfFire, int totalAmmo, int magazineAmmo, int damage,
		int accuracy, int stability, int concealment, int threat, int levelUnLock, int cost);///<contructor
	~Weapon();///<deconstructor

	/*Public Methods*/
	bool AddAvalibleModification(string modification);///<checks if mods are valid and add them if they are
	bool AddExtraUnLockReqs(string UnLockReq);///<checks if extra unlock requirements are valid and adds them if they are
	bool DeleteAvalibleModification(string modification);///<deletes specified mod 
	bool DeleteExtraUnLockReqs(string UnLockReq);///<deletes specified unlock requirements

	// overload the extraction operator for this class (for ASCII object output)
	friend ofstream& operator<< (ofstream& s, Weapon& obj);///<overloaded << operator for file output

	// overload the insertion operator for this class (for ASCII object output)
	friend ifstream& operator>> (ifstream& s, Weapon& obj);///< overloaded >> operator for file input

	/*Getters*/
	const string GetGunName(void);///<gets gun name
	const vector<string> GetAvalibleModifications(void);///<gets all equiped weapon mods
	int GetRateOfFire(void);///<gets the rate of fire of the weapon
	int GetTotalAmmo(void);///<gets the total ammo of the weapon
	int GetMagazineAmmo(void);///< gets the ammo capacity of the weapon
	int GetDamage(void);///< gets the damage of the weapon
	int GetAccuracy(void);///< gets the accuracy of the weapon
	int GetStability(void);///< gets the stability of the weapon
	int GetConcealment(void);///< get concealment of the weapon
	int GetThreat(void);///< gets the threat of the weapon
	int GetLevelUnLock(void);///< gets the level unlock requirements
	int GetCost(void);//< gets the cost of weapon
	const vector<string> GetextraUnLockReqs(void);///< get  the extra unlock requirements

	/*Setters*/
	bool SetGunName(string name);///< sets the name of the gun
	int SetAvalibleModifications(vector<string> modifications);///< sets the equiped modifactions
	bool SetRateOfFire(int rateOfFire);///< sets the rate of fire
	bool SetTotalAmmo(int totalAmmo);///< sets the total ammo of the weapon
	bool SetMagazineAmmo(int magazineAmmo);///< sets the magazine size
	bool SetDamage(int damage);///< sets the damage of the weapon
	bool SetAccuracy(int accuracy);///< sets the accuracy of the weapon
	bool SetStability(int stability);///< sets the stability of  the weapon
	bool SetConcealment(int concealment);///< sets the concealment of the weapon
	bool SetThreat(int threat);///< sets the threat of the weapon
	bool SetLevelUnLock(int LevelUnLock);///< sets the level to unlock requirement
	bool SetCost(int cost);///< sets the cost of the weapon
	int SetextraUnLockReqs(vector<string> extraUnLockReqs);///<  sets the extra unlock requiremnts
};

#endif