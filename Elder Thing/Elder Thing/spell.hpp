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
	const char* getName() const { return name; }
	void setName(const char* name);

	unsigned getDamage() const { return damage; }
	void setDamage(unsigned damage);

	unsigned getMpCost() const { return mpCost; }
	void setMpCost(unsigned mpCost);

	unsigned getCooldown() const { return cooldown; }
	void setCooldown(unsigned cooldown);

	//can not be changed due to task rules
	unsigned getRequiredIntelligence() const { return requiredIntelligence; }
	
	//can not be changed due to task rules
	unsigned getRequiredFaith() const { return requiredFaith; }

	//can be changed according to the cooldown property via the designated method below
	unsigned getRemainingCooldown() const { return remainingCooldown; }

private:
	char* name;
	unsigned damage;
	unsigned mpCost;
	unsigned cooldown; //in mins
	unsigned requiredIntelligence;
	unsigned requiredFaith;
	unsigned remainingCooldown; //in mins
};