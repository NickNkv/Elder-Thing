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
