#include <iostream>
#include "Player.hpp"
#include "Weapon.hpp"
#include "Enemy.hpp"

int main() {
	Player john;
	////john.printInfo();
	//john.printWeapons();
	//Weapon glock("Glock", 20, 2, 2);
	//john.addWeapon(glock);
	//john.printWeapons();
	//john.deleteWeapon();
	//john.printWeapons();

	Enemy barbarian("Mike", 30, 50, 10);
	//barbarian.printInfo();
	john.printInfo();
	barbarian.attackPlayer(john);
	john.printInfo();

	return 0;
}