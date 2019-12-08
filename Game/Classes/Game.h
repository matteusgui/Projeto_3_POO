#ifndef JOGO_H
#define JOGO_H

#include "Player.h"

const int SIZE = 3;

class Game
{
    public:
        Game(Player *p1, Player *p2);
        bool isFull();
        Player* winner(); 
        bool play(int lin, int col);
        void print();
        Player* getActive();
    private:
        Player* p1;
        Player* p2;
        Player* active;
        Player* matrix[SIZE][SIZE];
};

#endif