#ifndef JOGO_H
#define JOGO_H

#include "Player.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Game
{
    public:

        Game(Player *p1, Player *p2);

        bool isFull();
        Player* winner();
        bool play(int lin, int col);
        void print();
        void drawGrade();
        void drawPlays();
        
        //Setters
        void setWindow(sf::RenderWindow *window) {this->window=window;};
        void setPosition(sf::Vector2f& position) {this->position = position;};
        void setSize(float size) {this->size = size;};
        void setImages(sf::Image& xImage, sf::Image& oImage) {this->xImage = xImage; 
                                                              this->oImage = oImage;};

        //Getters
        float getSize() {return this->size;};
        sf::Vector2f getPosition() {return this->position;};
        Player* getActive() {return this->active;};

    private:
        sf::Image oImage;
        sf::Image xImage;
        sf::RenderWindow *window;
        float size;
        sf::Vector2f position;
        Player* p1;
        Player* p2;
        Player* active;
        Player* matrix[3][3];
};

#endif