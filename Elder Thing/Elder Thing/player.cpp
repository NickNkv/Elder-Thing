#include <iostream>
#include "player.hpp"

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
