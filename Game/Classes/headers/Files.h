#ifndef FILES_H
#define FILES_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "Player.h"
#include

template <class T>
template<class S>

using namespace std;

class Files
{
private:
    const string path = "ranking.dat";
public:
    Files();
    ~Files();
    void GravaJogo(T& a, S& b);
    void Stats();
};
#endif