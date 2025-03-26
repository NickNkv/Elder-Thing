#pragma once
#include "weapon.hpp"

class Player 
{
public:
	int getHp() const { return hp; }
	void setHp(int hp);

	int getMaxHp() const { return maxHp; }
	void setMaxHp(int maxHp);

	int getStamina() const { return stamina; }
	void setStamina(int stamina);

	int getMaxStamina() const { return maxStamina; }
	void setMaxStamina(int maxStamina);

	int getRunes() const { return runes; }
	void setRunes(int runes);

	int getLevel() const { return level; }
	void setLevel(int level);

	int getFlaskChargeHp() const { return flaskChargesHp; }
	void setFlaskChargeHp(int flaskChargeHp);

	int getFlaskChargeMp() const { return flaskChargesMp; }
	void setFlaskChargeMp(int setFlaskChargeMp);

	int getCurrentWeight() const { return currentWeight; }
	void setCurrentWeight(int currentWeight);

	int getMaxCarryCapacity() const { return maxCarryCapacity; }
	void setMaxCarryCapacity(int maxCarryCapacity);

	int getWeaponsCount() const { return weaponsCount; }
	void setWeaponsCount(int weaponsCount);

	Weapon* getWeapons() const;
	void setWeapons(Weapon* weapons);
private:
	//atributes
	int hp = 0;
	int maxHp = 0;
	int stamina = 0;
	int maxStamina = 0;
	int runes = 0;
	int level = 0;
	//resources
	int flaskChargesHp = 3;
	int flaskChargesMp = 3;
	//equipment
	int currentWeight = 0;
	int maxCarryCapacity = 0;
	int weaponsCount = 0;
	Weapon* weapons;
};