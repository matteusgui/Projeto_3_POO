#include "headers/Bot.h"

char winner(char matrix[3][3]);

Bot::Bot(char symbol) : Player("Bot", symbol)
{
    matrix = NULL;
}

int Bot::play(Player* **matrix)
{
    this->matrix = matrix;

    if(canWin() >= 0)
        return canWin();
    if(canLoose() >= 0)
        return canLoose();


    srand(time(NULL));
    vector<int> frees;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (matrix[i][j] == NULL)
            {
                frees.push_back(i * 3 + j);
            }
        }
    }
    return frees[rand() % frees.size()];
}

int Bot::canWin()
{
    char copy[3][3];
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(matrix[i][j])
                copy[i][j] = matrix[i][j]->getSymbol();
            else
                copy[i][j] = 0;            
        }
    }

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(matrix[i][j] == 0)
            {
                copy[i][j] = this->getSymbol();
                if(winner(copy) == this->getSymbol())
                {
                    return 3*i + j;
                }
                else
                {
                    copy[i][j] = 0;
                }
            }
        }
    }
    return -1;
}

int Bot::canLoose()
{
    char opp;
    if(this->getSymbol() == 'X')
        opp = 'O';
    else 
        opp = 'X';

    char copy[3][3];
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(matrix[i][j])
                copy[i][j] = matrix[i][j]->getSymbol();
            else
                copy[i][j] = 0; 
        }
    }

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(matrix[i][j] == 0)
            {
                copy[i][j] = opp;
                if(winner(copy) == opp)
                {
                    return 3*i + j;
                }
                else
                {
                    copy[i][j] = 0;
                }
            }
        }
    }
    return -1;
}

char winner(char matrix[3][3])
{
    //verify main diagonal
    for(int i = 1; i < 3 && matrix[i][i]; i++)
    {
        if(matrix[i][i] != matrix[i-1][i-1])
            break;
        if(i == 3-1)
            return matrix[i][i]; 
    }

    //verify antidiagonal
    for (int i = 1; i < 3 && matrix[i][3-1-i]; i++) 
    {
        if(matrix[i][3-1-i] != matrix[i-1][3-i])
            break;
        if(i == 3-1) 
            return matrix[i][3-1-i];
    }
    //verify lines
    for (int i = 0; i < 3; i++)
    {
        for(int j = 1; j < 3 && matrix[i][j]; j++)
        {
            if(matrix[i][j] != matrix[i][j-1])
                break;
            if(j == 3-1) 
                return matrix[i][j];
        }
    }
    //verify columns
    for (int j = 0; j < 3; j++)
    {
        for(int i = 1; i < 3 && matrix[i][j]; i++)
        {
            if(matrix[i][j] != matrix[i-1][j])
                break;
            if(i == 3-1)
                return matrix[i][j];
        }
    }
    return 0;
} 
