#include "headers/Game.h"

const sf::Color white(255,255,255);
const sf::Color black(0, 0, 0);

Game::Game(Player *p1, Player *p2)
{
    this->p1 = p1;
    this->p2 = p2;
    this->active = p1;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            matrix[i][j] = 0;
        }
    }
}

void Game::drawGrade()
{
    sf::RectangleShape lineH(sf::Vector2f(size, 5));
    lineH.setFillColor(black);
    lineH.setPosition(position.x, position.y + size/3);
    window->draw(lineH);
    lineH.setPosition(position.x, position.y + size*2/3);
    window->draw(lineH);
    
    sf::RectangleShape lineV(sf::Vector2f(5, size));
    lineV.setFillColor(black);
    lineV.setPosition(position.x + (size/3), position.y);
    window->draw(lineV);
    lineV.setPosition(position.x+(size*2/3), position.y);
    window->draw(lineV);
}

void Game::drawPlays()
{
    sf::Texture oTexture;
    oTexture.loadFromImage(oImage);
    
    sf::Texture xTexture;
    xTexture.loadFromImage(xImage);

    float radius = size/12;
    float thickness = radius/10;

    sf::Sprite circle;
    circle.setTexture(oTexture);

    sf::Sprite xshp;
    xshp.setTexture(xTexture);

    for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(matrix[i][j])
                {
                    switch (matrix[i][j]->getSymbol())
                    {
                        case 'O':
                        {
                            circle.setPosition(0.5*size/6 + position.x, 0.5*size/6 + position.y);
                            circle.move(j*size/3, i*size/3);
                            window->draw(circle); 
                        }
                        break;
                        case 'X':
                        {
                            xshp.setPosition(0.5*size/6 + position.x, 0.5*size/6 + position.y);
                            xshp.move(j*size/3, i*size/3);
                            window->draw(xshp); 
                            
                        }
                        
                    }
                }
            }
        }
}

bool Game::isFull()
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(!matrix[i][j])
                return false;
        }
    }
    return true;
}

Player* Game::winner()
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
    return NULL;
} 
        
bool Game::play(int lin, int col)
{
    if(lin >= 3 || lin < 0) 
        return false;
    else if (col >= 3 || col < 0) 
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
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(matrix[i][j])
                cout << matrix[i][j]->getSymbol(); 
            else cout << " ";
        }
        cout << endl;
    }
}

