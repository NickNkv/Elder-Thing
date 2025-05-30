#define _CRT_SECURE_NO_WARNINGS
#include "weapon.hpp"
#include <iostream>
#include <cstring>

Weapon::Weapon() {
	strcpy(this->name, "Common dagger");
	this->damage = 3;
	this->weight = 1;
	this->requiredStrength = 1;
}

Weapon::Weapon(const char name[32], unsigned damage, unsigned weight, unsigned requiredStrength) {
	if (strlen(name) == 0) {
		std::cout << "Name cannot be an empty string" << std::endl;
		throw std::invalid_argument("Invalid name input!");
	}
	if (strlen(name) > 31) {
		std::cout << "Name cannot be longer than 31 characters" << std::endl;
		throw std::invalid_argument("Invalid name input!");
	}
	if (damage < 0) {
		std::cout << "Damage cannot be negative" << std::endl;
		throw std::invalid_argument("Invalid damage input!");
	}
	if (weight <= 0) {
		std::cout << "Weight must be a positive number" << std::endl;
		throw std::invalid_argument("Invalid weight input!");
	}
	if (requiredStrength <= 0) {
		std::cout << "The required strength must be a positive number" << std::endl;
		throw std::invalid_argument("Invalid required strength input!");
	}

	strcpy(this->name, name);
	this->damage = damage;
	this->weight = weight;
	this->requiredStrength = requiredStrength;
}

void Weapon::printInfo() {
	std::cout << "Weapon info\n";
	std::cout << "Name: " << this->name << std::endl;
	std::cout << "Damage: " << this->damage << std::endl;
	std::cout << "Weight: " << this->weight << std::endl;
	std::cout << "Required strength: " << this->requiredStrength << std::endl;
}

//week 9 - predefinirane na operatori

std::ostream& operator<<(std::ostream& out, const Weapon& weapon) {
	out << "Name: " << weapon.getName() << "\n";
	out << "Damage: " << weapon.getDamage() << "\n";
	out << "Weight: " << weapon.getWeight() << "\n";
	out << "Required strength: " << weapon.getRequiredStrength() << std::endl;

	return out;
}

std::istream& operator>>(std::istream& in, Weapon& weapon) {
	char slash = ' ';

	char name[32];
	in >> name;
	in >> slash;
	if (slash != ' ') {
		in.setstate(std::ios::failbit);
	}

	unsigned damage = 1;
	in >> damage;
	in >> slash;
	if (slash != ' ') {
		in.setstate(std::ios::failbit);
	}

	unsigned weight = 1;
	in >> weight;
	in >> slash;
	if (slash != ' ') {
		in.setstate(std::ios::failbit);
	}

	unsigned reqStr = 1;
	in >> reqStr;


	if (in)
	{
		strcpy(weapon.name, name);
		weapon.damage = damage;
		weapon.weight = weight;
		weapon.requiredStrength = reqStr;
	}

	return in;
}

bool operator==(const Weapon& lhs, const Weapon& rhs) {
	if (strcmp(lhs.getName(), rhs.getName()) == 0 &&
		lhs.getDamage() == rhs.getDamage() &&
		lhs.getWeight() == rhs.getWeight() &&
		lhs.getRequiredStrength() == rhs.getRequiredStrength()) 
	{
		return true;
	}
	else {
		return false;
	}
}

bool operator!=(const Weapon& lhs, const Weapon& rhs) {
	return !(lhs == rhs);
}

bool operator>(const Weapon& lhs, const Weapon& rhs) {
	return lhs.getDamage() > rhs.getDamage();
}

bool operator<(const Weapon& lhs, const Weapon& rhs) {
	return lhs.getDamage() < rhs.getDamage();
}
