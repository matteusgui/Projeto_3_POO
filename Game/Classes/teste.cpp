#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "headers/Menu.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Menu");
    sf::Image background;
    background.loadFromImage("../Images/TicTacToe.png");
    sf::Font fonte;
    fonte.loadFromFile("../Fonts/OpenSans-Bold.ttf");
    Menu menu(window, background, fonte);
    while (/* condition */)
    {
        /* code */
    }
    
}