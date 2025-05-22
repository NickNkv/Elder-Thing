#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <exception>
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
	strcpy(this->name, "John");
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
	this->weapons = new (std::nothrow) Weapon[3];
	if (!this->weapons) {
		throw std::bad_alloc();
	}
	this->weapons[0] = tempWeapon;

	//new atributes
	this->strength = 10;
	this->dexterity = 10;
	this->intelligence = 10;
	this->faith = 3;
	this->endurance = 10;
	this->spellSlots = new (std::nothrow) Spell*[3];
	if (!this->spellSlots) {
		delete[] this->weapons;
		throw std::bad_alloc();
	}
	for (int i = 0; i < 3; i++) {
		this->spellSlots[i] = nullptr;
	}
	this->equippedSpellIndex = -1;
}

Player::Player(const char* name, int hp, int maxHp, int mp, int maxMp, int stamina, int maxStamina, int runes) {
	if (strlen(name) == 0 || strlen(name) > 31) {
		std::cout << "Name must be up to 31 characters (and not empty)" << std::endl;
		throw std::invalid_argument("Invalid name input!");
	}
	if (hp <= 0 || hp > MAX_HP) {
		std::cout << "Health must be in range [1, "<< MAX_HP << "]!" << std::endl;
		throw std::invalid_argument("Invalid hp input!");
	}
	if (maxHp < 10 || maxHp > MAX_HP) {
		std::cout << "Max health must be in range [10, " << MAX_HP << "]!" << std::endl;
		throw std::invalid_argument("Invalid max hp input!");
	}
	if (mp < 0 || mp > MAX_MP) {
		std::cout << "Mana points must be in range [0, " << MAX_MP << "]!" << std::endl;
		throw std::invalid_argument("Invalid mana input!");
	}
	if (maxMp < 10 || maxMp > MAX_MP) {
		std::cout << "Max mana points must be in range [10, " << MAX_MP << "]!" << std::endl;
		throw std::invalid_argument("Invalid max mana inout!");
	}
	if (stamina < 0 || stamina > MAX_STAMINA) {
		std::cout << "Stamina must be in range [0, " << MAX_STAMINA << "]!" << std::endl;
		throw std::invalid_argument("Invalid stamina input!");
	}
	if (maxStamina < 10 || maxStamina > MAX_STAMINA) {
		std::cout << "Max stamina must be in range [10, " << MAX_STAMINA << "]!" << std::endl;
		throw std::invalid_argument("Invalid max stamina input!");
	}
	if (runes < 0 || runes > MAX_RUNES) {
		std::cout << "Runes must be in range [0, " << MAX_RUNES << "]!" << std::endl;
		throw std::invalid_argument("Invalid runes input!");
	}

	//atributes
	strcpy(this->name, name);
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
	this->weapons = new (std::nothrow) Weapon[3];
	if (!this->weapons) {
		throw std::bad_alloc();
	}

	//new atributes
	this->strength = 10;
	this->dexterity = 10;
	this->intelligence = 10;
	this->faith = 3;
	this->endurance = 10;
	this->spellSlots = new (std::nothrow) Spell * [3];
	if (!this->spellSlots) {
		delete[] this->weapons;
		throw std::bad_alloc();
	}
	for (int i = 0; i < 3; i++) {
		this->spellSlots[i] = nullptr;
	}
	this->equippedSpellIndex = -1;
}

Player::Player(Player const &other) {
	//we copy the dynamic stuff first for if it throws an error
	//all the other static copying would be deemed unnecessary
	this->weaponsCount = other.weaponsCount;
	this->weapons = new (std::nothrow) Weapon[other.weaponsCount];
	if (!weapons) {
		throw std::bad_alloc();
	}

	for (int i = 0; i < other.weaponsCount; i++) {
		this->weapons[i] = other.weapons[i];
	}

	//atributes
	strcpy(this->name, other.name);
	this->hp = other.hp;
	this->maxHp = other.maxHp;
	this->mp = other.mp;
	this->maxMp = other.maxMp;
	this->stamina = other.stamina;
	this->maxStamina = other.maxStamina;
	this->runes = other.runes;
	this->level = other.level;

	//resources
	this->flaskChargesHp = other.flaskChargesHp;
	this->flaskChargesMp = other.flaskChargesMp;

	//equipment
	this->currentWeight = other.currentWeight;
	this->maxCarryCapacity = other.maxCarryCapacity;
}

Player& Player::operator =(Player const& other) {
	if (this != &other) {
		//we copy the dynamic stuff first for if it throws an error
		//all the other static copying would be deemed unnecessary
		Weapon* temp = new (std::nothrow) Weapon[other.weaponsCount];
		if (!temp) {
			throw std::bad_alloc();
		}

		for (int i = 0; i < other.weaponsCount; i++) {
			temp[i] = other.weapons[i];
		}
		delete[] this->weapons;
		this->weapons = temp;
		this->weaponsCount = other.weaponsCount;

		//atributes
		strcpy(this->name, other.name);
		this->hp = other.hp;
		this->maxHp = other.maxHp;
		this->mp = other.mp;
		this->maxMp = other.maxMp;
		this->stamina = other.stamina;
		this->maxStamina = other.maxStamina;
		this->runes = other.runes;
		this->level = other.level;

		//resources
		this->flaskChargesHp = other.flaskChargesHp;
		this->flaskChargesMp = other.flaskChargesMp;

		//equipment
		this->currentWeight = other.currentWeight;
		this->maxCarryCapacity = other.maxCarryCapacity;
	}

	return *this;
}

