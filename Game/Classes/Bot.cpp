#include "headers/Bot.h"

using namespace std;

char winner(char matrix[3][3]);
int firstO(int move);
int secondO(int m1, int m2);

Bot::Bot(char symbol, int level) : Player("Bot", symbol)
{
    this->level = level;
    this->matrix = new Player**[3];
    for(int i = 0; i < 3; i++)
    {
        matrix[i] = new Player*[3];
        for(int j = 0; j < 3; j++)
        {
            matrix[i][j] = NULL;
        }
    }
}

Bot::~Bot()
{
    delete this->matrix;
}

int Bot::play(Player ***m)
{
    srand((unsigned) time(NULL));

    vector<int> frees;
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            
            if (m[i][j] == NULL)
            {
                frees.push_back(i * 3 + j);
            }
            if (this->matrix[i][j] != m[i][j])
            {
                if(m[i][j]->getSymbol() != this->getSymbol())
                    opMoves.push_back(i*3 + j);
            }
            this->matrix[i][j] = m[i][j];
        }
    }

    //Se é primeira jogada de 'O'
    if (frees.size() == 8 && level > 1)
    {
        return firstO(opMoves[0]);
    }

    else
    {
        if(frees.size() == 6 && level > 2)
        {
            if( (opMoves[0] == 0 || opMoves[0] == 8) && (opMoves[1] == 0 || opMoves[1] == 8) ||
                (opMoves[0] == 2 || opMoves[0] == 6) && (opMoves[1] == 2 || opMoves[1] == 6) )    
            {
                int p[4] = {1, 3, 5, 7};
                int pos = p[rand() % 4];
                cout << pos << endl;
                return pos;
            }
            else if (canWin() >= 0)
                return canWin();

            else if (canLoose() >= 0)
                return canLoose();
            
            else
                return frees[rand() % frees.size()];
        }
        
        else
        {
            if (canWin() >= 0)
                return canWin();
            else if (canLoose() >= 0)
                return canLoose();
            else if (frees.size() > 0)
                return frees[rand() % frees.size()];
            else if (frees.size() == 0)
                return frees[0];
            else 
                return -1;
        }
    }
}

int Bot::canWin()
{
    char copy[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (matrix[i][j])
                copy[i][j] = matrix[i][j]->getSymbol();
            else
                copy[i][j] = 0;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (matrix[i][j] == 0)
            {
                copy[i][j] = this->getSymbol();
                if (winner(copy) == this->getSymbol())
                {
                    return 3 * i + j;
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
    if (this->getSymbol() == 'X')
        opp = 'O';
    else
        opp = 'X';

    char copy[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (matrix[i][j])
                copy[i][j] = matrix[i][j]->getSymbol();
            else
                copy[i][j] = 0;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (matrix[i][j] == 0)
            {
                copy[i][j] = opp;
                if (winner(copy) == opp)
                {
                    return 3 * i + j;
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
    for (int i = 1; i < 3 && matrix[i][i]; i++)
    {
        if (matrix[i][i] != matrix[i - 1][i - 1])
            break;
        if (i == 3 - 1)
            return matrix[i][i];
    }

    //verify antidiagonal
    for (int i = 1; i < 3 && matrix[i][3 - 1 - i]; i++)
    {
        if (matrix[i][3 - 1 - i] != matrix[i - 1][3 - i])
            break;
        if (i == 3 - 1)
            return matrix[i][3 - 1 - i];
    }
    //verify lines
    for (int i = 0; i < 3; i++)
    {
        for (int j = 1; j < 3 && matrix[i][j]; j++)
        {
            if (matrix[i][j] != matrix[i][j - 1])
                break;
            if (j == 3 - 1)
                return matrix[i][j];
        }
    }
    //verify columns
    for (int j = 0; j < 3; j++)
    {
        for (int i = 1; i < 3 && matrix[i][j]; i++)
        {
            if (matrix[i][j] != matrix[i - 1][j])
                break;
            if (i == 3 - 1)
                return matrix[i][j];
        }
    }
    return 0;
}

int firstO(int move)
{
    switch (move)
    {
        case 0:
            return 4;
        case 2:
            return 4;
        case 6:
            return 4;
        case 8:
            return 4;

        case 1:
        {
            int p[3] = {0, 2, 4};
            return p[rand() % 3];
        }
        case 3:
        {
            int p[3] = {0, 4, 6};
            return p[rand() % 3];
        }
        case 7:
        {
            int p[3] = {6, 4, 8};
            return p[rand() % 3];
        }
        case 5:
        {
            int p[3] = {2, 4, 8};
            return p[rand() % 3];
        }

        case 4:
        {
            int p[4] = {0, 2, 6, 8};
            return p[rand() % 4];
        }
    }
}

int secondO(int m1, int m2)
{
    cout << m1 << ' ' << m2 << endl;
    if( (m1 == 0 || m1 == 8) && (m2 == 0 || m2 == 8) ||
        (m1 == 2 || m1 == 6) && (m2 == 2 || m2 == 6) )
    {
        int p[4] = {1, 3, 5, 7};
        int pos = p[rand() % 4];
        cout << pos << endl;
        return pos;
    }
}
