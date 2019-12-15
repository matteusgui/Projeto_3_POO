#ifndef FILES_H
#define FILES_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "Player.h"
#include "Game.h"
#include "GameStats.h"

using namespace std;

class Files
{
private:
    const string path = "ranking.dat";
    GameStats* Last_Game;
public:
    Files(GameStats* Last_Game);
    ~Files();
    void GravaJogo(Player *a, Player *b);
    void Carrega_Jogos();
    void drawStats();
};
#endif