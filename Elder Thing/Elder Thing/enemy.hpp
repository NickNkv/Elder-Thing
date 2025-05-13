#pragma once
#include "player.hpp"

class Enemy 
{
public:
	//the params in the functions are int in order
	//to have validation with personalised messages
	
	//lifecycle
	Enemy();
	Enemy(const char* name, int hp, int maxHp, int attackPower);
	Enemy(Enemy const &other);
	~Enemy();

	Enemy& operator =(Enemy const& other);

	//getters
	char* getName() const { return name; }
	unsigned getHp() const { return hp; }
	unsigned getMaxHp() const { return maxHp; }
	unsigned getAttackPower() const { return attackPower; }

	//game mechanics
	int sufferDamage(unsigned damage);
	void attackPlayer(Player& player);
	void printInfo();

private:
	char* name;
	unsigned hp;
	unsigned maxHp;
	unsigned attackPower;
};