#ifndef FILES_H
#define FILES_H

#include <fstream>
#include <iostream>
#include <string>

#include "Player.h"

using namespace std;

class Files: public Player
{
private:
    const string path = "ranking.dat";
public:
    Files(/* args */);
    ~Files();
};

Files::Files(/* args */)
{
}

Files::~Files()
{
}
