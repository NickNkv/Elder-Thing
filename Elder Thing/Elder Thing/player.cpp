#include <iostream>
#include "player.hpp"
#include "weapon.hpp"

//max values for the game, not for a player
#define MAX_HP 1000
#define MAX_MP 1000
#define MAX_STAMINA 1000
#define MAX_CARRY_CAP 100

Player::Player() {
	//atributes
	this->hp = 30;
	this->maxHp = 30;
	this->mp = 0;
	this->maxMp = 30;
	this->stamina = 50;
	this->maxStamina = 100;
	this->runes = 20;
	this->level = 0;

	//resources
	this->flaskChargesHp = 3;
	this->flaskChargesMp = 3;

	//equipment
	this->currentWeight = 1; //weight is added from what the player is carrying, not his body weight
	this->maxCarryCapacity = 15;
	this->weaponsCount = 1;
	Weapon tempWeapon;
	this->weapons[0] = tempWeapon;
}

Player::Player(int hp, int maxHp, int mp, int maxMp, int stamina, int maxStamina, int runes) {
	if (hp <= 0 || hp > MAX_HP) {
		std::cout << "Health must be in range [1, "<< MAX_HP << "]!" << std::endl;
		return;
	}
	if (maxHp < 10 || maxHp > MAX_HP) {
		std::cout << "Max health must be in range [10, " << MAX_HP << "]!" << std::endl;
		return;
	}
	if (mp < 0 || mp > MAX_MP) {
		std::cout << "Mana points must be in range [0, " << MAX_MP << "]!" << std::endl;
		return;
	}
	if (maxMp < 10 || maxMp > MAX_MP) {
		std::cout << "Max mana points must be in range [10, " << MAX_MP << "]!" << std::endl;
		return;
	}
	if (stamina < 0 || stamina > MAX_STAMINA) {
		std::cout << "Stamina must be in range [0, " << MAX_STAMINA << "]!" << std::endl;
		return;
	}
	if (maxStamina < 10 || maxStamina > MAX_STAMINA) {
		std::cout << "Max stamina must be in range [10, " << MAX_STAMINA << "]!" << std::endl;
		return;
	}
	if (runes < 0) {
		std::cout << "Runes can not be a negative number!" << std::endl;
		return;
	}

	//atributes
	this->hp = (unsigned)hp;
	this->maxHp = (unsigned)maxHp;
	this->mp = (unsigned)mp;
	this->maxMp = (unsigned)maxMp;
	this->stamina = (unsigned)stamina;
	this->maxStamina = (unsigned)maxStamina;
	this->runes = (unsigned)runes;
	this->level = 0;
	
	//resources
	this->flaskChargesHp = 3;
	this->flaskChargesMp = 3;

	//equipment
	this->currentWeight = 0; //weight is added from what the player is carrying, not his body weight
	this->maxCarryCapacity = MAX_CARRY_CAP;
	this->weaponsCount = 0; //we start without weapons
}

void Player::setHp(int hp)
{
	if (hp < 0 || hp > MAX_HP) {
		std::cout << "Health can be set in range [0, " << MAX_HP << "]!" << std::endl;
	}
	else {
		this->hp = (unsigned)hp;
	}
}

void Player::setMaxHp(int maxHp){
	if (maxHp < 10 || maxHp > MAX_HP) {
		std::cout << "Max health must be in range [10, " << MAX_HP << "]!" << std::endl;
	}
	else {
		this->maxHp = (unsigned)maxHp;
		std::cout << "Max health was changed!" << std::endl;
	}
}

void Player::setMp(int mp) {
	if (mp < 0 || mp > MAX_MP) {
		std::cout << "Mana points must be in range [0, " << MAX_MP << "]!" << std::endl;
	}
	else {
		this->mp = (unsigned)mp;
	}
}

void Player::setMaxMp(int maxMp) {
	if (maxMp < 10 || maxMp > MAX_MP) {
		std::cout << "Max mana points must be in range [10, " << MAX_MP << "]!" << std::endl;
	}
	else {
		this->maxMp = (unsigned)maxMp;
		std::cout << "Max mana was changed!" << std::endl;
	}
}

void Player::setStamina(int stamina) {
	if (stamina < 0 || stamina > MAX_STAMINA) {
		std::cout << "Stamina must be in range [0, " << MAX_STAMINA << "]!" << std::endl;
	}
	else {
		this->stamina = (unsigned)stamina;
	}
}

void Player::setMaxStamina(int maxStamina) {
	if (maxStamina < 10 || maxStamina > MAX_STAMINA) {
		std::cout << "Max stamina must be in range [10, " << MAX_STAMINA << "]!" << std::endl;
	}
}
