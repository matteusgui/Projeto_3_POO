#ifndef BOT_H
#define BOT_H

#include "Player.h"
#include <stdlib.h>
#include <time.h>
#include <vector>

class Bot : public Player
{
    public:
        Bot(char symbol);
        int play(Player*** matrix);
        virtual bool isBot() {return true;};
    private:
        int canLoose();
        int canWin();
        Player*** matrix;
        int jogada;
};

#endif