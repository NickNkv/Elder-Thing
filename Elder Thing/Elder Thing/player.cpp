#include <iostream>
#include "player.hpp"

Player::Player() {

}

Player::Player(int hp, int maxHp, int mp, int maxMp, int stamina, int maxStamina, int runes, int level)
{
}

void Player::setHp(int hp)
{
	if (hp < 0) {
		std::cout << "Hp must be non-negative integer!" << std::endl;
	}
	else {
		this->hp = hp;
	}
}

void Player::setMaxHp(int maxHp)
{

}
