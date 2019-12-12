#include "headers/Files.h"

using namespace std;

void Files::GravaJogo(Player *a, Player* b)
{
    if (a->isBot() || b->isBot())
    {
        this->Contra_Bot = true;
    }
    
}

void Files::Stats()
{
    ifstream arqIn;
    arqIn.fopen(path, ios::binary);
    
}