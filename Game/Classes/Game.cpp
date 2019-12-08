#include "Game.h"

Game::Game(Player *p1, Player *p2)
{
    this->p1 = p1;
    this->p2 = p2;
    this->active = p1;
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            matrix[i][j] = 0;
        }
    }
}

bool Game::isFull()
{
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            if(!matrix[i][j])
                return false;
        }
    }
    return true;
}

Player* Game::getActive()
{
    return this->active;
}

Player* Game::winner()
{
    //verify main diagonal
    for(int i = 1; i < SIZE && matrix[i][i]; i++)
    {
        if(matrix[i][i] != matrix[i-1][i-1])
            break;
        if(i == SIZE-1)
            return matrix[i][i]; 
    }

    //verify antidiagonal
    for (int i = 1; i < SIZE && matrix[i][SIZE-1-i]; i++) 
    {
        if(matrix[i][SIZE-1-i] != matrix[i-1][SIZE-i])
            break;
        if(i == SIZE-1) 
            return matrix[i][SIZE-1-i];
    }
    //verify lines
    for (int i = 0; i < SIZE; i++)
    {
        for(int j = 1; j < SIZE && matrix[i][j]; j++)
        {
            if(matrix[i][j] != matrix[i][j-1])
                break;
            if(j == SIZE-1) 
                return matrix[i][j];
        }
    }
    //verify columns
    for (int j = 0; j < SIZE; j++)
    {
        for(int i = 1; i < SIZE && matrix[i][j]; i++)
        {
            if(matrix[i][j] != matrix[i-1][j])
                break;
            if(i == SIZE-1)
                return matrix[i][j];
        }
    }
    return NULL;
} 
        
bool Game::play(int lin, int col)
{
    if(lin >= SIZE || lin < 0) 
        return false;
    else if (col >= SIZE || col < 0) 
        return false;
    else if (matrix[lin][col]) 
        return false;
    else
    {
        matrix[lin][col] = active;
        if(active == p1)
            active = p2;
        else
            active = p1;
        return true;   
    }        
}

void Game::print()
{
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            if(matrix[i][j])
                cout << matrix[i][j]->getSymbol(); 
            else cout << " ";
        }
        cout << endl;
    }
}

