#include "headers/GameStats.h"

void GameStats::setWinner(Player* winner)
{
    this->winner = winner;
}

Player* GameStats::getWinner()
{
    return winner;
}

void GameStats::setContra_Bot(bool Contra_Bot)
{
    this->Contra_Bot = Contra_Bot;
}

bool GameStats::getContra_Bot()
{
    return Contra_Bot;
}