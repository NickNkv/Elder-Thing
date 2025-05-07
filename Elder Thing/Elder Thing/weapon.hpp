#pragma once

class Weapon {
public:
	Weapon();
	Weapon(const char name[32], int damage, int weight, int requiredStrength);
	void printInfo();

private:
	char name[32] = "John Doe";
	int damage = 0;
	int weight = 0;
	int requiredStrength = 0;
};