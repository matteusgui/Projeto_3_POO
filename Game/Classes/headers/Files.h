#ifndef FILES_H
#define FILES_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "Player.h"
#include "GameStats.h"

using namespace std;

class Files
{
private:
    const string path = "ranking.dat";
    GameStats dados_do_ultimo_jogo;
public:
    Files();
    ~Files();
    void GravaJogo(Player *a, Player *b);
    void Stats();
};
#endif