Player::~Player() {
	std::cout << this->name << " has been destroyed!" << std::endl;
	delete[] this->weapons;
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

Weapon* Player::getWeapons() const {
	return this->weapons;
}

//game mechanics
void Player::addWeapon(Weapon& weapon) {
	if (this->weaponsCount == 3) {
		std::cout << "Max number of weapons reached!\nA player can have up to 3 weapons!" << std::endl;
	}
	else if (this->currentWeight + weapon.getWeight() > this->maxCarryCapacity) {
		std::cout << "This weapon is too heavy for your current inventory!" << std::endl;
	}
	else {
		this->weapons[this->weaponsCount] = weapon;
		this->weaponsCount += 1;
		this->currentWeight += weapon.getWeight();
	}
}

void Player::deleteWeapon() {
	std::cout << "Deleting a weapon - " << this->name << std::endl;
	std::cout << "Current weapon inventory" << std::endl;

	if (this->weaponsCount == 0) std::cout << "No weapons available\n";

	for (int i = 0; i < this->weaponsCount; i++) {
		std::cout << "No." << i + 1 << " - ";
		this->weapons[i].printInfo();
		std::cout << "\n";
	}

	std::cout << "Choose a weapon to delete (0 to cancel): ";
	int option = 0;
	std::cin >> option;
	while (option < 0 || option > this->weaponsCount) {
		std::cout << "Invalid option!\n" << "Choose a weapon to delete (0 to cancel): ";
		std::cin >> option;
	}

	//when we delete a weapon, we just move the others at the first positions
	//weaponsCount serves as a hint to how many indexes are filled with a weapon (counting from 0)
	//not the best design, but works for now

	if (option == 0) {
		std::cout << "Weapon deleting was canceled" << std::endl;
	}
	else if (option == 1) {
		this->currentWeight -= this->weapons[0].getWeight();
		this->weaponsCount -= 1;
		this->weapons[0] = this->weapons[1];
		this->weapons[1] = this->weapons[2];
	}
	else if (option == 2) {
		this->currentWeight -= this->weapons[1].getWeight();
		this->weaponsCount -= 1;
		this->weapons[1] = this->weapons[2];
	}
	else {
		this->currentWeight -= this->weapons[2].getWeight();
		this->weaponsCount -= 1;
	}
}

void Player::heal() {
	if (this->hp == this->maxHp) {
		std::cout << "Max hp reached!" << std::endl;
		return;
	}

	this->hp += 1;
	this->flaskChargesHp -= 1;
	std::cout << "+1 hp" << std::endl;
}

void Player::rechargeMana() {
	if (this->mp == this->maxMp) {
		std::cout << "Max mana reached!" << std::endl;
		return;
	}

	this->mp += 1;
	this->flaskChargesMp -= 1;
	std::cout << "+1 mana" << std::endl;
}

int Player::takeDamage(unsigned damage) {
	// 0 - damage not taken
	// 1 - damage taken
	// -1 - character died
	if (damage >= this->hp) {
		std::cout << this->name << " has died!" << std::endl;
		return -1;
	}
	else {
		this->hp -= damage;
		return 1;
	}
}

void Player::printInfo() {
	std::cout << this->name << "'s info\n";
	std::cout << "Hp - " << this->hp << "\t" << "Max hp - " << this->maxHp << "\n";
	std::cout << "Mp - " << this->mp << "\t" << "Max mp - " << this->maxMp << "\n";
	std::cout << "Stamina - " << this->stamina << "\t" << "Max stamina - " << this->maxStamina << "\n";
	std::cout << "Runes - " << this->runes << "\n";
	std::cout << "Level - " << this -> level << "\n";
	std::cout << "Flask charges: Hp - " << this->flaskChargesHp << "  Mana - " << this->flaskChargesMp << "\n";
	std::cout << "Current luggage weight - " << this->currentWeight << "\n";
	std::cout << "Max carry capacity - " << this->maxCarryCapacity << "\n";
	std::cout << "Current weapon inventory:\n";

	if (this->weaponsCount == 0) std::cout << "No weapons available\n";

	for (int i = 0; i < this->weaponsCount; i++) {
		std::cout << "No." << i + 1 << " - ";
		this->weapons[i].printInfo();
		std::cout << "\n";
	}
}

void Player::printWeapons() {
	if (this->weaponsCount == 0) std::cout << "No weapons available\n";

	for (int i = 0; i < this->weaponsCount; i++) {
		std::cout << "No." << i + 1 << " - ";
		this->weapons[i].printInfo();
		std::cout << "\n";
	}
}
