#include "headers/Menu.h"

Menu::Menu(sf::RenderWindow &window,sf::Image background_Recieved, sf::Font fonte)
{
    sf::Texture texture;
    texture.loadFromImage(background_Recieved);

    this->background.setTexture(texture);
    this->fonte = fonte;
    this->window = window;

    Selecionar.setFont(this->fonte);
    ComoJogar.setFont(this->fonte);

    Selecionar.setString("Selecionar modo de Jogo");
    ComoJogar.setString("Como Jogar");

    Selecionar.setCharacterSize(40);
    ComoJogar.setCharacterSize(40);

    Selecionar.setFillColor(Color::Black);
    ComoJogar.setFillColor(Color::Black);
}

void Menu::drawMenu()
{
    background.setPosition(0,0);
    sf::RectangleShape  hLine()
}
