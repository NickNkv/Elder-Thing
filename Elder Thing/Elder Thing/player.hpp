#pragma once
#include <iostream>
#include "weapon.hpp"
#include "spell.hpp"

class Player 
{
public:
	//the params in the functions are int in order
	//to have validation with personalised messages 
	
	//lifecycle
	Player();
	Player(const char* name, int hp, int maxHp, int mp, int maxMp, int stamina, int maxStamina, int runes);
	Player(Player const &other);
	~Player();

	Player& operator =(Player const& other);

	//getters and setters
	char getName() const { return *name; }
	void setName(const char* name);

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
	void setFlaskChargeHp(int flaskChargesHp);

	unsigned getFlaskChargeMp() const { return flaskChargesMp; }
	void setFlaskChargeMp(int setFlaskChargesMp);

	unsigned getCurrentWeight() const { return currentWeight; }
	void setCurrentWeight(int currentWeight);

	unsigned getMaxCarryCapacity() const { return maxCarryCapacity; }
	void setMaxCarryCapacity(int maxCarryCapacity);

	unsigned getWeaponsCount() const { return weaponsCount; }
	void setWeaponsCount(int weaponsCount);

	Weapon* getWeapons() const;

	//new getters/setters - week 7
	unsigned getStrength() const { return strength; }
	void setStrength(int strength);

	unsigned getDexterity() const { return dexterity; }
	void setDexterity(int dexterity);

	unsigned getIntelligence() const { return intelligence; }
	void setIntelligence(int intelligence);

	unsigned getFaith() const { return faith; }
	void setFaith(int faith);

	unsigned getEndurance() const { return endurance; }
	void setEndurance(int endurance);

	unsigned getEquippedSpellIndex() const { return equippedSpellIndex; }
	void setEquippedSpell(int index);

	//game mechanics
	void addWeapon(Weapon& weapon);
	void deleteWeapon();
	void heal();
	void rechargeMana();
	int takeDamage(unsigned damage); // todo: add armor
	void printInfo();
	void printWeapons();

	//new game mechanics - week 7
	void learnSpell(Spell& spell, int slotIndex);
	void unequipSpell();
	void castSpell();

	//week 9 - predefinirane na operatori
	friend std::ostream& operator << (std::ostream&, const Player&);

private:
	//atributes
	char name[32];
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
	Weapon* weapons;

	//new atributes - week 7
	unsigned strength;
	unsigned dexterity;
	unsigned intelligence;
	unsigned faith;
	unsigned endurance;
	Spell** spellSlots;
	int equippedSpellIndex;
};

//week 9 - predefinirane na operatori
Player& operator++(Player&); // ++player
const Player& operator++(Player&, int); // player++