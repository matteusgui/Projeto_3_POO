#ifndef BOT_H
#define BOT_H

#include "Player.h"
#include <cstdlib>
#include <ctime>
#include <vector>

class Bot : public Player
{
    public:
        Bot(char symbol, int level);
        ~Bot();
        int play(Player*** matrix);
        virtual bool isBot() {return true;};
    private:
        int level;
        int canLoose();
        int canWin();
        Player*** matrix;
        vector <int> opMoves;
};

#endif