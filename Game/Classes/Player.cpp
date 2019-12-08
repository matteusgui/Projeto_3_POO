#include "headers/Player.h"

Player::Player(string name, char symbol)
{
    this->name = name;
    this->symbol = symbol;
}

string Player::getName()
{
    return this->name;
}

char Player::getSymbol()
{
    return this->symbol;
}

void Player::rename(string newName)
{
    this->name = newName;
}

