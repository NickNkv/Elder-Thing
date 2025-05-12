#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <exception>
#include "enemy.hpp"

#define MAX_ENEMY_HP 100

//lifecycle
Enemy::Enemy() {
	this->name = new (std::nothrow) char[strlen("Barbarian") + 1];
	if (!name) {
		throw std::bad_alloc();
	}
	strcpy(this->name, "Barbarian");
	this->hp = 10;
	this->maxHp = 10;
	this->attackPower = 2;
}

Enemy::Enemy(char* name, int hp, int maxHp, int attackPower) {
	this->name = new (std::nothrow) char[strlen(name) + 1];
	if (!name) {
		throw std::bad_alloc();
	}
	if (hp <= 0 || hp > MAX_ENEMY_HP) {
		std::cout << "Health must be in range [1, " << MAX_ENEMY_HP << "]!" << std::endl;
		delete[] this->name;
		this->name = nullptr;
		throw std::invalid_argument("Invalid hp input!");
	}
	if (maxHp < 1 || maxHp > MAX_ENEMY_HP) {
		std::cout << "Max health must be in range [1, " << MAX_ENEMY_HP << "]!" << std::endl;
		delete[] this->name;
		this->name = nullptr;
		throw std::invalid_argument("Invalid max hp input!");
	}
	if (attackPower < 1) {
		std::cout << "Attack power must be a positive number!" << std::endl;
		delete[] this->name;
		this->name = nullptr;
		throw std::invalid_argument("Invalid attack power input!");
	}

	strcpy(this->name, name);
	this->hp = hp;
	this->maxHp = maxHp;
	this->attackPower = attackPower;
}

