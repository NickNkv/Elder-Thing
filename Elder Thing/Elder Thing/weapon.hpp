#pragma once
#include <iostream>

class Weapon {
public:
	//life cycle
	Weapon();
	Weapon(const char name[32], unsigned damage, unsigned weight, unsigned requiredStrength);

	//getters/setters
	const char* getName() const { return name; }
	unsigned getDamage() const { return damage; }
	unsigned getWeight() const { return weight; }
	unsigned getRequiredStrength() const { return requiredStrength; }

	//game mechanics
	void printInfo();

	//week 9 - predefinirane na operatori
	friend std::ostream& operator << (std::ostream&, const Weapon&);
	friend std::istream& operator >> (std::istream&, Weapon&);

private:
	char name[32];
	unsigned damage;
	unsigned weight;
	unsigned requiredStrength;
};

//week 9 - predefinirane na operatori
bool operator == (const Weapon&, const Weapon&);
bool operator != (const Weapon&, const Weapon&);
bool operator >  (const Weapon&, const Weapon&);
bool operator <  (const Weapon&, const Weapon&);