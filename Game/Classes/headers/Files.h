#ifndef FILES_H
#define FILES_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "Player.h"

using namespace std;

class Files
{
private:
    const string path = "ranking.dat";
    bool Contra_Bot;
    Player winner;
public:
    Files();
    ~Files();
    void GravaJogo(Player *a, Player *b);
    void Stats();
};
#endif