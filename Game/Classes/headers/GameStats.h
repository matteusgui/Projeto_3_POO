#ifndef  GAMESTATS_H
#define GAMESTATS_H

#include "Player.h"
using namespace std;

class GameStats
{
private:
    bool Contra_Bot;
    Player* winner;
    
    public:
    GameStats();
    ~GameStats();
    void setWinner(Player* winner);
    Player* getWinner();
    void setContra_Bot(bool Contra_Bot);
    bool getContra_Bot();
};