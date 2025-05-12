#pragma once

class Weapon {
public:
	//life cycle
	Weapon();
	Weapon(const char name[32], unsigned damage, unsigned weight, unsigned requiredStrength);

	//getters/setters
	unsigned getWeight() const { return weight; };

	//game mechanics
	void printInfo();

private:
	char name[32];
	unsigned damage;
	unsigned weight;
	unsigned requiredStrength;
};