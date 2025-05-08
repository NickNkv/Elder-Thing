#pragma once
#include "weapon.hpp"

class Player 
{
public:
	//the params in the functions are int in order
	//to have validation with personalised messages 
	
	//constructor
	Player();
	Player(int hp, int maxHp, int mp, int maxMp, int stamina, int maxStamina, int runes);
	
	//getters and setters
	unsigned getHp() const { return hp; }
	void setHp(int hp);

	unsigned getMaxHp() const { return maxHp; }
	void setMaxHp(int maxHp);

	unsigned getMp() const { return mp; }
	void setMp(int mp);

	unsigned getMaxMp() const { return maxMp; }
	void setMaxMp(int maxMp);

	unsigned getStamina() const { return stamina; }
	void setStamina(int stamina);

	unsigned getMaxStamina() const { return maxStamina; }
	void setMaxStamina(int maxStamina);

	unsigned getRunes() const { return runes; }
	void setRunes(int runes);

	unsigned getLevel() const { return level; }
	void setLevel(int level);

	unsigned getFlaskChargeHp() const { return flaskChargesHp; }
	void setFlaskChargeHp(int flaskChargeHp);

	unsigned getFlaskChargeMp() const { return flaskChargesMp; }
	void setFlaskChargeMp(int setFlaskChargeMp);

	unsigned getCurrentWeight() const { return currentWeight; }
	void setCurrentWeight(int currentWeight);

	unsigned getMaxCarryCapacity() const { return maxCarryCapacity; }
	void setMaxCarryCapacity(int maxCarryCapacity);

	unsigned getWeaponsCount() const { return weaponsCount; }
	void setWeaponsCount(int weaponsCount);

	Weapon getWeapons() const;
	void setWeapons(Weapon& weapons);
private:
	//atributes
	unsigned hp;
	unsigned maxHp;
	unsigned mp;
	unsigned maxMp;
	unsigned stamina;
	unsigned maxStamina;
	unsigned runes;
	unsigned level;
	//resources
	unsigned flaskChargesHp;
	unsigned flaskChargesMp;
	//equipment
	unsigned currentWeight;
	unsigned maxCarryCapacity;
	unsigned weaponsCount;
	Weapon weapons[3];
};