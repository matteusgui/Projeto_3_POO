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
    private:
        string name;
        char symbol;
};

#endif