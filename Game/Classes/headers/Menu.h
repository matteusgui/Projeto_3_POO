#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <sstream>

class Menu
{
private:
    sf::Font fonte;
    sf::Text Selecionar;
    sf::Text Titulo;
    sf::RenderWindow &window;
public:
    Menu( sf::RenderWindow &window, sf::Image background, sf::Font fonte);
    ~Menu();
    void drawMenu();
    bool cliqueIniciar();
};
