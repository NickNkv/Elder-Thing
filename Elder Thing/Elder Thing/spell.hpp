#pragma once

class Spell 
{
public:
	//lifecycle
	Spell();
	Spell(char* name, int damage, int mpCost, int cooldown, int intelligence, int faith);
	Spell(const Spell& other);
	~Spell();

	Spell& operator=(const Spell& other);

	//getters and setters


private:
	char* name;
	unsigned damage;
	unsigned mpCost;
	unsigned cooldown; //in mins
	unsigned requiredIntelligence;
	unsigned requiredFaith;
	unsigned remainingCooldown; //in mins
};