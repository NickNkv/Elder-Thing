#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "player.hpp"
#include "weapon.hpp"

//max values for the game, not for a player
#define MAX_HP 1000
#define MAX_MP 1000
#define MAX_STAMINA 1000
#define MAX_CARRY_CAP 100
#define MAX_RUNES 10000

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
	if (runes < 0 || runes > MAX_RUNES) {
		std::cout << "Runes must be in range [0, " << MAX_RUNES << "]!" << std::endl;
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

void Player::setName(const char* name) {
	if (strlen(name) == 0 || strlen(name) > 31) {
		std::cout << "Name must be up to 31 characters (and not empty)" << std::endl;
	}
	else {
		strcpy(this->name, name);
	}
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
	else {
		this->maxStamina = (unsigned)maxStamina;
		std::cout << "Max stamina was changed!" << std::endl;
	}
}

void Player::setRunes(int runes) {
	if (runes < 0 || runes > MAX_RUNES) {
		std::cout << "Runes must be in range [0, " << MAX_RUNES << "]!" << std::endl;
	}
	else {
		this->runes = (unsigned)runes;
	}
}

void Player::setLevel(int level) {
	if (level < 0) {
		std::cout << "Level can not be a negative number!" << std::endl;
	}
	else {
		this->level = (unsigned)level;
	}
}

void Player::setFlaskChargeHp(int flaskChargesHp) {
	if (flaskChargesHp < 0) {
		std::cout << "Hp flask charge can not be a negative number!" << std::endl;
	}
	else {
		this->flaskChargesHp = (unsigned)flaskChargesHp;
	}
}

void Player::setFlaskChargeMp(int setFlaskChargesMp) {
	if (flaskChargesMp < 0) {
		std::cout << "Mana flask charge can not be a negative number!" << std::endl;
	}
	else {
		this->flaskChargesMp = (unsigned)flaskChargesMp;
	}
}

void Player::setCurrentWeight(int currentWeight) {
	if (currentWeight < 0) {
		std::cout << "Weight can not be a negative number!" << std::endl;
	}
	else {
		this->currentWeight = (unsigned)currentWeight;
	}
}

void Player::setMaxCarryCapacity(int maxCarryCapacity) {
	if (maxCarryCapacity <= 0 || maxCarryCapacity > MAX_CARRY_CAP) {
		std::cout << "Max carry capacity must be in range of [1, " << MAX_CARRY_CAP << "]!" << std::endl;
	}
	else {
		this->maxCarryCapacity = (unsigned)maxCarryCapacity;
		std::cout << "Max carry capacity was changed!" << std::endl;
	}
}

void Player::setWeaponsCount(int weaponsCount) {
	if (weaponsCount < 0 || weaponsCount > 3) {
		std::cout << "A player can hold up to 3 weapons" << std::endl;
	}
	else {
		this->weaponsCount = (unsigned)weaponsCount;
	}
}

