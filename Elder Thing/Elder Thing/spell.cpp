#define _CRT_SECURE_NO_WARNINGS
#include "spell.hpp"
#include <iostream>
#include <exception>

Spell::Spell() {
	this->name = new char[5];
	strcpy(this->name, "Fire");
	this->damage = 2;
	this->mpCost = 1;
	this->cooldown = 1;
	this->requiredIntelligence = 1;
	this->requiredFaith = 1;
	this->remainingCooldown = 0;
}

Spell::Spell(char* name, int damage, int mpCost, int cooldown, int intelligence, int faith) {
	this->name = new char[strlen(name) + 1];

	if (damage < 0) {
		std::cout << "Damage can not be a negative number!" << std::endl;
		throw std::invalid_argument("Invalid damage input!");
	}
	if (mpCost <= 0) {
		std::cout << "Mana points cost must be a positive number!" << std::endl;
		throw std::invalid_argument("Invalid mana cost input!");
	}
	if (cooldown < 0) {
		std::cout << "Cooldown cannot be a negative number!" << std::endl;
		throw std::invalid_argument("Invalid cooldown input!");
	}
	if (intelligence <= 0) {
		std::cout << "Required intelligence must be a positive number!" << std::endl;
		throw std::invalid_argument("Invalid required intelligence input!");
	}
	if (faith < 0) {
		std::cout << "Required faith can not be a negative number!" << std::endl;
		throw std::invalid_argument("Invalid required faith input!");
	}

	strcpy(this->name, name);
	this->damage = (unsigned)damage;
	this->mpCost = (unsigned)mpCost;
	this->cooldown = (unsigned)cooldown;
	this->requiredIntelligence = (unsigned)intelligence;
	this->requiredFaith = (unsigned)faith;
	this->remainingCooldown = 0;
}

Spell::Spell(const Spell& other) {
	this->name = new char[strlen(other.name) + 1];
	strcpy(this->name, other.name);
	this->damage = other.damage;
	this->mpCost = other.mpCost;
	this->cooldown = other.cooldown;
	this->requiredIntelligence = other.requiredIntelligence;
	this->requiredFaith = other.requiredFaith;
	this->remainingCooldown = other.remainingCooldown;
}

Spell::~Spell() {
	delete[] this->name;
}

Spell& Spell::operator=(const Spell& other) {
	if (this == &other) {
		return *this;
	}

	char* temp = new char[strlen(other.name) + 1];
	strcpy(temp, other.name);
	delete[] this->name;
	this->name = temp;
	temp = nullptr;

	this->damage = other.damage;
	this->mpCost = other.mpCost;
	this->cooldown = other.cooldown;
	this->requiredIntelligence = other.requiredIntelligence;
	this->requiredFaith = other.requiredFaith;
	this->remainingCooldown = other.remainingCooldown;

	return *this;
}

//getters and setters
void Spell::setName(const char* name) {
	char* temp = new char[strlen(name) + 1];
	strcpy(temp, name);
	delete[] this->name;
	this->name = temp;
	temp = nullptr;
}

void Spell::setDamage(unsigned damage) {
	if (damage < 0) {
		std::cout << "Damage can not be a negative number!" << std::endl;
	}
	else {
		this->damage = damage;
	}
}

void Spell::setMpCost(unsigned mpCost) {
	if (mpCost <= 0) {
		std::cout << "Mana points cost must be a positive number!" << std::endl;
	}
	else {
		this->mpCost = mpCost;
	}
}

void Spell::setCooldown(unsigned cooldown) {
	if (cooldown < 0) {
		std::cout << "Cooldown cannot be a negative number!" << std::endl;
	}
	else {
		this->cooldown = cooldown;
	}
}
