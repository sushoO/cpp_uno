#include <iostream>
#include "uno.hpp"
#include <string>
#include <vector>
#include <array>

//Player Class Methods

Player::Player(std::string anom, int playerNumber)
{
    name = anom;
    number = playerNumber;
}

std::string Player::getName()
{
    return name;
}

void Player::setHand(std::vector<Card> ahand)
{
    hand = ahand;
}

std::vector<Card> Player::getHand()
{
    return hand;
}


int Player::getNumber()
{
    return number; 
}
