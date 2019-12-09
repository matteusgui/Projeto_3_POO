#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

using namespace std;

class Player
{
    public:
        Player(string name, char symbol);
        string getName();
        char getSymbol();
        void rename(string newName);
        virtual int play(Player*** matrix) {};
        virtual bool isBot() {return false;};
    private:
        string name;
        char symbol;
};

#endif